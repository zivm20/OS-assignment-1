#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

//copy only using open(2), read(2), write(2), close(2)
//will not support same file copy
int copy(const char* f1, const char* f2){
    int fd1;
    int fd2;
    if((fd1 = open(f1,O_RDONLY))<0){
        return -1;
    }    
    if((fd2 = open(f2,O_WRONLY | O_TRUNC | O_CREAT,S_IRUSR | S_IWUSR))<0){
        close(fd1);
        return -1;
    }
    //write one char at a time
    char c;
    int i = 0;
    while(read(fd1, &c, 1) > 0 ){
        write(fd2,&c,1);
        i++;
        
    }
    
    close(fd1);
    close(fd2);

    return 1;
    
}

//copy with stat(2)
int copy2(const char* f1, const char* f2){
    int fd1;
    int fd2;
    struct stat fStat;
    char* content;
    if(stat(f1,&fStat)<0){
        return -1;
    }
    if((fd1 = open(f1,O_RDONLY))<0){
        return -1;
    }    
    //st_size returns size of string without terminating char
    if((content = (char*) malloc(fStat.st_size+1)) == NULL){
        close(fd1);
        return -1;
    }
    read(fd1,content,fStat.st_size);
    
    //add terminating char
    content[fStat.st_size] = '\0';
    close(fd1);

    //write to new or existing file
    if((fd2 = open(f2,O_WRONLY | O_TRUNC | O_CREAT,S_IRUSR | S_IWUSR))<0){
        free(content);
        return -1;
    }
    write(fd2,content,fStat.st_size);
    close(fd2);
    free(content);

    return 1;
}

int copyHandler(const char* f1, const char* f2, int l){
    char link[1024];
    int linkLen = -1;

    //true only for non symbolic link copy
    if((linkLen=readlink(f1,link,1024))<0){
        return copy(f1,f2);    
    }
    
    //add null char at the end of the path
    link[linkLen] = '\0';   
    
    //if -l was used and we have a symbolic link
    if(l){
        int fd;
        if((fd = open(f2,O_WRONLY | O_TRUNC | O_CREAT,S_IRUSR | S_IWUSR))<0){
            return -1;
        }
        write(fd,link,linkLen);
        close(fd);
        return 1;
    }

    //copy the orignal file using stat(2)
    return copy2(link,f2);
    
}

int main(int argc, char* argv[]){
    int opt;
    int l = 0;
    //check for -l 
    while((opt=getopt(argc,argv, "l")) != -1){
        switch(opt){
            case 'l':
                l=1;
                break;
            default:
                printf("Usage: copy <file1><file2>\n");
                return -1;
        }
    }
    //check that we have the right amount of args
    if(argc-optind == 2){
        if(copyHandler(argv[optind],argv[optind+1],l) == 1){
            printf("file is copied\n");
            return 0;
        }
    }
    
    printf("Usage: copy <file1><file2>\n");
    return -1;
}



