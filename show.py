#!/usr/bin/env python3

import tkinter as tk

from sys import argv

X = 0
Y = 1
W = 2
H = 3

window_size = 1000

def load_rects(path):
    f = open(path, 'r')
    return [list(map(int, i.split())) for i in f.readlines()]
    f.close()


def get_size(rects):
    width = 0
    height = 0

    for rect in rects:
        if rect[X] + rect[W] > width:
            width = rect[X] + rect[W]
        if rect[Y] + rect[H] > height:
            height = rect[Y] + rect[H]

    return width, height


rectangles = load_rects(argv[1])

width, height = get_size(rectangles)
print(width, height)
extent = max(width, height)

root = tk.Tk()
root.resizable(width = False, height = False)

canvas = tk.Canvas(root, width = window_size, height = window_size)
canvas.pack()

for rect in rectangles:
    canvas.create_rectangle((rect[X] / extent) * window_size,
                            (rect[Y] / extent) * window_size,
                            ((rect[X] + rect[W]) / extent) * window_size,
                            ((rect[Y] + rect[H]) / extent) * window_size,
                            fill='#ff00ff', width=1)

root.mainloop()

