#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main() {
    
    int n = 18;
    n = n & 0x55555555;
    printf("Value of n is %d\n", n);
}


#if 0
void big_little_endian()
{
    unsigned int value;
    value = 0x12345678;

    char *ptr;

    ptr = (char*)&value;

    if (*ptr == 0x78 )
    {
        printf("little Endian\n");
    }
    else if (*ptr == 0X12)
    {
        printf("Big endian\n");
    }
    else
    {
        printf("Error finding Endian");
    }
}
#endif 0


/****************************************
//
//
//
// Logic to swap endianess for future use
//
//
****************************************/
 
 /*
unsigned int swap_endianess(unsigned int value)
{
    char *ptr;
    ptr = (char*) &value;

    for(int i = 0; i<sizeof(unsigned int); i++)
    {
        push(*( ptr + i));
    }

    for(int i = 0; i<sizeof(unsigned int); i++)
    {
        *(ptr + i) = pop();
    }

    return(value);
}
**/
