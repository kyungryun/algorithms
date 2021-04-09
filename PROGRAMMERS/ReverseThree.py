def solution(n):
    three = ''
    
    while(n>2):
        three += str(n%3)
        n = n//3
    
    three += str(n)
    answer = 0
    for i in range(len(three)):
        answer += int(three[-(i+1)])*(3**i)
    return answer
