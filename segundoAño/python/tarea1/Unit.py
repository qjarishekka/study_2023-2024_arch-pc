from abc import ABC, abstractmethod

def getdirection(command):
    
    if(command.find('s') != -1 and command.find('a') != -1):
        return (-1,-1)
    if(command.find('s') != -1 and command.find('d') != -1):
        return (1,-1)
    if(command.find('w') != -1 and command.find('a') != -1):
        return (-1,1)
    if(command.find('w') != -1 and command.find('d') != -1):
        return (1,1)    





class Unit(ABC):

    @abstractmethod
    def move(self):
        pass 

    @abstractmethod
    def out(self):
        pass   

    @abstractmethod
    def damage(self):
        pass

    @abstractmethod
    def getpoints(self):
        pass

    # @abstractmethod
    # def aretherecoins(self):
    #     pass



class Rook(Unit):

    icon = "■"


    def __init__(self, field):
        self.field = field
        self.pos = (1,1)
        self.score = 0
        self.health = 3

    def out(self):
        
        for i in range(self.field.size[1]):
            line = ''
            for j in range(self.field.size[0]):
                if(j, i) == self.pos:
                    line += self.icon + ' '
                else:
                    line += self.field.matrix[i][j] + ' '
            print(line)
        print("твоя жизнь: " + str(self.health))
        print("твой счет:" + str(self.score))

    def damage(self):

        if self.field.matrix[self.pos[1]][self.pos[0]] == '*':
            self.health -= 1

    def getpoints(self):

        if self.field.matrix[self.pos[1]][self.pos[0]] == '©':
            self.score += 1
            self.field.matrix[self.pos[1]][self.pos[0]] = '_'

    def move(self, command):

    
        x, y = self.pos
        if command == 'w' or command == 'up':
            y = y - 1
        if command == 's' or command == 'down':
            y = y + 1
        if command == 'a' or command == 'left':
            x = x - 1
        if command == 'd' or command == 'right':
            x = x + 1

        if self.field.matrix[y][x] == '▓':
            return

       
        self.pos = (x,y)
        


        self.damage()
        self.getpoints()

    # def aretherecoins(self):
    #     for i in range(self.field.size[1]):
    #         for j in range(self.field.size[0]):
    #             if(self.field.matrix == '©'):
    #                 return True
        
    #     return False

class RookBuffed(Rook):

    icon = '█' 

    def move(self, command):
        x, y = self.pos
        if command == 'w' or command == 'up':
            y = y - 2
        if command == 's' or command == 'down':
            y = y + 2
        if command == 'a' or command == 'left':
            x = x - 2
        if command == 'd' or command == 'right':
            x = x + 2

        if self.field.matrix[y][x] == '▓':
            return

       
        self.pos = (x,y)
        


        self.damage()
        self.getpoints()    




class BishopWhite(Unit):
    icon = '╬'
    pos = (1,1)

    def __init__(self, field):
        self.field = field

        self.score = 0
        self.health = 3


    def out(self):
        for i in range(self.field.size[1]):
            line = ''
            for j in range(self.field.size[0]):
                if(j, i) == self.pos:
                    line += self.icon + ' '
                else:
                    line += self.field.matrix[i][j] + ' '
            print(line)


    def move(self, command):
        x, y = self.pos
        if getdirection(command) == (-1,-1) :
            y = y +1
            x = x -1
        if getdirection(command) == (1,-1) :
            y = y +1
            x = x + 1
        if getdirection(command) == (-1,1) :
            y = y - 1
            x = x - 1
        if getdirection(command) == (1,1) :
            y = y - 1
            x = x + 1

        if self.field.matrix[y][x] == '▓':
            return

        
        self.pos = (x,y)
        self.damage()
        self.getpoints()


    def damage(self):

        if self.field.matrix[self.pos[1]][self.pos[0]] == '*':
            self.health -= 1

    def getpoints(self):

        if self.field.matrix[self.pos[1]][self.pos[0]] == '©':
            self.score += 1
            self.field.matrix[self.pos[1]][self.pos[0]] = '_'


class BishopBlack(BishopWhite):
    icon = "╩"
    pos = (1,2)