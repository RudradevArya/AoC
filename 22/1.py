with open('Day1input.txt','r') as input:
    lines = input.readlines()
    calorie = [i.strip() for i in lines]


sum = []
current = 0
for i in calorie:
    if i != '':
        current += int(i)
    elif i == '':
        sum.append(current)
        current = 0

sum.append(current)
print(max(sum))
#Ans = 64929

#Part 2
res = 0
sum.sort(reverse=True)
#print(sum[0]+sum[1]+sum[2])
for i in range (0,3):
    res += sum[i]
print(res)
#Ans = 193697
