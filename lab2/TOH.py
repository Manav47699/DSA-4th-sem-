#tower of hanoi
# python treats global varibale as local unless expicitely declared as "global"

moves = 0

def TOH(n, src, dst, temp):
    global moves
    if n == 1:
        print (f"move disc{n} from {src} to {dst}\n")
        moves +=1
    else:
        global moves
        TOH(n-1, src, temp, dst)
        print (f"Move disc {n} from {src} to dst\n")
        TOH(n-1, temp, dst, src)
        moves += 1


n = int(input("Enter the number of plates"))
TOH(n, 'A', 'B', 'C')
print (f"The total number of moves required was {moves}")