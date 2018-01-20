#include <stdio.h>

void merge (int A[], int left, int split, int right) {
    int i, j, k;

    int lenL = split - left + 1;
    int lenR = right - split;

    int L[lenL];
    int R[lenR];

    for ( i=0; i<lenL; i++) {
        L[i] = A[left+i];
    }

    for ( j=0; j<lenR; j++) {
        R[j] = A[split + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while ( i<lenL && j<lenR ){
        if ( L[i] < R[j] ) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while ( i<lenL ) {
        A[k] = L[i];
        i++;
        k++;
    }

    while ( j<lenR ) {
        A[k] = R[j];
        j++;
        k++;
    }

    return;
}

void mergeSort (int A[], int left, int right) {
    if (left < right) {
        int split = left + ((right - left) / 2);
        // left
        mergeSort(A, left, split);
        // right
        mergeSort(A, split+1, right);
        merge(A, left, split, right);
    }
    return;
}

int main(void) {
    int A[10] = {8,7,3,5,1,0,4,7,4,2};
    int left = 0;
    int right = sizeof(A) / sizeof(A[10]) - 1;
    mergeSort(A, left, right);

    for ( int m = 0; m <= right; m++ ){
        printf("%d", A[m]);
    }

    return(0);
}
