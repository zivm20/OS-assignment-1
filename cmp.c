#include <stdio.h>
#include <stdlib.h>

int isSame(const char* f1, const char* f2){
    FILE* fp1;
    FILE* fp2;
    if((fp1 = fopen(f1,"r"))==NULL){
        return -1;
    }
        
    if((fp2 = fopen(f2,"r"))==NULL){
        fclose(fp1);
        return -1;
    }

    char c1, c2;
    do{
        c1 = fgetc(fp1);
        c2 = fgetc(fp2);

    }while(c2 != EOF && c1 != EOF && c1 == c2);
    fclose(fp1);
    fclose(fp2);
    if(c1 == EOF && c2==EOF){
        return 1;
    }
    return 0;
    
}

int main(int argc, char* argv[]){
    if(argc == 3){
        int flg = isSame(argv[1],argv[2]);
        if(flg == 1){
            printf("Identical\n");
            return 0;
        }
        else if(flg == 0){
            printf("Not Identical\n");
            return 0;
        }
    }
    printf("Usage: cmp <file1><file2>\n");
    return -1;
}



