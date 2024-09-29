from Field import * 
from Unit import *

print('hello')
 
field = Field( (10,20))

field.out()

print('///' * field.size[0])

player = Jumper(field)
player.out()

command = input()

while(command != 'exit'):
    
    player.move(command)
    player.out()
    print('//'*field.size[0])
    command = input()