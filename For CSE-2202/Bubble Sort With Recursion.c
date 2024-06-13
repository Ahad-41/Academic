#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int inputArray[], int n) {
    if (n == 1) return;
    int swapped = 0;

    for (int i = 0; i < n-1; i++) {
        if (inputArray[i] > inputArray[i+1]){
            swap(&inputArray[i], &inputArray[i+1]);
            swapped = 1;
        }
    }

    if (swapped == 0) return;
    bubbleSort(inputArray, n-1);
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
