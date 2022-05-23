from Zwierze import Zwierze


class Owca(Zwierze):

    def __init__(self, polozenie, swiat):
        super(Owca, self).__init__(4, 4, 'O', 0, True, polozenie, swiat)

    def getNazwaOrganizmu(self):
        return "Owca"