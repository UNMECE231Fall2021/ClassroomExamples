#import matplotlib.pyplot as plt
from matplotlib import pyplot as plt

def quad(x):
    return x * x

def main():
    x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    y = [quad(i) for i in x]

    for i in y:
        print(f"{i=}") # i = x

    #plt.plot(x, x, 'g^')
    plt.plot(x, x, 'k--')
    plt.show()

    #plt.plot(x, y, "ro")
    plt.plot(x, y, "b-")
    plt.show()

if __name__ == "__main__":
    main()
