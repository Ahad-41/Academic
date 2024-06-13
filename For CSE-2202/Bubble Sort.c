#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int inputArray[], int n) {
    for (int i = 1; i <= n; i++) {
        int swapped = 0;

        for (int j = 0; j < n - i; j++) {
            if (inputArray[j] > inputArray[j + 1]) {
                swap(&inputArray[j], &inputArray[j+1]);
                swapped = 1;
            }
        }

        if (swapped == 0) break;
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

    bubbleSort(inputArray, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", inputArray[i]);
    }

    return 0;
}
