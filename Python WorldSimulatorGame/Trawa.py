from Roslina import Roslina


class Trawa(Roslina):

    def __init__(self, polozenie, swiat):
        super(Trawa, self).__init__(0, 0, 'T', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Trawa"