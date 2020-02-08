def bubbleSort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-1):
            if arr[j+1]<arr[j]:
                arr[j], arr[j+1] = arr[j+1], arr[j]

n = int(input())
arr = list(map(int, input().split()))
bubbleSort(arr)
for i in range(len(arr)):
	print(arr[i],end=" ")
