#include <stdio.h>

int main(void) {
    int A[3][3] = {
                    {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}
                    };
    int B[3][3] = {
                    {10, 11, 12},
                    {13, 14, 15},
                    {16, 17, 18}
                    };

    int maxX = sizeof(A) / sizeof(A[0]) - 1;
    int maxY = sizeof(A[0]) / sizeof(A[0][0]) - 1;

    int splitX = maxX / 2;
    int splitY = maxY / 2;

    // Quadrant 1
    int sizeXq1 = splitX + 1;
    int sizeYq1 = splitY + 1;
    int Aq1[sizeXq1][sizeYq1];
    int Bq1[sizeXq1][sizeYq1];
    for (int i=0; i<=splitX; i++) {
        for (int j=0; j<=splitY; j++) {
            Aq1[i][j] = A[i][j];
            Bq1[i][j] = B[i][j];
        }
    }
    // Quadrant 2
    int sizeXq2 = maxX - splitX + 1;
    int sizeYq2 = splitY + 1;
    int Aq2[sizeXq2][sizeYq2];
    int Bq2[sizeXq2][sizeYq2];
    for (int i=0; i<sizeXq2; i++) {
        for (int j=0; j<sizeYq2; j++) {
            Aq2[i][j] = A[i+splitX+1][j];
            Bq2[i][j] = B[i+splitX+1][j];
        }
    }
    // Quadrant 3
    int sizeXq3 = splitX + 1;
    int sizeYq3 = maxY - splitY + 1;
    int Aq3[sizeXq3][sizeYq3];
    int Bq3[sizeXq3][sizeYq3];
    for (int i=0; i<sizeXq3; i++) {
        for (int j=0; j<sizeYq3; j++) {
            Aq3[i][j] = A[i][j+splitY+1];
            Bq3[i][j] = B[i][j+splitY+1];
        }
    }

    // Quadrant 4
    int sizeXq4 = maxX - splitX + 1;
    int sizeYq4 = maxY - splitY + 1;
    int Aq4[sizeXq4][sizeYq4];
    int Bq4[sizeXq4][sizeYq4];
    for (int i=0; i<sizeXq4; i++) {
        for (int j=0; j<sizeYq2; j++) {
            Aq4[i][j] = A[i+splitX+1][j+splitY+1];
            Bq4[i][j] = B[i+splitX+1][j+splitY+1];
        }
    }


    // test
    for (int i=0; i<=splitX; i++) {
        for (int j=0; j<=splitY; j++) {
            printf("%d ", Aq1[i][j]);
        }
        printf("\n");
    }
    return(0);
}
