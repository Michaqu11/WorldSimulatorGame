import random

from Organizm import Organizm
from Punkt import Punkt
from Roslina import Roslina


class BarszczSosnowskiego(Roslina):

    def __init__(self, polozenie, swiat):
        super(BarszczSosnowskiego, self).__init__(10, 0, 'B', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Barszcz Sosnowskiego"

    def akcja(self):
        self.wiek += 1
        self.ogolneInformacje()
        self.zabijSasiadow(self.polozenie)
        x = random.randint(0, 19)
        if x != 0:
            pass
        else:
            self.rozprzestrzenianie()

    def kolizja(self, other: Organizm, atakujacy, ruch):
            self.zabojczeInformacjeDlaRoslin(other, self)
            if other.getZnak() != 'Ⓒ':
                self.setSila(other.getSila()+10)
                self.swiat.setPrzerwij(self.swiat.getPrzerwij() + 1)
                other.kolizja(self, True, ruch)
            self.setZycie(False)

    def zabijSasiadow(self, stary):

        if stary.getY() != 0:
            org = self.swiat.zwrocOrganizmZPola(Punkt(stary.getX(), stary.getY() - 1))
            if org is not None and self.swiat.czyZwierzeZeZnaku(org.getZnak()) and org.getZnak() != 'Ⓒ':
                self.swiat.dodajInformacje(" " + self.getNazwaOrganizmu() + " zabil -> " + org.getNazwaOrganizmu() + " ")
                #print(" " + self.getNazwaOrganizmu() + " zabil -> " + org.getNazwaOrganizmu())
                org.setZycie(False)
        if stary.getY() != self.swiat.getHeight() - 1:
            org = self.swiat.zwrocOrganizmZPola(Punkt(stary.getX(), stary.getY() + 1))
            if org is not None and self.swiat.czyZwierzeZeZnaku(org.getZnak()) and org.getZnak() != 'Ⓒ':
                self.swiat.dodajInformacje(" " + self.getNazwaOrganizmu() + " zabil -> " + org.getNazwaOrganizmu() + " ")
                #print(" " + self.getNazwaOrganizmu() + " zabil -> " + org.getNazwaOrganizmu())
                org.setZycie(False)
        if stary.getX() != 0:
            org = self.swiat.zwrocOrganizmZPola(Punkt(stary.getX() - 1, stary.getY()))
            if org is not None and self.swiat.czyZwierzeZeZnaku(org.getZnak()) and org.getZnak() != 'Ⓒ':
                self.swiat.dodajInformacje(" " + self.getNazwaOrganizmu() + " zabil -> " + org.getNazwaOrganizmu() + " ")
                #print(" " + self.getNazwaOrganizmu() + " zabil -> " + org.getNazwaOrganizmu())
                org.setZycie(False)
        if stary.getX() != self.swiat.getWidth() - 1:
            org = self.swiat.zwrocOrganizmZPola(Punkt(stary.getX() + 1, stary.getY()))
            if org is not None and self.swiat.czyZwierzeZeZnaku(org.getZnak()) and org.getZnak() != 'Ⓒ':
                self.swiat.dodajInformacje(" " + self.getNazwaOrganizmu() + " zabil -> " + org.getNazwaOrganizmu() + " ")
                #print(" " + self.getNazwaOrganizmu() + " zabil -> " + org.getNazwaOrganizmu())
                org.setZycie(False)
