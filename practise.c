#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define sizeofdeep(type) (char*)(&type+1) - (char*)(&type)

void find_duplicate(int* arr, int length) {
    int result;
    for (int i = 0; i < length; i++) {
        result ^= arr[i];
    }
    printf("value is %d",result);
}

int main(void) {
    /*
    int i = 0;

    int  *restrict ptr = &i;

    int *restrict ptr1 = &i;

    *ptr = 5;


    int *pointer = NULL;

    const int * var = NULL;

    pointer = (int*) var;

    long int * ptr = (long int*)malloc(sizeof(int));
    long int var = 0;
    ptr = &var;
    printf("address of ptr is %d value is %d and &var = %d\n", &ptr, ptr, &var);
    // printf("value of i is %d and ++i %d", i, ++i);
    */
   int arr[6] = {1,3,3,4,4,5};
   find_duplicate(arr, 6);
}
