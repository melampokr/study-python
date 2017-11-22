import rps

user_rps = input('choose the rock or paper or scissors >')
computer_rps = rps.random_rps()

print('user : {}, computer : {}'.format(user_rps, computer_rps))

if (user_rps == rps.ROCK and computer_rps == rps.ROCK) or (user_rps == rps.PAPER and computer_rps == rps.PAPER) or (user_rps == rps.SCISSORS and computer_rps == rps.SCISSORS):
    print('DRAW!!')
elif (user_rps == rps.ROCK and computer_rps == rps.SCISSORS) or (user_rps == rps.PAPER and computer_rps == rps.ROCK) or (user_rps == rps.SCISSORS and computer_rps == rps.PAPER):
    print('USER WINS')
elif (computer_rps == rps.ROCK and user_rps == rps.SCISSORS) or (computer_rps == rps.PAPER and user_rps == rps.ROCK) or (computer_rps == rps.SCISSORS and user_rps == rps.PAPER):
    print('COMPUTER WINS')
else:
    print('INVALID USER INPUT')



