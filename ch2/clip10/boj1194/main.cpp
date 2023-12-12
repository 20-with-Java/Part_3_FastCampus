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

int N, M;
char maze[52][52];
point_t direction[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int distance[1<<6][52][52];

int main()
{
    std::queue<std::pair<int, point_t>> point;

    scanf("%d %d", &N, &M);

    for(int j = 1; j <= N; j++)
    {
        for(int i = 1; i <= M; i++)
        {
            scanf(" %c", &maze[j][i]);

            if('0' == maze[j][i])
            {
                point.push({0, {j, i}});
                distance[0][j][i] = 1;
            }
        }
        maze[j][0] = maze[j][M + 1] = '#';
    }

    for(int i = 1; i <= N; i++)
    {
        maze[0][i] = maze[N + 1][i] = '#';
    }

    for(; point.empty() == false; point.pop())
    {
        int ownKey = point.front().first;
        point_t now = point.front().second;

        for(int i = 0; i < 4; i++)
        {
            point_t next = now + direction[i];
            char spaceType = maze[next.y][next.x];
            if('.' == spaceType || '0' == spaceType)
            {
                if(0 == distance[ownKey][next.y][next.x])
                {
                    distance[ownKey][next.y][next.x] = distance[ownKey][now.y][now.x] + 1;
                    point.push({ownKey, next});
                }
            }
            else if('1' == spaceType)
            {
                printf("%d", distance[ownKey][now.y][now.x]);
                return 0;
            }
            else if('a' <= spaceType && spaceType <= 'f')
            {
                int updatedOwnKey = ownKey | (1 << (spaceType - 'a'));
                if(0 == distance[updatedOwnKey][next.y][next.x])
                {
                    distance[updatedOwnKey][next.y][next.x] = distance[ownKey][now.y][now.x] + 1;
                    point.push({updatedOwnKey, next});
                }
            }
            else if('A' <= spaceType && spaceType <= 'F')
            {
                if((ownKey & (1 << (spaceType - 'A'))) != 0 && 0 == distance[ownKey][next.y][next.x])
                {
                    distance[ownKey][next.y][next.x] = distance[ownKey][now.y][now.x] + 1;
                    point.push({ownKey, next});
                }
            }
        }
    }

    printf("-1");

    return 0;
}