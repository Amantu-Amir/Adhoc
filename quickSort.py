def MakePartition(arr, low, high):
    idx = (low - 1)
    pivot = arr[high]
    for j in range(low, high):
        if arr[j] < pivot:
            idx = idx + 1
            arr[idx], arr[j] = arr[j], arr[idx]
    arr[idx + 1], arr[high] = arr[high], arr[idx + 1]
    return (idx + 1)

def quickSort(arr, low, high):
    if low < high:
        pos = MakePartition(arr, low, high)
        quickSort(arr, low, pos - 1)
        quickSort(arr, pos + 1, high)


n = int(input())
arr = list(map(int, input().split()))
quickSort(arr,0,n-1)
for i in range(len(arr)):
    print(arr[i],end=" ")