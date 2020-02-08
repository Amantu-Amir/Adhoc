def selectionSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(i+1,n):
            if arr[i]>arr[j]:
                arr[i], arr[j] = arr[j], arr[i]


n = int(input())
arr = list(map(int, input().split()))
selectionSort(arr)
for i in range(len(arr)):
    print(arr[i],end=" ")
