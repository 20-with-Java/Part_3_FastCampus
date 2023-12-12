#include <iostream>

int main()
{
    int N, K;
    int coin;
    int numberOfType[10001];
    
    scanf("%d %d", &N, &K);
    numberOfType[0] = 1;
    for(int i = 1; i <= K; i++)
    {
        numberOfType[i] = 0;
    }

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &coin);

        for(int k = coin; k <= K; k++)
        {
            numberOfType[k] += numberOfType[k - coin];
        }
    }

    printf("%d", numberOfType[K]);

    return 0;
}