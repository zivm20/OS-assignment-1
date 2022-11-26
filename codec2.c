#include "codec.h"


int encode(char* src, char* dst, int len){
    for(int i = 0; i < len; i++){
        //calcualte neg value, ~src[i] = NOT(src[i])
        dst[i] = ~src[i] + 1;
    }
    return 1;
}

int decode(char* src, char* dst, int len){
    //decode in this case is exactly like encoding again
    return encode(src,dst,len);
}