def is_num(N):
    flag = 0
    for i in N:
        if i == " ":
            flag = 1
    if flag == 1:
        return False
    else:
        return True


T = int(input())

for i in range(T):
    listNo = []
    N = 0
    R = 0
    counter = 0
    val = 0
    numspace = 0
    summ = 0
    string = input()
    for i in range(len(string)):
        if string[i] == " ":
            N = string[0:i]
            R = string[i+1:len(string)]
    
    string2 = input()
    for i in range(len(string2)):
        if string2[i] == " ":
            val = string2[counter:i]
            listNo.append(val)
            counter = i+1
            numspace += 1
            
        
        if i+1 == len(string2):
            val = string2[counter:i+1]
            listNo.append(val)
           # print(listNo)
    if is_num(N) == True:
        if numspace + 1 == int(N):
            for i in range(int(N)):
                summ += int(listNo[i])
        if (summ + 1500) == int(R):
            print("Correct")
        else:
            print("Bug")