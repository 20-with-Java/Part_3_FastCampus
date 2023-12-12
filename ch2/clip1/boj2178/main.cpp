#include <iostream>
#include <queue>

struct point_t
{
    int y;
    int x;
};

int board[101][101];
int depth[101][101];

point_t direction[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for(int j = 1; j <= N; j++)
    {
        for(int i = 1; i <= M; i++)
        {
            scanf("%1d", &board[j][i]);
        }
    }

    std::queue<point_t> point;
    depth[1][1] = 1;

    for(point.push({1, 1}); ; point.pop())
    {
        int y = point.front().y, x = point.front().x;

        if(y == N && x == M)
        {
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            int nextY = y + direction[i].y, nextX = x + direction[i].x;

            if(nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= M)
            {
                if(1 == board[nextY][nextX] && 0 == depth[nextY][nextX])
                {
                    depth[nextY][nextX] = depth[y][x] + 1;
                    point.push({nextY, nextX});
                }
            }
        }
    }

    printf("%d", depth[N][M]);

    return 0;
}