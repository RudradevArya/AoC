with open("Day4input.txt", 'r') as f:
    lines = f.readlines()
    pairs = [entry.strip() for entry in lines]


# def range(a, b):
#     start_a, end_a = map(int, a.split('-'))
#     #print(a)
#     start_b, end_b = map(int, b.split('-'))
#     #print(b)
#     return start_b <= start_a and end_a <= end_b

# num = 0
# for i in pairs:
#     range1, range2 = i.split(',')
#     if range(range1, range2) or range(range2, range1):
#         num += 1
# num
# print(num)
#ans = 547
# 2-4,6-8

#COPIED PART 2

num = 0
for X in pairs:
    first_range, second_range = X.split(',')
    start_a, end_a = map(int, first_range.split('-'))
    start_b, end_b = map(int, second_range.split('-'))
    if start_a in range(start_b, end_b+1) or end_a in range(start_b, end_b+1) or  start_b in range(start_a, end_a+1) or end_b in range(start_a, end_a+1):
        num += 1
num  
print(num)
#ans = 843