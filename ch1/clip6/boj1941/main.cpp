#include <iostream>

int seat[5][5];
int seatNumber[7];
bool visited[7];

bool is_neighbor(int a, int b)
{
    if(a < b)
    {
        std::swap(a, b);
    }

    if((a % 5 != 0 && a - b == 1) || (a - b == 5))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int dfs(int number)
{
    int count = 1;
    visited[number] = true;

    for(int i = 1; i < 7; i++)
    {
        if(false == visited[i]
        && is_neighbor(seatNumber[number], seatNumber[i]) == true)
        {
            count += dfs(i);
        }
    }
    return count;
}

int make_combination(int number, int length, int countOfS)
{
    if(7 - length + countOfS < 4 || 7 - length + number > 25)
    {
        return 0;
    }

    if(length == 7)
    {
        for(int i = 0; i < 7; i++)
        {
            visited[i] = false;
        }

        if(dfs(0) == 7)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int count = 0;
    count += make_combination(number + 1, length, countOfS);

    seatNumber[length] = number;
    count += make_combination(number + 1, length + 1, countOfS + seat[number / 5][number % 5]);
    seatNumber[length] = 0;

    return count;
}

int main()
{
    char str;
    for(int j = 0; j < 5; j++)
    {
        for(int i = 0; i < 5; i++)
        {
            scanf(" %c", &str);
            if(str == 'S')
            {
                seat[j][i] = 1;
            }
            else
            {
                seat[j][i] = 0;
            }
        }
    }

    printf("%d", make_combination(0, 0, 0));

    return 0;
}