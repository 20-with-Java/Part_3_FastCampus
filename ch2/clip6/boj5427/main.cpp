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

int w, h;
char building[1000][1001];
int fire[1000][1000], distance[1000][1000];
std::queue<point_t> fireQueue, distanceQueue;

void fire_bfs()
{
    if(fireQueue.empty() == true)
    {
        return;
    }

    int time = fire[fireQueue.front().y][fireQueue.front().x];

    for(; fireQueue.empty() == false; fireQueue.pop())
    {
        point_t now = fireQueue.front();

        if(fire[now.y][now.x] > time)
        {
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            point_t next = now + direction[i];
            if(next.y >= 0 && next.y < h && next.x >= 0 && next.x < w)
            {
                if(building[next.y][next.x] != '#' && -1 == fire[next.y][next.x])
                {
                    fire[next.y][next.x] = fire[now.y][now.x] + 1;
                    fireQueue.push(next);
                }
            }
        }
    }

    return;
}

bool distance_bfs()
{
    if(distanceQueue.empty() == true)
    {
        return false;
    }

    int time = distance[distanceQueue.front().y][distanceQueue.front().x];

    for(; distanceQueue.empty() == false; distanceQueue.pop())
    {
        point_t now = distanceQueue.front();

        if(distance[now.y][now.x] > time)
        {
            break;
        }

        for(int i = 0; i < 4; i++)
        {
            point_t next = now + direction[i];
            if(next.y < 0 || next.y >= h || next.x < 0 || next.x >= w)
            {
                return true;
            }

            if(building[next.y][next.x] != '#' && -1 == fire[next.y][next.x] && -1 == distance[next.y][next.x])
            {
                distance[next.y][next.x] = distance[now.y][now.x] + 1;
                distanceQueue.push(next);
            }
        }
    }

    return false;
}

int main()
{
    int T;

    scanf("%d", &T);
    for(int t = 0; t < T; t++)
    {
        scanf("%d %d", &w, &h);

        for(int j = 0; j < h; j++)
        {
            for(int i = 0; i < w; i++)
            {
                scanf(" %c", &building[j][i]);
                fire[j][i] = -1;
                distance[j][i] = -1;
                if(building[j][i] == '*')
                {
                    fire[j][i] = 0;
                    fireQueue.push({j, i});
                }
                else if(building[j][i] == '@')
                {
                    distance[j][i] = 0;
                    distanceQueue.push({j, i});
                }
            }
        }

        for(int time = 1; distanceQueue.size() > 0; time++)
        {
            fire_bfs();

            if(distance_bfs() == true)
            {
                printf("%d\n", time);
                break;
            }
        }

        if(distanceQueue.empty() == true)
        {
            printf("IMPOSSIBLE\n");
        }

        for(;fireQueue.empty() == false; fireQueue.pop());
        for(;distanceQueue.empty() == false; distanceQueue.pop());
    }

    return 0;
}