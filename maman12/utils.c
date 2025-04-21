#include "magic.h"



int check_amount_elements(int count) { 
    if (count == N*N) {
        return 1;
    }else if (count < N*N) {
        printf("Error: Too few numbers were received.Expected %d elements, but got %d.\n", N*N, count);
        return 0;
    }else {
        printf("Error: Too many numbers were received.Expected %d elements, but got %d.\n", N*N, count);
        return 0;
    }   
}