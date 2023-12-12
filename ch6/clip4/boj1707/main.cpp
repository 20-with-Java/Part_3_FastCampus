#include <iostream>
#include <vector>

std::vector<int> node[20001];
int visitedDepth[20001];

bool dfs(int nodeNumber, int depth)
{
   visitedDepth[nodeNumber] = depth;

   for(int nextNode : node[nodeNumber])
   {
        if(0 == visitedDepth[nextNode])
        {
            if(dfs(nextNode, depth + 1) == false)
            {
                return false;
            }
        }
        else
        {
            if(visitedDepth[nextNode] % 2 == visitedDepth[nodeNumber] % 2)
            {
                return false;
            }
        }
   }

   return true;
}

int main()
{
    int K;
    scanf("%d", &K);
    
    for(int k = 0; k < K; k++)
    {
        int V, E, u, v;
        scanf("%d %d", &V, &E);

        for(int i = 1; i <= V; i++)
        {
            visitedDepth[i] = 0;
            node[i].clear();
        }

        for(int i = 0; i < E; i++)
        {
            scanf("%d %d", &u, &v);

            node[u].push_back(v);
            node[v].push_back(u);
        }

        bool result = true;
        for(int i = 1; true == result && i <= V; i++)
        {
            if(0 == visitedDepth[i])
            {
                if(dfs(i, 1) == false)
                {
                    result = false;
                }
            }
        }
        
        if(true == result)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}