def inverse_dict(dict = {}):
    print (dict.items())
    inversed_dict = {}
    if dict is None:
        return None
    for key,value in dict.items():
        inversed_dict[value] = key

    return inversed_dict

dict1 = {"bob":1, "mary":2, "sasha":3}

dict2 = inverse_dict(dict1)
print(dict2)