from collections import deque

def is_out_of_range(r, c):
    return r < 0 or r >= h or c < 0 or c >= w

def is_exit(r, c):
    return r == 0 or r == h - 1 or c == 0 or c == w - 1

def escape_building():
    q = deque()
    fire_q = deque()

    for i in range(h):
        for j in range(w):
            if building[i][j] == '#':
                fire[i][j] = visited[i][j] = -1
            elif building[i][j] == '@':
                q.append((i, j))
                visited[i][j] = 1
            elif building[i][j] == '*':
                fire_q.append((i, j))
                fire[i][j] = 1

    while fire_q:
        now = fire_q.popleft()
        for i in range(4):
            nr, nc = now[0] + dr[i], now[1] + dc[i]
            if is_out_of_range(nr, nc):
                continue
            if fire[nr][nc] == 0:
                fire[nr][nc] = fire[now[0]][now[1]] + 1
                fire_q.append((nr, nc))

    while q:
        now = q.popleft()
        if is_exit(now[0], now[1]):
            return visited[now[0]][now[1]]

        for i in range(4):
            nr, nc = now[0] + dr[i], now[1] + dc[i]
            if is_out_of_range(nr, nc):
                continue
            if visited[nr][nc] != 0:
                continue
            if fire[nr][nc] == 0 or fire[nr][nc] > visited[now[0]][now[1]] + 1:
                visited[nr][nc] = visited[now[0]][now[1]] + 1
                q.append((nr, nc))

    return "IMPOSSIBLE"

t = int(input())
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

for _ in range(t):
    w, h = map(int, input().split())
    building = [input() for _ in range(h)]
    visited = [[0] * w for _ in range(h)]
    fire = [[0] * w for _ in range(h)]
    result = escape_building()
    print(result)
