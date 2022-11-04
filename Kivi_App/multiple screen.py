from kivy.app import App

from kivy.lang import Builder
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.uix.screenmanager import ScreenManager,Screen
from kivy.properties import ObjectProperty
from kivy.uix.popup import Popup
#from database import DataBase
#db = DataBase("passdata.txt")

class MenuScreen(ScreenManager):
    pass


class MainWindow(Screen):
    def menu(self):
        show_menu()

class SecondWindow(Screen):
    point = ObjectProperty(None)
    note = ObjectProperty(None)

    def pressed(self):
        ''' this fuction is the function of the good action button'''
        point1 = self.point.text
        Note1 = self.note.text
        try:
            point1 = int(point1)
            print("You just got: ",point1)
            print('Note of this action: ')
            print(Note1)
            #db.add_action(self.note.text,self.point.text)
        except:
            if point1 == '':
                print('please enter something')
            else:
                print("point should be a number")
        self.point.text = ""
        self.note.text = ''

        #print(point1, Note1)
        # db.add_action(self.note.text,self.point.text)
        # self.point.text = ""
        # self.note.text = ''
        #return grid
    def increased(self):
        ''' this function is to increase the mark'''
        point2 = self.point.text
        try:
            point2 = int(float(point2))+1
            print('increase point is', point2)
            #self.point.text = str(point2)
        except:
            point2 = 1
            print('your point is: ','1')
        self.point.text = str(point2)
    def decreased(self):
        ''' this function decrease the point'''
        point3 = self.point.text
        try:
            point3 = int(float(point3))-1
            print('decrease point is', point3)
            #self.point.text = str(point3)
        except:
            point3 = -1

            print('your point is: ', '-1')
        self.point.text = str(point3)
    def menu(self):
        show_menu()
    def up(self):
        show_post()

class ThirdWindow(Screen):
    point = ObjectProperty(None)
    note = ObjectProperty(None)
    def pressed(self):
        ''' this fuction is the function of the good action button'''
        point1 = self.point.text
        Note1 = self.note.text
        try:
            point1 = int(point1)
            print("You just got: ",point1)
            print('Note of this action: ')
            print(Note1)
            #db.add_action(self.Note1.text,self.point1.text)
        except:
            if point1 == '':
                print('please enter something')
            else:
                print("point should be a number")

        #print(point1, Note1)

        self.point.text = ""
        self.note.text = ''
    def increased(self):
        ''' this function is to increase the mark'''
        point2 = self.point.text
        try:
            point2 = int(float(point2))+1
            print('increase point is', point2)
            #self.point.text = str(point2)
        except:
            point2 = 1
            print('your point is: ','1')
        self.point.text = str(point2)
    def decreased(self):
        ''' this function decrease the point'''
        point3 = self.point.text
        try:
            point3 = int(float(point3))-1
            print('decrease point is', point3)
            #self.point.text = str(point3)
        except:
            point3 = -1

            print('your point is: ', '-1')
        self.point.text = str(point3)
    def menu(self):
        show_menu()
    def show_nega(self):
        shownega()

#class datawindow(Screen):

class Menupop(Widget):
    pass
class post(FloatLayout):
    pass
class nega(FloatLayout):
    pass


def show_menu():
    show = Menupop()

    popupWindow=Popup(title='  Menu',content=show,size_hint=(0.3,1),pos_hint={'x':-0.01})
    popupWindow.open()

def show_post():
    show = post()
    popupWindow=Popup(title='Are you sure?',content=show,size_hint=(0.5,0.5),pos=(400,400))
    popupWindow.open()

def shownega():
    show = nega()
    popupWindow=Popup(title='Are you sure?',content=show,size_hint=(0.5,0.5),pos=(400,400))
    popupWindow.open()


class MyMainApp(App):
    pass
    # def build(self):
    #     return kv



if __name__ == '__main__':
    MyMainApp().run()