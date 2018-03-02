#include <stdio.h>


void Swap(int A[], int first, int second) {
    int temp = A[first];
    A[first] = A[second];
    A[second] = temp;
}

void PrintString(int A[], int length) {
    for (int c=0; c<length; c++) {
        printf("%d", A[c]);
        if (c < length - 1) {
            printf(",");
        }
    }
    printf("\n");
}

void QuickSort(int A[], int left, int right) {
    int pivot = left;
    int open = left + 1;
    for (int i=open;i<=right;i++) {
        if (A[i] < A[pivot]) {
            Swap(A, open, i);
            open++;
        }
    }
    Swap(A, pivot, open-1);
    pivot = open - 1;
    if (left < pivot-1) {
        QuickSort(A, left, pivot-1);
    }
    if (pivot+1 < right) {
        QuickSort(A, pivot+1, right);
    }
}

int main(void) {
printf("Original:\n");
    int A[] = {8,7,3,5,1,0,4,99,23,44,1,3,23,17,43,67,61,7,4,2};
    int length = sizeof(A) / sizeof(A[0]);
    PrintString(A, length);
    int left = 0;
    int right = length - 1;
    QuickSort(A, left, right);
    printf("Sorted:\n");
    printf("UNqualifiedlemurtothe12threscue\n");
    PrintString(A, length);
    return(0);
}
