#!/usr/bin/python3

def no_c(my_string):
    chars = list(my_string)
    chars = [ch for ch in chars if ch not in "cC"]
    return "".join(chars)
