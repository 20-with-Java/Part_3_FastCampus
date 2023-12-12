import sys
from collections import deque

def bfs(node):
    q = deque()
    q.append(node)
    visited[node] = True
    while q:
        now = q.popleft()
        cnt[0] += 1
        for i in range(1, v + 1):
            if graph[now][i] == 1 and not visited[i]:
                q.append(i)
                visited[i] = True

v = int(sys.stdin.readline().strip())
e = int(sys.stdin.readline().strip())

graph = [[0] * (v + 1) for _ in range(v + 1)]
visited = [False] * (v + 1)
cnt = [0]

for _ in range(e):
    src, dst = map(int, sys.stdin.readline().split())
    graph[src][dst] = 1
    graph[dst][src] = 1

bfs(1)
sys.stdout.write(str(cnt[0] - 1))
