from Organizm import Organizm
from Zwierze import Zwierze
from Punkt import Punkt

class Czlowiek(Zwierze):

    def __init__(self, polozenie, swiat):
        super(Czlowiek, self).__init__(5, 4, 'C', 0, True, polozenie, swiat)
        self.ileOdejmowac= 0

    def getNazwaOrganizmu(self):
        return "Czlowiek"

    def akcja(self):
        self.wiek += 1
        self.ogolneInformacje()
        nowePolozenie = self.swiat.getNastepnyPunktCzlowieka()
        if self.swiat.sprawdzCzyPolePuste(nowePolozenie.getX(), nowePolozenie.getY()):
            self.Ruch(nowePolozenie)
            self.swiat.setPunktCzlowieka(nowePolozenie)
        else:
            ruch = True
            if self.swiat.zwrocOrganizmZPola(nowePolozenie).getZycie():
                self.kolizja(self.swiat.zwrocOrganizmZPola(nowePolozenie), True, ruch)
            if self.getZycie() and ruch:
                org = self.swiat.zwrocOrganizmZPola(nowePolozenie)
                if org is not None and org.getZycie() is False or org is None:
                    self.Ruch(nowePolozenie)
                    self.swiat.setPunktCzlowieka(nowePolozenie)
        if self.getSila() >= 10 and self.swiat.getIloscTurDoSuperMocy() < 5:
            self.swiat.setCzyCzlowiekMozeUzywacSuperMocy(False)
        if self.ileOdejmowac > 0:
            self.setSila(self.getSila() - 1)
            self.ileOdejmowac -= 1

    def kolizja(self, other: Organizm, atakujacy, ruch):
        if self.swiat.getCzySuperMocZostalaAktywowana():
            self.ileOdejmowac = 10 - self.getSila() - (10 - self.swiat.getIloscTurDoSuperMocy())
            if self.ileOdejmowac > 0:
                self.setSila(self.getSila() + self.ileOdejmowac)
            self.swiat.setCzySuperMocZostalaAktywowana(False)
        if other.getZycie():
            if self.getSila() > other.getSila() or (self.getSila() == other.getSila() and atakujacy):
                other.kolizja(self, False, ruch)
            elif self.swiat.getPrzerwij() < 2:
                self.swiat.setPrzerwij(self.swiat.getPrzerwij() + 1)
                other.kolizja(self, False, ruch)
            else:
                self.zabojczeInformacjeDlaZwierzat(other)
                self.setZycie(False)
