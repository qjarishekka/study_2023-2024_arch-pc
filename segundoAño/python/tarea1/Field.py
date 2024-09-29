import random

class Field:

    def __init__(self, size):  #constructor
        self.size = size
        self.matrix =[]       #[['_']*size[0]]*size[1]
        self.gen()


    def out(self):
        for row in self.matrix:
            line = ''
            for symbol in row:
                line += symbol + ' '
            
            print(line)


    def gen(self):
        for i in range(self.size[1]):
            self.matrix.append([])

            for j in range(self.size[0]):
                rnd = random.randint(1,100)
                if rnd <= 60:    
                    self.matrix[i].append('_')
                elif rnd <= 75:
                    self.matrix[i].append('▓')
                elif rnd <= 90:
                    self.matrix[i].append('©')
                else:
                        self.matrix[i].append('*')

        for i in range(self.size[1]):
            self.matrix[0][i] = "▓"

        for i in range(self.size[0]):
            self.matrix[i][0] = "▓"

        for i in range(self.size[1]):
            self.matrix[self.size[0]- 1][i] = "▓"

        for i in range(self.size[0]):
            self.matrix[i][self.size[1] - 1] = "▓"
