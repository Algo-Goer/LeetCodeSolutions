import os

def rm_space():
    for f in os.listdir("."):
        if f.find(" ") > 0:
            n  =  f.replace(" ", "_")
            if n != f:
                os.rename(f, n)
            else:
                os.rename(f, "_"+n)

rm_space()