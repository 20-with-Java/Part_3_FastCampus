#include <iostream>

int minSum[5], maxSum[5];
int score[4];

int getMin(int index)
{
    int minValue = 1000000;
    for(int i = index - 1; i <= index + 1; i++)
    {
        if(minValue > minSum[i])
        {
            minValue = minSum[i];
        }
    }

    return minValue;
}

int getMax(int index)
{
    int maxValue = 0;
    for(int i = index - 1; i <= index + 1; i++)
    {
        if(maxValue < maxSum[i])
        {
            maxValue = maxSum[i];
        }
    }

    return maxValue;
}

int main()
{
    int N;
    int temp[5];

    scanf("%d", &N);

    for(int i = 0; i < 5; i++)
    {
        minSum[i] = 0;
        maxSum[i] = 0;
    }

    minSum[0] = 1000000;
    minSum[4] = 1000000;

    for(int n = 0; n < N; n++)
    {
        for(int i = 1; i <= 3; i++)
        {
            scanf("%d", &score[i]);
        }

        for(int i = 1; i <= 3; i++)
        {
            temp[i] = getMin(i) + score[i];
        }

        for(int i = 1; i <= 3; i++)
        {
            minSum[i] = temp[i];
        }

        for(int i = 1; i <= 3; i++)
        {
            temp[i] = getMax(i) + score[i];
        }

        for(int i = 1; i <= 3; i++)
        {
            maxSum[i] = temp[i];
        }
    }

    printf("%d %d", getMax(2), getMin(2));

    return 0;
}