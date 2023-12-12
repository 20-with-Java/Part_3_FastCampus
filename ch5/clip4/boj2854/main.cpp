#include <iostream>

#define MOD (1000000007LL)

long long difficulty[2][100001];
long long dp[3][100001];

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        scanf("%lld", &difficulty[0][i]);
    }

    for(int i = 1; i < N; i++)
    {
        scanf("%lld", &difficulty[1][i]);
    }

    dp[0][0] = 1;
    dp[1][0] = dp[2][0] = 0;
    
    dp[0][1] = difficulty[0][1];
    dp[1][1] = difficulty[1][1];
    dp[2][1] = 0;

    for(int i = 2; i <= N; i++)
    {
        dp[0][i] = ((dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) * difficulty[0][i]) % MOD;
        dp[1][i] = ((dp[0][i - 1] + dp[1][i - 1] + dp[2][i - 1]) * difficulty[1][i]) % MOD;
        dp[2][i] = (((dp[0][i - 1] + dp[2][i - 1]) * difficulty[1][i - 1] % MOD) + (dp[0][i - 2] + dp[1][i - 2] + dp[2][i - 2]) * ((difficulty[1][i - 1] * (difficulty[1][i - 1] - 1)) % MOD)) % MOD;
    }

    printf("%lld", (dp[0][N] + dp[1][N] + dp[2][N]) % MOD);
    return 0;
}