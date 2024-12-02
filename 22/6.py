with open('Day6input.txt', 'r') as f:
    line = f.read()
    #print(lines)

#PART 1

for i in range(4, len(line)):
    #ans = line[(i-4):i]
    #print(ans ,i)

    ans = set(line[(i-4):i])
    #print(ans ,i)
    if len(ans) == 4:
        print(i)
        break


# for part 2 just change 4 to 14
# part 1 anser 1198
#part 2 answer 3120