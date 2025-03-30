#	converts things to strings -- even tuples, lists, and dicts

import types
import string


def tostr(x):
    t = type(x)
    if t is dict:
        return '{' + ", ".join( map(lambda k, d=x: tostr(k) + ": " + tostr(d[k]), x.keys()  ) ) + "}"

    if t is list:
        return '[' + ", ".join( map(lambda i: tostr(i), x) ) + "]"

    return str(x)