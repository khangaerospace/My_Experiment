''' this is to see how to use floeat layout'''

import kivy
from kivy.app import App
from kivy.uix.floatlayout import FloatLayout

class MyWorldApp(App):
    def build(self):
        return FloatLayout()

if __name__ == '__main__':
    MyWorldApp().run()