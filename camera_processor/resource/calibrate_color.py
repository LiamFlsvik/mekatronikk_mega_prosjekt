import cv2
from cvzone.ColorModule import ColorFinder

cap = cv2.VideoCapture(2)  # Valg av kamera
color_finder = ColorFinder(True)

while True:
    success, img = cap.read()
    if not success:
        continue
    img_color, mask = color_finder.update(img)
    cv2.imshow("Color Calibration", img_color)
    cv2.waitKey(1)
