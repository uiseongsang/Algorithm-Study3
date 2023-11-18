def get_reverse_value(n):
    if n == '1': return '0'
    return '1'

def reverse_maps(x, y):
    for i in range(3):
        for j in range(3):
            nx, ny = x + i, y + j
            a[nx][ny] = get_reverse_value(a[nx][ny])

def is_equal_maps(a, b):
    for i in range(n):
        for j in range(m):
            if a[i][j] != b[i][j]: return False
    return True
            
n, m = map(int, input().split())
a, b = [list(input()) for _ in range(n)], [list(input()) for _ in range(n)]

count = 0
for i in range(n - 2):
    for j in range(m - 2):
        if a[i][j] != b[i][j]:
            count += 1
            reverse_maps(i, j)

print(count if is_equal_maps(a, b) else -1)
