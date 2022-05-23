import random

from Antylopa import Antylopa
from BarszczSosnowskiego import BarszczSosnowskiego
from CyberOwca import CyberOwca
from Czlowiek import Czlowiek
from Guarana import Guarana
from Mlecz import Mlecz
from Organizm import Organizm
from Punkt import Punkt
from Trawa import Trawa
from WilczeJagody import WilczeJagody
from Wilk import Wilk
from Owca import Owca
from Lis import Lis
from Zolw import Zolw


class Swiat:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.iloscZwierzat: int = width * height * 0.3
        self.liczbaTur = 0
        self.organizmy = []
        self.przerwij = 0
        self.nastepnyPunktCzlowieka = Punkt()
        self.punktCzlowieka = Punkt()
        self.czyCzlowiekZyje = True
        self.iloscTurDoSuperMocy = 0
        self.czyCzlowiekMozeUzywacSuperMocy = True
        self.czyMocZostalaAktywowana = False
        self.informacje = []
        self.poprzedniaMapa=""
        self.aktualnaMapa=""

    def getWidth(self):
        return self.width

    def getHeight(self):
        return self.height

    def getPrzerwij(self):
        return self.przerwij

    def getNumerTury(self):
        return self.liczbaTur

    def dodajInformacje(self, info):
        self.informacje.append(info)

    def printInformacje(self):
        for info in self.informacje:
            print(info, end='')

    def setInformacje(self, info):
        self.informacje = info

    def getInformacje(self):
       temp = ""
       for info in self.informacje:
           temp = temp + info
       return temp

    def setPrzerwij(self, liczba):
        self.przerwij = liczba

    def getAktualnaMapa(self):
        return self.aktualnaMapa

    def getPoprzedniaMapa(self):
        return self.poprzedniaMapa

    def getNastepnyPunktCzlowieka(self):
        return self.nastepnyPunktCzlowieka

    def setNastepnyPunktCzlowieka(self, other: Punkt):
        self.nastepnyPunktCzlowieka = other

    def getPunktCzlowieka(self):
        return self.punktCzlowieka

    def setPunktCzlowieka(self, other: Punkt):
        self.punktCzlowieka = other

    def getCzyCzlowiekZyje(self):
        return self.czyCzlowiekZyje

    def setCzyCzlowiekZyje(self, zycie):
        self.czyCzlowiekZyje = zycie

    def getIloscTurDoSuperMocy(self):
        return self.iloscTurDoSuperMocy

    def setCzyCzlowiekMozeUzywacSuperMocy(self, czyCzlowiekMozeUzywacSuperMocy):
        self.czyCzlowiekMozeUzywacSuperMocy = czyCzlowiekMozeUzywacSuperMocy

    def getCzyCzlowiekMozeUzywacSuperMocy(self):
        return self.czyCzlowiekMozeUzywacSuperMocy

    def getCzySuperMocZostalaAktywowana(self):
        return self.czyMocZostalaAktywowana

    def setCzySuperMocZostalaAktywowana(self, czyMocZostalaAktywowana):
        self.czyMocZostalaAktywowana = czyMocZostalaAktywowana

    def stworzSwiat(self):
        p = self.wylosujPustyPunkt()
        self.organizmy.append(Czlowiek(p, self))
        self.punktCzlowieka = p
        for i in range(0, int(self.iloscZwierzat) - 1):
            p = self.wylosujPustyPunkt()
            self.stworzOrganizm(p)

        self.aktualnaMapa = self.aktualnaMapa + "ilosc organizmow to: " + str(len(self.organizmy)) + " a runda: " + str(
            self.liczbaTur) + "\n\n"
        # print("ilosc organizmow to: " + str(len(self.organizmy)) + " a runda: " + str(self.liczbaTur))
        for i in range(0, self.height):
            for j in range(0, self.width):
                o = self.zwrocOrganizmZPola(Punkt(j, i))
                if o is not None:
                    # print(o.getZnak(), end='')
                    self.aktualnaMapa = self.aktualnaMapa + o.getZnak()
                else:
                    # print("_", end='')
                    self.aktualnaMapa = self.aktualnaMapa + "_"
            # print('\n')
            self.aktualnaMapa = self.aktualnaMapa + "\n"
            self.poprzedniaMapa = self.aktualnaMapa

    def dodajOrganizm(self, znak, punkt: Punkt):
        if znak == 'W':
            self.organizmy.append(Wilk(punkt, self))
        elif znak == 'O':
            self.organizmy.append(Owca(punkt, self))
        elif znak == 'L':
            self.organizmy.append(Lis(punkt, self))
        elif znak == 'A':
            self.organizmy.append(Antylopa(punkt, self))
        elif znak == 'Z':
            self.organizmy.append(Zolw(punkt, self))
        elif znak == 'Ⓒ':
            self.organizmy.append(CyberOwca(punkt, self))
        elif znak == 'T':
            self.organizmy.append(Trawa(punkt, self))
        elif znak == 'M':
            self.organizmy.append(Mlecz(punkt, self))
        elif znak == 'G':
            self.organizmy.append(Guarana(punkt, self))
        elif znak == 'J':
            self.organizmy.append(WilczeJagody(punkt, self))
        elif znak == 'B':
            self.organizmy.append(BarszczSosnowskiego(punkt, self))

    def stworzOrganizm(self, punkt):
        x = random.randint(0, 11)
        if x == 0:
            self.organizmy.append(Wilk(punkt, self))
        elif x == 1:
            self.organizmy.append(Owca(punkt, self))
        elif x == 2:
            self.organizmy.append(Lis(punkt, self))
        elif x == 3:
            self.organizmy.append(Antylopa(punkt, self))
        elif x == 4:
            self.organizmy.append(Zolw(punkt, self))
        elif x == 5:
            self.organizmy.append(CyberOwca(punkt, self))
        elif x == 6:
            self.organizmy.append(Trawa(punkt, self))
        elif x == 7:
            self.organizmy.append(Mlecz(punkt, self))
        elif x == 8:
            self.organizmy.append(Guarana(punkt, self))
        elif x == 9:
            self.organizmy.append(WilczeJagody(punkt, self))
        elif x == 11:
            self.organizmy.append(BarszczSosnowskiego(punkt, self))

    def klawisze(self, klucz):
        rezultat = True
        print(klucz)
        if self.getCzyCzlowiekZyje():
            p = self.punktCzlowieka
            nowePolozenie = Punkt()
            if self.iloscTurDoSuperMocy != 0:
                self.iloscTurDoSuperMocy -= 1
            if klucz == 0:  # gora
                if p.getY() != 0:
                    nowePolozenie.setX(p.getX())
                    nowePolozenie.setY(p.getY() - 1)
                    e = True
                else:
                    rezultat = False
                    print(" Nie mozesz isc wyzej! ")
            elif klucz == 1:  # dol
                if p.getY() != self.height - 1:
                    nowePolozenie.setX(p.getX())
                    nowePolozenie.setY(p.getY() + 1)
                    e = True
                else:
                    print("  Nie mozesz isc nizej! ")
            elif klucz == 2:  # lewo
                if p.getX() != 0:
                    nowePolozenie.setX(p.getX() - 1)
                    nowePolozenie.setY(p.getY())
                    e = True
                else:
                    rezultat = False
                    print(" Nie mozesz isc bardziej w lewo!")
            elif klucz == 3:  # prawo
                if p.getX() != self.width - 1:
                    nowePolozenie.setX(p.getX() + 1)
                    nowePolozenie.setY(p.getY())
                    e = True
                else:
                    rezultat = False
                    print(" Nie mozesz isc bardziej w prawo! ")
            elif klucz == 4:  # super moc
                if self.czyCzlowiekMozeUzywacSuperMocy:
                    if self.iloscTurDoSuperMocy == 0:
                        print(" Moc zostanie aktywowana! ")
                        self.czyMocZostalaAktywowana = True
                        self.iloscTurDoSuperMocy = 10
                    else:
                        print(" Zostalo jeszcze " + str(self.iloscTurDoSuperMocy) + " tur do aktywowania super mocy")
                else:
                    print(" Czlowiek ma juz wiecej niz 10 sily! ")
                rezultat = False
            else:
                print(" Kliknij dobry przcyisk! ")
                rezultat = False

            if rezultat is True:
                self.nastepnyPunktCzlowieka = nowePolozenie
        else:
            print("# CZLOWIEK NIE ZYJE! Nie mozesz juz nim sterowac :c # ")

            if klucz == 3:  # prawo
                e = True
            else:
                rezultat = False
                print(" Kliknij dobry przcyisk!")
        return rezultat

    def wykonajTure(self, klucz):
        self.organizmy.sort(key=lambda x: (x.getInicjatywa(), x.getWiek()), reverse=True)
        rezultat = self.klawisze(klucz)
        if rezultat:
            self.poprzedniaMapa = self.aktualnaMapa
            self.aktualnaMapa = ""
            self.informacje.clear()
            rozmiar = len(self.organizmy)
            czyKtosUmarl = False
            self.setPrzerwij(0)
            for i in range(0, rozmiar):
                if self.organizmy[i].getZycie():
                    self.organizmy[i].akcja()
                    #print("\n")
                    self.dodajInformacje("\n")

            for i in range(0, rozmiar):
                if self.organizmy[i].getZycie() is False:
                    czyKtosUmarl = True
                    break

            if czyKtosUmarl:
                #print("\nCmentarz: \n", end='')
                self.dodajInformacje("\nCmentarz: \n")
                for organizm in self.organizmy:
                    if organizm.getZycie() is False:
                        self.usunOrganizm(organizm)


            self.aktualnaMapa = self.aktualnaMapa + "ilosc organizmow to: " + str(len(self.organizmy)) + " a runda: " + str(self.liczbaTur) +"\n\n"
            #print("ilosc organizmow to: " + str(len(self.organizmy)) + " a runda: " + str(self.liczbaTur))
            for i in range(0, self.height):
                for j in range(0, self.width):
                    o = self.zwrocOrganizmZPola(Punkt(j, i))
                    if o is not None:
                        #print(o.getZnak(), end='')
                        self.aktualnaMapa = self.aktualnaMapa + o.getZnak()
                    else:
                        #print("_", end='')
                        self.aktualnaMapa = self.aktualnaMapa + "_"
                #print('\n')
                self.aktualnaMapa = self.aktualnaMapa + "\n"

            self.printInformacje()
            self.liczbaTur += 1

    def usunOrganizm(self, organizm: Organizm):
       #print(" Mordowanie " + organizm.getNazwaOrganizmu() + " z pola " + organizm.polozenie.printPunkt())
        self.dodajInformacje(" Mordowanie " + organizm.getNazwaOrganizmu() + " z pola " + organizm.polozenie.printPunkt() + "\n")
        if organizm.getZnak() == "C":
            self.setCzyCzlowiekZyje(False)
        self.organizmy.remove(organizm)

    def wylosujPustyPunkt(self):
        while (True):
            x = random.randint(0, self.width - 1)
            y = random.randint(0, self.height - 1)
            p = Punkt(x, y)
            if self.zwrocOrganizmZPola(p) is None:
                break
        return p

    def zwrocOrganizmZPola(self, point):
        for i in range(0, len(self.organizmy)):
            if self.organizmy[i].polozenie.sprwadzCzyTenSam(point):
                return self.organizmy[i]
        return None

    def sprawdzCzyPolePuste(self, x: int, y: int):
        point = Punkt(x, y)
        for organizm in self.organizmy:
            if organizm.polozenie.sprwadzCzyTenSam(point):
                return False
        return True

    def czyZwierzeZeZnaku(self, znak):
        if znak == 'W' or znak == 'O' or znak == 'L' or znak == 'A' or znak == 'Z' or znak == 'Ⓒ' or znak == 'C':
            return True
        return False

    def czyOrganizmJestNaSwiecie(self, znak):
        for organizm in self.organizmy:
            if organizm.getZnak() == znak:
                return True
        return False
