#include <stdio.h>

struct Tuple {
    int start;
    int end;
    int sum;
};

struct Tuple FindMaxCrossingSubarray(int arr[], int start, int mid, int end) {
    int leftSum = -1000000;
    int leftStart;
    int sum = 0;
    for (int i=mid; i>=start; i--) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            leftStart = i;
        }
    }
    sum = 0;
    int rightSum = -1000000;
    int rightEnd;
    for (int j=mid+1; j<=end; j++) {
        sum += arr[j];
        if (sum > rightSum) {
            rightSum = sum;
            rightEnd = j;
        }
    }

    struct Tuple val;
    val.sum = leftSum + rightSum;
    val.start = leftStart;
    val.end = rightEnd;

    return val;
};

struct Tuple FindMaxSubarray(int arr[], int start, int end) {
    struct Tuple val;
    if (start == end) {
        val.sum = arr[start];
        val.start = start;
        val.end = end;
        return val;
    } else {
        int mid = (start + end) / 2;
        struct Tuple leftVal;
        leftVal = FindMaxSubarray(arr, start, mid);
        struct Tuple rightVal;
        rightVal = FindMaxSubarray(arr, mid+1, end);
        struct Tuple crossVal;
        crossVal = FindMaxCrossingSubarray(arr, start, mid, end);
        if (leftVal.sum >= rightVal.sum && rightVal.sum >= crossVal.sum) {
            return leftVal;
        } else if (rightVal.sum >= leftVal.sum && leftVal.sum >= crossVal.sum) {
            return rightVal;
        } else {
            return crossVal;
        }
    }
};

int main(void) {
    int arr[] = { 14, -7, 3, -20, 27, 26, 23, 27, -8, -29, 24, -11, -28, -5,
    -12, -12, -12, 21, -20, 22, -14, -27, -11, 7, 14, -16, -22, 22, -28, 20,
    -10, 1, -7, -3, -25, 18, -28, 22, 6, -20, 1, -27, -29, 21, 17, -29, 5, 1, 18, -26 };

    int lenArr = sizeof(arr) / sizeof(int);

    struct Tuple finalVal;

    finalVal = FindMaxSubarray(arr, 0, lenArr-1);

    printf("Array %d to %d sum is %d\n", finalVal.start+1, finalVal.end+1, finalVal.sum);
    printf("Subarray contents: ");
    for (int k=finalVal.start; k<=finalVal.end; k++) {
        printf("%d", arr[k]);
        if (k != finalVal.end) {
            printf(", ");
        } else {
            printf("\n");
        }
    }

    return(0);
}
