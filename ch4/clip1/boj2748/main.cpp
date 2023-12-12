#include <iostream>

long long fibonacciNumber[91] = {0, 1, 1};

long long func(int index)
{
    if(0 == fibonacciNumber[index])
    {
        fibonacciNumber[index] = func(index - 1) + func(index - 2);
    }

    return fibonacciNumber[index];
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%lld", func(n));

    return 0;
}