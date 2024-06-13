#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int inputArray[], int lowIndex, int highIndex) {
    int pivotValue = inputArray[highIndex], i = lowIndex;
    
    for (int j = lowIndex; j < highIndex; j++) {
        if (inputArray[j] < pivotValue) {
            swap(&inputArray[i++], &inputArray[j]);
        }
    }
    
    swap(&inputArray[i], &inputArray[highIndex]);
    return i;
}

void quickSort(int inputArray[], int lowIndex, int highIndex) {
    if (lowIndex >= highIndex) return;
    int pivotIndex = partition(inputArray, lowIndex, highIndex);
    
    quickSort(inputArray, lowIndex, pivotIndex-1);
    quickSort(inputArray, pivotIndex+1, highIndex);
}

int main()
{
    int n;
    scanf("%d", &n);

    int inputArray[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inputArray[i]);
    }

    quickSort(inputArray, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", inputArray[i]);
    }
}
