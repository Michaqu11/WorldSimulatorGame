import random

from Roslina import Roslina


class Mlecz(Roslina):

    def __init__(self, polozenie, swiat):
        super(Mlecz, self).__init__(0, 0, 'M', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Mlecz"

    def akcja(self):
        self.wiek += 1
        self.ogolneInformacje()
        i = 0
        while True:
            i += 1
            x = random.randint(0, 9)
            if x == 0:
                self.rozprzestrzenianie()
                break
            if i == 3:
                break