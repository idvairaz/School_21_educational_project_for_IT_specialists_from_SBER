def data_types():

    a = 42
    b = "Hello"
    c = 3.14
    d = True
    e = [1, 2, 3]
    f = {"name": "John", "age": 30}
    g = (1, 2, 3)
    h = {1, 2, 3}

############################### Первый способ ##########################################

    type_names = [
        type(a),
        type(b),
        type(c),
        type(d),
        type(e),
        type(f),
        type(g),
        type(h)
    ]

    # output = "["
    
    # for i, t in enumerate(type_names):
    #     if i!= 0:
    #         output = output + ", "
    #     output = output + t.__name__

    # output = output + "]"

############################### Второй способ ##########################################

    arr = [a, b, c, d, e, f, g, h]
    output = "[" 

    for i in arr:
        output = output + type(i).__name__ + ", "

    output = output[:-2] + "]"

############################### Третий способ ##########################################

    # arr = [a, b, c, d, e, f, g, h]

    # type_names = [type(i).__name__ for i in arr]
    # str = ", ".join(type_names)
    # output = "[" + str + "]"


    print(output)
    # print(c)                # 3.14
    # print(type(c))          # <class 'float'>
    # print(type(c).__name__) # float
    # print(type_names)       # 1 [<class 'int'>, <class 'str'>, <class 'float'>, <class 'bool'>, <class 'list'>, <class 'dict'>, <class 'tuple'>, <class 'set'>]
                            # 3 ['int', 'str', 'float', 'bool', 'list', 'dict', 'tuple', 'set']

if __name__ == '__main__':
    data_types()
    
