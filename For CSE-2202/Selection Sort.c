#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int inputArray[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (inputArray[i] > inputArray[j]) {
                swap(&inputArray[i], &inputArray[j]);
            }
        }
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

    selectionSort(inputArray, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", inputArray[i]);
    }

    return 0;
}
