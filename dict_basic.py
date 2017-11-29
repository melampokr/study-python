wintable = {
        'scissors' : 'paper',
        'rock' : 'scissors',
        'paper' : 'rock'
        }

def rps(mine,yours):
    if mine == yours:
        return 'draw'
    elif wintable[mine] == yours:
        return 'win'
    else:
        return 'lose'

result = rps('scissors', 'rock')
print(result)

