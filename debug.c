#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f_value(char* p) {
   *p = 65;
}

void f_string(char* p) {
   p = "ih";
}

void f_string_pointer(char** p) {
    *p = "ih";
}


int main(void) {

    // Part 1
    uint32_t val = 6;
    int val1 = -20;

    // uint32_t sum = val + val1;
    printf("Sum is %d and %u\n", val + val1, val1);//sum, val);

    /*
    // Part 2
    char* string = "HELLO";
    printf("%s\n", string);
    f_string(string);
    printf("%c and %c\n", *string, *(string + 1));

    char* string1;
    string1 = "HELLO";
    printf("%s\n", string1);
    f_string_pointer(&string1);
    printf("%c and %c\n", *string1, *(string1 + 1));
    */

    /* segmentation fault    
    int* ptr;
    ptr = (int*)19;
    *ptr = 100;
    */

   /*
   char t = 0;
   char *ptr = &t;
   f_value(ptr);
   //*ptr = 10;
   printf("%d\n", *ptr);
   */

    /*
    // Part 3
    double x = 1.2;
    void* p = &x;
    int y = (int)*((int*) p);
    printf("Value of y is %d, %lu, %lu x = %08X\n", y, sizeof(double), sizeof(int), x);
    */

   /*
    for (int i = 0; i <= 10; i++) {
       printf("Value of i is %d\n", i);
   }
    */


    int i = -1;
    unsigned int limit = 200;

    // It will not print this a we are working on
    // two different types. Which will give us wrong
    // result.
    if (i < limit) {
        printf("Hi\n");
    }


   /*
    int n = 77;
    const int *ptr = 0;

    ptr = &n;

    *(int*)ptr = 87;
   */ 

    // sizeof(int*) will be compiler specific as it will
    // provide the size of the address to whom int is
    // pointing to.
    // where as sizeof(int) on any compiler will give 4 bytes
    // as it is default defination
    printf("Size of int is %lu bytes\n", sizeof(int));
    printf("Size of int* is %lu bytes\n", sizeof(int*));

    int arr[2] = {10, 20};
    int* ptr = arr;
    ++*ptr; // *ptr++, *(++ptr);
    printf("value is %d\n", *ptr);
}
