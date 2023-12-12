b_time, r_time, n = map(int, input().split())
blue_queue = []
red_queue = []

for _ in range(n):
    time, color, cnt = input().split()
    time = int(time)
    cnt = int(cnt)

    if color == 'B':
        if blue_queue and blue_queue[-1] + b_time > time:
            time = blue_queue[-1] + b_time
        for _ in range(cnt):
            blue_queue.append(time)
            time += b_time
    elif color == 'R':
        if red_queue and red_queue[-1] + r_time > time:
            time = red_queue[-1] + r_time
        for _ in range(cnt):
            red_queue.append(time)
            time += r_time

blue_order = []
red_order = []
order_number = 0

while blue_queue and red_queue:
    if blue_queue[0] <= red_queue[0]:
        blue_order.append(order_number + 1)
        order_number += 1
        blue_queue.pop(0)
    else:
        red_order.append(order_number + 1)
        order_number += 1
        red_queue.pop(0)

while blue_queue:
    blue_order.append(order_number + 1)
    order_number += 1
    blue_queue.pop(0)

while red_queue:
    red_order.append(order_number + 1)
    order_number += 1
    red_queue.pop(0)

print(len(blue_order))
print(" ".join(map(str, blue_order)))
print(len(red_order))
print(" ".join(map(str, red_order)))
