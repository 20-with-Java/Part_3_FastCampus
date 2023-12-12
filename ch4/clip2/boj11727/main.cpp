#include <iostream>

int numberOfType[1001];

int func(int n)
{
    if(n <= 1)
    {
        return 1;
    }

    if(0 == numberOfType[n])
    {
        numberOfType[n] = (func(n - 1) + func(n - 2) * 2) % 10007;
    }
    
    return numberOfType[n];
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d", func(n));

    return 0;
}