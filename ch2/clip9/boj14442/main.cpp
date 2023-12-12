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
    int N, M, K;
    int wall[1001][1001];
    int distance[11][1001][1001];

    scanf("%d %d %d", &N, &M, &K);
    for(int j = 1; j <= N; j++)
    {
        for(int i = 1; i <= M; i++)
        {
            scanf("%1d", &wall[j][i]);
            for(int k = 0; k <= K; k++)
            {
                distance[k][j][i] = 0;
            }
        }
    }

    for(int k = 0; k <= K; k++)
    {
        distance[k][1][1] = 1;
    }
    std::queue<std::pair<int, point_t>> point;
    
    for(point.push({wall[1][1], {1, 1}}); point.empty() == false; point.pop())
    {
        int broken = point.front().first;
        point_t now = point.front().second;
        
        if(now.y == N && now.x == M)
        {
            printf("%d", distance[broken][N][M]);
            return 0;
        }

        for(int i = 0; i < 4; i++)
        {
            point_t next = now + direction[i];
            if(next.y >= 1 && next.y <= N && next.x >= 1 && next.x <= M)
            {
                if(broken < K)
                {
                    if(0 == distance[broken + wall[next.y][next.x]][next.y][next.x])
                    {
                        distance[broken + wall[next.y][next.x]][next.y][next.x] = distance[broken][now.y][now.x] + 1;
                        point.push({broken + wall[next.y][next.x], next});
                    }
                }
                else
                {
                    if(0 == wall[next.y][next.x] && 0 == distance[K][next.y][next.x])
                    {
                        distance[K][next.y][next.x] = distance[K][now.y][now.x] + 1;
                        point.push({K, next});
                    }
                }
            }
        }
    }

    printf("-1");

    return 0;
}