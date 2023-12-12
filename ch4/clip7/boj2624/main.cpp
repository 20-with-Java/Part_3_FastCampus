#include <iostream>

int main()
{
    int T, K, p, n;
    int numberOfType[10001];
    
    scanf("%d %d", &T, &K);

    numberOfType[0] = 1;
    for(int i = 1; i <= T; i++)
    {
        numberOfType[i] = 0;
    }

    for(int i = 0; i < K; i++)
    {
        scanf("%d %d", &p, &n);

        for(int value = T; value >= p; value--)
        {
            for(int coin = 1; coin <= n; coin++)
            {
                if(value - coin * p < 0)
                {
                    break;
                }
                numberOfType[value] += numberOfType[value - coin * p];
            }
        }
    }

    printf("%d", numberOfType[T]);

    return 0;
}