#include <iostream>
#include <cstring>

char str[101];

void printOctal(int index)
{
    if(index < 0)
    {
        return;
    }
    else if(0 == index)
    {
        printf("1");
        return;
    }
    else if(1 == index)
    {
        printf("%d", 2 + str[index] - '0');
    }
    else
    {
        printOctal(index - 3);
        printf("%d", (str[index - 2] - '0') * 4 + (str[index - 1] - '0') * 2 + str[index] - '0');
    }

    return;
}

int main()
{
    scanf("%s", str);

    printOctal(strlen(str) - 1);

    return 0;
}