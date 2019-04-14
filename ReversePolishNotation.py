def is_digit(n):
    try:
        int(n)
        return True
    except ValueError:
        return False


input_string = input()

string = input_string.split(" ")
stack_of_digits = []

bool_ans = 0

if len(string) == 0:
    bool_ans = 1

count = 0
for i in range(len(string)):
    if is_digit(string[i]):
        count += 1
if count == len(string):
    bool_ans = 1
if len(string) == 1 and is_digit(string[0]):
    bool_ans = 0

for i in range(len(string)):
    if is_digit(string[i]) and len(stack_of_digits) >= 0: #if it's a digit
        if int(string[i]) <= 100 and int(string[i]) >= -100: 
            stack_of_digits.append(int(string[i])) # add lements to the end
        else:
            bool_ans = 1
    elif string[i] == '+' and len(stack_of_digits) >= 2:
        stack_of_digits.append(stack_of_digits.pop(-2) + stack_of_digits.pop(-1))
    elif string[i] == '-' and len(stack_of_digits) >= 2:
        stack_of_digits.append(stack_of_digits.pop(-2) - stack_of_digits.pop(-1))
    elif string[i] == '*' and len(stack_of_digits) >= 2:
        stack_of_digits.append(stack_of_digits.pop(-2) * stack_of_digits.pop(-1))
    elif string[i] == '/' and len(stack_of_digits) >= 2:
        i = stack_of_digits.pop()
        if i != 0:
            stack_of_digits.append(int(stack_of_digits.pop() / i)) #integer division
        else:
            bool_ans = 1
    elif string[i] == 'x' and len(stack_of_digits) >= 2:
        i = stack_of_digits.pop(-2)
        stack_of_digits.append(i * i + stack_of_digits.pop(-1))
    elif string[i] == 'y' and len(stack_of_digits) >= 1:
        stack_of_digits.append(stack_of_digits.pop(-1) * 2 + 1)
    elif string[i] == 'z' and len(stack_of_digits) >= 3:
        stack_of_digits.append(stack_of_digits.pop(-3) + stack_of_digits.pop(-2) * 2 + stack_of_digits.pop(-1) * 3)
    else:
        bool_ans = 1

if bool_ans != 1 and len(stack_of_digits) == 1:
    print(stack_of_digits[0])
elif bool_ans == 1:
    print("NO")
else:
    print("NO")
