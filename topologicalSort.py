from collections import defaultdict


def build(root, visited, stack):
    visited[root] = True
    for i in G[root]:
        if visited[i] is False:
            build(i, visited, stack)
    stack.insert(0, root)


def topologicalSort(node):
    visited = [False]*1000
    stack =[]
    for i in range(1, node):
        if visited[i] is False:
            build(i, visited, stack)
    print(stack)


node, edge = map(int, input().split())
G = defaultdict(list)
for i in range(edge):
    u, v = map(int, input().split())
    G[u].append(v)
    G[v].append(u)
topologicalSort(node)

