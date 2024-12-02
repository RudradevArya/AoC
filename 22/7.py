with open('Day7input.txt', 'r') as f:
    lines = [l.strip() for l in f.readlines()]
    print(lines)

path = "/"
dir = {"/":0}

for i in lines:
    if i[0] == "$":

        if i[2:4] == "ls":
            pass
        elif i[2:4] == "cd":
            if i[5:6] == "/":
                path = "/"
            elif i[5:7] == "..":
                path = path[:path.rfind("/")] #rfind gives the last occurance of that thing

            else:
                dir_name = i[5:]
                path = path + "/" + dir_name
                dir.update({path:0})

    elif i[0:3] == "dir":
        pass


    else:
        size = int(i[:i.find(" ")])

        depth = path
        for i in range(path.count("/")):
            dir[depth] += size
            depth = depth[:depth.rfind("/")]


# for d in dir:
#     print(d, dir[d])

total = 0

limit = 30000000 - (70000000 - dir["/"])
#print(limit) #= 6728267
final = []


for x in dir:
    if dir[x] <= 100000:
        total += dir[x]

    if limit <= dir[x]:
        final.append(dir[x])
    smallest_dir = min(final)

print(total)
#1390824 part 1 answer

print(smallest_dir)
#7490863 part 2 answer





