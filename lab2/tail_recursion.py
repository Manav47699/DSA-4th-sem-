def tailfact(n, a):
    if (n==0):
        return a
    else:
        return tailfact(n-1, a*n)
    
print (f"{tailfact(5,1)}")