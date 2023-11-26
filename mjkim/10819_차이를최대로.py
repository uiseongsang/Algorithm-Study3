from itertools import permutations

def sum_abs_arr(arr):
    ans = 0
    for i in range(1, len(arr)):
        ans += abs(arr[i - 1] - arr[i])
    return ans

n = int(input())
nums = list(map(int, input().split()))
max_sum = 0

for arr in permutations(nums):
    s = sum_abs_arr(arr)
    max_sum = max(max_sum, s)
print(max_sum)
