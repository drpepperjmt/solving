ans = 0

nodes = {}
edges = []

n, m = map(int, input().split())
for _ in range(m):
    a, b = map(int, input().split())
    edges.append([a, b])
    try:
        if a < b:
            nodes[a].add(b)
        else:
            nodes[b].add(a)
    except KeyError:
        if a < b:
            nodes[a] = set()
            nodes[a].add(b)
        else:
            nodes[b] = set()
            nodes[b].add(a)

for edge in edges:
    try:
        coms = nodes[edge[0]] & nodes[edge[1]]
        if coms:
            ans += len(coms)
    except KeyError:
        pass

print(ans)
