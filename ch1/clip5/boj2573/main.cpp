#include <iostream>
#include <vector>

struct point_t
{
    int y;
    int x;
};

struct iceberg_t
{
    point_t point;
    int height;
};

point_t direction[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int ocean[300][300];
bool visited[300][300];

int N, M;
std::vector<iceberg_t> iceberg;

int dfs(int y, int x)
{
    int count = 1;

    visited[y][x] = true;

    for(int i = 0; i < 4; i++)
    {
        int nextY = y + direction[i].y, nextX = x + direction[i].x;
        if(false == visited[nextY][nextX])
        {
            count += dfs(nextY, nextX);
        }
    }

    return count;
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int j = 0; j < N; j++)
    {
        for(int i = 0; i < M; i++)
        {
            scanf("%d", &ocean[j][i]);
            if(ocean[j][i] > 0)
            {
                iceberg.push_back({j, i, ocean[j][i]});
            }
            visited[j][i] = true;
        }
    }

    for(int year = 1; iceberg.empty() == false; year++)
    {
        for(int j = 0; j < iceberg.size(); j++)
        {
            for(int i = 0; i < 4; i++)
            {
                if(0 == ocean[iceberg[j].point.y + direction[i].y][iceberg[j].point.x + direction[i].x])
                {
                    iceberg[j].height--;
                }
            }
        }

        for(int j = 0; j < iceberg.size(); j++)
        {
            if(iceberg[j].height <= 0)
            {
                ocean[iceberg[j].point.y][iceberg[j].point.x] = 0;
                iceberg[j] = iceberg.back();
                iceberg.pop_back();
                j--;
            }
            else
            {
                visited[iceberg[j].point.y][iceberg[j].point.x] = false;
            }
        }

        if(iceberg.size() > 0 && dfs(iceberg[0].point.y, iceberg[0].point.x) != iceberg.size())
        {
            printf("%d", year);
            return 0;
        }
    }
    printf("0");

    return 0;
}