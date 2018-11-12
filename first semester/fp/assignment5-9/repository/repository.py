from repository.repositoryException import RepositoryException
import pickle


class Repository:
    def __init__(self):
        self._data = []

    def add(self, other):
        """
        store element into repository
        :param other: element to be stored
        :return:
        """
        if other in self._data:
            raise RepositoryException("existing element")
        self._data.append(other)

    def __str__(self):
        """

        :return:
        """
        result = ''
        for x in self._data:
            result += str(x) + '\n'
        return result

    def get(self, ID):
        """
        Get a book from the repository
        ID - ID for the element
        RepositoryException - If an invalid position is given
        """
        if self.findByID(ID) == -1:
            raise RepositoryException("Invalid element position")
        else:
            for x in self._data:
                if x.getID() == ID:
                    return x

    def findByID(self, ID):
        """

        :param ID:
        :return:
        """
        for x in self._data:
            if x.getID() == ID:
                return ID
        return -1

    def remove(self, ID):
        """

        :return:
        """
        if self.findByID(ID) == -1:
            raise RepositoryException("There is no element with given ID.")
        self._data[:] = [x for x in self._data if x.getID() != ID]

    def update(self, elem):
        if elem not in self._data:
            raise RepositoryException("Non existing element")
        idx = self._data.index(elem)
        self._data[idx] = elem

    def getAll(self):
        return self._data[:]

    def __len__(self):
        return len(self._data)


class FileRepository(Repository):

    def __init__(self, _filename, _readObjFromLine, _writeObjToLine):
        Repository.__init__(self)
        self.__readObjFromLine = _readObjFromLine
        self.__writeObjToLine = _writeObjToLine
        self.__filename = _filename
        try:
            self.__readAllFromFile()
        except FileNotFoundError:
            f = open(_filename, 'w')
            f.close()

    def __appendElemToFile(self, elem):
        with open(self.__filename, 'a') as f:
            line = self.__writeObjToLine(elem)
            f.write(line + '\n')

    def add(self, other):
        Repository.add(self, other)
        self.__appendElemToFile(other)

    def __writeAllToFile(self):
        with open(self.__filename, 'w') as f:
            for elem in self._data:
                line = self.__writeObjToLine(elem)
                f.write(line)

    def __readAllFromFile(self):
        with open(self.__filename, 'r') as f:
            for line in f.readlines():
                line = line.strip()
                if len(line) > 0:
                    o = self.__readObjFromLine(line)
                    self._data.append(o)

    def upd(self, elem):
        Repository.update(self, elem)
        self.__writeAllToFile()

    def rem(self, ID):
        Repository.remove(self, ID)
        self.__writeAllToFile()


class BinaryRepository(Repository):
    def __init__(self, _filename):
        Repository.__init__(self)
        self.__filename = _filename

    def writeToBinaryFile(self, elems):
        f = open(self.__filename, 'wb')
        pickle.dump(f, elems)
        f.close()

    def readBinaryFile(self):
        result = []
        try:
            f = open(self.__filename, 'wb')
            return pickle.load(f)
        except EOFError:
            return []
        except IOError as e:
            print("an error occured -" + str(e))
        return result
