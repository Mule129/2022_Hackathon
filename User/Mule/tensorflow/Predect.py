import keras
import cv2
import numpy as np
width, height = 320, 240
cam = cv2.VideoCapture(1)
cam.set(cv2.CAP_PROP_FRAME_WIDTH, width)
cam.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
model_1 = keras.models.load_model(r"2022_Hackathon\User\Mule\tensorflow\save_model\model.h5")
while True:
    _, img = cam.read()
    img = cv2.flip(img, 1)
    cv2.imshow("Predect", img)
    img = np.array(img)
    
    img = np.array([img])
    
    prd = model_1.predict(img)
    print(f"predicton : {prd}")
    if cv2.waitKey(1) > 0:
        break