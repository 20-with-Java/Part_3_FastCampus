#include <iostream>

int main()
{
    char str[51];
    int countAlpha['Z' - 'A' + 1];
    for(int i = 0; i <= 'Z' - 'A'; i++)
    {
        countAlpha[i] = 0;
    }

    scanf("%s", str);

    int strLength;
    for(strLength = 0; str[strLength]; strLength++)
    {
        countAlpha[str[strLength] - 'A']++;
    }
    strLength--;

    int oddIndex = -1;

    for(int i = 0; i <= 'Z' - 'A'; i++)
    {
        if(countAlpha[i] % 2 == 1)
        {
            if(oddIndex != -1)
            {
                printf("I'm Sorry Hansoo");
                return 0;
            }
            else
            {
                countAlpha[i]--;
                oddIndex = i;
            }
        }
    }

    int strIndex = 0;
    for(int j = 0; j <= 'Z' - 'A'; j++)
    {
        for(int i = 0; i < countAlpha[j]; i += 2)
        {
            str[strIndex] = j + 'A';
            str[strLength - strIndex] = j + 'A';
            strIndex++;
        }
    }

    if(oddIndex != -1)
    {
        str[strIndex] = oddIndex + 'A';
    }

    printf("%s", str);

    return 0;
}