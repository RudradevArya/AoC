with open('Day5input.txt', 'r') as f:
    stack_in_string, instructions = (i.splitlines() for i in f.read().strip('\n').split("\n\n"))
#print(stack_in_string, instructions)


stacks = {int(digit):[] for digit in stack_in_string[-1].replace(" ","")}

#print(stacks)

index = [x for x, char in enumerate(stack_in_string[-1]) if char != " "]

def display():
    for i in stacks:
        print(i, stacks[i])

#display()


def load():
    for s in stack_in_string[:-1]:
        num = 1
        for i in index:
            if s[i] != " ":
                stacks[num].insert(0, s[i])
            num += 1

load()
#display()

def empty():
    for num in stacks:
        stacks[num].clear()

def answer():
    answer = ""
    for s in stacks:
        answer += stacks[s][-1]
    return answer

#empty()
#display()
            
# === MAIN Part 1 ===

for inst in instructions:
    #print(inst)
    inst = inst.replace("move ","").replace("from ","").replace("to ","").split(" ")
    #print(inst)
    inst = [int(i) for i in inst]
    #print(inst)

    crates = inst[0]
    From = inst[1]
    To = inst[2]

    for c in range(crates):
        removed = stacks[From].pop()
        stacks[To].append(removed)

print(answer())


# === 2 ===

empty()
load()

for inst in instructions:
    #print(inst)
    inst = inst.replace("move ","").replace("from ","").replace("to ","").split(" ")
    #print(inst)
    inst = [int(i) for i in inst]
    #print(inst)

    crates = inst[0]
    From = inst[1]
    To = inst[2]

    remove = stacks[From][-crates:]       #finding which crates to remoces
    stacks[From] = stacks[From][:-crates] #removing crates

    for c in remove:
        stacks[To].append(c)                #adding crates
    #print(remove)
#display()
print(answer())