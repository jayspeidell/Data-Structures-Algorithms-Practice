#include <stdio.h>

int main(void) {
    int arr[] = { 14, -7, 3, -20, 27, 26, 23, 27, -8, -29, 24, -11, -28, -5,
    -12, -12, -12, 21, -20, 22, -14, -27, -11, 7, 14, -16, -22, 22, -28, 20,
    -10, 1, -7, -3, -25, 18, -28, 22, 6, -20, 1, -27, -29, 21, 17, -29, 5, 1, 18, -26 };

    int lenArr = sizeof(arr) / sizeof(int);

    int sum = -1000000;
    int start;
    int end;
    int tempSum;

    for (int i=0; i<lenArr; i++){
        tempSum = arr[i];
        for (int j=i+1; j<lenArr; j++) {
            tempSum += arr[j];
            if (tempSum > sum) {
                sum = tempSum;
                start = i;
                end = j;
            }
        }
    }

    printf("Sum of array %d to %d is %d.\n", start+1, end+1, sum);
    printf("Subarray: ");
    for (int k=start; k<=end; k++) {
        printf("%d", arr[k]);
        if (k != end) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
    printf("Finished.");

    return(0);
}

