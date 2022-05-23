from Organizm import Organizm
from Zwierze import Zwierze
from Punkt import Punkt
import random

class Zolw(Zwierze):

    def __init__(self, polozenie, swiat):
        super(Zolw, self).__init__(2, 1, 'Z', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Zolw"

    def akcja(self):
        self.wiek += 1
        x = random.randint(0, 3)
        czyRuch = True
        nowePolozenie = Punkt()
        self.ogolneInformacje()
        if(x == 0):
            nowePolozenie = self.wylosujPunktObok()
        else:
            nowePolozenie.setPunkt(self.polozenie)
            czyRuch = False
            self.swiat.dodajInformacje(" zostaje w miejscu")
            #print(" zostaje w miejscu", end='')
        if czyRuch:
            if self.swiat.sprawdzCzyPolePuste(nowePolozenie.getX(), nowePolozenie.getY()):
                self.Ruch(nowePolozenie)
            else:
                ruch = True
                if self.swiat.zwrocOrganizmZPola(nowePolozenie).getZycie():
                    self.kolizja(self.swiat.zwrocOrganizmZPola(nowePolozenie), True, ruch)
                if self.getZycie() and ruch:
                    org = self.swiat.zwrocOrganizmZPola(nowePolozenie)
                    if org is not None and org.getZycie() is False:
                        self.Ruch(nowePolozenie)

    def kolizja(self, other: Organizm, atakujacy, ruch):
        if other.getZycie():
            if type(self) == type(other):
                self.rozmnazanie()
            elif self.getSila() > other.getSila() or (self.getSila() == other.getSila() and atakujacy):
                other.kolizja(self, False, ruch)
            elif other.getSila() < 5:
                self.swiat.dodajInformacje(" Zolw odbil atak! ")
                #print( " Zolw odbil atak! ", end='')
                ruch = False
            elif self.swiat.getPrzerwij() < 2:
                self.swiat.setPrzerwij(self.swiat.getPrzerwij() + 1)
                other.kolizja(self, False, ruch)
            else:
                self.zabojczeInformacjeDlaZwierzat(other)
                self.setZycie(False)

