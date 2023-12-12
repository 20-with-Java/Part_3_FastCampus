#include <iostream>

int main()
{
    int N, T, P;
    int dp[1500002];

    scanf("%d", &N);

    for(int i = 0; i <= N + 1; i++)
    {
        dp[i] = 0;
    }

    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d", &T, &P);

        if(dp[i] < dp[i - 1])
        {
            dp[i] = dp[i - 1];
        }

        if(i + T <= N + 1)
        {
            if(dp[i + T] < dp[i] + P)
            {
                dp[i + T] = dp[i] + P;
            }
        }
    }

    printf("%d", std::max(dp[N], dp[N + 1]));

    return 0;
}