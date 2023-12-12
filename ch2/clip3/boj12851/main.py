import sys
from collections import deque

A, B = map(int, sys.stdin.readline().split())
visited = [-1] * 100001
count = [0] * 100001
visited[A] = 0
count[A] = 1

q = deque([A])
while q:
    x = q.popleft()
    for nx in [x - 1, x + 1, x * 2]:
        if 0 <= nx <= 100000:
            if visited[nx] == -1:
                visited[nx] = visited[x] + 1
                count[nx] = count[x]
                q.append(nx)
            elif visited[nx] == visited[x] + 1:
                count[nx] += count[x]

sys.stdout.write(f"{visited[B]}\n{count[B]}\n")
