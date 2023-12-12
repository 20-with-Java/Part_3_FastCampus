n = int(input())
wine = [0] + [int(input()) for _ in range(n)]
d = [[0] * (n + 1) for _ in range(3)]

d[0][1] = 0
d[1][1] = wine[1]
d[2][1] = wine[1]

for i in range(2, n + 1):
    d[0][i] = max(d[0][i - 1], max(d[1][i - 1], d[2][i - 1]))
    d[1][i] = d[0][i - 1] + wine[i]
    d[2][i] = d[1][i - 1] + wine[i]

print(max(d[0][n], max(d[1][n], d[2][n])))
