from logic import *

'''
# Sentence: "If it's rains, it's wet".
def rainWet():
    Rain = Atom('Rain') # whether it's raining
    Wet = Atom('Wet') # whether it's wet
    return Implies(Rain, Wet)

# Sentence: "There is a light that shines."
def lightShines():
    def Light(x): return Atom('Light', x)    # whether x is lit
    def Shines(x): return Atom('Shines', x)  # whether x is shining
    return Exists('$x', And(Light('$x'), Shines('$x')))
'''
# Defining Parent in terms of Child.
def parentChild():
    def Parent(x, y): return Atom('Parent', x, y)  # whether x has a parent y
    def Child(x, y): return Atom('Child', x, y)    # whether x has a child y
    return Forall('$x', Forall('$y', Equiv(Parent('$x', '$y'), Child('$y', '$x'))))


print ('\nПример с погодой')
Rain = Atom('Rain')           # Shortcut
Wet = Atom('Wet')             # Shortcut
kb = createResolutionKB()     # Create the knowledge base
print(kb.ask(Wet))                   # Prints "I don't know."
print(kb.ask(Not(Wet)))              # Prints "I don't know."
print(kb.tell(Implies(Rain, Wet)))   # Prints "I learned something."
print(kb.ask(Wet))                   # Prints "I don't know."
print(kb.tell(Rain))                 # Prints "I learned something."
kb.dump()


'''
"Яблоко красное и ароматное."
"Если яблоко красное, то яблоко вкусное."
Докажем утверждение, что "яблоко вкусное". 
'''
print ('\nПример с яблоком')
kb2 = createResolutionKB()
Red = Atom('Apple is red')  #красное
Flavored = Atom('Apple is flavored')  #ароматное
Tasty = Atom('Apple is tasty')  #вкусное
print(kb2.tell(And(Red, Flavored)))
print(kb2.tell(Implies(Red, Tasty)))
kb2.dump()
print(kb2.ask(Tasty))

#Задание 2 придумать свои примеры пропозициональной логики


#Возьмем высказывание «Каждый человек смертен. Конфуций — человек».
#Надо показать, что «Конфуций смертен».
print ('\nПример: Конфуций смертен')
kb2 = createResolutionKB()
konf = Constant('конфуций')
def Mortal(x): return Atom('Mortal', x)
def Human(x): return Atom('Human', x)
print(kb2.tell(Human(konf)))
print(kb2.tell(Forall('$x', Implies(Human('$x'), Mortal('$x'))) ) )
kb2.dump()
print(kb2.ask(Mortal(konf)))


#Если студент прошел курс и курс содержит концепт, то студент знает концепт
print ('\nПример: Про знания стуентов')
kb2 = createResolutionKB()
#kb2 = createModelCheckingKB()

vasya = Constant('вася')
petya = Constant('петя')
alena = Constant('алена')
def Student(x): return Atom('Student', x)
F1 = AndList([\
                Student(vasya),\
                Student(petya),\
                Student(alena)\
            ])

ai = Constant('ии')  # Artificial intelligence
deq = Constant('ду')  # Differential equation
def Course(y): return Atom('Course', y)
F2 = AndList([Course(ai), Course(deq)])

def Takes(x, y): return Atom('Takes', x, y)
F3 = AndList([Takes(vasya, ai), \
              Not(Takes(vasya, deq)), \
              Takes(petya, deq),\
              Not(Takes(petya, ai)), \
              Takes(alena, ai), Takes(alena, deq)])

def Takes2(x, y): return Atom('Takes2', x, y)
F4 = AndList([Takes2(vasya, ai), \
              Not(Takes2(vasya, deq)), \
              Takes2(petya, deq),\
              Not(Takes2(petya, ai)), \
              Takes2(alena, ai), Takes2(alena, deq)])


#concepts
ml = Constant('машинное обучение')  # machine learning
knowl = Constant('представление знаний')  # knowledge representation
cauchy = Constant('теорема Коши')  # Cauchy's theorem
euler = Constant('теорема Эйлера')  # Euler's equation
def Concept(z): return Atom('Concept', z)
F5 = AndList([Concept(ml), \
              Concept(knowl), \
              Concept(cauchy), \
              Concept(euler)\
              ])


def Covers(y, z): return Atom('Covers', y, z)
F6 = AndList([Covers(ai, ml), \
              Covers(ai, knowl), \
              Not(Covers(ai, cauchy)), \
              Not(Covers(ai, euler)), \
              Covers(deq, cauchy),
              Covers(deq, euler), \
              Not(Covers(deq, ml)),
              Not(Covers(deq, knowl)) \
             ])

def Knows(x, z): return Atom('Knows', x, z)


F7 = Forall('$x', \
            Forall('$y', \
                   Forall('$z',
                            Implies(AndList([Student('$x'), Course('$y'), Concept('$z'), Takes('$x', '$y'), Covers('$y', '$z')]), \
                                    Knows('$x', '$z') ),

                         )
                   )
            )


F8 = Forall('$x', \
            Forall('$y', \
                   Forall('$z',
                            Implies(AndList([Student('$x'), Course('$y'), Concept('$z'), Not(Takes2('$x', '$y')), Covers('$y', '$z')]), \
                                    Not(Knows('$x', '$z')) ),
                         )
                   )
            )

'''
F7 = Forall('$x', \
            Forall('$y', \
                   Forall('$z',
                            Implies(AndList([Takes('$x', '$y'), Covers('$y', '$z')]), \
                                    Knows('$x', '$z') ),

                         )
                   )
            )


F8 = Forall('$x', \
            Forall('$y', \
                   Forall('$z',
                            Implies(AndList([Not(Takes2('$x', '$y')), Covers('$y', '$z')]), \
                                    Not(Knows('$x', '$z')) ),
                         )
                   )
            )
'''

formulas = AndList([F1, F2, F3, F4, F5, F6, F7])
print(kb2.tell (formulas))
print(kb2.tell (F8))
kb2.dump()


print ('Does Petya know machine learning? =', kb2.ask (Knows(petya, ml)) )
print ('Does Petya know Cauchy theorem? =',kb2.ask (Knows(petya, cauchy)) )
print ('Does Vasya know machine learning? =', kb2.ask (Knows(vasya, ml)) )
print ('Does Vasya know Cauchy theorem? = ', kb2.ask (Knows(vasya, cauchy)) )
print ('Does Alena know machine learning? =', kb2.ask (Knows(alena, ml)) )
print ('Does Alena know Cauchy theorem? = ', kb2.ask (Knows(alena, cauchy)) )


#Задание 4 придумать свои примеры логики предикатов


print ('\nПример с пазлом')
def TellTruth(x): return Atom('TellTruth', x)
def CrashedServer(x): return Atom('CrashedServer', x)

john = Constant('john')
susan = Constant('susan')
nicole = Constant('nicole')
mark = Constant('mark')

# We provide the formula for fact 0 here.

# We provide the formula for fact 0 here.
F1 = Equiv(TellTruth(john), Not(CrashedServer(john)))
# You should add 5 formulas, one for each of facts 1-5.
# BEGIN_YOUR_CODE (our solution is 11 lines of code, but don't worry if you deviate from this)

F2 = Equiv(TellTruth(susan), CrashedServer(nicole))
F3 = Equiv(TellTruth(mark), CrashedServer(susan))
F4 = Equiv(TellTruth(nicole), Not(TellTruth(susan)))
F5 = Exists('$y', Forall('$x', Equiv( TellTruth('$x'), Equals('$x', '$y') )  ) )
F6 = Exists('$y', Forall('$x', Equiv( CrashedServer('$x'), Equals('$x', '$y') )  ) )
formulas = AndList([F1, F2, F3, F4, F5, F6])
kb2 = createModelCheckingKB()     # Create the knowledge base.
print(kb2.tell(formulas))
#kb2.dump()
#query = CrashedServer('$x')
print (kb2.ask( CrashedServer('$x') ))
