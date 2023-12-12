import sys

n = int(input())
t = [0] * (n + 2)
p = [0] * (n + 2)
dp = [0] * (n + 2)

for i in range(1, n + 1):
    t[i], p[i] = map(int, sys.stdin.readline().split())

max_profit = 0

for i in range(1, n + 2):
    max_profit = max(max_profit, dp[i])
    
    if i + t[i] <= n + 1:
        dp[i + t[i]] = max(dp[i + t[i]], max_profit + p[i])

print(max_profit)
