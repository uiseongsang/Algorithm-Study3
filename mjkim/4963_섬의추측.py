from sys import setrecursionlimit
setrecursionlimit(10 ** 6)
directions = [[0, 1], [0, -1], [1, 0], [-1, 0], [-1, -1], [1, 1], [1, -1], [-1, 1]]

def dfs(m, x, y, w, h):
    if m[x][y] == 0: return
    m[x][y] = 0
    for dx, dy in directions:
        nx, ny = x + dx, y + dy
        if 0 <= nx < h and 0 <= ny < w:
            dfs(m, nx, ny, w, h)

w, h = map(int, input().split())
while w > 0 and h > 0:
    m = [list(map(int, input().split())) for i in range(h)]
    count = 0
    for x in range(h):
        for y in range(w):
            if m[x][y] == 0: continue
            count += 1
            dfs(m, x, y, w, h)
    print(count)
    w, h = map(int, input().split())
