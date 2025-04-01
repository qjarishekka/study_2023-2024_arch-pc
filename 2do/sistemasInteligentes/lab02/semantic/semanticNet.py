from semnet import *

from tostr import tostr
import string



example = GetExampleOf()


#entities
animal = Entity("animal")
fruit = Entity("fruit")
apple = Entity("apple")
human = Entity("human")
livingBeing= Entity("living being")
dog = Entity("dog")
cat = Entity("cat")
meat = Entity("meat")
food = Entity("food")


#relations
eats = Relation("eats", 1)
isa = GetIsA()
isBiggerThan = Relation("is bigger than" , 1)

#facts
Fact(apple, isa, fruit)
Fact(fruit , isa, food)
Fact(meat , isa , food)
Fact(dog , eats , meat)
Fact(cat , eats , meat)
Fact(dog , isa , animal)
Fact(cat , isa, animal)
Fact(animal, isa , livingBeing)
Fact(livingBeing , eats, food)
Fact(dog , isBiggerThan, cat)
Fact(human , isa, livingBeing)
Fact(human, eats , apple)


print("is fruit a food", isa(fruit, food))
print("is a dog an living being?" , isa(dog,livingBeing))
print("is meat a living being?" , isa(meat,livingBeing))
