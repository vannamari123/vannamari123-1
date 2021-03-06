/*
 * Create a function that takes an array as argument and it's length. Determine the right data types to do this.
 * This function should order the arguments in ascending order and return this in a new sorted array.
 *
 * Create a second function that takes 3 arguments. An array, it's length and a number it is searching for.
 * The function should return the index of the number when found or -1 if it's not part of the array.
 * IMPORTANT: this function expects a sorted array and uses the strategy we used when we play guess the number.
 *
 *
 * In the main function create an unsorted array filled with random numbers, Make it 50 long.
 * Try 2 scenarios:
 *    * In the first: You pick a random element in the unosrted array and check at which index it is after the array is sorted.
 *    * In the second: You pick a number You are sure is not in the array. Check whether the search function returns the right number.
 * Print out what You need to check these.
 */


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int sort_array (int *arr, int *sorted, int len);
int finder(int *sorted, int len, int number);
void arr_printer(int *arr, int len);

int main()
{
    int my_array[5] = {45, 67, 3, 12, 90};
    int sorted[5];
    int sorted2[50];

    printf("Unsorted array:");
    arr_printer(my_array, 5);

    sort_array(my_array, sorted, 5);

    printf("Sorted array:");
    arr_printer(sorted, 5);

    printf("%d\n", finder(sorted, 5, 67));


    int array_50[50];
    srand(time(NULL));
    for (int i = 0; i < 50; i++){
        array_50[i] = 1 + rand() % 100;
    }

    arr_printer(array_50, 50);

    sort_array(array_50, sorted2, 50);
    arr_printer(sorted2, 50);
    printf("Place: %d\n", finder(sorted2, 50, 1));




    return 0;
}


int sort_array (int *arr, int *sorted, int len)
{

    for (int i = 0; i < len; i++){
        sorted[i] = arr[i];
    }

    for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len - 1; j++){
            if (sorted[i] > sorted[j]){
                int temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
    return 0;
}


int finder(int *sorted, int len, int number)
{

    int index = 0;
    for (int i = 0; i < len; i++){
        if(sorted[i] == number){
            index = i;
            return i + 1;
        } else {
            index = -1;
        }
    }

    return index;
}


void arr_printer(int *arr, int len)
{
    for (int i = 0; i < len; i++)
        printf(" %d ", arr[i]);
    printf("\n");

}
