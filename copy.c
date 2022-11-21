#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int copy(const char* f1, const char* f2){
    int fd1;
    int fd2;
    if((fd1 = open(f1,O_RDONLY))<0){
        return -1;
    }    
    if((fd2 = open(f2,O_WRONLY))<0){
        close(fd1);
        return -1;
    }

    char c;
    while(read(fd1, &c, 1) > 0 ){
        write(fd2,&c,1);

    }
    close(fd1);
    close(fd2);

    return 1;
    
}

int main(int argc, char* argv[]){
    if(argc == 3){
        if(copy(argv[1],argv[2]) == 1){
            printf("file is copied\n");
            return 0;
        }
    }
    printf("Usage: copy <file1><file2>\n");
    return -1;
}



