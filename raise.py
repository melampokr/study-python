def rps(mine, yours):
    allowed = ['rock', 'paper', 'scissors']
    if mine not in allowed:
        raise ValueError
    if yours not in allowed:
        raise ValueError

try:
    rps('scissors', 'rok')
except ValueError:
    print("Invalid Value")
