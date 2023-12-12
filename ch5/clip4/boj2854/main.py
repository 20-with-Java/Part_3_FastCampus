import sys

n = int(sys.stdin.readline())
exam1 = [0] + list(map(int, sys.stdin.readline().split()))
exam2 = [0] + list(map(int, sys.stdin.readline().split())) + [0]

MOD = 1000000007
STATIC = 0
DYNAMIC_1 = 1
DYNAMIC_2 = 2

d = [[0] * (n + 1) for _ in range(3)]

d[STATIC][0] = 1
d[DYNAMIC_1][0] = 0
d[DYNAMIC_2][0] = 0

d[STATIC][1] = exam1[1]
d[DYNAMIC_1][1] = exam2[1]
d[DYNAMIC_2][1] = 0

for i in range(2, n + 1):
    d[STATIC][i] = ((d[STATIC][i - 1] + d[DYNAMIC_1][i - 1] + d[DYNAMIC_2][i - 1]) * exam1[i]) % MOD
    d[DYNAMIC_1][i] = ((d[STATIC][i - 1] + d[DYNAMIC_1][i - 1] + d[DYNAMIC_2][i - 1]) * exam2[i]) % MOD

    d[DYNAMIC_2][i] = (d[STATIC][i - 1] + d[DYNAMIC_2][i - 1]) * exam2[i - 1] % MOD + \
                      (d[STATIC][i - 2] + d[DYNAMIC_1][i - 2] + d[DYNAMIC_2][i - 2]) * ((exam2[i - 1] * (exam2[i - 1] - 1)) % MOD) % MOD

sum_value = d[STATIC][n] + d[DYNAMIC_1][n] + d[DYNAMIC_2][n]
print(sum_value % MOD)
