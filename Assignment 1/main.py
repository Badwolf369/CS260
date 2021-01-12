from random import randint as rand

# I didnt have time to figure out how to do this in C++

class Marble():
    def __init__(self, id, color, isShooter):
        self.id = id
        self.color = (color[0], color[1], color[2])
        self.isShooter = isShooter
    
    def getInfo(self):
        if self.isShooter:
            return f"Shooter #{self.id}, color: ({self.color[0]}, {self.color[1]}, {self.color[2]})"
        else:
            return f"Marble #{self.id}, color: ({self.color[0]}, {self.color[1]}, {self.color[2]})"


class Bag():
    def __init__(self):
        self.curID = 0
        self.marbles = []

    def putMarble(self):
        self.marbles.append(Marble(self.curID, [rand(0, 255), rand(0, 255), rand(0, 255)], rand(0, 1)))
        self.curID += 1
        print("Marble successfully created")

    def grabMarble(self):
        if len(self.marbles) > 0:
            grabbed = self.marbles.pop(rand(0, len(self.marbles)))
            print(grabbed.getInfo())
        else:
            print("No marbles to grab")
    
    def dumpMarbles(self):
        if len(self.marbles) > 0:
            for i in self.marbles:
                print(i.getInfo())
            self.marbles = []
        else:
            print("Nothing came out of the bag")


def main():
    bag = Bag()

    while True:
        print("What would you like to do?")
        inp = int(input("add marble(1) grab marble(2) dump marbles(3) close(-1)-->:"))
        if inp == -1:
            return
        elif inp == 1:
            bag.putMarble()
        elif inp == 2:
            bag.grabMarble()
        elif inp == 3:
            bag.dumpMarbles()
        else:
            print("I do not understand")

if __name__ == "__main__":
    main()

