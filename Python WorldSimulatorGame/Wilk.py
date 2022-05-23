from Zwierze import Zwierze


class Wilk(Zwierze):

    def __init__(self, polozenie, swiat):
        super(Wilk, self).__init__(9, 5, 'W', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Wilk"