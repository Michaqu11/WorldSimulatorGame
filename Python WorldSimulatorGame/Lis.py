import random

from Punkt import Punkt
from Zwierze import Zwierze


class Lis(Zwierze):

    def __init__(self, polozenie, swiat):
        super(Lis, self).__init__(3, 7, 'L', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Lis"

    def akcja(self):
        self.wiek += 1
        self.ogolneInformacje()
        nowePolozenie = self.wylosujPunktDlaLisa()
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

    def wylosujPunktDlaLisa(self):
        stary = self.polozenie
        nowy:Punkt = Punkt(0, 0)
        nowy.setPunkt(stary)
        end = False
        sprawdzonePozycja = [False for i in range(4)]
        badLuck = 0
        while(end is False):
            x = random.randint(0, 3)
            if x == 0 and sprawdzonePozycja[0] is False:
                if stary.getY() != 0:
                    nowy.setX(stary.getX())
                    nowy.setY(stary.getY() - 1)
                sprawdzonePozycja[0] = True
            if x == 1 and sprawdzonePozycja[1] is False:
                if stary.getY() != self.swiat.getHeight() - 1:
                    nowy.setX(stary.getX())
                    nowy.setY(stary.getY() + 1)
                sprawdzonePozycja[1] = True
            if x == 2 and sprawdzonePozycja[2] is False:
                if stary.getX() != 0:
                    nowy.setX(stary.getX() - 1)
                    nowy.setY(stary.getY())
                sprawdzonePozycja[2] = True
            if x == 3 and sprawdzonePozycja[3] is False:
                if stary.getX() != self.swiat.getWidth() - 1:
                    nowy.setX(stary.getX() + 1)
                    nowy.setY(stary.getY())
                sprawdzonePozycja[3] = True

            wszystkieSprwadzone = True

            if not nowy.sprwadzCzyTenSam(stary):
                if self.swiat.sprawdzCzyPolePuste(nowy.getX(), nowy.getY()) or self.swiat.zwrocOrganizmZPola(nowy) is not None and self.swiat.zwrocOrganizmZPola(nowy).getSila() <= self.sila:
                    end = True

            if end == False:
                for i in range(0, 4):
                    if sprawdzonePozycja[i]:
                        wszystkieSprwadzone = False

                if wszystkieSprwadzone:
                    end = True
                    nowy = stary

            if badLuck == 1000:
                end = True
                nowy = stary

            badLuck += 1
        if nowy.sprwadzCzyTenSam(stary):
            self.swiat.dodajInformacje(" Zostaje na polu " + nowy.printPunkt())
            #print(" Zostaje na polu " + nowy.printPunkt(), end='')

        return nowy