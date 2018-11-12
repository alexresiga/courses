class RepositoryException(Exception):
    pass


class Repository:
    def __init__(self):
        self.__data = []

    def add(self, elem):
        if elem in self.__data:
            raise RepositoryException("existing weapon")
        self.__data.append(elem)

    def __str__(self):
        result = ''

        for x in self.__data:
            result += str(x) + '\n'

        return result

    def remove(self, elem):
        if elem not in self.__data:
            raise RepositoryException("non existing element")
        self.__data.remove(elem)

    def find(self, elem):
        if elem not in self.__data:
            raise RepositoryException("non existing element")
        idx = self.__data.index(elem)
        return self.__data[idx]

    def getAll(self):
        return self.__data[:]

    def size(self):
        return len(self.__data)

