#include <iostream>

int minValue[1001];

int main()
{
    int N, A;
    scanf("%d", &N);

    for(int i = 0; i <= N; i++)
    {
        minValue[i] = 1001;
    }

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A);

        int index;
        for(index = 0; minValue[index] < A; index++){;}
        
        minValue[index] = A;
    }

    for(int i = 0; ; i++)
    {
        if(1001 == minValue[i])
        {
            printf("%d", i);
            break;
        }
    }

    return 0;
}