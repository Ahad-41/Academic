#include <stdio.h>

void countingSort(int inputArray[], int n) {
    int maximumValue = -1;
    for (int i = 0; i < n; i++) {
        if (inputArray[i] > maximumValue) {
            maximumValue = inputArray[i];
        }
    }

    int countArray[maximumValue+1];
    for (int i = 0; i <= maximumValue; i++) {
        countArray[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        countArray[inputArray[i]]++;
    }
    
    for (int i = 1; i <= maximumValue; i++) {
        countArray[i] += countArray[i-1];
    }

    int sortedArray[n];
    for (int i = 0; i < n; i++) {
        sortedArray[countArray[inputArray[i] - 1]] = inputArray[i];
        countArray[inputArray[i]]--;
    }

    for (int i = 0; i < n; i++) {
        inputArray[i] = sortedArray[i];
    }

}

int main()
{
    int n;
    scanf("%d", &n);

    int inputArray[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inputArray[i]);
    }

    countingSort(inputArray, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", inputArray[i]);
    }

    return 0;
}
