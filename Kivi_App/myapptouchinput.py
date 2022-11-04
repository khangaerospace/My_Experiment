import kivy
from kivy.app import App
from kivy.uix.widget import Widget
from kivy.properties import ObjectProperty
from kivy.graphics import Rectangle
from kivy.graphics import Line
from kivy.graphics import Color


class Touch(Widget):
    btn = ObjectProperty(None)
    def __init__(self,**kwargs):
        super(Touch,self).__init__(**kwargs)

        with self.canvas:
            #Line(points = (20,30,400,60,500))
            # search rgba color code
            Color(1,0,0,.5,mode='rgba')# this code is for red
            self.rect = Rectangle(pos=(250.99999,208.0),size=(1  ,1))
            Color(1,1,0,.5,mode='rgba')# this code is for yellow
            self.rect2 = Rectangle(pos=(0,0),size=(50,50))

    def on_touch_down(self,touch):
        self.rect.pos = touch.pos
        print('mouse down',touch)
        self.btn.opacity  = 0.5
    def on_touch_move(self,touch):
        self.rect.pos = touch.pos
        print('mouse move',touch)
    def on_touch_up(self,touch):
        print('mouse up',touch)
        self.btn.opacity =1


class MyApp(App):
    def build(self):
        return Touch()



if __name__ == '__main__':
    MyApp().run()
