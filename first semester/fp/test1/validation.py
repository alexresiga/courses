def validatePoem(poem):
    """
    validate if input poem is correct
    :param poem:
    :return:
    """
    for i in range(len(poem["lyrics"])-1):
        if poem["lyrics"][i][-3:] != poem["lyrics"][i+1][-3:]:
            return False
    return True
