from collections import deque

n, k = map(int, input().split())
visited = [0] * 100001

def is_range(x):
    return 0 <= x <= 100000

q = deque()
q.append(n)
visited[n] = 1

while q:
    now = q.popleft()
    if now == k:
        break
    next_positions = [now - 1, now + 1, now * 2]
    
    for next_pos in next_positions:
        if is_range(next_pos) and visited[next_pos] == 0:
            visited[next_pos] = visited[now] + 1
            q.append(next_pos)

print(visited[k] - 1)
