import random

from Organizm import Organizm
from Roslina import Roslina


class Guarana(Roslina):

    def __init__(self, polozenie, swiat):
        super(Guarana, self).__init__(0, 0, 'G', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Guarana"

    def kolizja(self, other: Organizm, atakujacy, ruch):
        self.zabojczeInformacjeDlaRoslin(other, self)
        # print(" " + other.getNazwaOrganizmu() + " zjadl -> " + self.getNazwaOrganizmu())
        other.setSila(other.getSila() + 3)
        self.setZycie(False)
