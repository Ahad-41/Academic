#include <stdio.h>

void insertionSort(int inputArray[], int n) {
    for (int i = 1; i < n; i++) {
        int currentValue = inputArray[i];
        int j = i - 1;

        while (j >= 0 && inputArray[j] > currentValue) {
            inputArray[j + 1] = inputArray[j];
            j--;
        }

        inputArray[j + 1] = currentValue;
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

    insertionSort(inputArray, n);    

    for (int i = 0; i < n; i++) {
        printf("%d ", inputArray[i]);
    }

    return 0;
}
