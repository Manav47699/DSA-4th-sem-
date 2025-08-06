#block 1
import math
G =[
    [0, 10, math.inf, 5, math.inf],
    [math.inf, 0, 1, 2, math.inf],
    [math.inf, math. inf, 0, math.inf, 4],
    [math.inf, 3, 9, 0, 2],
    [7, math.inf,6, math.inf, 0]
]


#block 2

# # Block 2
# def fw(w):
#     n = len(w)
#     d = {}

#     # Make a deep copy for d[0]
#     d[0] = [row[:] for row in w]

#     for k in range(n):
#         # Deep copy previous distance matrix
#         d[k+1] = [row[:] for row in d[k]]

#         for i in range(n):
#             for j in range(n):
#                 # Use correct indices
#                 if d[k][i][k] + d[k][k][j] < d[k][i][j]:
#                     d[k+1][i][j] = d[k][i][k] + d[k][k][j]

#     # Final result after all iterations
#     print("Final shortest path matrix:")
#     for row in d[n]:
#         print(row)



def fw(w):
    n = len(w)
    d = dict()
    d[0] = w
    for k in range(n):
        d[k+1] =d[k]
        for i in range (n):
            for j in range (n):
                d[k+1][i][j] = min (d[k][j], d[k][i] + d[k][k][j])
    print (d[k])

fw (G)

