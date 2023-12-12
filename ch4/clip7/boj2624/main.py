t = int(input())
k = int(input())
d = [0] * (t + 1)
d[0] = 1

for i in range(k):
    coin_price, coin_count = map(int, input().split())
    for j in range(t, -1, -1):
        for cnt in range(1, coin_count + 1):
            next_value = j + coin_price * cnt
            if next_value > t:
                break
            d[next_value] += d[j]

print(d[t])
