from PIL import Image

img = Image.open("arvore.jpeg")
# img.show()
img.save("arvore2.jpeg")
img.save("arvore2.png")
print(img.size)
img_resized = img.resize((30,30))
img_resized.save("small.jpeg")
print(img_resized.size)
pixeis = img_resized.load()
R = 200
G = 200
B = 200

cor = (R,G,B)
pixeis[3,3] = cor

img_resized.show()