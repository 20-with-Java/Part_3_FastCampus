import sys
sys.setrecursionlimit(10**6)

def dfs(nodeNum):
    next = nextNode[nodeNum]
    cycleCnt = 0
    # 첫 방문
    if depth[next] == 0:
        depth[next] = depth[nodeNum] + 1
        cycleCnt = dfs(next)
    # 재방문 (사이클)
    else:
        cycleCnt = depth[nodeNum] - depth[next] + 1
    # 다음 탐색을 위해 재귀 안에서 초기화
    depth[nodeNum] = 100001
    # 사이클이 아니면(음수) 0을 리턴
    return cycleCnt if cycleCnt >= 0 else 0

T = int(sys.stdin.readline())

for _ in range(T):
    n = int(sys.stdin.readline())
    nextNode = [0] + list(map(int, sys.stdin.readline().split()))
    depth = [0] * (n + 1)
    cnt = 0

    for i in range(1, n + 1):
        if depth[i] == 0:
            depth[i] = 1
            cnt += dfs(i)

    sys.stdout.write(f"{n - cnt}\n")
