MOD = 1000000000
n = int(input())
d = [[0] * 10 for _ in range(n + 1)]

for i in range(1, 10):
    d[1][i] = 1

for i in range(2, n + 1):
    for j in range(10):
        if j == 0:
            d[i][j] = d[i - 1][j + 1] % MOD
        elif j == 9:
            d[i][j] = d[i - 1][j - 1] % MOD
        else:
            d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % MOD

sum_value = sum(d[n]) % MOD
print(sum_value)
