from Organizm import Organizm
from Zwierze import Zwierze
from Punkt import Punkt
import random

class Antylopa(Zwierze):

    def __init__(self, polozenie, swiat):
        super(Antylopa, self).__init__(4, 4, 'A', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Antylopa"

    def akcja(self):
        self.wiek += 1
        nowePolozenie = self.wylosujPunktDlaAntylopy()
        self.ogolneInformacje()
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

    def kolizja(self, other: Organizm, atakujacy, ruch):
        if other.getZycie():
            if type(self) == type(other):
                self.rozmnazanie()
            elif self.getSila() > other.getSila() or (self.getSila() == other.getSila() and atakujacy):
                other.kolizja(self, False, ruch)
            else:
                x = random.randint(0, 1)
                nowy = self.znajdzWolnyPunktObok(self.polozenie)
                if x == 0 and not self.polozenie.sprwadzCzyTenSam(nowy):
                    self.swiat.dodajInformacje(" A tu nagle antylopa z punktu: " + self.polozenie.printPunkt() + " zrobila unik! i ")
                    #print(" A tu nagle antylopa z punktu: " + self.polozenie.printPunkt() + " zrobila unik! i ", end='')
                    self.Ruch(nowy)
                elif self.swiat.getPrzerwij() < 2:
                    self.swiat.setPrzerwij(self.swiat.getPrzerwij() + 1)
                    other.kolizja(self, False, ruch)
                else:
                    self.zabojczeInformacjeDlaZwierzat(other)
                    self.setZycie(False)


    def wylosujPunktDlaAntylopy(self):
        nowePolozenie = Punkt()
        e = False
        while (e is False):
            x = random.randint(0, 7)
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
            elif x == 4 and self.polozenie.getY() - 1 > 0:
                nowePolozenie.setX(self.polozenie.getX())
                nowePolozenie.setY(self.polozenie.getY() - 2)
                e = True
            elif x == 5 and self.polozenie.getY() + 1 < self.swiat.height - 1:
                nowePolozenie.setX(self.polozenie.getX())
                nowePolozenie.setY(self.polozenie.getY() + 2)
                e = True
            elif x == 6 and self.polozenie.getX() - 1 > 0:
                nowePolozenie.setX(self.polozenie.getX() - 2)
                nowePolozenie.setY(self.polozenie.getY())
                e = True
            elif x == 7 and self.polozenie.getX() + 1 < self.swiat.width - 1:
                nowePolozenie.setX(self.polozenie.getX() + 2)
                nowePolozenie.setY(self.polozenie.getY())
                e = True

        return nowePolozenie