G = {
    'A': {'B':1, 'D':4},
    'B': {'A':1, 'C':3, 'E':3},
    'C': {'B':3, 'F':2, 'E':1},
    'D': {'A':4, 'E':1},
    'E': {'D':1, 'B':3, 'C':1, 'F':4},
    'F': {'C':2, 'E':4}
}

#append paths in the list 'path[]'
path = []       # this list looks like this [('A', 'B', 1), ...........]
for u in G:
    for v in G[u]:
        if (v, u, G[u][v]) not in path: 
            path.append((u, v, G[u][v]))

# Sort path by weight
#key is a argument that takes a lamda function, which return 2nd element of the path[] i.e just the weight
path.sort(key=lambda path: path[2]) 

# IN union-find data structure, each node is its  own parent initially meaning each node is separate.
parent = {
    'A': 'A',
    'B': 'B',
    'C': 'C',
    'D':'D', 
    'E':'F',
}

'''an example of how this works. Suppose a tree 
A -> B
B -> C
C -> C  (root)

- call find(A), as A has parent != A (i.e == B), it calles find find(B) recucively
    - call find(B), as B has parent C i.e != C, it calls find(C) recursively again
        - call find(C), as C is the parent of C, we update the parent of B to be C
    - again, parent of A is updated
'''
def find(node):
    # Path compression for efficiency
    if parent[node] != node:       
        parent[node] = find(parent[node])
    return parent[node]

# if u and v have different root, apperently means they will not form a cycle some how. so we merge we merge these 2 nodes and return True on mergeing function
def merge(u, v):          #'u' is the starting node and 'v ' is the ending node
    root_u = find(u)
    root_v = find(v)
    if root_u != root_v:        
        parent[root_v] = root_u
        return True
    return False

def kruskal():
    mst = []
    total_weight = 0

    for u, v, w in path:
        if merge(u, v):
            mst.append((u, v, w))
            total_weight += w

    print("Minimum Spanning Tree path:")
    for u, v, w in mst:
        print(f"{u} - {v} : {w}")
    print("Total weight:", total_weight)

kruskal()
