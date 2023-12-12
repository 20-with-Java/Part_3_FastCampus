#include <iostream>
#include <queue>

struct 
{
    int prevNumber;
    char command;
} route[10000];

void print_command(int number)
{
    if(route[number].prevNumber != 10000)
    {
        print_command(route[number].prevNumber);
        printf("%c", route[number].command);
    }

    return;
}

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 0; t < T; t++)
    {
        for(int i = 0; i < 10000; i++)
        {
            route[i].prevNumber = -1;
        }

        int A, B;
        scanf("%d %d", &A, &B);

        route[A].prevNumber = 10000;
        std::queue<int> numberQueue;
        for(numberQueue.push(A); ; numberQueue.pop())
        {
            int number = numberQueue.front(), nextNumber;
            if(number == B)
            {
                break;
            }

            nextNumber = (number * 2) % 10000;
            if(-1 == route[nextNumber].prevNumber)
            {
                route[nextNumber] = {number, 'D'};
                numberQueue.push(nextNumber);
            }

            nextNumber = (number + 9999) % 10000;
            if(-1 == route[nextNumber].prevNumber)
            {
                route[nextNumber] = {number, 'S'};
                numberQueue.push(nextNumber);
            }
            
            nextNumber = ((number * 10) % 10000) + number / 1000;
            if(-1 == route[nextNumber].prevNumber)
            {
                route[nextNumber] = {number, 'L'};
                numberQueue.push(nextNumber);
            }

            nextNumber = ((number % 10) * 1000) + number / 10;
            if(-1 == route[nextNumber].prevNumber)
            {
                route[nextNumber] = {number, 'R'};
                numberQueue.push(nextNumber);
            }
        }
    
        print_command(B);
        printf("\n");
    }

    return 0;
}