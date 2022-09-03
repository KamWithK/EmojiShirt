import numpy as np
import emoji

from PIL import Image, ImageFont
from pilmoji import Pilmoji

SIZE = 16, 16
SHOW = False

emojis = []

with open("emoji_list.txt", "r", encoding="utf-8") as file:
    emojis = [line.rstrip() for line in file]

def emoji_to_image(emoji_string):
    with Image.new("RGB", (24, 24), (0, 0, 0)) as image:
        font = ImageFont.truetype("arial.ttf", 24)

        with Pilmoji(image) as pilmoji:
            pilmoji.text((0, 0), emoji_string, (0, 0, 0), font)

        image.thumbnail(SIZE)
        if SHOW: image.show()

        return image

def rgb_to_int(rgb):
    red, green, blue = rgb[0], rgb[1], rgb[2]
    return (((red & 0xf8) << 8) + ((green & 0xfc) << 3) + (blue >> 3))

def get_emoji_data(emoji):
    image = emoji_to_image(emoji)
    data = np.array(list(image.getdata())).reshape((*image.size, 3))

    return data, image

format_list = lambda list_input : "{" + ", ".join([str(item) for item in list_input]) + "}"
to_string = lambda data : format_list([format_list([rgb_to_int(col) for col in row]) for row in data])
cpp_array_string = lambda data_string, rows, cols : f"uint16_t data[{rows}][{cols}] = {data_string};"
cpp_array_size_string = lambda rows, cols : f"int data_size[2] = " + "{" + f"{rows}, {cols}" + "};"

to_cpp_format = lambda data, image : f"{cpp_array_string(to_string(data), *image.size)}\n{cpp_array_size_string(*image.size)}"

def write_to_file(string_input, file_name):
    with open(f"emojis/{file_name}.txt", "w") as file:
        file.write(string_input)

emoji_name = lambda emoji_string : emoji.demojize(emoji_string).split(":")[1]
save_emoji = lambda emoji_string : write_to_file(to_cpp_format(*get_emoji_data(emoji_string)), emoji_name(emoji_string))

[save_emoji(emoji) for emoji in emojis]
