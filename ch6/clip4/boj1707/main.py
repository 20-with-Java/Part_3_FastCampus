import sys
sys.setrecursionlimit(10**6)

def dfs(node_num, depth):
    if color[node_num] != 0:
        return
    
    if depth % 2 == 0:
        color[node_num] = RED
    else:
        color[node_num] = BLUE
    
    for next_node in graph[node_num]:
        dfs(next_node, depth + 1)

RED = 1
BLUE = 2

k = int(input())

for _ in range(k):
    v, e = map(int, sys.stdin.readline().split())
    
    graph = [[] for _ in range(v + 1)]
    color = [0] * (v + 1)
    
    for _ in range(e):
        a, b = map(int, sys.stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)
    
    for i in range(1, v + 1):
        dfs(i, 0)
    
    is_binary = True
    
    for i in range(1, v + 1):
        for next_node in graph[i]:
            if color[i] == color[next_node]:
                is_binary = False
                break
    
    if is_binary:
        print("YES")
    else:
        print("NO")
