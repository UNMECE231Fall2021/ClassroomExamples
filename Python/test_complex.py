import FrankComplex

def main():
    a = FrankComplex.Complex(1, 1)
    print(a)
    print(a.mag());
    print(a.phase());
    print("")

    b = FrankComplex.Complex(3, 4)
    print(b)
    print(b.mag());
    print(b.phase());
    print("")

    c = FrankComplex.Complex(5, 12)

    print(b.add(c))
    print(b.sub(c))
    print(b.mult(c))
    print(b.div(c))
    print("")

    print(b + c) # __add__
    print(b - c) # __sub__
    print(b * c) # __mul__
    print(b / c) # __truediv__

if __name__ == "__main__":
    main()
