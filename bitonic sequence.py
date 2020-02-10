def bitonic(arr):
    n = len(arr)
    LIS = [1 for i in range(n + 1)]
    for i in range(1, n):
        for j in range(0, i):
            if (arr[i] > arr[j]) and (LIS[i] < LIS[j] + 1):
                LIS[i] = LIS[j] + 1
    LDS = [1 for i in range(n + 1)]
    for i in reversed(range(n - 1)):
        for j in reversed(range(i - 1, n)):
            if arr[i] > arr[j] and LDS[i] < LDS[j] + 1:
                LDS[i] = LDS[j] + 1
    maximum = LIS[0] + LDS[0] - 1
    for i in range(1, n):
        maximum = max((LIS[i] + LDS[i] - 1), maximum)
    return maximum


arr = list(map(int, input().split()))
res = bitonic(arr)
print(res)
