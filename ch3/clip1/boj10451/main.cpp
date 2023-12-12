#include <iostream>

int nextNode[1001];
bool visited[1001];

void dfs(int number)
{
    visited[number] = true;

    if(false == visited[nextNode[number]])
    {
        dfs(nextNode[number]);
    }

    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++)
    {
        int N;
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
            scanf("%d", &nextNode[i]);
            visited[i] = false;
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
        printf("%d\n", count);
    }

    return 0;
}