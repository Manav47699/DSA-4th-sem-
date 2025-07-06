
def eval():
    stack = []
    expression = input("enter the expression")           #this is stored as a str so convert it to float or int
    tokens = expression.split()
    for token in tokens:
        if token.isdigit():
            stack.append(float(token))                   #converting expression to float 
        else: 
            op1 = stack.pop()
            op2 = stack.pop()
            if token == '+':
                result = op2 + op1
            elif token =='-':
                result = op2 - op1
            elif token == '*':
                result = op2 * op1
            elif token == '/':
                result = op2 / op1
            else:
                print ("enter a known operator")
            
            stack.append(result)
    print (f'result: {stack.pop()}')


eval()

