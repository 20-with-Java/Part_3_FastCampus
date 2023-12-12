#include <iostream>
#include <vector>

std::vector<int> edge[101];
bool visited[101];

int dfs(int number)
{
    int count = 1;

    visited[number] = true;

    for(int nextNumber : edge[number])
    {
        if(false == visited[nextNumber])
        {
            count += dfs(nextNumber);
        }
    }

    return count;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < M; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    printf("%d", dfs(1) - 1);

    return 0;
}