n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]
dp = [100001] * (k + 1)

for i in range(n):
    coin = coins[i]
    if coin <= k:
        dp[coin] = 1

for i in range(1, k + 1):
    for j in range(n):
        if i + coins[j] <= k:
            dp[i + coins[j]] = min(dp[i + coins[j]], dp[i] + 1)
        if i - coins[j] >= 0:
            dp[i] = min(dp[i], dp[i - coins[j]] + 1)

if dp[k] == 100001:
    print(-1)
else:
    print(dp[k])
