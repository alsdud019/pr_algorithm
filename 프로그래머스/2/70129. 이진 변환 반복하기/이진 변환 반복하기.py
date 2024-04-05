def change(num):
    
    answer=[]
    
    while num>0:
        mok=num//2
        remain=num%2
        
        answer.append(remain)
        num=mok
        
    answer.reverse()
    return answer
    
    
def solution(s):
    answer = []
    
    zero_count=0

    string=s
    total_count=0
    
    while len(string)>1:
        one_count=0
        print(string)
        for i in range(0, len(string)):

        #      0일때 
            if string[i]=="0":
                zero_count+=1
        #      1일때 
            else :
                one_count+=1
        # if one_count==1:
        #     break
            
        plus_string=""
        # print(one_count)
        for i in change(one_count):
            plus_string+=str(i)
        string=plus_string
        # print(len(string))
        
        # print(string)
        total_count+=1
    # total_count+=1


    # print(total_count)
    # print(zero_count)
    answer.append(total_count)
    answer.append(zero_count)
            
            
    return answer