# импортирует необходимые библиотеки
import serial
import time
import sys
from PyQt5.QtWidgets import *
from PyQt5 import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from PIL import Image, ImageDraw
import serial.tools.list_ports
import sqlite3
from design import Ui_MainWindow
from create_gif import Ui_Form


class Create_gif(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        # подключение дизайна
        self.setupUi(self)
        self.setWindowTitle('Create GIF')

        self.file_lis = []
        self.item_delete = -1

        # присваиваем кнопкам функции
        self.pushButton.clicked.connect(self.upload)
        self.listWidget.clicked.connect(self.to_delete)
        self.pushButton_3.clicked.connect(self.delete)
        self.pushButton_2.clicked.connect(self.create_gif)

    def create_gif(self):
        if self.file_lis != []:
            # получаем путь и название файла для сохранения гифки
            fname = QtWidgets.QFileDialog.getSaveFileName(
                parent=self,
                caption="New file name",
                directory='C:\\',
                filter="*.gif")[0]

            # создаем список фотографий
            frames = [Image.open(image) for image in self.file_lis]
            frame_one = frames[0]
            # создаем гифку
            frame_one.save(fname, format="GIF", append_images=frames,
                           save_all=True, duration=100, loop=0)

    def delete(self):
        if self.item_delete != -1:
            # удалить выделенную строку из виджета
            self.listWidget.takeItem(self.item_delete)
            # удаляем путь картинки из списка
            del self.file_lis[self.item_delete]
            # сбрасываем выбранную строку
            self.listWidget.clearSelection()
            self.item_delete = -1

    def to_delete(self):
        # сохраняем индекс строки для удаления
        self.item_delete = self.listWidget.currentRow()

    def upload(self):
        # получаем путь к картинке
        fname = QFileDialog.getOpenFileName(self, 'Open file',
                                            'C:\\',
                                            "Image files (*.jpg *.png)")

        if fname[0] != '':
            # записываем путь в список
            self.file_lis.append(fname[0])
            # получить название файла
            to_table = (fname[0].split("/"))[-1]
            # добавляем название файла в виджет
            if to_table != "":
                self.listWidget.addItem(to_table)


class MyWidget(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        # подключение дизайна
        self.setupUi(self)
        self.setWindowTitle('PyQT LED Matrix')
        self.label_23.setText("")
        self.label_23.setStyleSheet("QLabel { color: rgba(255, 255, 255); }")

        # создаем вложеный список со всеми кнопками матрицы
        self.matrix = [[self.p11, self.p12, self.p13, self.p14,
                       self.p15, self.p16, self.p17, self.p18],
                       [self.p21, self.p22, self.p23, self.p24,
                        self.p25, self.p26, self.p27, self.p28],
                       [self.p31, self.p32, self.p33, self.p34,
                       self.p35, self.p36, self.p37, self.p38],
                       [self.p41, self.p42, self.p43, self.p44,
                        self.p45, self.p46, self.p47, self.p48],
                       [self.p51, self.p52, self.p53, self.p54,
                        self.p55, self.p56, self.p57, self.p58],
                       [self.p61, self.p62, self.p63, self.p64,
                        self.p65, self.p66, self.p67, self.p68],
                       [self.p71, self.p72, self.p73, self.p74,
                        self.p75, self.p76, self.p77, self.p78],
                       [self.p81, self.p82, self.p83, self.p84,
                        self.p85, self.p86, self.p87, self.p88]]

        # получаем начальное положение матрицы из базы данных
        con = sqlite3.connect("led_data.db")
        cur = con.cursor()
        result = cur.execute("""SELECT * FROM data
        WHERE name like 'start'""").fetchall()
        self.led_matrix = [[int(b) for b in elem[1:]]for elem in result[0][1:]]
        con.close()

        self.tabWidget.setEnabled(False)

        self.r = 255
        self.g = 0
        self.b = 0
        self.state = 0
        self.active_anim = 0

        # подключаем функции к слайдерам
        self.verticalSlider.valueChanged.connect(
            lambda x: self.colour("r", self.verticalSlider.value()))
        self.verticalSlider_3.valueChanged.connect(
            lambda x: self.colour("g", self.verticalSlider_3.value()))
        self.verticalSlider_2.valueChanged.connect(
            lambda x: self.colour("b", self.verticalSlider_2.value()))

        # подключаем функции к кнопкам
        self.connection.clicked.connect(self.connect_btn)
        self.toolButton_2.clicked.connect(self.clear)
        self.pushButton_66.clicked.connect(self.preview)
        self.pushButton_65.clicked.connect(self.save_img)
        self.pushButton_11.clicked.connect(self.new_window)

        # подключаем функции к кнопкам матрицы
        for index_y, i in enumerate(self.matrix):
            for index_x, n in enumerate(i):
                n.clicked.connect(self.matrix_colour)

        # присваиваем картинку к кнопкам
        # присваиваем функцию и передаем кодовое значение
        self.pushButton.setStyleSheet(
            "background-image : url(pictures/full.jpg);")
        self.pushButton.clicked.connect(lambda x: self.ready_img("301"))

        self.pushButton_2.setStyleSheet(
            "background-image : url(pictures/smile.jpg);")
        self.pushButton_2.clicked.connect(lambda x: self.ready_img("302"))

        self.pushButton_5.setStyleSheet(
            "background-image : url(pictures/heart.jpg);")
        self.pushButton_5.clicked.connect(lambda x: self.ready_img("303"))

        self.pushButton_4.setStyleSheet(
            "background-image : url(pictures/cat.jpg);")
        self.pushButton_4.clicked.connect(lambda x: self.ready_img("304"))

        self.pushButton_3.setStyleSheet(
            "background-image : url(pictures/apple.jpg);")
        self.pushButton_3.clicked.connect(lambda x: self.ready_img("305"))

        self.pushButton_6.setStyleSheet(
            "background-image : url(pictures/arrow.jpg);")
        self.pushButton_6.clicked.connect(lambda x: self.ready_img("306"))

        self.pushButton_7.setStyleSheet(
            "background-image : url(pictures/anim1.jpg);")
        self.pushButton_7.clicked.connect(lambda x: self.anim("308"))

        self.pushButton_8.setStyleSheet(
            "background-image : url(pictures/anim2.jpg);")
        self.pushButton_8.clicked.connect(lambda x: self.anim("309"))

        self.pushButton_9.setStyleSheet(
            "background-image : url(pictures/anim3.jpg);")
        self.pushButton_9.clicked.connect(lambda x: self.anim("310"))

        self.pushButton_10.setStyleSheet(
            "background-image : url(pictures/anim4.jpg);")
        self.pushButton_10.clicked.connect(lambda x: self.anim("311"))

    def anim(self, name):
        # обнуляем матриуцу
        if self.active_anim == 0:
            self.clear()
            time.sleep(0.3)
            self.active_anim = 1

        # отправляем код на ардуино
        try:
            self.write_read(name)
        except Exception:
            self.label_23.setText("Ошибка, Перезапустите программу")

    def new_window(self):
        # открываем окно для создании гифки
        self.w = Create_gif()
        self.w.show()

    def save_img(self):
        # получаем путь и название файла для сохранения картинки
        fname = QtWidgets.QFileDialog.getSaveFileName(
            parent=self,
            caption="New file name",
            directory='C:\\',
            filter="JPG;;PNG")

        if fname[0] != "":
            fname = fname[0] + "." + fname[1].lower()
            # создаем картинку
            self.preview()
            # сохраняем картинку
            im1 = Image.open("pictures/preview.jpg")
            im1.save(fname)

    def findArduinoUnoPort(self):
        # проверяем есть ли доступный порт ардуино
        portList = list(serial.tools.list_ports.comports())
        for port in portList:
            if ("VID:PID=2341:0043" in port[0] or
                "VID:PID=2341:0043" in port[1] or
               "VID:PID=2341:0043" in port[2]):
                    return port[0]

    def preview(self):
        # создаем картинку нужного размера и цвета
        im = Image.new("RGB", (376, 376), (255, 255, 255))
        draw = ImageDraw.Draw(im)

        # рисуем картину
        for index_row, row in enumerate(self.led_matrix):
            for index_col, col in enumerate(row):
                if col == 1:
                    temp = 47 * index_col
                    temp2 = 47 * index_row
                    draw.ellipse((temp + 5, temp2 + 5, temp + 42, temp2 + 42),
                                 fill=(self.r, self.g, self.b))
        # сохраняем картинку и отображем ее
        im.save("pictures/preview.jpg")
        self.pixmap = QPixmap("pictures/preview.jpg")
        self.label_21.setPixmap(self.pixmap)

    def ready_img(self, img):
        self.active_anim = 0
        # из базы данных получаем список для включения готовых картин
        con = sqlite3.connect("led_data.db")
        cur = con.cursor()
        result = cur.execute("""SELECT * FROM data
        WHERE name like '{}'""".format(img)).fetchall()
        self.led_matrix = [[int(b) for b in ele[1:]] for ele in result[0][1:]]
        con.close()

        # закрашиваем все необходимые кнопки на матрице
        for index_y, i in enumerate(self.led_matrix):
            for index_x, n in enumerate(i):
                if n == 1:
                    self.matrix[index_y][index_x].setStyleSheet(
                        "background-color: red")
                else:
                    self.matrix[index_y][index_x].setStyleSheet(
                        "background-color: white")

        # отправляем код на ардуино
        try:
            self.write_read(img)
        except Exception:
            self.label_23.setText("Ошибка, Перезапустите программу")

    def clear(self):
        # закрашиваем все необходимые кнопки на матрице в белый
        for index_y, i in enumerate(self.matrix):
            for index_x, n in enumerate(i):
                n.setStyleSheet("background-color: white")
                self.led_matrix[index_y][index_x] = 0

        # отправляем код на ардуино
        try:
            self.write_read("307")
        except Exception:
            self.label_23.setText("Ошибка, Перезапустите программу")

    def matrix_colour(self):
        # проверяем если есть анимация и стирать ее
        if self.active_anim == 1:
            self.clear()
            time.sleep(2)
            self.active_anim = 0

        # получаем название нажатой кнопки
        send_b = self.sender()
        send_b = list(str(send_b.objectName())[1:])

        # создаем код для отправки на ардуино и закрашиваем необходимую точку
        if self.led_matrix[int(send_b[0]) - 1][int(send_b[1]) - 1] == 0:
            self.matrix[int(send_b[0]) - 1][int(send_b[1]) - 1].setStyleSheet(
                "background-color: red")
            self.led_matrix[int(send_b[0]) - 1][int(send_b[1]) - 1] = 1

            try:
                self.write_read('1' + str(int(send_b[1]) - 1) +
                                str(int(send_b[0]) - 1))
            except Exception:
                self.label_23.setText("Ошибка, Перезапустите программу")

        else:
            self.matrix[int(send_b[0]) - 1][int(send_b[1]) - 1].setStyleSheet(
                "background-color: white")
            self.led_matrix[int(send_b[0]) - 1][int(send_b[1]) - 1] = 0

            try:
                self.write_read('2' + str(int(send_b[1]) - 1) +
                                str(int(send_b[0]) - 1))
            except Exception:
                self.label_23.setText("Ошибка, Перезапустите программу")

    def write_read(self, data):
        # отправляем данные на ардуино
        self.arduino.write(bytes(data, 'utf-8'))
        time.sleep(0.5)

    def colour(self, rgb, val):
        # определяем какой слайдер и присваиваем новое значение
        if rgb == "r":
            self.r = val
        elif rgb == "g":
            self.g = val
        else:
            self.b = val

        # меняем цвет label_2
        temp = "background-color: rgb({}, {}, {})".format(
            self.r, self.g, self.b)
        self.label_2.setStyleSheet(temp)

    def connect_btn(self):
        # проверяем есть ли доступный порт ардуино
        unoPort = self.findArduinoUnoPort()

        if unoPort:
            if self.state == 0:
                # пробуем подключиться к ардуине
                try:
                    self.arduino = serial.Serial(port='COM6',
                                                 baudrate=115200,
                                                 timeout=1)
                    self.state = 1
                    self.label_23.setText("")
                    self.connection.setStyleSheet("background-color: green")
                    self.connection.setText("Отключить")
                    self.tabWidget.setEnabled(True)

                except Exception:
                    self.label_23.setText("Ошибка")
                    self.connection.setStyleSheet("background-color: red")
                    self.tabWidget.setEnabled(False)

            else:
                # при отключении очищаем матрицу
                self.clear()
                self.connection.setStyleSheet("background-color: white")
                self.connection.setText("Подключить")
                self.state = 0
                self.tabWidget.setEnabled(False)
                # закрываем порт
                self.arduino.close()

        else:
            if self.state == 1:
                self.clear()
                self.connection.setStyleSheet("background-color: white")
                self.connection.setText("Подключить")
                self.state = 0
                self.tabWidget.setEnabled(False)
                self.arduino.close()

            else:
                self.label_23.setText("Подключите Arduino")
                self.connection.setStyleSheet("background-color: red")
                self.tabWidget.setEnabled(False)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyWidget()
    ex.show()
    sys.exit(app.exec_())
