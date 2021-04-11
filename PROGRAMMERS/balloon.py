def solution(a):
    answer = 2
    left = a[0]
    right = a[-1]
    
    for i in range(1, len(a)-1):
        if left > a[i]:
            answer += 1
            left = a[i]
        if right > a[-1-i]:
            answer += 1
            right = a[-1-i]
    
    return answer if left != right else answer-1
