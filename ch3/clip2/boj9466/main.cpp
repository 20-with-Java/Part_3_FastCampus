#include <iostream>

int nextNode[100001];
int depth[100001];

int dfs(int number)
{
    int result;
    if(0 == depth[nextNode[number]])
    {
        depth[nextNode[number]] = depth[number] + 1;
        result =  dfs(nextNode[number]);
    }
    else
    {
        result = depth[number] - depth[nextNode[number]] + 1;
        if(result < 0)
        {
            result = 0;
        }
    }

    depth[number] = 100001;

    return result;
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
            depth[i] = 0;
        }

        int result = 0;
        for(int i = 1; i <= N; i++)
        {
            if(0 == depth[i])
            {
                depth[i] = 1;
                result += dfs(i);
            }
        }
        printf("%d\n", N - result);
    }

    return 0;
}