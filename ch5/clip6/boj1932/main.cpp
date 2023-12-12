#include <iostream>

int main()
{
    int n;
    int triangle[501];
    int maxSum[501][501];
    scanf("%d", &n);

    triangle[0] = 0;
    for(int i = 0; i <= n; i++)
    {
        maxSum[i][0] = 0;
    }

    for(int j = 1; j <= n; j++)
    {
        for(int i = 1; i <= j; i++)
        {
            scanf("%d", &triangle[i]);
            maxSum[j][i] = std::max(maxSum[j - 1][i - 1], maxSum[j - 1][i]) + triangle[i];
        }
    }

    int result = 0;
    for(int i = 1; i <= n; i++)
    {
        if(maxSum[n][i] > result)
        {
            result = maxSum[n][i];
        }
    }

    printf("%d", result);

    return 0;
}