def insertionSort(arr):
    n = len(arr)
    for i in range(n):
        temp = arr[i]
        idx = i-1
        while idx>=0 and arr[idx]>temp:
            arr[idx+1] = arr[idx]
            idx-=1
        arr[idx+1] = temp


n = int(input())
arr = list(map(int, input().split()))
insertionSort(arr)
for i in range(len(arr)):
    print(arr[i],end=" ")
