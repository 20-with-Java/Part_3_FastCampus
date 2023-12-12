def is_friend(a, b):
    diff = abs(a - b)
    max_val = max(a, b)

    if diff == 1 and max_val % 5 != 0:
        return True
    if diff == 5:
        return True

    return False

def dfs(student_num):
    count = 1
    check[student_num] = True
    for i in range(7):
        me = pick[student_num]
        you = pick[i]
        if not check[i] and is_friend(me, you):
            count += dfs(i)
    return count

def next_combination(student_num):
    global pick
    if len(pick) == 7:
        cnt = sum(students[idx] for idx in pick)
        if cnt < 4:
            return 0

        for i in range(7):
            check[i] = False
        if dfs(0) == 7:
            return 1
        return 0
    
    if student_num >= 25:
        return 0

    ret = next_combination(student_num + 1)
    pick.append(student_num)
    ret += next_combination(student_num + 1)
    pick.pop()
    return ret

students = []
for _ in range(5):
    line = input().strip()
    for c in line:
        if c == 'S':
            students.append(1)
        else:
            students.append(0)

pick = []
check = [False] * 7
result = next_combination(0)
print(result)
