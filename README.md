# EmojiShirt
Use Arduino with a 32x32 RGB Matrix to create a light up emoji shirt

Supports both Discord and native unicode emojis

## Instructions
* Add whatever emojis you want into `emoji_list.txt` and then run `emoji_to_image.py` which populates the `emojis/` folder (note for Discord emojis send a message into a server with `\` + the emoji you want to extract its code or native version)
* Go into the `emojis/` folder and copy the first line for whatever you want to light up
* Replace whatever emoji data is currently in `EmojiLighter.ino` with those two lines into (technically only the first needs to be coppied, since the size should stay constant)
* Plug in and wire up an RGB Matrix, run the code, put it on a shirt...
