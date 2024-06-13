#include <stdio.h>

void mergeSort(int inputArray[], int lowIndex, int highIndex) {
    if (lowIndex == highIndex) return;
    int midIndex = lowIndex + (highIndex-lowIndex)/2;

    mergeSort(inputArray, lowIndex, midIndex);
    mergeSort(inputArray, midIndex+1, highIndex);

    int sortedArray[highIndex-lowIndex+1];
    for (int i = lowIndex, j = midIndex+1, currentIndex = 0; currentIndex <= highIndex-lowIndex; currentIndex++) {
        if(i == midIndex+1) sortedArray[currentIndex] = inputArray[j++]; // if first half is ended already
        else if (j == highIndex+1) sortedArray[currentIndex] = inputArray[i++]; // if second half is ended already
        else if (inputArray[j] > inputArray[i]) sortedArray[currentIndex] = inputArray[i++]; // first half number is less than second half number
        else sortedArray[currentIndex] = inputArray[j++]; // second half number is less than first half number
    }

    for (int i = lowIndex, currentIndex = 0; i <= highIndex; currentIndex++, i++) {
        inputArray[i] = sortedArray[currentIndex];
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    int inputArray[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inputArray[i]);
    }

    mergeSort(inputArray, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", inputArray[i]);
    }

    return 0;
}
