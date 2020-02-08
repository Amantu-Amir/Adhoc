def countingSort(arr, max_val):
    m = max_val + 1
    cnt = [0]*m
    for a in arr:
        cnt[a] += 1
    i = 0
    for a in range(m):
        for c in range(cnt[a]):
            arr[i] = a
            i += 1
    return arr


n = int(input())
arr = list(map(int, input().split()))
mx = max(arr)
countingSort(arr,mx)
for i in range(len(arr)):
    print(arr[i],end=" ")