n = int(input())
a = [[0] * (n + 1) for _ in range(n + 1)]
d = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    line = list(map(int, input().split()))
    for j in range(1, i + 1):
        a[i][j] = line[j - 1]

d[1][1] = a[1][1]

for i in range(2, n + 1):
    for j in range(1, i + 1):
        d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + a[i][j]

for i in range(1, n):
    for j in range(1, i + 1):
        d[i + 1][j] = max(d[i + 1][j], d[i][j] + a[i + 1][j])
        d[i + 1][j + 1] = max(d[i + 1][j + 1], d[i][j] + a[i + 1][j + 1])

ans = 0
for i in range(1, n + 1):
    ans = max(ans, d[n][i])

print(ans)
