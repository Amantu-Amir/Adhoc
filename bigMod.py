def bigMod(b, p, m):
    if p==0:
        return 1
    if p%2==0:
        even = bigMod(b, int(p/2), m)
        ans = (even*even)%m
    if p%2!=0:
        odd = b%m
        even = bigMod(b, p-1, m)
        ans = (odd*even)%m
    return ans


b, p, m = map(int, input().split())
res = bigMod(b, p, m)
print(res)