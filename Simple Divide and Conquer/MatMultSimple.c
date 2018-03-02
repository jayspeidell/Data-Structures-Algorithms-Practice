#include <stdio.h>

int main(void) {
    int A[3][3] = {
                    {11, 12, 13},
                    {14, 15, 16},
                    {17, 18, 19}
                    };
    int B[3][3] = {
                    {21, 22, 23},
                    {24, 25, 26},
                    {27, 28, 29}
                    };
    int C[3][3];

    int height = sizeof(A)/sizeof(A[0]);
    printf("C height %d\n", height);
    int width = sizeof(B[0])/sizeof(B[0][0]);
    printf("C width %d\n", width);
    int kMax = (height < width) ? height : width;
    printf("kMax is %d\n", kMax);

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
        C[i][j] = 0;
        for (int k=0; k<kMax; k++) {
            C[i][j] += A[i][k] * B[k][j];
            printf("%d times %d is %d\n", A[i][k], B[k][j], A[i][k] * B[k][j]);
        }
        printf("%d, %d is %d\n", i, j, C[i][j]);
        }
    }
    printf("\n");
    printf("Output:\n");
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return(0);
}
