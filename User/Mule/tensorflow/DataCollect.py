import numpy as np
import cv2
from PIL import Image
import time

cam = cv2.VideoCapture(0)
"""cam.set(cv2.CAP_PROP_FRAME_WIDTH, 1920)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT, 1080)"""
action = [0, 1, 2]
x_data, y_data = [], []
cnt, i = 0, 0

while cam != 0:
    _, img = cam.read()
    img = cv2.flip(img, 1)
    x_data.append(img)
    y_data.append(action[i])
    #print(np.array(img).shape)#480, 640, 3
    cv2.imshow("DataCollet", img)
    #time.sleep(1)
    cnt += 1
    if cnt >= 20:
        i += 1
        cnt = 0
        if i > 2:
            cv2.destroyAllWindows()
            break
        time.sleep(2)
    if cv2.waitKey(1) > 0:
        cv2.destroyAllWindows()
        break
print(np.array(x_data).shape)
print(np.array(y_data).shape)

import tensorflow as tf

from keras import datasets, layers, models
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split

y_data = np.array([y_data])
y_data = y_data.T

x_train, x_test, y_train, y_test = train_test_split(x_data, y_data)
x_train, x_test, y_train, y_test = np.array(x_train), np.array(x_test), np.array(y_train), np.array(y_test)
print(x_train.shape, x_test.shape, y_train.shape, y_test.shape)

model = models.Sequential()
model.add(layers.Conv2D(32, (3, 3), activation='relu', input_shape=(480, 640, 3)))
model.add(layers.MaxPooling2D((2, 2)))
model.add(layers.Conv2D(64, (3, 3), activation='relu'))
model.add(layers.MaxPooling2D((2, 2)))
model.add(layers.Conv2D(64, (3, 3), activation='relu'))

model.add(layers.Flatten())
model.add(layers.Dense(64, activation='relu'))
model.add(layers.Dense(10, activation='softmax'))

model.compile(optimizer='adam',
              loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
              metrics=['accuracy'])

history = model.fit(x_train, y_train, epochs=10, 
                    validation_data=(x_test, y_test))


plt.plot(history.history['accuracy'], label='accuracy')
plt.plot(history.history['val_accuracy'], label = 'val_accuracy')
plt.xlabel('Epoch')
plt.ylabel('Accuracy')
plt.ylim([0.5, 1])
plt.legend(loc='lower right')

test_loss, test_acc = model.evaluate(x_test, y_test, verbose=2)

print(test_acc)

model.save(r"2022_Hackathon\User\Mule\tensorflow\save_model\model.h5")