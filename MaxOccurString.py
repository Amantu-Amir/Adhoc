from collections import Counter
n, cnt, mx, arr = int(input()), Counter(), -1, []
for i in range(n):
    s = input()
    arr.append(s)
    cnt[s] += 1
    mx = max(mx,cnt[s])
res = []
for i in arr:
    if cnt[i] == mx:
        res.append(i)
        cnt[i] = 0
res.sort()
for i in res:
    print(i)