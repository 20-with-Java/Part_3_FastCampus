n = int(input())
arr = list(map(int, input().split()))
d = [1] * n
max_length = 1

for i in range(n):
    for j in range(i):
        if arr[j] < arr[i]:
            if d[j] + 1 < d[i]:
                continue
            d[i] = d[j] + 1
            max_length = max(max_length, d[i])

print(max_length)
