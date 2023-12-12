#include <iostream>
#include <queue>

int factory[102][102];
int visited[4][102][102];
int M, N;

struct point_t
{
    int y;
    int x;
    int dir = 0;
    point_t operator+(point_t rhs)
    {
        return {y + rhs.y, x + rhs.x, dir + rhs.dir};
    }
    point_t operator*(int n)
    {
        return {y * n, x * n, dir};
    }
    bool operator==(point_t rhs)
    {
        return y == rhs.y && x == rhs.x && dir == rhs.dir;
    }
};

point_t startPoint, finishPoint;
point_t direction[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main()
{
    scanf("%d %d", &M, &N);

    for(int j = 1; j <= M; j++)
    {
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &factory[j][i]);
        }
    }

    scanf("%d %d %d", &startPoint.y, &startPoint.x, &startPoint.dir);
    scanf("%d %d %d", &finishPoint.y, &finishPoint.x, &finishPoint.dir);

    switch(startPoint.dir)
    {
    case 1:
        startPoint.dir = 1;
        break;
    case 2:
        startPoint.dir = 3;
        break;
    case 3:
        startPoint.dir = 2;
        break;
    case 4:
        startPoint.dir = 0;
        break;
    }

    switch(finishPoint.dir)
    {
    case 1:
        finishPoint.dir = 1;
        break;
    case 2:
        finishPoint.dir = 3;
        break;
    case 3:
        finishPoint.dir = 2;
        break;
    case 4:
        finishPoint.dir = 0;
        break;
    }

    std::queue<point_t> point;
    visited[startPoint.dir][startPoint.y][startPoint.x] = 1;

    for(point.push(startPoint); ; point.pop())
    {
        point_t nowPoint = point.front();
        point_t nextPoint;
        int nowDepth = visited[nowPoint.dir][nowPoint.y][nowPoint.x];

        if(nowPoint == finishPoint)
        {
            printf("%d", nowDepth - 1);
            break;
        }

        for(int i = 1; i <= 3; i++)
        {
            nextPoint = nowPoint + direction[nowPoint.dir] * i;
            if(nextPoint.y <= 0 || nextPoint.y > M || nextPoint.x <= 0 || nextPoint.x > N
            || 1 == factory[nextPoint.y][nextPoint.x])
            {
                break;
            }
        
            if(0 == visited[nextPoint.dir][nextPoint.y][nextPoint.x])
            {
                visited[nextPoint.dir][nextPoint.y][nextPoint.x] = nowDepth + 1;
                point.push(nextPoint);
            }
        }

        nextPoint = nowPoint;
        nextPoint.dir = (nowPoint.dir + 1) % 4;

        if(0 == visited[nextPoint.dir][nextPoint.y][nextPoint.x])
        {
            visited[nextPoint.dir][nextPoint.y][nextPoint.x] = nowDepth + 1;
            point.push(nextPoint);
        }

        nextPoint = nowPoint;
        nextPoint.dir = (nowPoint.dir + 3) % 4;

        if(0 == visited[nextPoint.dir][nextPoint.y][nextPoint.x])
        {
            visited[nextPoint.dir][nextPoint.y][nextPoint.x] = nowDepth + 1;
            point.push(nextPoint);
        }
    }

    return 0;
}