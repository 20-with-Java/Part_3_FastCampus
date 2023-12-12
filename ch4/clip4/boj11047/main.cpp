#include <iostream>

int main()
{
    int N, K;
    int coin[10];

    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &coin[i]);
    }

    int count = 0;
    for(int i = N - 1; i >= 0; i--)
    {
        count += K / coin[i];
        K %= coin[i];
    }

    printf("%d", count);

    return 0;
}