
from PIL import Image

def write_image(image, filename):
    height = image.height
    width = image.width

    f = open(filename, "wb")

    f.write(height.to_bytes(2, byteorder='big'))
    f.write(width.to_bytes(2, byteorder='big'))
    img_raster = []
    for i in range(height):
        for j in range(width):
            img_raster.extend(image.getpixel((j, i))[:3])

    f.write(bytearray(img_raster))
    f.close()

def read_2bytes(f):
    bytes = f.read(2) # [int(f.read(1)), int(f.read(1))]
    return int.from_bytes(bytes, byteorder = 'big')


def read_image(filename):
    f = open(filename, "rb")
    height = read_2bytes(f)
    width = read_2bytes(f)
    image = Image.new("RGB", (width, height))
    bytes = f.read()
    for i in range(height):
        for j in range(width):
            image.putpixel((j, i), (bytes[3*(i*width + j)+0],
                                    bytes[3*(i*width + j)+1],
                                    bytes[3*(i*width + j)+2]))

    return image

# #Write a png image to bin
# image = Image.open("UofTPres.jpg")
# write_image(image, "6x5.bin")
# image = Image.open("UofTPres.jpg")
# write_image(image, "3x4.bin")

#Read image from a bin file, save it to png
#im2 = read_image("a.bin")
im3 = read_image("new.bin")
im3.save("grad.png")


# Write multiple images from bin to png
# for i in range(200):
#     image = read_image("6x5.bin" % i)
#
#     image.save("new.png" % i)
#img_raster.extend(image.getpixel((j, i)))