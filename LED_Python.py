import serial
import time
import sys
from PyQt5.QtWidgets import *
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtGui import * 
from PyQt5.QtCore import *
from PIL import Image, ImageDraw
import serial.tools.list_ports
import sqlite3
from design import Ui_MainWindow


class MyWidget(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle('PyQT LED Matrix')
        self.label_23.setText("")
        self.label_23.setStyleSheet("QLabel { color: rgba(255, 255, 255); }")

        self.matrix = [[self.p11, self.p12, self.p13, self.p14, self.p15, self.p16, self.p17, self.p18],
                  [self.p21, self.p22, self.p23, self.p24, self.p25, self.p26, self.p27, self.p28],
                  [self.p31, self.p32, self.p33, self.p34, self.p35, self.p36, self.p37, self.p38],
                  [self.p41, self.p42, self.p43, self.p44, self.p45, self.p46, self.p47, self.p48],
                  [self.p51, self.p52, self.p53, self.p54, self.p55, self.p56, self.p57, self.p58],
                  [self.p61, self.p62, self.p63, self.p64, self.p65, self.p66, self.p67, self.p68],
                  [self.p71, self.p72, self.p73, self.p74, self.p75, self.p76, self.p77, self.p78],
                  [self.p81, self.p82, self.p83, self.p84, self.p85, self.p86, self.p87, self.p88]]

        con = sqlite3.connect("led_data.db")
        cur = con.cursor()
        result = cur.execute("""SELECT * FROM data WHERE name like 'start'""").fetchall()
        self.led_matrix = [[int(b) for b in elem[1:]] for elem in result[0][1:]]
        con.close()

        self.tabWidget.setEnabled(False)
    
        self.r = 255
        self.g = 0
        self.b = 0
        self.state = 0

        self.verticalSlider.valueChanged.connect(lambda x: self.colour("r", self.verticalSlider.value()))
        self.verticalSlider_3.valueChanged.connect(lambda x: self.colour("g", self.verticalSlider_3.value()))
        self.verticalSlider_2.valueChanged.connect(lambda x: self.colour("b", self.verticalSlider_2.value()))

        self.connection.clicked.connect(self.connect_btn)
        self.toolButton_2.clicked.connect(self.clear)

        for index_y, i in enumerate(self.matrix):
            for index_x, n in enumerate(i):
                n.clicked.connect(self.matrix_colour)

        self.pushButton.setStyleSheet("background-image : url(pictures/full.jpg);")
        self.pushButton.clicked.connect(lambda x: self.ready_img("full"))
        
        self.pushButton_2.setStyleSheet("background-image : url(pictures/smile.jpg);")
        self.pushButton_2.clicked.connect(lambda x: self.ready_img("smile"))
        
        self.pushButton_5.setStyleSheet("background-image : url(pictures/heart.jpg);")
        self.pushButton_5.clicked.connect(lambda x: self.ready_img("heart"))
        
        self.pushButton_4.setStyleSheet("background-image : url(pictures/cat.jpg);")
        self.pushButton_4.clicked.connect(lambda x: self.ready_img("cat"))
        
        self.pushButton_3.setStyleSheet("background-image : url(pictures/apple.jpg);")
        self.pushButton_3.clicked.connect(lambda x: self.ready_img("apple"))
        
        self.pushButton_6.setStyleSheet("background-image : url(pictures/arrow.jpg);")
        self.pushButton_6.clicked.connect(lambda x: self.ready_img("arrow"))

        self.pushButton_66.clicked.connect(self.preview)

        self.pushButton_65.clicked.connect(self.save_img)

    def save_img(self):
        fname = QtWidgets.QFileDialog.getSaveFileName(
            parent = self,
            caption = "Select a data file",
            directory = 'C:\\',
            filter = "JPG;;PNG")
        
        if fname[0] != "":
            fname = fname[0] + "." + fname[1].lower()
            self.preview()
            im1 = Image.open("pictures/preview.jpg")
            im1.save(fname)
        

    def findArduinoUnoPort(self):
        portList = list(serial.tools.list_ports.comports())
        for port in portList:
            if "VID:PID=2341:0043" in port[0]\
                or "VID:PID=2341:0043" in port[1]\
                or "VID:PID=2341:0043" in port[2]:
                return port[0]
            

    def preview(self):
        im = Image.new("RGB", (376, 376), (255, 255, 255))
        draw = ImageDraw.Draw(im)

        for index_row, row in enumerate(self.led_matrix):
            for index_col, col in enumerate(row):
                if col == 1:
                    temp = 47 * index_col
                    temp2 = 47 * index_row
                    draw.ellipse((temp + 5, temp2 + 5, temp + 42, temp2 + 42), fill=(self.r, self.g, self.b))

        im.save("pictures/preview.jpg")
        self.pixmap = QPixmap("pictures/preview.jpg")
        self.label_21.setPixmap(self.pixmap)

    def ready_img(self, img):
        con = sqlite3.connect("led_data.db")
        cur = con.cursor()
        result = cur.execute("""SELECT * FROM data WHERE name like '{}'""".format(img)).fetchall()
        self.led_matrix = [[int(b) for b in elem[1:]] for elem in result[0][1:]]
        con.close()

        for index_y, i in enumerate(self.led_matrix):
            for index_x, n in enumerate(i):
                if n == 1:
                    self.matrix[index_y][index_x].setStyleSheet("background-color: red")
                else:
                    self.matrix[index_y][index_x].setStyleSheet("background-color: white")

        if img == "full":
            to_send = "301"
        elif img == "smile":
            to_send = "302"
        elif img == "heart":
            to_send = "303"
        elif img == "cat":
            to_send = "304"
        elif img == "apple":
            to_send = "305"
        elif img == "arrow":
            to_send = "306"
            
        try:
            self.write_read(to_send)
        except Exception:
            self.label_23.setText("Ошибка, Перезапустите программу")


    def clear(self):
        for index_y, i in enumerate(self.matrix):
            for index_x, n in enumerate(i):
                n.setStyleSheet("background-color: white")
                self.led_matrix[index_y][index_x] = 0

        try:
            self.write_read("307")
        except Exception:
            self.label_23.setText("Ошибка, Перезапустите программу")

    def matrix_colour(self):
        sending_button = self.sender()
        sending_button = list(str(sending_button.objectName())[1:])

        if self.led_matrix[int(sending_button[0]) - 1][int(sending_button[1]) - 1] == 0:
            self.matrix[int(sending_button[0]) - 1][int(sending_button[1]) - 1].setStyleSheet("background-color: red")
            self.led_matrix[int(sending_button[0]) - 1][int(sending_button[1]) - 1] = 1
            try:
                self.write_read('1' + str(int(sending_button[1]) - 1) + str(int(sending_button[0]) - 1))
            except Exception:
                self.label_23.setText("Ошибка, Перезапустите программу")
            
        else:
            self.matrix[int(sending_button[0]) - 1][int(sending_button[1]) - 1].setStyleSheet("background-color: white")
            self.led_matrix[int(sending_button[0]) - 1][int(sending_button[1]) - 1] = 0
            try:
                self.write_read('2' + str(int(sending_button[1]) - 1) + str(int(sending_button[0]) - 1))
            except Exception:
                self.label_23.setText("Ошибка, Перезапустите программу")

    def write_read(self, mmm):
        self.arduino.write(bytes(mmm, 'utf-8'))
        time.sleep(0.5)

    def colour(self, rgb, val):
        if rgb == "r":
            self.r = val
        elif rgb == "g":
            self.g = val
        else:
            self.b = val

        temp = "background-color: rgb({}, {}, {})".format(self.r, self.g, self.b)
        self.label_2.setStyleSheet(temp)

        send_data = rgb + str(val)

    def connect_btn(self):
        unoPort = self.findArduinoUnoPort()
        
        if unoPort:
            if self.state == 0:
                try:
                    self.arduino = serial.Serial(port='COM6', baudrate=115200, timeout=1)
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
                self.arduino.close()
                self.connection.setStyleSheet("background-color: white")
                self.connection.setText("Подключить")
                self.state = 0
                self.tabWidget.setEnabled(False)        
                
        else:
            if self.state == 1:
                self.arduino.close()
                self.connection.setStyleSheet("background-color: white")
                self.connection.setText("Подключить")
                self.state = 0
                self.tabWidget.setEnabled(False)

            else:
                self.label_23.setText("Подключите Arduino")
                self.connection.setStyleSheet("background-color: red")
                self.tabWidget.setEnabled(False)


    def write_data(self, x):
        self.arduino.write(bytes(x, 'utf-8'))
        time.sleep(0.05)
        return "done"
                

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = MyWidget()
    ex.show()
    sys.exit(app.exec_())

    
