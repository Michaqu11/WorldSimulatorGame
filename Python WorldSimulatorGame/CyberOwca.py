import sys
import random

from Punkt import Punkt
from Zwierze import Zwierze


class CyberOwca(Zwierze):

    def __init__(self, polozenie, swiat):
        super(CyberOwca, self).__init__(11, 4, 'Ⓒ', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Cyber Owca"

    def akcja(self):
        self.wiek += 1
        self.ogolneInformacje()
        nowePolozenie = self.wylosujPunktObokDlaCyberOwcy()
        if self.swiat.sprawdzCzyPolePuste(nowePolozenie.getX(), nowePolozenie.getY()):
            self.Ruch(nowePolozenie)
        else:
            ruch = True
            if self.swiat.zwrocOrganizmZPola(nowePolozenie).getZycie():
                self.kolizja(self.swiat.zwrocOrganizmZPola(nowePolozenie), True, ruch)
            if self.getZycie() and ruch:
                org = self.swiat.zwrocOrganizmZPola(nowePolozenie)
                if org is not None and org.getZycie() is False or org is None:
                    self.Ruch(nowePolozenie)

    def wylosujPunktObokDlaCyberOwcy(self):
        nowePolozenie = Punkt()
        zapamietajOrganizm = None
        max = sys.maxsize
        for organizm in self.swiat.organizmy:
            if organizm.getZycie() and organizm.getZnak() == "B" and self.polozenie.getDystans(organizm.polozenie) < max:
                max = self.polozenie.getDystans(organizm.polozenie)
                zapamietajOrganizm = organizm

        if zapamietajOrganizm is not None:
            if self.polozenie.getY() > zapamietajOrganizm.polozenie.getY():
                nowePolozenie.setX(self.polozenie.getX())
                nowePolozenie.setY(self.polozenie.getY() - 1)
            elif self.polozenie.getY() < zapamietajOrganizm.polozenie.getY():
                nowePolozenie.setX(self.polozenie.getX())
                nowePolozenie.setY(self.polozenie.getY() + 1)
            elif self.polozenie.getX() > zapamietajOrganizm.polozenie.getX():
                nowePolozenie.setX(self.polozenie.getX() - 1)
                nowePolozenie.setY(self.polozenie.getY())
            elif self.polozenie.getX() < zapamietajOrganizm.polozenie.getX():
                nowePolozenie.setX(self.polozenie.getX() + 1)
                nowePolozenie.setY(self.polozenie.getY())
        else:
            e = False
            while (e is False):
                x = random.randint(0, 3)
                if x == 0 and self.polozenie.getY() != 0:
                    nowePolozenie.setX(self.polozenie.getX())
                    nowePolozenie.setY(self.polozenie.getY() - 1)
                    e = True
                elif x == 1 and self.polozenie.getY() != self.swiat.height - 1:
                    nowePolozenie.setX(self.polozenie.getX())
                    nowePolozenie.setY(self.polozenie.getY() + 1)
                    e = True
                elif x == 2 and self.polozenie.getX() != 0:
                    nowePolozenie.setX(self.polozenie.getX() - 1)
                    nowePolozenie.setY(self.polozenie.getY())
                    e = True
                elif x == 3 and self.polozenie.getX() != self.swiat.width - 1:
                    nowePolozenie.setX(self.polozenie.getX() + 1)
                    nowePolozenie.setY(self.polozenie.getY())
                    e = True

        return nowePolozenie