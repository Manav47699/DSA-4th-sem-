#block 1  [storing all the vertexs in G]
import math
G ={
    's':{'t':10, 'y':5},
    't':{'x':1, 'y': 2},
    'x':{'z':4},
    'y':{'x':9, 'z':2, 't':3},
    'z':{'x':6, 's':7}
}

#block 2[]
def intialize_single_source(G, s):
    
    cost = dict()
    prev = dict()
    for vertex in G.keys():
        cost[vertex] = math.inf    # here, key is "vertex" and value is math.inf
        prev[vertex] = " "           # here, key is "vertex" and value is ""
    cost[s] = 0
    return cost, prev

#block 3
def relax(G, u, v, cost, prev):
    if cost[v] > cost[u] + G[u][v]:
        cost[v] = cost[u] + G[u][v]
        prev[v]= u
    return cost, prev


#block 4
from queue import PriorityQueue
def dj(G, s):
    cost, prev = intialize_single_source(G, s)
    PQ = PriorityQueue()
    for vertex in G.keys():
        PQ.put([cost[vertex], vertex])
    visited = []
    while (len(visited) != len(G.keys())):
        _, currentvertex = PQ.get()              # tuple ko 1st value ko matlab xaina hamilai, 2nd value lai chai currentvertex ma lagera rakhne
        visited.append(currentvertex)
        for chimeki in G[currentvertex.keys]:
            if chimeki not in visited:
                cost, prev = relax(G, currentvertex, chimeki, cost)
                PQ.put(cost [chimeki], chimeki)
    return cost, prev




#block 6
def reconstruct_path(vertex, prev):
    path = vertex
    while prev[vertex] != " ":
        path = prev[vertex] + '->' + path
        vertex = prev[vertex]
    return path 

#block 5
s = 's'
cost= dj(G, s)
prev = dj(G, s)
for vertex in G.keys():
    print (f'Shortest path from {s} to {vertex} is {reconstruct_path[vertex, prev]} ')
    print (f'Cost is {cost[vertex]}')







