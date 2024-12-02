# with open('Day2input.txt', 'r') as input:
#     lines = input.readlines()
#     round = [i.strip() for i in lines]

# # with open('Day2input.txt') as input:
# #     round = [i for i in input.read().strip().split("\n")]

# #print(round)

# round_points = {'Win': 6, 'Draw' : 3, 'Lose' : 0}
# shape_points = {'Rock' : 1, 'Paper' : 2 , 'Scissors' : 3}
# choice = {'A' : 'Rock', 'B' : 'Paper', 'C' : 'Scissors', 'X' : 'Rock', 'Y' : 'Paper', 'Z' : 'Scissors'}

# def points_per_round(round_string):
#     opponent_shape = choice[round_string[0]]
#     our_shape = choice[round_string[2]]

#     if opponent_shape == our_shape:
#         return round_points['Draw'] + shape_points[our_shape]
#     elif (opponent_shape, our_shape) in [('Paper', 'Rock'), ('Rock', 'Scissors'), ('Scissors', 'Paper')]:
#         return round_points['Lose'] + shape_points[our_shape]
#     else:
#         return round_points['Win'] + shape_points[our_shape]

# #points_per_round(round_string)
# sum([points_per_round(round_string) for round_string in round])



#from Kuku

List = [line.rstrip() for line in open('Day2input.txt')]
Score = 0

# Dict = {'A X': 4 , 'B X': 1 , 'C X':7,
#         'A Y':8 , 'B Y':5 , 'C Y':2,          #part1
#         'A Z':3 , 'B Z':9 , 'C Z':6}

Dict = {'A X': 3 , 'B X': 1 , 'C X':2,       #part2
        'A Y':4 , 'B Y':5 , 'C Y':6,
        'A Z':8 , 'B Z':9 , 'C Z':7}

for i in List:
    Score += Dict[i]
    
print(Score)
