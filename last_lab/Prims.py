import math

G = {
    's':{'t':10, 'y':5},
    't':{'y':2, 'x':1},
    'x':{'z':4},
    'y':{'x':9, 't':3, 'z':2},
    'z':{'x':6, 's':7}
}

nodes = ['s', 't', 'x', 'y', 'z']
n = len(nodes)  

start = input('Enter the starting vertex: ')


def prim (G, start):      #"start" is the starting node of MST
    mst = {}
    mst[start] = {'cost':0, 'parent':None}    #since it is the 1st node, no cost & parent
    selected = []
    selected.append(start)

    while len(selected) < n:     #"n" is our number of nodes
        min_value = math.inf        # suru ma infinity dinthim nita cost hamile
        min_key = None
# u: nodes that are present in out MST currently
# v: neighbouring nodes of u
# G[u]: a dictonary of all neighbours of u with their weight
# G[u][v]: this gives weight of path (u,v)
        for u in selected:      
            for v in G[u]:
                if v not in selected and G[u][v] < min_value:          #only take 'v' that is not already in the selected list 
                    min_value = G[u][v]
                    min_key = v
                    previous = u 

        selected.append(min_key)
        mst[min_key] = {'cost': min_value, 'parent': previous}

    def display(mst):
        print("The mimimum spanning tree is given below:\n")
        weight_mst = 0
        for i in mst.keys():
            weight_mst = weight_mst + mst[i]['cost']
            #The root (starting node) has no parent, so there’s no edge to display.
            if mst[i]['parent'] == None:
                continue
            print(f"{mst[i]['parent']} -- {mst[i]['cost']} -- {i}")
        print(f"Weight of MST = {weight_mst}")

    display(mst)

prim(G,start)