#include <iostream>
#include <queue>

bool edge[1001][1001];
bool dfsVisited[1001];
bool bfsVisited[1001];
int N, M, V;

void dfs(int number)
{
    dfsVisited[number] = true;
    printf("%d ", number);

    for(int i = 1; i <= N; i++)
    {
        if(true == edge[number][i] && false == dfsVisited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    scanf("%d %d %d", &N, &M, &V);

    for(int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edge[a][b] = true;
        edge[b][a] = true;
    }

    dfs(V);
    printf("\n");

    std::queue<int> bfsQueue;
    bfsVisited[V] = true;
    for(bfsQueue.push(V); bfsQueue.empty() == false; bfsQueue.pop())
    {
        int number = bfsQueue.front();
        printf("%d ", number);
    
        for(int i = 1; i <= N; i++)
        {
            if(true == edge[number][i] && false == bfsVisited[i])
            {
                bfsVisited[i] = true;
                bfsQueue.push(i);
            }
        }
    }



    return 0;
}