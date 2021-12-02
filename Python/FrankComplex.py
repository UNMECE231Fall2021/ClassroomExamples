#import math #math.sqrt()
#from math import *
from math import sqrt
from math import atan
from math import pi

class Complex:
    # Constructor
    def __init__(self, re=0, im=0):
        self.real = re
        self.imag = im

    # Destructor
    def __del__(self):
        pass

    # 'Operator' overloading
    # '+' operator
    def __add__(self, other):
        return self.add(other)

    # '-' operator
    def __sub__(self, other):
        return self.sub(other)

    # '*' operator
    def __mul__(self, other):
        return self.mult(other)

    # '/' operator
    def __truediv__(self, other):
        return self.div(other)

    # Overload print() function
    def __str__(self):
        if (self.imag < 0):
            #return str(self.real) + " - " + str(-self.imag) + "j" 
            return f"{self.real} - {-self.imag}j"
        else:
            #return str(self.real) + " + " + str(self.imag) + "j" 
            return f"{self.real} + {self.imag}j"

    # Normal division '/'
    # Floor division '//'

    # General methods
    def mag(self):
        return sqrt((self.real ** 2) + (self.imag  ** 2))

    def phase(self):
        assert(self.real != 0)
        radian_phase = atan(self.imag / self.real)
        degree_phase = radian_phase * (180/pi)
        return degree_phase

    def conjugate(self):
        result =  Complex(self.real, -self.imag)
        return result

    def add(self, other):
        return Complex(self.real + other.real, self.imag + other.imag)
    
    def sub(self, other):
        return Complex(self.real - other.real, self.imag - other.imag)

    def mult(self, other):
        real_result = (self.real * other.real) - (self.imag * other.imag)
        imag_result = (self.real * other.imag) + (self.imag * other.real)
        result = Complex(real_result, imag_result)
        return result

    def div(self, other):
        conj = other.conjugate()
        divisor = conj.mag() ** 2
        assert(divisor != 0)

        result = self.mult(conj)
        result.real /= divisor
        result.imag /= divisor
        return result
