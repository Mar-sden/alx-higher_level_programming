#!/usr/bin/python3
def divisible_by_2(my_list=[]):
    is_div = []
    for n in my_list:
        if n % 2 == 0:
            is_div.append(True)
        else:
            is_div.append(False)
    return is_div
