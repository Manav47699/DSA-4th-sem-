def rGCD(a, n):
    if (n == 0):
        return a
    else:
        return rGCD(n, a%n)
    
print (f"the GCD of 20 and 7 is = {rGCD(20,7)}")

