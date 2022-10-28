import serial
import cv2
import numpy as np
from PIL import Image


data = []
cam = cv2.VideoCapture(0)

while True:
    _, img = cam.read()
    img = cv2.flip(img, 1)
    """img = Image.open(img)
    img = img.convert("L")"""
    data.append(img)
    cv2.imshow("test",img)
    if cv2.waitKey(1) > 0:
        break
print(len(data))



import tensorflow as tf

from tensorflow import keras

from tensorflow.keras import datasets, layers, models


model = keras.Sequential()
# Add an Embedding layer expecting input vocab of size 1000, and
# output embedding dimension of size 64.
model.add(layers.Embedding(input_dim=1000, output_dim=64))

# Add a LSTM layer with 128 internal units.
model.add(layers.LSTM(128))

# Add a Dense layer with 10 units.
model.add(layers.Dense(10))

model.summary()