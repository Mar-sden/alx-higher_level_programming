#!/usr/bin/python3
def add_tuple(tuple_a=(), tuple_b=()):
    new_a = [0, 0]
    new_b = [0, 0]

    if len(tuple_a) >= 2:
        new_a = tuple_a[:2]
    elif len(tuple_a) == 1:
        new_a[0] = tuple_a[0]

    if len(tuple_b) >= 2:
        new_b = tuple_b[:2]
    elif len(tuple_b) == 1:
        new_b[0] = tuple_b[0]

    return tuple((new_a[x] + new_b[x]) for x in range(2))
