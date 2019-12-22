import os
import copy
import progressbar
import cv2
import numpy as np
import time

# Image will be decreased in size by scale
scale = 3
# Size of small images. Images will be rescaled! 
# So they should originally have close to this ratio to look natural.
pixelSizeX = 20
pixelSizeY = 28
# Path to image you want to create
collageImage = "../koska.png"
# Path to folder with images
pathToImagesFolder = "images"
# Path to save image
pathToSave = "../collage.png"

def getMediums(img):
    bgr = (0, 0, 0)
    div = pixelSizeX * pixelSizeY
    for k in img:
        for p in k:
            bgr += p
    bgr[:] = bgr[:]/div
    return bgr

os.chdir(pathToImagesFolder)
listOfImages = os.listdir()
images = list()
mediums = list()

timeStart = time.time()

for i in listOfImages:
    im = cv2.imread(i)
    im = cv2.resize(im, (pixelSizeX, pixelSizeY))
    images.append(im)
    mediums.append(getMediums(im))

print("Time: ", (time.time()-timeStart))
img = cv2.imread(collageImage)
print("Shape of original image")
print(img.shape)
img = cv2.resize(img, (int((img.shape[1] / scale) * (pixelSizeY / pixelSizeX)), int(img.shape[0] / scale)))
print("Shape of scaled image")
print(img.shape)

cv2.imshow("image", img)
result = np.zeros((img.shape[0] * pixelSizeY, img.shape[1] * pixelSizeX, 3), np.uint8)
print("Shape of collage image")
print(result.shape)

bar = progressbar.ProgressBar(img.shape[0]*img.shape[1], widgets=None, term_width=100)
bar.start()
cntr = 0

for row in range(img.shape[0]):
    for col in range(img.shape[1]):
        cntr += 1
        bar.update(cntr)
        lookFor = img[row][col]
        minDist = 1000000
        index = 0
        for i in range(mediums.__len__()):
            dist = (lookFor[0] - mediums[i][0])**2 + (lookFor[1] - mediums[i][1])**2 + (lookFor[2] - mediums[i][2])**2
            if dist < minDist:
                minDist = dist
                index = i
        temp = copy.copy(images[index])
        counter = 0
        result[row*pixelSizeY:(row+1)*pixelSizeY, col*pixelSizeX:(col + 1) * pixelSizeX] = temp
cv2.imwrite(pathToSave, result)
print("finished")
print("Time: ", (time.time()-timeStart))
