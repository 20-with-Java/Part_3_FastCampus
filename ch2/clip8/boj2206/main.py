from collections import deque

n, m = map(int, input().split())
board = []
visited = [[[0] * 2 for _ in range(m)] for _ in range(n)]

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

for _ in range(n):
    row = list(map(int, list(input().strip())))
    board.append(row)

q = deque()
q.append((0, 0, 0))
visited[0][0][0] = 1

while q:
    r, c, is_broken = q.popleft()
    if r == n - 1 and c == m - 1:
        print(visited[r][c][is_broken])
        exit()

    for i in range(4):
        nr, nc = r + dr[i], c + dc[i]
        if 0 <= nr < n and 0 <= nc < m:
            if board[nr][nc] == 0 and visited[nr][nc][is_broken] == 0:
                visited[nr][nc][is_broken] = visited[r][c][is_broken] + 1
                q.append((nr, nc, is_broken))
            elif board[nr][nc] == 1 and is_broken == 0:
                visited[nr][nc][1] = visited[r][c][0] + 1
                q.append((nr, nc, 1))

print(-1)
