n = int(input())
arr = sorted(list(map(int,input().split())))
dest = int(input())
L, R = 0, n-1
while L<=R:
    mid = L+(R-L)
    if arr[mid]>dest:
        R = mid-1
    elif arr[mid]<dest:
        L = mid+1
    else:
        ok = 1
        break
if ok == 1:
    print("Found and its position is", mid+1)
else:
    print("Not Found")