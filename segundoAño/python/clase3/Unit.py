class Unit:
    def __init__(self, field):
        self.field = field
        self.pos = (0,0)
        #self.score
        self.icon = '&'
    
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
        if command == 'w' or command == 'up':
            y = y - 1
        if command == 's' or command == 'down':
            y = y + 1
        if command == 'a' or command == 'left':
            x = x - 1
        if command == 'd' or command == 'right':
            x = x + 1
        self.pos = (x,y)

class Jumper(Unit):
    
    def move(self,command):
        x, y = self.pos
        if command == 'w' or command == 'up' : #command in { ' w' , 'up'}
            y = y - 2
        if command == 's' or command == 'down' : #command in { ' w' , 'up'}
            y = y + 2
        if command == 'a' or command == 'left' : #command in { ' w' , 'up'}
            x = x - 2
        if command == 'd' or command == 'right' : #command in { ' w' , 'up'}
            x = x + 2
        
        self.pos = (x, y)