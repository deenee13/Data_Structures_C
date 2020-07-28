#include <stdio.h>
#include <stdint.h>



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