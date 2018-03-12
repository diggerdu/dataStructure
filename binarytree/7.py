import os
def commonAncestor(m, n):
    return int(os.path.commonprefix((bin(m), bin(n))), 2)

