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
    bool operator==(point_t rhs)
    {
        return y == rhs.y && x == rhs.x;
    }
};

point_t direction[8] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};

int main()
{
    int T, l;
    int depth[300][300];
    point_t start, goal;
    scanf("%d", &T);

    for(int t = 0; t < T; t++)
    {
        scanf("%d %d %d %d %d", &l, &start.y, &start.x, &goal.y, &goal.x);

        for(int j = 0; j < l; j++)
        {
            for(int i = 0; i < l; i++)
            {
                depth[j][i] = 0;
            }
        }

        std::queue<point_t> point;
        depth[start.y][start.x] = 1;
        
        for(point.push(start); ; point.pop())
        {
            point_t now = point.front();

            if(now == goal)
            {
                printf("%d\n", depth[goal.y][goal.x] - 1);
                break;
            }

            for(int i = 0; i < 8; i++)
            {
                point_t next =  now + direction[i];
                if(next.y >= 0 && next.y < l && next.x >= 0 && next.x < l)
                {
                    if(0 == depth[next.y][next.x])
                    {
                        depth[next.y][next.x] = depth[now.y][now.x] + 1;
                        point.push({next.y, next.x});
                    }
                }
            }
        }        
    }

    return 0;
}