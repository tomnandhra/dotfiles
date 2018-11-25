#!/bin/sh

# set wallpaper
hsetroot -tile /Pictures/texture.jpg -tint "#1d1f27" -contrast 1.1

# load Xresources
xrdb -load ~/.Xresources

# set keyboard layout
setxkbmap gb

# open dunst
dunst -config ~/.config/dunst/dunstrc &


# start i3
exec i3
