import math
import copy

G = [
    [0, 10, math.inf, 5, math.inf],
    [math.inf, 0, 1, 2, math.inf],
    [math.inf, math.inf, 0, math.inf, 4],
    [math.inf, 3, 9, 0, 2],
    [7, math.inf, 6, math.inf, 0]
]


#main block
def fw(G):
    n = len(G)

    # Create a deepcopy  of w as the initial distance matrix so that we dont end up changing the original matrix later on
    dist = copy.deepcopy(G)  

    for k in range(n):            # potential intermidiate node
        for i in range(n):        #starting node
            for j in range(n):    #ending node
                # Update dist[i][j] if a shorter path is found through k 
                # Check if going from i → k → j is shorter than the current i → j
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

    print("Final shortest path matrix:")
    for row in dist:
        print(row)


fw(G)
