#include <iostream>
#include <queue>

struct
{
    int depth;
    int count;
} arrivalTime[100001];

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    std::queue<int> index;
    arrivalTime[N] = {1, 1};

    for(index.push(N); arrivalTime[K].depth == 0 || arrivalTime[K].depth > arrivalTime[index.front()].depth; index.pop())
    {
        int nowIndex = index.front();

        if(nowIndex - 1 >= 0)
        {
            if(0 == arrivalTime[nowIndex - 1].depth)
            {
                index.push(nowIndex - 1);
                arrivalTime[nowIndex - 1].depth = arrivalTime[nowIndex].depth + 1;
                arrivalTime[nowIndex - 1].count = arrivalTime[nowIndex].count;
            }
            else if(arrivalTime[nowIndex].depth + 1 == arrivalTime[nowIndex - 1].depth)
            {
                arrivalTime[nowIndex - 1].count += arrivalTime[nowIndex].count;
            }
        }
        if(nowIndex + 1 <= 100000)
        {
            if(0 == arrivalTime[nowIndex + 1].depth)
            {
                index.push(nowIndex + 1);
                arrivalTime[nowIndex + 1].depth = arrivalTime[nowIndex].depth + 1;
                arrivalTime[nowIndex + 1].count = arrivalTime[nowIndex].count;
            }
            else if(arrivalTime[nowIndex].depth + 1 == arrivalTime[nowIndex + 1].depth)
            {
                arrivalTime[nowIndex + 1].count += arrivalTime[nowIndex].count;
            }
        }
        if(nowIndex * 2 <= 100000)
        {
            if(0 == arrivalTime[nowIndex * 2].depth)
            {
                index.push(nowIndex * 2);
                arrivalTime[nowIndex * 2].depth = arrivalTime[nowIndex].depth + 1;
                arrivalTime[nowIndex * 2].count = arrivalTime[nowIndex].count;
            }
            else if(arrivalTime[nowIndex].depth + 1 == arrivalTime[nowIndex * 2].depth)
            {
                arrivalTime[nowIndex * 2].count += arrivalTime[nowIndex].count;
            }
        }
    }

    printf("%d\n%d", arrivalTime[K].depth - 1, arrivalTime[K].count);

    return 0;
}