from Field import * 
from Unit import *


field = Field( (12,12) )

field.out()

print('///' * field.size[0])

print(chr(27)+ "[33m" + "\n""///////////////////////" "\n" "///////МОЯ ИГРА////////" "\n" "///////////////////////" "\n" )

print("выбери своего персонажа: ")

print(chr(27)+ "[36m" + "Rook \t"  + chr(27)+ "[35m" + "RookBuffed \t"  + chr(27)+ "[34m" + "BishopWhite \t" + chr(27)+ "[32m" + "BishopBlack \t"  )

print(chr(27)+ "[37m")



choosedCaracter = input()

while(choosedCaracter != 'Rook' or choosedCaracter != 'BishopWhite' or choosedCaracter != 'RookBuffed' or choosedCaracter != 'BishoBlack'):

    if(choosedCaracter == 'Rook' ):
        print(chr(27)+ "[36m")
        player = Rook(field)
        player.out()
        break

    if(choosedCaracter == 'BishopWhite'):
        print(chr(27)+ "[34m")
        player = BishopWhite(field)
        player.out()      
        break

    if(choosedCaracter == 'RookBuffed'):
        print(chr(27)+ "[35m")
        player = RookBuffed(field)
        player.out()      
        break

    if(choosedCaracter == 'BishopBlack'):
        print(chr(27)+ "[32m")
        player = BishopBlack(field)
        player.out()      
        break

    choosedCaracter = input()


command = input()

while(command != 'exit'):
    
    player.move(command)
    player.out()
    print('//'*field.size[0])

    if player.health == 0:
        break


    command = input()

print( chr(27)+ "[31m" + "\n""//////////////////////" "\n" "////ИГРА ОКОНЧЕНА/////" "\n" "//////////////////////" "\n" )

print("ТВОЙ СЧЕТ: " + str( player.score ))




