from PyQt5.QtWidgets import *
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton

from Buttons import Buttons
from Swiat import Swiat
import pickle
import sys


class Mapa(QMainWindow):

    def __init__(self, swiat: Swiat):
        super(Mapa, self).__init__()
        self.title = 'Swiat'
        self.left = 1000
        self.top = 300
        self.width = 50 * swiat.width
        self.height = 50 * swiat.height
        self.swiat = swiat
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        for i in range(0, self.swiat.height):
            for j in range(0, self.swiat.width):
                button = Buttons(self, self.swiat, j, i)
                button.resize(50, 50)
                button.move(j * 50, i * 50)

        self.show()

    def keyPressEvent(self, event):

        key = event.key()

        if key == 16777235 or key == 87:  # gora
            self.swiat.wykonajTure(0)
        elif key == 16777237 or key == 83:  # dol
            self.swiat.wykonajTure(1)
        elif key == 16777234 or key == 65:  # lewo
            self.swiat.wykonajTure(2)
        elif key == 16777236 or key == 68:  # prawo
            self.swiat.wykonajTure(3)
        elif key == 80:  # super moc
            self.swiat.wykonajTure(4)
        elif key == 73:  # info
            temp = self.swiat.getInformacje()
            msgBox = QMessageBox()
            msgBox.setStyleSheet("QLabel{min-width:500 px; font-size: 20px; text-align: center;}");
            msgBox.setText(self.swiat.getPoprzedniaMapa())
            msgBox.setDetailedText(temp)
            msgBox.setWindowTitle("Informator")
            msgBox.exec_()
        elif key == 75:
            with open('plik.txt', 'wb') as f:
                pickle.dump(self.swiat, f, pickle.HIGHEST_PROTOCOL)
            print(". . . . Zapisano!")
        elif key == 76:
            with open('plik.txt', 'rb') as f:
                obiekt = pickle.load(f)
            self.close()
            self.open = Mapa(obiekt)

        self.repaint()




if __name__ == '__main__':

    app = QApplication(sys.argv)
    print("Czy chcesz stowrzyc gre czy wczytac? stworzyc - s wczytac - w")
    start = input()
    if start == "s":
        print("Podaj rozmiar mapy: (x,y)")
        x = input()
        y = input()
        s = Swiat(int(x), int(y))
        s.stworzSwiat()
        ex = Mapa(s)
    else:
        with open('plik.txt', 'rb') as f:
            obiekt = pickle.load(f)
            ex = Mapa(obiekt)
    ex.repaint()
    ex.setFocus()
    sys.exit(app.exec_())
