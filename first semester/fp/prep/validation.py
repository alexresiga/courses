def validateCircle(circle):
    """

    :param circle:
    :return:
    """
    if not isFloat(circle["x"]) or not isFloat(circle["y"]) or not isFloat(circle["r"]):
        raise ValueError("x, y and r must be float")
    else:
        if not circle["colour"]:
            raise ValueError("colour cannot be empty")


def isFloat(x):
    try:
        n = float(x)
        return n
    except ValueError:
        print("incorrect values")
    return


def isCircle(circle):
    if not isFloat(circle["x"]) or not isFloat(circle["y"]) or not isFloat(circle["r"]):
        print("x, y and r must be float")
        return False
    else:
        if not circle["colour"]:
            print("colour cannot be empty")
            return False
    return True
