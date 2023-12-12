import sys
from collections import deque

def bfs(A, B):
    visited = [(False, 0)] * 10000
    queue = deque()
    queue.append(A)
    visited[A] = ("\0", A)

    while True:
        num = queue.popleft()

        if num == B:
            result = []
            while A != B:
                result.append(visited[B][0])
                B = visited[B][1]
            return ''.join(reversed(result))

        D = (num * 2) % 10000
        S = num - 1 if num > 0 else 9999
        L = (num % 1000) * 10 + num // 1000
        R = (num % 10) * 1000 + num // 10

        if not visited[D][0]:
            queue.append(D)
            visited[D] = ("D", num)
        if not visited[S][0]:
            queue.append(S)
            visited[S] = ("S", num)
        if not visited[L][0]:
            queue.append(L)
            visited[L] = ("L", num)
        if not visited[R][0]:
            queue.append(R)
            visited[R] = ("R", num)

T = int(sys.stdin.readline().strip())
for _ in range(T):
    A, B = map(int, sys.stdin.readline().split())
    print(bfs(A, B))
