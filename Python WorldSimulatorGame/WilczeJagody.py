from Organizm import Organizm
from Roslina import Roslina


class WilczeJagody(Roslina):

    def __init__(self, polozenie, swiat):
        super(WilczeJagody, self).__init__(99, 0, 'J', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Wilcze Jagody"

    def kolizja(self, other: Organizm, atakujacy, ruch):
            self.zabojczeInformacjeDlaRoslin(other, self)
            self.setSila(other.getSila()+10)
            self.swiat.setPrzerwij(self.swiat.getPrzerwij() + 1)
            other.kolizja(self, True, ruch)
            self.setZycie(False)


