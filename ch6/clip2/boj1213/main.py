name = input()
cnt = [0] * 26

for char in name:
    cnt[ord(char) - ord('A')] += 1

odd = 0
odd_idx = -1

for i in range(26):
    if cnt[i] % 2 == 1:
        odd += 1
        odd_idx = i

if odd > 1:
    print("I'm Sorry Hansoo")
else:
    sb = []
    for i in range(26):
        sb.extend([chr(ord('A') + i)] * (cnt[i] // 2))

    ans = sb[:]
    if odd_idx != -1:
        ans.append(chr(ord('A') + odd_idx))
    
    ans.extend(reversed(sb))
    print(''.join(ans))
