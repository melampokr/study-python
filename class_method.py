class Human():
    def create(name, weight):
        person = Human()
        person.name = name
        person.weight = weight
        return person

    def eat(person):
        person.weight += 0.1
        print("{}가 먹어서 {}kg이 되었습니다.".format(person.name, person.weight))

    def walk(person):
        person.weight -= 0.1
        print("{}가 걸어서 {}kg이 되었습니다.".format(person.name, person.weight))


person = Human.create("철수", 60.5)
person.eat()
person.walk()
