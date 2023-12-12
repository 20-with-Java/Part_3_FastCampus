#include <iostream>

int dp[10][101];

int func(int lastNum, int length)
{
    if(lastNum < 0 || lastNum > 9)
    {
        return 0;
    }

    if(1 == length)
    {
        if(lastNum != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if(dp[lastNum][length] != 0)
    {
        return dp[lastNum][length];
    }

    dp[lastNum][length] = (func(lastNum - 1, length - 1) + func(lastNum + 1, length - 1)) % 1000000000;

    return dp[lastNum][length];
}

int main()
{
    int N;
    scanf("%d", &N);

    int sum = 0;

    for(int i = 0; i <= 9; i++)
    {
        sum = (sum + func(i, N)) % 1000000000;
    }

    printf("%d", sum);

    return 0;
}