#!/bin/sh

# set wallpaper
hsetroot -tile ~/Pictures/texture.jpg -tint "#1d1f27" -contrast 1.1

# load Xresources
xrdb -load ~/.Xresources

# set keyboard layout
setxkbmap gb

# open dunst
dunst -config ~/.config/dunst/dunstrc &

# welcome message
dunstify "Hello Tom"

# polybar
pkill polybar
sh ~/.config/polybar/launch.sh -r &

# start compton
compton --config ~/.config/compton/config &

# start window manager
2bwm&
exec urxvt
