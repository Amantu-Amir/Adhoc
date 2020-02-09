from collections import defaultdict
N = 100000
def bfs(root, dest):
    vis = [False]*N
    queue = []
    queue.append(root)
    vis[root] = True
    ok = 0
    while queue:
        u = queue.pop(0)
        if u == dest:
            ok = 1
            break
        for i in G[u]:
            if vis[i] == False:
                vis[i] = True
                queue.append(i)
    return ok


node, edge = map(int, input().split())
G = defaultdict(list)
for i in range(edge):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)
dest = int(input())
if bfs(1, dest) == True:
    print("Found")
else:
    print("Not Found")
