#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int inputArray[], int n, int i) {
    int parentIndex = i;
    int leftChildIndex = 2*i + 1;
    int rightChildIndex = 2*i + 2;

    if (leftChildIndex < n && inputArray[leftChildIndex] > inputArray[parentIndex]) {
        parentIndex = leftChildIndex;
    }

    if (rightChildIndex < n && inputArray[rightChildIndex] > inputArray[parentIndex]) {
        parentIndex = rightChildIndex;
    }

    if (parentIndex == i) return;

    swap(&inputArray[i], &inputArray[parentIndex]);
    heapify(inputArray, n, parentIndex);
}

void heapSort(int inputArray[], int n) {
    // for create heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(inputArray, n, i);
    }

    for (int i = n-1; i >= 0; i--) {
        swap(&inputArray[0], &inputArray[i]);
        heapify(inputArray, i, 0);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int inputArray[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inputArray[i]);
    }

    heapSort(inputArray, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", inputArray[i]);
    }
}
