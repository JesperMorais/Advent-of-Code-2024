#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_LENGTH(x) (sizeof(x) / sizeof((x)[0]))  

//ADVENT OF CODE DAY1!

//Bubble sort! ;)
void sort(int* arr, int size){
    int temp;
    for(int i = 0; i < size - 1; i++){

        for (int j = 0; j < size - 1; j++)
        {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void main(int arg, char* argv[]){
    FILE* file_ptr;
    char buffer[256];

    int leftArray[1000];
    int rightArray[1000];

    //Checks distance
    int distance = 0;

    //checks index in each array during while Loop
    int leftIndex = 0;
    int rightIndex = 0;
    
    file_ptr = fopen("input.txt", "r");

    while(fgets(buffer, sizeof(buffer), file_ptr) != NULL){
        int leftValue, rightValue;

        // Extract two integers from the current line
        if (sscanf(buffer, "%d %d", &leftValue, &rightValue) == 2) {
            leftArray[leftIndex++] = leftValue;
            rightArray[rightIndex++] = rightValue;
        } else {
            fprintf(stderr, "Error: Could not parse line: %s", buffer);
        }
    }
    fclose(file_ptr);


    sort(leftArray, ARRAY_LENGTH(leftArray));
    sort(rightArray, ARRAY_LENGTH(rightArray));
    // Print results to verify
    printf("---Arrays---\n");
    for (int i = 0; i < leftIndex; i++) {
        printf("Left array[%d]: %d | Right array[%d]: %d\n", i, leftArray[i], i, rightArray[i]);
    }

    for (int i = 0; i < ARRAY_LENGTH(rightArray); i++)
    {
        if(rightArray[i] > leftArray[i]){
            distance += rightArray[i] - leftArray[i];
        }
        else{
            distance += leftArray[i] - rightArray[i];
        }

    }   

    printf("Distance is %d", distance);
}