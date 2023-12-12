from collections import deque

n, m = map(int, input().split())
maze = []
visited = [[0] * m for _ in range(n)]

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

for _ in range(n):
    row = list(map(int, list(input().strip())))
    maze.append(row)

q = deque()
q.append((0, 0))
visited[0][0] = 1

while q:
    r, c = q.popleft()
    for i in range(4):
        nr, nc = r + dr[i], c + dc[i]
        if 0 <= nr < n and 0 <= nc < m and visited[nr][nc] == 0 and maze[nr][nc] == 1:
            visited[nr][nc] = visited[r][c] + 1
            q.append((nr, nc))

print(visited[n - 1][m - 1])
