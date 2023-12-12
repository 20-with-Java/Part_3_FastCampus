n = int(input())
costs = []

for _ in range(n):
    r, g, b = map(int, input().split())
    costs.append((r, g, b))

dp = [[0] * 3 for _ in range(n)]
dp[0] = costs[0]

for i in range(1, n):
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0]
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1]
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2]

result = min(dp[n - 1])
print(result)
