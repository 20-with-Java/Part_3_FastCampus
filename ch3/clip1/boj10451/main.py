def dfs(node):
    visited[node] = True
    if not visited[next_node[node]]:
        dfs(next_node[node])

t = int(input())
for _ in range(t):
    n = int(input())
    next_node = [0] + list(map(int, input().split()))
    visited = [False] * (n + 1)
    cnt = 0

    for i in range(1, n + 1):
        if not visited[i]:
            dfs(i)
            cnt += 1

    print(cnt)
