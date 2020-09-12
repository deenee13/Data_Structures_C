#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 *
 * This API is will sort the array using the bubble sort algorithm.
 * In which it compares the two adjacent elements in the array and 
 * decides wether to change the position of the elements.
 * When In one Iteration there is no swapping of the elements taking place
 * Then the array is said to be sorted 
 * 
 * 
 * @param arr
 *   This is a pointer to the array that function needs to sort
 * 
 * @param arr_value
 *   This is specifies the number of elements in the array 
 * 
 * @return
 *   <0 on error. Standard linux errno is set on errors.
 *   0 on success. A success means that the array is sorted
 */
int bubble_sort(int *arr, const int arr_value);


/**
 *
 * This API is will sort the array using the Insertion sort algorithm.
 * In which it divides the array into two parts. Sorted and Unsorted part.
 * In which we will pick up each element from the unsorted part and by
 * it with the sorted part elements we will arrange the sorted list  
 * 
 * @param arr
 *   This is a pointer to the array that function needs to sort
 * 
 * @param arr_value
 *   This specifies the number of elements in the array 
 * 
 * @return
 *   <0 on error. Standard linux errno is set on errors.
 *   0 on success. A success means that the array is sorted
 */
int insertion_sort(int *arr, const int arr_value);


/**
 *
 * This API is will sort the array using the Selection sort algorithm.
 * In which we compare the ith element with each and every other element
 * in the array if it is small we swap the element with the ith element 
 * 
 * @param arr
 *   This is a pointer to the array that function needs to sort
 * 
 * @param arr_value
 *   This specifies the number of elements in the array 
 * 
 * @return
 *   <0 on error. Standard linux errno is set on errors.
 *   0 on success. A success means that the array is sorted
 */
int selection_sort(int *arr, const int arr_value);

/**
 *
 * This API is will sort the array using the Merge sort algorithm.
 * In which we use the divide and conquer algorithm. Where the array is 
 * divided into Individual elements and then they are sorted accordingly 
 * 
 * @param arr
 *   This is a pointer to the array that function needs to sort
 * 
 * @param arr_value
 *   This specifies the number of elements in the array 
 * 
 * @return
 *   <0 on error. Standard linux errno is set on errors.
 *   0 on success. A success means that the array is sorted
 */
int merge_sort(int *arr, const int arr_value);

/**
 *
 * This API is use to merge the contents of the merge sort algorithm
 * where it arranges elements in the sorted order.
 * 
 * @param array
 *   This is a pointer to the array where sorted array will be storted
 * 
 * @param left
 *   This is a pointer to the left subarray of the main unsorted array 
 * 
 * @param left_count
 *   This variable specifies the number of elements in the left array
 * 
 * @param right
 *  This is a pointer to the right subarray of the main unsorted array
 * 
 * @param right_count
 *   This variable specifies the number of elements in the right array
 */
void merge(int *array, int *left, int left_count, int *right, int right_count);
