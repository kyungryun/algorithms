def solution(x, y):
    # Your code here
    M, F = int(x), int(y)
    gen = 0
    
    while(M > 1 or F > 1):
        if(M%2 == 0 and F%2 == 0) or M < 1 or F < 1:
            return "impossible"
        if(M < F):
            gen += F/M
            F %= M
        else:
            gen += M/F
            M %= F
            
        if(M == 0 or F == 0):
            gen -= 1
    return str(gen)
