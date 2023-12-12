from collections import deque

def is_range(r, c, m, n):
    return 1 <= r <= m and 1 <= c <= n

m, n = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(m)]
dist = [[[-1] * (n + 1) for _ in range(m + 1)] for _ in range(5)]
EAST, WEST, SOUTH, NORTH = 1, 2, 3, 4

start_r, start_c, start_dir = map(int, input().split())
end_r, end_c, end_dir = map(int, input().split())

dr = [0, 0, 0, 1, -1]
dc = [0, 1, -1, 0, 0]

for i in range(1, m + 1):
    for j in range(1, n + 1):
        for k in range(1, 5):
            dist[k][i][j] = -1

dist[start_dir][start_r][start_c] = 0
q = deque([(start_r, start_c, start_dir)])

while q:
    now_r, now_c, now_dir = q.popleft()

    for k in range(1, 4):
        nr = now_r + dr[now_dir] * k
        nc = now_c + dc[now_dir] * k

        if not is_range(nr, nc, m, n) or a[nr - 1][nc - 1] == 1:
            break

        if dist[now_dir][nr][nc] != -1:
            continue

        dist[now_dir][nr][nc] = dist[now_dir][now_r][now_c] + 1
        q.append((nr, nc, now_dir))

    for k in range(1, 5):
        if k == now_dir:
            continue

        if dist[k][now_r][now_c] != -1:
            continue

        cnt = 0
        if k in (EAST, WEST):
            if now_dir in (NORTH, SOUTH):
                cnt = 1
            else:
                cnt = 2
        elif k in (SOUTH, NORTH):
            if now_dir in (EAST, WEST):
                cnt = 1
            else:
                cnt = 2

        dist[k][now_r][now_c] = dist[now_dir][now_r][now_c] + cnt
        q.append((now_r, now_c, k))

print(dist[end_dir][end_r][end_c])
