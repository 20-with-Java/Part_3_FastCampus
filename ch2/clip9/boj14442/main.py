import sys
from collections import deque

N, M, K = map(int, sys.stdin.readline().split())
board = []
for _ in range(N):
    board.append(list(map(int, sys.stdin.readline().strip())))

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

visited = [[[0] * (K + 1) for _ in range(M)] for _ in range(N)]
visited[0][0][0] = 1

queue = deque([(0, 0, 0)])  # (row, column, broken walls)

while queue:
    r, c, b = queue.popleft()

    if r == N - 1 and c == M - 1:
        sys.stdout.write(f"{visited[r][c][b]}\n")
        sys.exit(0)

    for i in range(4):
        nr, nc = r + dr[i], c + dc[i]

        if 0 <= nr < N and 0 <= nc < M:
            if board[nr][nc] == 0 and visited[nr][nc][b] == 0:
                visited[nr][nc][b] = visited[r][c][b] + 1
                queue.append((nr, nc, b))
            elif board[nr][nc] == 1 and b < K and visited[nr][nc][b + 1] == 0:
                visited[nr][nc][b + 1] = visited[r][c][b] + 1
                queue.append((nr, nc, b + 1))

sys.stdout.write("-1\n")
