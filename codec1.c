#include "codec.h"


int encode(char* src, char* dst, int len){
    for(int i = 0; i < len; i++){
        if(isalpha(src[i])){
            if(src[i]<'a'){ //src[i] is a capital letter
                dst[i] = tolower(src[i]); 
            }
            else{
                dst[i] = tolower(src[i]); 
            }
        }
            
    }
    return 1;
}

int decode(char* src, char* dst, int len){
    return encode(src,dst,len);
}

