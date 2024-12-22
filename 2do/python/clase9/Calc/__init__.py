if __name__ == '__main__':
    from Task import Task
else:
    from Calc.Task import Task

def test1(comments=False):
    test = Task('1+1')
    print(test)
    #assert test == 2
    if comments:
        print('test 1.1 completed')
    test = Task('2*3')
    #assert test == 6
    if comments:
        print('test 1.2. completed')

if __name__ == '__main__':
    print('this is init of Calc module!')
    test1()
