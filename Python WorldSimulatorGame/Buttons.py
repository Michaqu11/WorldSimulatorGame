from PyQt5.QtWidgets import QPushButton, QLineEdit, QInputDialog
from Punkt import Punkt
from Swiat import Swiat


class Buttons(QPushButton):

    def __init__(self, parent, swiat: Swiat, x, y):
        super(Buttons, self).__init__(' ', parent)
        self.swiat = swiat
        self.x = x
        self.y = y

    def paintEvent(self, q_paint_event):
        o = self.swiat.zwrocOrganizmZPola(Punkt(self.x, self.y))
        if o is not None:
            self.setText(o.getZnak())
            if o.getZnak() == "C":
                self.setStyleSheet('background-color: blue')
            elif self.swiat.czyZwierzeZeZnaku(o.getZnak()):
                self.setStyleSheet('background-color: orange')
            else:
                self.setStyleSheet('background-color: green')
        else:
            self.setText('')
            self.setStyleSheet('background-color: #ddd')
            self.setAccessibleDescription(str(self.x) + " " + str(self.y))
            self.clicked.connect(self.clickme)

        super().paintEvent(q_paint_event)

    def clickme(self):

        o = self.swiat.zwrocOrganizmZPola(Punkt(self.x, self.y))
        if o is None:
            text, okPressed = QInputDialog.getText(self, "Dodawasz 2000", "Podaj znak organzimu: ", QLineEdit.Normal, "")
            if okPressed and text != '':
                if self.swiat.czyOrganizmJestNaSwiecie(text):
                    self.swiat.dodajOrganizm(text, Punkt(self.x, self.y))

