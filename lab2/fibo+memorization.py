
MAX = 10
table = [0] * MAX      # a table of size 10 with all elements 0
 
def fiboM(n):
    if n == 1 or n==2:
        return 1
    else:
       if table[n] != 0:
           return table[n]
       else:
           table[n] = fiboM(n-1) + fiboM(n-2)
           return table[n]
       
print (fiboM(5))
    
