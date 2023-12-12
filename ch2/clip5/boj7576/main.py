from collections import deque

def min_days_to_ripe_tomatoes(box):
    n = len(box)
    m = len(box[0])

    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    q = deque()

    # 초기 익은 토마토들을 큐에 추가하고 방문 표시
    for i in range(n):
        for j in range(m):
            if box[i][j] == 1:
                q.append((i, j, 0))

    max_days = 0

    while q:
        r, c, days = q.popleft()
        max_days = max(max_days, days)

        for i in range(4):
            nr = r + dr[i]
            nc = c + dc[i]

            if 0 <= nr < n and 0 <= nc < m and box[nr][nc] == 0:
                box[nr][nc] = 1
                q.append((nr, nc, days + 1))

    # 모든 토마토가 익었는지 확인
    for i in range(n):
        for j in range(m):
            if box[i][j] == 0:
                return -1

    return max_days

m, n = map(int, input().split())
box = []

for _ in range(n):
    row = list(map(int, input().split()))
    box.append(row)

result = min_days_to_ripe_tomatoes(box)
print(result)
