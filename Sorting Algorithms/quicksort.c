#include <stdio.h>

# define N 10

void operation(int a[N]);

int main(void)
{
    int a[N];
    for (int i = 0; i <=10; i++)
    {
        a[i] = i;
    }
    operation(a);

    for (int j = 0; j<=10; j++)
    {
        printf("%d", a[j]);
    }

    return(0);
}

void operation(int a[N])
{
    a[2] = 5;
}
