#include <iostream>

int main()
{
    int N, K;
    int coin;
    int numberOfType[10001];
    
    scanf("%d %d", &N, &K);

    numberOfType[0] = 0;
    for(int i = 1; i <= K; i++)
    {
        numberOfType[i] = 10001;
    }

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &coin);

        for(int k = coin; k <= K; k++)
        {
            numberOfType[k] = std::min(numberOfType[k], numberOfType[k - coin] + 1);
        }
    }

    if(10001 == numberOfType[K])
    {
        printf("-1");
    }
    else
    {
        printf("%d", numberOfType[K]);
    }

    return 0;
}