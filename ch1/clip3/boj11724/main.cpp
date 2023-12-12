#include <iostream>
#include <vector>

int N, M;
std::vector<int> edge[1001];
bool visited[1001];

void dfs(int number)
{
    visited[number] = true;

    for(int nextNumber : edge[number])
    {
        if(false == visited[nextNumber])
        {
            dfs(nextNumber);
        }
    }

    return;
}

int main()
{
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    int count = 0;

    for(int i = 1; i <= N; i++)
    {
        if(false == visited[i])
        {
            count++;
            dfs(i);
        }
    }

    printf("%d", count);

    return 0;
}