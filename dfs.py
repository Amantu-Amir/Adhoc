from collections import defaultdict

def dfs(root):
    vis[root] = True
    arr.append(root)
    for i in G[root]:
        if vis[i] == False:
            vis[i] = True
            dfs(i)


arr = []
N = 100000
vis = [False]*N
node, edge = map(int, input().split())
G = defaultdict(list)
for i in range(edge):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)
dest = int(input())
dfs(1)
if dest in arr:
    print("Found")
else:
    print("Not Found")
