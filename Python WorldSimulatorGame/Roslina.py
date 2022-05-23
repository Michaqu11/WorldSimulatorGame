from Organizm import Organizm
from Punkt import Punkt
import random


class Roslina(Organizm):

    def __init__(self, sila, inicjatywa, znak, wiek, zycie, swiat, polozenie):
        super(Roslina, self).__init__(sila, inicjatywa, znak, wiek, zycie, swiat, polozenie)

    def akcja(self):
        self.wiek += 1
        self.ogolneInformacje()
        x = random.randint(0, 9)
        if x == 0:
            self.rozprzestrzenianie()

    def kolizja(self, other: Organizm, atakujacy, ruch):
        self.zabojczeInformacjeDlaRoslin(other, self)
        # print(" " + other.getNazwaOrganizmu() + " zjadl -> " + self.getNazwaOrganizmu())
        self.setZycie(False)

    def rozprzestrzenianie(self):
        miejsceUrodzenia = self.znajdzWolnyPunktObok(self.polozenie)

        if self.polozenie.sprwadzCzyTenSam(miejsceUrodzenia) is False:
            self.swiat.dodajOrganizm(self.getZnak(), miejsceUrodzenia)
            #print(" Rozprzestrzenia sie! Powstaje nowa " + self.getNazwaOrganizmu() + " na polu: " + miejsceUrodzenia.printPunkt(), end='')
            self.swiat.dodajInformacje(" Rozprzestrzenia sie! Powstaje nowa " + self.getNazwaOrganizmu() + " na polu: " + miejsceUrodzenia.printPunkt())

    def znajdzWolnyPunktObok(self, stary: Punkt):

        nowy = Punkt()
        if stary.getY() != 0 and self.swiat.sprawdzCzyPolePuste(stary.getX(), stary.getY() - 1):
            nowy.setX(stary.getX())
            nowy.setY(stary.getY() - 1)
        elif stary.getY() != self.swiat.getHeight() - 1 and self.swiat.sprawdzCzyPolePuste(stary.getX(),
                                                                                           stary.getY() + 1):
            nowy.setX(stary.getX())
            nowy.setY(stary.getY() + 1)
        elif stary.getX() != 0 and self.swiat.sprawdzCzyPolePuste(stary.getX() - 1, stary.getY()):
            nowy.setX(stary.getX() - 1)
            nowy.setY(stary.getY())
        elif stary.getX() != self.swiat.getWidth() - 1 and self.swiat.sprawdzCzyPolePuste(stary.getX() + 1,
                                                                                          stary.getY()):
            nowy.setX(stary.getX() + 1)
            nowy.setY(stary.getY())
        else:
            nowy = stary
        return nowy


