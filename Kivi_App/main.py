''' show how to use gridlayout and create kivy file'''
import kivy
from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.properties import ObjectProperty

class MyGrid1(Widget):
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
        except:
            if point1 == '':
                print('please enter something')
            else:
                print("point should be a number")

        #print(point1, Note1)
        self.point.text = ""
        self.note.text = ''
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







class BetterApp(App):
    def build(self):
        return MyGrid1()


if __name__ == '__main__':
    BetterApp().run()