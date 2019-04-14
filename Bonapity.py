testcases = int(input())
str2 = ""
str3 = ""

for i in range(testcases):
    str1 = input()

    counter = 0
    if " " in str1:
        for i in range(len(str1)):
            if str1[i] == " ":
                str2 = str1[0:i].lower()
                str3 = str1[i+1:len(str1)].lower()
    else:
        str2 = str1
        str3 = input()

    if len(str2) == len(str3):
        for i in range(len(str2)):
            
            if str2[i] != str3[i]:
                if str2[i] == 'b' or str2[i] == 'p' or str2[i] == 'B' or str2[i] == 'P':
                    if str3[i] == 'b' or str3[i] == 'p' or str3[i] == 'B' or str3[i] == 'P':
                        counter += 1
                elif str2[i] == 'e' or str2[i] == 'i' or str2[i] == 'E' or str2[i] == 'I':
                    if str3[i] == 'e' or str3[i] == 'i' or str3[i] == 'E' or str3[i] == 'I':
                        counter += 1
            if str2[i] == str3[i]:
                    counter += 1

       
    if counter == len(str2):
        print("Yes")
    else:
        print("No")
        
    
