#include <iostream>

int n;
int wine[10001];
int maxAmount[3][10001];

int func(int drank, int number)
{
    if(number <= 0)
    {
        return 0;
    }
    else if(maxAmount[drank][number] != 0)
    {
        return maxAmount[drank][number];
    }

    if(0 == drank)
    {
        for(int prevDrank = 0; prevDrank <= 2; prevDrank++)
        {
            if(maxAmount[drank][number] < func(prevDrank, number - 1))
            {
                maxAmount[drank][number] = func(prevDrank, number - 1);
            }
        }
    }
    else
    {
        maxAmount[drank][number] = maxAmount[drank - 1][number - 1] + wine[number];
    }

    return maxAmount[drank][number];
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &wine[i]);
    }

    int result = 0;

    for(int i = 0; i <= 2; i++)
    {
        if(result < func(i, n))
        {
            result = func(i, n);
        }
    }

    printf("%d", result);

    return 0;
}