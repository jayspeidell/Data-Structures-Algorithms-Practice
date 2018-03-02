#include <stdio.h>

int main(void) {
    int lst[10] = {6, 3, 4, 9, 7, 0, 1, 2, 8, 8};
    int len = sizeof(lst) / sizeof(lst[0]);
    int min;
    int i, j, k;
    int temp;

    for ( k = 0; k < len; k++ ){
        printf("%d", lst[k]);
    }

    for ( i = 0; i < len - 2; i++ ){
        min = i;
        for ( j=i+1; j < len-1; j++ ){
            if (lst[j] < lst[min]){
                min = j;
            }
        }
        if ( i != min ){
            temp = lst[i];
            lst[i] = lst[min];
            lst[min] = temp;
        }
    }

    printf("\n");
    for ( k = 0; k < len; k++ ){
        printf("%d", lst[k]);
    }


    return(0);
}

