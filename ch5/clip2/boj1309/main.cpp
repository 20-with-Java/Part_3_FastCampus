#include <iostream>

#define NONE (0)
#define LEFT (1)
#define RIGHT (2)

int dp[3][100002];

int main()
{
    int N;
    scanf("%d", &N);

    dp[NONE][1] = dp[LEFT][1] = dp[RIGHT][1] = 1;

    for(int i = 2; i <= N + 1; i++)
    {
        dp[LEFT][i] = (dp[RIGHT][i - 1] + dp[NONE][i - 1]) % 9901;
        dp[RIGHT][i] = (dp[LEFT][i - 1] + dp[NONE][i - 1]) % 9901;
        dp[NONE][i] = (dp[LEFT][i - 1] + dp[RIGHT][i - 1] + dp[NONE][i - 1]) % 9901;
    }

    printf("%d", dp[NONE][N + 1]);

    return 0;
}