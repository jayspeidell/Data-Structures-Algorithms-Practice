#include <stdio.h>

int main(void) {
    int lst[10] = {6, 3, 4, 9, 7, 0, 1, 2, 8, 8};
    int n = sizeof(lst) / sizeof(lst[0]);
    int i = 0;
    int j, key;
    int k;
    for( j = 1; j < n; j++ ) {
        key = lst[j];
        //printf("key is %d\n", lst[j]);
        // reference left in sequence
        i = j - 1;
        //printf("j %d, i %d\n", j, i);
        // move left until finding value smaller than key
        //printf("checking %d\n", lst[i]);
        while ( i >= 0 && lst[i] > key ){
            for ( k = 0; k < n; k++ ){
                    //printf("%d", lst[k]);
            }
            //printf("\n");
            //printf("copying %d to the right \n", lst[i]);
            // if current value is bigger than key, copy current value right
            // shifting values right to make room to insert key
            lst[i+1] = lst[i];
            // step left
            i = i - 1;
        }

        // when moving left to a value smaller than the key, copy key to
        // previous position
        // printf("inserting %d\n", key);
        lst[i+1] = key;

        for ( k = 0; k < n; k++ ){
                //printf("%d", lst[k]);
        }
        //printf("\n");
    }


    for ( k = 0; k < n; k++ )
    {
        printf("%d", lst[k]);
    }
    return(0);
}
