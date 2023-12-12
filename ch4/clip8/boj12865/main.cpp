#include <iostream>

int main()
{
    int N, K, W, V;
    int maxValue = 0;
    int backpack[100001];

    scanf("%d %d", &N, &K);

    for(int i = 0; i <= K; i++)
    {
        backpack[i] = 0;
    }

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &W, &V);

        for(int weight = K; weight >= W; weight--)
        {
            if(backpack[weight] < backpack[weight - W] + V)
            {
                backpack[weight] = backpack[weight - W] + V;

                if(backpack[weight] > maxValue)
                {
                    maxValue = backpack[weight];
                }
            }
        }
    }

    printf("%d", maxValue);

    return 0;
}