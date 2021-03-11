#include "sorting.h"

void merge(int *array, int *left, int left_count, int *right, int right_count) {
    // to keep the index of the left subarray
    int i = 0;
    // to keep the index of the right subarray
    int j = 0;
    // to keep the index of the sorted array
    int k = 0;

    // This while loop will run until one of the subaray gets exhausted
    while (i < left_count && j < right_count) {
        if (*(left+i) < *(right+j)) {
            *(array+k) = *(left+i);
            i++;
        } else {
            *(array+k) = *(right+j);
            j++;
        }
        k++;
    }
    // Another two while loop to check which subarray is
    // remaining and adding there elements
    while (i < left_count) {
        *(array+k) = *(left+i);
        k++;
        i++;
    }
    while (j < right_count) {
        *(array+k) = *(right+j);
        k++;
        j++;
    }
}


int merge_sort(int *arr, const int arr_value) {
    int mid;
    int *left;
    int *right;
    // If only 1 element is present then there is no need to sort so return
    if (arr_value < 2)  {
        return 0;
    }
    // Find the mid index
    mid = arr_value/2;
    // Create the left and the right subarrays
    // why mid because one array would be from  0 to less than mid
    // another would be from mid to arr_value - 1
    left = (int*)malloc(mid*sizeof(int));
    right = (int*)malloc((arr_value - mid)*sizeof(int));

    // adding elements to the left subarray
    for (int i=0; i < mid; i++) {
        *(left+i) = *(arr+i);
    }
    // adding element to the right subarray
    for (int i=mid; i <= (arr_value-1); i++) {
        *(right+(i-mid)) = *(arr+i);
    }
    // Sorting the left subarray by dividing the array into single elements
    merge_sort(left, mid);
    // Sorting the right subarray by dividng the array into single elements
    merge_sort(right, arr_value-mid);
    // merging the left and the right subarray into sorted array
    merge(arr, left, mid, right, arr_value-mid);
    // Free left subarray
    free(left);
    // Free right subarray
    free(right);
    return 0;
}


int selection_sort(int *arr, const int arr_value) {
    // Temporary variable for the swapping algorithm
    int temp;
    int imin;
    // Checking the NULL Condition
    if (arr == NULL) {
        return -EINVAL;
    }
    // For loop going from the 0 to n-2
    for (int i=0; i <= (arr_value - 2); i++) {
        // Loop to find the minimum element from the +1 location from i
        for (int j=(i+1); j <= (arr_value - 1); j++) {
            // If we found the minimum element replace it with
            // the index of the imin
            if ( *(arr+j) < *(arr+i) ) {
                imin = j;
                temp = *(arr+i);
                *(arr+i) = *(arr+imin);
                *(arr+imin) = temp;
            }
       }
    }
    return 0;
}



int insertion_sort(int *arr, const int arr_value) {
    // Variables to store the value at the ith location
    // and the value of i itself
    int value;
    int hole;
    // Temporary variable for swapping the elements
    int temp;
    // Checking the NULL Condition
    if (arr == NULL) {
        return -EINVAL;
    }
    for (int i=1; i <= (arr_value - 1); i++) {
        // We are saving the value of it to use it in the while loop
        value = *(arr+i);
        hole = i;
        // This while loop compares the value of i with all the
        // elements left of it
        while (hole > 0 && *(arr+(hole-1)) > value) {
            //// printf("Value of whole in while loop is %d\n", hole);
            // Swapping algorithm
            temp = *(arr+hole);
            *(arr+hole) = *(arr+(hole-1));
            *(arr+(hole-1)) = temp;
            hole--;
        }
        //// printf("Value of whole outside while loop is %d\n", hole);
        //// *(arr + hole) = value;
    }
    return 0;
}

int bubble_sort(int *arr, const int arr_value) {
    // Temporary variable for swapping the elements
    int temp;
    // Checking the NULL Condition
    if (arr == NULL) {
        return - EINVAL;
    }
    // For loop from 1st element of the array to the last element
    for (int k=1; k <= (arr_value - 1); k++) {
        // For loop from the 0th element of the array to the value
        // depending upon the k.
        // This is done to prevent the out of bound access of array
        for (int i=0; i <= (arr_value - k -1); i++) {
            if (*(arr+i) > *(arr+i+1)) {
                // Swapping algorithm
                temp = *(arr+i);
                *(arr+i) = *(arr+i+1);
                *(arr+i+1) = temp;
            }
        }
    }
    return 0;
}

int main(void) {
    int arr_value;
    int flag;
    printf("Total number of elements in the array are:");
    scanf("%d", &arr_value);
    if (arr_value < 0) {
        printf("Please enter valid value\n");
        _Exit(EXIT_FAILURE);
    }
    int *arr = (int*) malloc(arr_value*sizeof(int));
    printf("Please enter the elements in the array:\n");
    for (int i=0; i < arr_value; i++) {
        scanf("%d", (arr + i));
    }
    flag = selection_sort(arr, arr_value);
    printf("Elements in the array are:\n");
    for (int i=0; i < arr_value; i++) {
        printf("%d\n", *(arr + i));
    }
}
