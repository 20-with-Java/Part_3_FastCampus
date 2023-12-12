import sys
from collections import deque

def dfs(node):
    visited[node] = True
    sys.stdout.write(str(node) + ' ')
    for i in range(1, n+1):
        if graph[node][i] == 1 and not visited[i]:
            dfs(i)

def bfs(node):
    q = deque()
    q.append(node)
    visited[node] = True
    while q:
        now = q.popleft()
        sys.stdout.write(str(now) + ' ')
        for i in range(1, n+1):
            if graph[now][i] == 1 and not visited[i]:
                q.append(i)
                visited[i] = True

n, m, v = map(int, sys.stdin.readline().split())
graph = [[0] * (n+1) for _ in range(n+1)]
visited = [False] * (n+1)

for _ in range(m):
    src, dst = map(int, sys.stdin.readline().split())
    graph[src][dst] = 1
    graph[dst][src] = 1

dfs(v)
sys.stdout.write('\n')
visited = [False] * (n+1)
bfs(v)
sys.stdout.write('\n')
