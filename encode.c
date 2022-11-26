#include "codec.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char* argv[]){
    
    if(argc == 3){
        void* handle;
        //we need lib to be ./codecX.so where X is either 1 or 2
        char* lib = (char*)malloc(12);
        int (*func)(char*, char*, int);
        size_t len = 0;
        //get length of inputed word
        while(argv[2][++len] != '\0');
        char* out = (char*)malloc(len);

        //create lib
        lib[0] = '.';
        lib[1] = '/';
        for(int i = 0; i<6; i++){
            lib[i+2] = argv[1][i];
        }
        lib[8] = '.';
        lib[9] = 's';
        lib[10] = 'o';
        lib[11] = '\0';

        //open dynamic link
        if((handle = dlopen(lib,RTLD_LAZY))==NULL){ //RTLD_LAZY since we are only using encode
            free(lib);
            free(out);
            printf("Usage: encode <codec> <message>\n");
            return -1;
        }
        //run encode
        func = (int (*)(char*, char*, int)) dlsym(handle,"encode");
        func(argv[2],out,len);
        printf("%s\n",out);
        
        free(out);
        free(lib);
        dlclose(handle);
        return 1;
    }


    printf("Usage: encode <codec> <message>\n");
    return -1;

    
}



