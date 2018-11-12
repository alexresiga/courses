from domain.domain import IDObj


class Client(IDObj):
    def __init__(self, clientID, name):
        IDObj.__init__(self, clientID)
        self.__name = name

    def setName(self, b):
        self.__name = b

    def getName(self):
        return self.__name

    def __str__(self):
        result = ''
        result += str(self.getID()).zfill(3) + ". " + str(self.__name) + "\n"
        return result

    def __eq__(self, other):
        return isinstance(other, self.__class__) and other.getID() == self.getID()

    @staticmethod
    def create_client(a, b):
        return Client(a, b)

    @staticmethod
    def readClientFromLine(line):
        parts = line.split("|")
        return Client(int(parts[0]), parts[1])

    @staticmethod
    def writeClientToLine(client):
        return str(client.getID()) + '|' + client.getName()
