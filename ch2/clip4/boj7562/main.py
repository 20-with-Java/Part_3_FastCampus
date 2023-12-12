from collections import deque

def min_moves_to_destination(l, start, end):
    visited = [[0] * l for _ in range(l)]
    dr = [-2, -1, 1, 2, 2, 1, -1, -2]
    dc = [1, 2, 2, 1, -1, -2, -2, -1]

    q = deque()
    q.append(start)
    visited[start[0]][start[1]] = 1

    while q:
        now = q.popleft()
        if now == end:
            return visited[end[0]][end[1]] - 1

        for i in range(8):
            nr = now[0] + dr[i]
            nc = now[1] + dc[i]
            if 0 <= nr < l and 0 <= nc < l and visited[nr][nc] == 0:
                visited[nr][nc] = visited[now[0]][now[1]] + 1
                q.append((nr, nc))

    return -1

t = int(input())
for _ in range(t):
    l = int(input())
    start = tuple(map(int, input().split()))
    end = tuple(map(int, input().split()))
    result = min_moves_to_destination(l, start, end)
    print(result)
