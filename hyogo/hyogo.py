import cv2
cap = cv2.VideoCapture(0)

fmt = cv2.VideoWriter_fourcc('m', 'p', '4', 'v')

fps = 15.0
size = (640, 360)
writer = cv2.VideoWriter('out1.m4v', fmt, fps, size)

face_cascade_file5 = "haarcascade_frontalface_alt.xml"
face_cascade_5 = cv2.CascadeClassifier(face_cascade_file5)

pic_file = "Harbor.jpg"
pic_face = cv2.imread(pic_file)

pic2_file = "Luminarie.jpg"
pic2_face = cv2.imread(pic2_file)


def pic_face_func(img, rect):
    (x1, y1, x2, y2) = rect
    w = x2 - x1
    h = y2 - y1

    if(w < 150):
        img_face = cv2.resize(pic_face, (w, h))
    else:
        img_face = cv2.resize(pic2_face, (w, h))

    img2 = img.copy()
    img2[y1:y2, x1:x2] = img_face
    return img2


while True:
    # 画像を取得
    _, img = cap.read()
    img = cv2.resize(img, size)
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    faces = face_cascade_5.detectMultiScale(gray, 1.1, 2)

    for (x, y, w, h) in faces:
        img = pic_face_func(img, (x, y, x+w, y+h))

    cv2.imshow('img', img)

    # ESCかEnterキーが押されたら終了
    k = cv2.waitKey(1)
    if k == 13:
        break

cap.release()
cv2.destroyAllWindows()
