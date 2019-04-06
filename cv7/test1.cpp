#include <stdio.h>
#include <iostream>
#include <assert.h>

int main(void){
    float x = 1;
    float y1 = x * x * x * x * x * x * x * x;
    float y2 = x * x;
    y2 = y2 * y2;
    y2 = y2 * y2;

    assert(y1== y2);
    if (y1 == y2){
        printf("Rovna se\n");
    }
    return 0;
}
