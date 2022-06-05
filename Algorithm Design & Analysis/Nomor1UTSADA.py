def krushkal(connections):
    from queue import PriorityQueue
    from collections import defaultdict
    def find(u): return root[u]
    def union(u,v):
        root[v] = u
        children[u].append(v)
    def reduceRank(u,v):
        while children[v]:
            child=children[v].pop()
            root[child]=u
            children[u].append(child)
    E=len(connections)
    children=defaultdict(list)
    pq=PriorityQueue()#minHeap
    vertices=set()#switches
    for u,v,c in connections:
        pq.put((c,u,v))
        vertices.add(u)
        vertices.add(v)
    root = {v: v for v in vertices}
    V = len(vertices)
    ans=[]
    minCost=0
    e=0
    while V-1!=e:#number of edges in resulting connections will v-1
        c,u,v=pq.get()
        r1=find(u)
        r2=find(v)
        if r1!=r2:
            ans.append((u, v, c))
            if r1!=u: u=r1
            if r2!=v: v=r2
            union(u,v)
            e += 1
            reduceRank(u,v)
            minCost+=c
    return ans,minCost
E=int(input("Masukkan Jumlah Koneksi yang diinput : "))
connections=[]
for _ in range(E):
    u,v,c=input().split()
    c=int(c)
    connections.append((u,v,c))
ans,minCost=krushkal(connections)
print("Output : ")
print(minCost)
for u,v,c in ans:
    print(f"{u}-{v} {c}")