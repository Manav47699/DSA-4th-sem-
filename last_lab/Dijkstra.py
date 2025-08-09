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
    
    cost = {}
    prev = {}
    for vertex in G.keys():
        cost[vertex] = math.inf    # here, key is "vertex" and value is math.inf
        prev[vertex] = " "           # here, key is "vertex" and value is ""
    cost[s] = 0      #the cost of parent node is initialized to zero
    return cost, prev

#block 3 
#Check if the current known cost to reach 'v' (i.e chimeki) can be improved by going through 'u' (i.e current node).
def relax(G, u, v, cost, prev):
    if cost[v] > cost[u] + G[u][v]:
        cost[v] = cost[u] + G[u][v]
        prev[v]= u
    return cost, prev


#block 4
from queue import PriorityQueue
def dj(G, s):         # s is the source vertex or the starting vertex
    
    cost, prev = intialize_single_source(G, s)

# priorityQueue is a type of queue where every elemnt has a priority order assigned to it
#Syntax : -> (priority , node)
    PQ = PriorityQueue()

    #inserting everyy vertx into the priority queue
    for vertex in G.keys():

        PQ.put([cost[vertex], vertex])     #(priority, node)

    visited = []

    while (len(visited) != len(G.keys())):
        _, currentvertex = PQ.get()              # _, ignores the cost value, so that only the node is stored in 'currentvertex'
        visited.append(currentvertex)
        for chimeki in G[currentvertex].keys():
            
            # if the neighbours are not already finalized(i.e appended to visited[]), we may be able to improve it's cost with the relax()
            if chimeki not in visited:     
                cost, prev = relax(G, currentvertex, chimeki, cost, prev)

                PQ.put([cost [chimeki], chimeki])
    return cost, prev




#block 6
def reconstruct_path(vertex, prev):
    path = vertex
    # loop untill we reach the starting vertex that has empty prev i.e no parents
    while prev[vertex] != " ":     
        path = prev[vertex] + '->' + path
        vertex = prev[vertex]
    return path 

#block 5
s = 's'
cost, prev = dj(G, s)

for vertex in G.keys():
    print (f'Shortest path from {s} to {vertex} is {reconstruct_path(vertex, prev)} ')
    print (f'Cost is {cost[vertex]}')







