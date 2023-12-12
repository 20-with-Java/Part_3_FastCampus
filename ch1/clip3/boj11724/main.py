import sys

sys.setrecursionlimit(10**6)

def dfs(node):
    visited[node] = True
    for i in range(1, n + 1):
        if graph[node][i] == 1 and not visited[i]:
            dfs(i)

def count_connected_components():
    cnt = 0
    for i in range(1, n + 1):
        if not visited[i]:
            dfs(i)
            cnt += 1
    return cnt

n, m = map(int, sys.stdin.readline().split())
graph = [[0] * (n + 1) for _ in range(n + 1)]
visited = [False] * (n + 1)

for _ in range(m):
    src, dst = map(int, sys.stdin.readline().split())
    graph[src][dst] = 1
    graph[dst][src] = 1

result = count_connected_components()
sys.stdout.write(str(result))
