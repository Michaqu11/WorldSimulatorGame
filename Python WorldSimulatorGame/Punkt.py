import math

class Punkt:

    def __init__(self, x: int = 0, y: int = 0):
        self.x = x
        self.y = y

    def printPunkt(self):
        return str(self.x) + " " + str(self.y)

    def setPunkt(self, p):
        self.x = p.x
        self.y = p.y

    def setX(self, x):
        self.x = x

    def setY(self, y):
        self.y = y

    def getX(self):
        return self.x

    def getY(self):
        return self.y

    def sprwadzCzyTenSam(self, other):
        if other.x == self.x and other.y == self.y:
            return True
        return False

    def getDystans(self, other):
        return math.sqrt(pow(abs(self.x - other.x), 2) + pow(abs(self.y - other.y), 2))

