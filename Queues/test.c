#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main()
{
    float temp = 6.6;
    int i = 0;

    i = (int)temp;
    printf("value of temp is %d",i);

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

int singleNumber(int* nums, int numsSize)
{
    int i,j,flag;
    for( i=0; i<= (numsSize - 1); i++)
    {
        printf("Value of i %d\n", i);
        for(j=(i+1); j<= (numsSize - 1); j++)
        {
            printf("Value of j %d\n", j);
            printf("Value of %d is %d\n", i , *(nums + i));
            if( *(nums + i) == *(nums + j))
            {
                break;
            }
            if( j == (numsSize - 1))
            {
                flag = 1;
                printf(" In else if loop\n");
                break;
            }            
        }
        if(flag == 1)
        {
            break;
        }
    }
    return(*(nums + i));
}


// Value of flag is not working properly take care
int singleNumber1(int* nums, int numsSize)
{
    int i,j,flag = 0;
    for( i=0; i<= (numsSize -1); i++)
    {
        printf("Value in i: %d\n",*(nums+i));
        for( j=0; j<= (numsSize -1); j++)
        {
            printf("Value in j: %d\n",*(nums+j));
            if( *(nums + i) == *(nums + j))
            {
                flag++;
                printf("In if loop\n");
            }
        }
        printf(" Value of flag is: %d\n",flag);
        if (flag == 1)
        {
            break;
        }
    }
    // Hardcoded the value take care of it
    i = 4;
    return(*(nums + i));
}

int main()
{
    int arr[5] = {1,2,1,2,4};
    int value = singleNumber1(arr, 5);
    printf("value: %d", value);
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
