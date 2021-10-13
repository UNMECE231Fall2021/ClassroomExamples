# Rectangle base class

## rectangle.hpp

The attributes of the class has an access specifier of *protected* rather than *private* because the class is being created with the intention of being a *base class*. A base class is a class that other classes will get information from, or will *inherit* from.

Additionally, there are two methods that are *protected*, `calc_area` and `calc_perimeter`.

The rest of the methods have an access specifier of *public* which is normal for creating an independent class. The only thing that is different from classes you've seen before is that the destructor, as well as the setters, are preceeded with the *virtual* keyword meaning that these methods are acticipated to change when another class inherits from the base class. So, in the future, other classes that inherit from the `Rectangle` class can change the destructor, as well as `set_length`, and `set_width`.

## Rectangle_methods.cpp

A lot of the methods look like a typical independent class. The only thing that is somewhat out of place is the empty destructor and this is done because **all virtual methods must be implemented**. At this point, the implementation of the Rectangle class is done and is ready to be inherited by other classes.

## cube.hpp

Here is where the beauty of object oriented programming shines. Since the newly created Cube class will inherit from the Rectangle class, it must include the rectangle header file.

```cpp
#include "rectangle.hpp"
```

Now the Cube class has access to inherit from the Rectangle class. The declaration of the Cube class is followed by `: public Rectangle` which means that the Cube class publicly inherits from the Rectangle class. Cube now becomes a *derived* class.

The *public* inheritance means that private attributes and methods are private for the partent class and cannot be accessed by the derived class, the protected attributes and methods stay protected in the Cube class. The public attributes and methods also remain public in the Cube class. This is why in the Rectangle base class has protected attributes and methods rather than private, although usually it is private. [For more information, I recommend clicking on this sentence that leads to cppreference](https://en.cppreference.com/w/cpp/language/access).

Some thing that sticks out is the redeclaration of `set_length` and `set_width`.

```cpp
void set_length(int length) override;
void set_width(int width) override;
```

At the end of each method declaration, the *override* keyword is used. The *override* keyword is introduced in C++11 and let's you explicitly tell the compiler that you are going to change the behavior of the method in the derived class. This means the `set_length` and `set_width` that are implemented in the derived Cube class will be different from the base Rectangle class. Of course, the details are shown in the `Rectangle_methods.cpp` file.

## Cube_methods.cpp

The first thing that is different from a typical independent classes is that in the constructors, the Cube class calls the constructors from the Rectangle class! This is one of the benefits of inheritance, having access to the attributes and methods of the base (or parent) class so that it can be used in the derived class.

The implementation of `set_length` and `set_width` are found after and it begins by calling the parent method of the method that is being overridden.

```cpp
void Cube::set_length(int length) {
    Rectangle::set_length(length);
    calc_surface_area();
    calc_volume();
}

void Cube::set_width(int width) {
    Rectangle::set_width(width);
    calc_surface_area();
    calc_volume();
}
```

So `Cube::set_length` calls `Rectangle::set_length`, and the same thing for `set_width` is done. This is advantageous as methods get reused.

One disadvantage is that when overloading the = and << operator, the methods (or friend functions in the case) must account for all attributes from both the base and derived class.