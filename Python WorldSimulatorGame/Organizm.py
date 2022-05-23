import Swiat
import Punkt

class Organizm:

    def __init__(self, sila, inicjatywa, znak, wiek, zycie, polozenie: Punkt, swiat: Swiat):
        self.sila = sila
        self.inicjatywa = inicjatywa
        self.znak = znak
        self.wiek = wiek
        self.zycie = zycie
        self.polozenie = polozenie
        self.swiat = swiat

    def getSila(self):
        return self.sila

    def setSila(self, sila):
        self.sila = sila

    def getInicjatywa(self):
        return self.inicjatywa

    def setInicjatywa(self, inicjatywa):
        self.inicjatywa = inicjatywa

    def getWiek(self):
        return self.wiek

    def setWiek(self, wiek):
        self.wiek = wiek

    def getZnak(self):
        return self.znak

    def setZnak(self, znak):
        self.znak = znak

    def getZycie(self):
        return self.zycie

    def setZycie(self, zycie):
        self.zycie = zycie

    def getPolozenie(self):
        return self.polozenie

    def setPolozenie(self, polozenie):
        self.polozenie = polozenie

    def getSwiat(self):
        return self.swiat

    def setSwiat(self, swiat):
        self.swiat = swiat

    def akcja(self):
        pass

    def kolizja(self, other, atakujacy, ruch):
        pass

    def getNazwaOrganizmu(self):
        pass

    def rysowanie(self):
        pass

    def ogolneInformacje(self):
        self.swiat.dodajInformacje(str(self.getNazwaOrganizmu()) + " z pola: " + self.polozenie.printPunkt() + " ma sily: " + str(self.getSila()) + " i lat: " + str(self.getWiek()))
        #print(str(self.getNazwaOrganizmu()) + " z pola: " + self.polozenie.printPunkt() + " ma sily: " + str(self.getSila()) + " i lat: " + str(self.getWiek()) + " ", end='')

    def zabojczeInformacjeDlaZwierzat(self, other):
        self.swiat.dodajInformacje(" " + str(other.getNazwaOrganizmu()) + " zabil -> " + str(self.getNazwaOrganizmu()))
        #print(" " + str(other.getNazwaOrganizmu()) + " zabil -> " + str(self.getNazwaOrganizmu()), end='')

    def zabojczeInformacjeDlaRoslin(self, org1, org2):
        #print(" " + str(org1.getNazwaOrganizmu()) + " zjadl -> " + str(org2.getNazwaOrganizmu()), end='')
        self.swiat.dodajInformacje(" " + str(org1.getNazwaOrganizmu()) + " zjadl -> " + str(org2.getNazwaOrganizmu()))

    def informacjeONowychOrganizmach(self, nazwa, miejsceUrodzenia):
        self.swiat.dodajInformacje(" Rozmnaza sie! Powstaje nowy " + str(nazwa) + " na polu: " + miejsceUrodzenia.printPunkt())
        #print(" Rozmnaza sie! Powstaje nowy " + str(nazwa) + " na polu: " + miejsceUrodzenia.printPunkt(), end='')