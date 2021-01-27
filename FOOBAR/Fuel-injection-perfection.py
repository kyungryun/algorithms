def solution(n):
    # Your code herei
    n = int(n)
    cnt = 0
    
    while n > 1:
        if n & 1 == 1:
            if n != 3 and ((n+1) % 4 == 0):
                n += 1
            else:
                n -= 1
        else:
            n>>=1
            
        cnt+=1
        
    return cnt
