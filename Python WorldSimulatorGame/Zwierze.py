from Organizm import Organizm
from Punkt import Punkt
import random


class Zwierze(Organizm):

    def __init__(self, sila, inicjatywa, znak, wiek, zycie, swiat, polozenie):
        super(Zwierze, self).__init__(sila, inicjatywa, znak, wiek, zycie, swiat, polozenie)

    def akcja(self):
        self.wiek += 1
        nowePolozenie = self.wylosujPunktObok()
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
            elif self.swiat.getPrzerwij() < 2:
                self.swiat.setPrzerwij(self.swiat.getPrzerwij() + 1)
                other.kolizja(self, False, ruch)
            else:
                self.zabojczeInformacjeDlaZwierzat(other)
                self.setZycie(False)

    def rozmnazanie(self):
        miejsceUrodzenia = self.znajdzWolnyPunktObok(self.polozenie)
        if self.swiat.sprawdzCzyPolePuste(miejsceUrodzenia.getX(), miejsceUrodzenia.getY()):
            self.swiat.dodajOrganizm(self.getZnak(), miejsceUrodzenia)
            #print(" Rozmnaza sie! Powstaje nowy " + self.getNazwaOrganizmu() + " na polu: " + miejsceUrodzenia.printPunkt(), end='')
            self.swiat.dodajInformacje(" Rozmnaza sie! Powstaje nowy " + self.getNazwaOrganizmu() + " na polu: " + miejsceUrodzenia.printPunkt())

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

    def Ruch(self, nowyPunkt):
        self.polozenie.setX(nowyPunkt.getX())
        self.polozenie.setY(nowyPunkt.getY())
        #print(" idzie na pole: " + nowyPunkt.printPunkt(), end='')
        self.swiat.dodajInformacje(" idzie na pole: " + nowyPunkt.printPunkt())

    def wylosujPunktObok(self):
        nowePolozenie = Punkt()
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
