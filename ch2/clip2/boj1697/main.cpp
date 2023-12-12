#include <iostream>
#include <queue>

int arrivalTime[100001];

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    std::queue<int> index;
    arrivalTime[N] = 1;

    for(index.push(N); ;index.pop())
    {
        int nowIndex = index.front();

        if(nowIndex == K)
        {
            printf("%d", arrivalTime[nowIndex] - 1);
            break;
        }

        if(nowIndex - 1 >= 0 && 0 == arrivalTime[nowIndex - 1])
        {
            arrivalTime[nowIndex - 1] = arrivalTime[nowIndex] + 1; 
            index.push(nowIndex - 1);
        }
        if(nowIndex + 1 <= 100000 && 0 == arrivalTime[nowIndex + 1])
        {
            arrivalTime[nowIndex + 1] = arrivalTime[nowIndex] + 1; 
            index.push(nowIndex + 1);
        }
        if(nowIndex * 2 <= 100000 && 0 == arrivalTime[nowIndex * 2])
        {
            arrivalTime[nowIndex * 2] = arrivalTime[nowIndex] + 1; 
            index.push(nowIndex * 2);
        }
    }

    return 0;
}