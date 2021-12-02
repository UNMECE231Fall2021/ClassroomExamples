def main():
    x = [3, 5, "hello"]
    y = (3, 5, "hello")
    a = 25
    z = {'name' : "frankie", "age" : a}
    print(z)
    print("My name is", z["name"])
    print("I am", z["age"], "years old")

    #print(len(x))
    '''
    x[0] = 12
    for i in range(len(x)):
        print(x[i])
    '''

if __name__ == "__main__":
    main()
