import kivy
from kivy.app import App
from kivy.uix.label import Label
from kivy.uix.gridlayout import GridLayout
from kivy.uix.textinput import TextInput
from kivy.uix.button import Button
import math


class MyGrid(GridLayout):
    def __init__(self, **kwargs):
        '''build the good page function'''
        super(MyGrid, self).__init__(**kwargs)
        self.cols = 1

        # self.inside = GridLayout()
        # self.inside.cols = 2


        #create text box to enter good point
        self.add_widget(Label(text = "Point for good"))
        self.point = TextInput(multiline = False)
        self.add_widget(self.point)
        #create the up button
        self.increase = Button(text = "up",font_size = 20)
        self.increase.bind(on_press=self.increased)
        self.add_widget(self.increase)
        #create a decrease button
        self.decrease = Button(text = "down",font_size = 20)
        self.decrease.bind(on_press=self.decreased)
        self.add_widget(self.decrease)
        # create the note text box
        self.add_widget(Label(text = "Note:  "))
        self.Note = TextInput(multiline = True)
        self.add_widget(self.Note)
        #create the action to get value
        self.submit = Button(text = "Good action",font_size = 40)
        self.submit.bind(on_press=self.pressed)
        self.add_widget(self.submit)

    def pressed(self, instance):
        ''' this fuction is the function of the good action button'''
        point1 = self.point.text
        Note1 = self.Note.text
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
        self.Note.text = ''
        #return grid
    def increased(self, instance):
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
    def decreased(self, instance):
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

    # def buildButton(self):
    #     self.submit = Button(text = "Good action",font_size = 20)
    #     return self.add_widget(self.submit)

class betterworld(App):
    def build(self):
        return MyGrid()

if __name__ == '__main__':
    betterworld().run()
    #TextBox().run()