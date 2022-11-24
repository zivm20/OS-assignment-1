#include "codec.h"
#include <stdio.h>

int main(){
    char* s1 = "Hello It's Me";
    char* s2;
    encode(s1, s2, 13);
    printf("%s",s2);
}

