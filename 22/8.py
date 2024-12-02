with open('Day8input.txt', 'r') as f:
    data =  [row.strip() for row in f.readlines()]

#print(data)
row = len(data)
col = len(data[0])

edges = (row * 2) + ((col - 2) * 2)
total = edges
scenic_scores = []

for i in range(1,row-1):
    for j in range(1, col-1):
        tree = data[i][j]

        left = [data[i][j-x] for x in range(1, j+1) ]
        right = [data[i][j+x] for x in range(1, col-j) ]
        up = [data[i-x][j] for x in range(1, i+1) ]
        down = [data[i+x][j] for x in range(1, row-i) ]

        # if max(left) < tree or max(right) < tree or max(up) < tree or max(down) < tree:
        #     total += 1  #part 1

        # part 2
        scenic = 1
        for lst in (left, right, up, down):
            counter = 0
            for i in range(len(lst)):
                if lst[i] < tree:
                    counter += 1
                elif lst[i] >= tree:
                    counter += 1
                    break
                

            scenic *= counter  
        scenic_scores.append(scenic)              

print(total) 
#ans part 1 = 1546
print(max(scenic_scores))
#ans part 2 = 519064

