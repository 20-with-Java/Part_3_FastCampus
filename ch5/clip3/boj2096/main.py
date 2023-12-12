import sys

n = int(sys.stdin.readline())
MAX_VALUE = 1000000

dmx = [0] * 5
dmn = [0] * 5
tmx = [0] * 5
tmn = [0] * 5

dmx[0] = dmx[4] = 0
dmn[0] = dmn[4] = MAX_VALUE

for _ in range(n):
    inputs = list(map(int, sys.stdin.readline().split()))
    for j in range(1, 4):
        input_value = inputs[j - 1]
        tmx[j] = max(dmx[j - 1], max(dmx[j], dmx[j + 1])) + input_value
        tmn[j] = min(dmn[j - 1], min(dmn[j], dmn[j + 1])) + input_value

    for j in range(1, 4):
        dmx[j] = tmx[j]
        dmn[j] = tmn[j]

max_score = max(dmx[1:4])
min_score = min(dmn[1:4])

print(max_score, min_score)
