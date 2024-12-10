def factorial(n):
    f = 1
    for i in range(1,n+1):
        f *= i
    return f


def permutation(n):
    return factorial(n)

def combination(n ,k):
    return factorial(n)/ (factorial(k) * factorial(n-k))

def test(comments=False):
    assert permutation(4) == 24
    if comments:
        print('test 1.1 completed')
    assert combination(5,3) == 10
    if comments:
        print('test 1.2 completed')

if __name__ == '__main__':
    test()