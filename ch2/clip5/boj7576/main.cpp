#include <iostream>
#include <queue>

struct point_t
{
    int y;
    int x;
    point_t operator+(point_t rhs)
    {
        return {y + rhs.y, x + rhs.x};
    }
};

point_t direction[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    int M, N;
    int box[1000][1000];
    std::queue<point_t> tomato;

    scanf("%d %d", &M, &N);

    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < M; i++)
        {
            scanf("%d", &box[j][i]);
            if(1 == box[j][i])
            {
                tomato.push({j, i});
            }
        }
    }
    
    for(;tomato.empty() == false; tomato.pop())
    {
        point_t now = tomato.front();

        for(int i = 0; i < 4; i++)
        {
            point_t next = now + direction[i];
            if(next.y >= 0 && next.y < N && next.x >= 0 && next.x < M)
            {
                if(0 == box[next.y][next.x])
                {
                    box[next.y][next.x] = box[now.y][now.x] + 1;
                    tomato.push(next);
                }
            }
        }
    }

    int result = 0;
    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < M; i++)
        {
            if(0 == box[j][i])
            {
                printf("-1");
                return 0;
            }
            
            if(result < box[j][i])
            {
                result = box[j][i];
            }
        }
    }
    printf("%d", result - 1);

    return 0;
}