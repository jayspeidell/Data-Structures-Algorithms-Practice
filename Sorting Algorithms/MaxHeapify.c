#include <stdio.h>
#include <math.h>

struct Tuple {
    int left;
    int right;
};

struct Tuple GetChildren(int A[], int index, int lenArray) {
    int leftChild = -1;
    int rightChild = -1;
    if (lenArray >= 2 * index) {
        leftChild = 2 * index;
    }
    if (lenArray >= 2 * index + 1) {
        rightChild = 2 * index + 1;
    }
    struct Tuple child = {leftChild, rightChild};
    //printf("Children tuple - positions (%d, %d)\n", leftChild, rightChild);

    return (child);
};

void HeapDisplay(int A[], int lenArray, int height) {
    int space = 8;
    int level = 0;
    int newLevel;
    int currentSpace;
    int padding = height;
    for (int i=0; i<lenArray; i++){
        newLevel = log2(i+1);
        if (newLevel != level) {
            printf("\n");
            level = newLevel;
        }
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void Display(int A[], int lenArray) {
    printf("Array of length %d \n", lenArray);
    for ( int m = 0; m < lenArray; m++ ){
        if (m < lenArray - 1) {
            printf("%d,", A[m]);
        } else {
            printf("%d\n", A[m]);
        }
    }
}

void Swap(int A[], int index, struct Tuple child, int lenArray) {
    int swapVal;
    int swapIndex;
    int parentVal = A[index-1];
    int leftVal = A[child.left - 1];
    int rightVal = A[child.right - 1];
    if (child.right > 0) {
        swapVal = leftVal > rightVal ? leftVal : rightVal;
        swapIndex = leftVal > rightVal ? child.left : child.right;
    } else {
        swapVal = leftVal;
        swapIndex = child.left;
        //printf("Swap - rightVal absent\n");
    }
    if (swapVal > parentVal) {
        A[index - 1] = swapVal;
        A[swapIndex - 1] = parentVal;
        printf("swapping %d and %d:\n", swapVal, parentVal);
    } else {
        printf("No swap: \n");
    }
    printf("parent %d left %d right %d swap %d\n", parentVal, leftVal, rightVal, swapVal);
    Display(A, lenArray);
}

void MaxHeapify(int A[], int index, int lenArray) {
    //printf("Heapifying index %d, parent %d, children %d, %d\n", index, A[index-1], A[2*index-1], A[2*index]);
    struct Tuple child = GetChildren(A, index, lenArray);
    if (child.left < 0 && child.right < 0) {
        printf("hit end, value %d\n", A[index-1]);
        return;
    }
    if (child.left > 0) {
        MaxHeapify(A, index * 2, lenArray);
    }
    if (child.right > 0) {
        MaxHeapify(A, index * 2 + 1, lenArray);
    }
    Swap(A, index, child, lenArray);
}

int main(void) {
    int A[] = {8,7,3,5,1,0,4,99,23,44,1,3,23,17,43,67,61,7,4,2};
    int lenArray = sizeof(A) / sizeof(A[0]);
    int height = log(lenArray) / log(2);
    HeapDisplay(A, lenArray, height);
    printf("height %d\n", height);
    int index = 1;
    Display(A, lenArray);
    int max = (1<<lenArray) - 1;
    for (int h = height;height>=0;height--){
        MaxHeapify(A, index, lenArray);
    }
    Display(A, lenArray);
    HeapDisplay(A, lenArray, height);
    printf("fin %d", lenArray);
}
