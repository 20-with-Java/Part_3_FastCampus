import sys
from collections import deque

n, m = map(int, input().split())
maze = [list(input().strip()) for _ in range(n)]
distance = [[[0] * (1 << 6) for _ in range(m)] for _ in range(n)]

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def is_out_of_range(r, c):
    return r < 0 or r >= n or c < 0 or c >= m

def get_type(c):
    if c == '#':
        return 4  # WALL
    elif c == '.' or c == '0':
        return 5  # NONE
    elif 'a' <= c <= 'f':
        return 2  # KEY
    elif 'A' <= c <= 'F':
        return 1  # DOOR
    elif c == '1':
        return 3  # EXIT
    else:
        return -1

q = deque()
for r in range(n):
    for c in range(m):
        if maze[r][c] == '0':
            q.append((r, c, 0))
            distance[r][c][0] = 1

while q:
    r, c, key = q.popleft()
    for i in range(4):
        nr, nc = r + dr[i], c + dc[i]
        if is_out_of_range(nr, nc):
            continue
        next_type = get_type(maze[nr][nc])
        if next_type == 4:  # WALL
            continue
        elif next_type == 5:  # NONE
            if distance[nr][nc][key] == 0:
                distance[nr][nc][key] = distance[r][c][key] + 1
                q.append((nr, nc, key))
        elif next_type == 3:  # EXIT
            print(distance[r][c][key])
            sys.exit(0)
        elif next_type == 2:  # KEY
            next_key = key | (1 << (ord(maze[nr][nc]) - ord('a')))
            if distance[nr][nc][next_key] == 0:
                distance[nr][nc][next_key] = distance[r][c][key] + 1
                q.append((nr, nc, next_key))
        elif next_type == 1:  # DOOR
            if (key & (1 << (ord(maze[nr][nc]) - ord('A')))) != 0:
                if distance[nr][nc][key] == 0:
                    distance[nr][nc][key] = distance[r][c][key] + 1
                    q.append((nr, nc, key))

print(-1)
