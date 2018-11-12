from domain.domain import IDObj


class Book(IDObj):
    def __init__(self, bookId, title, description, author):
        IDObj.__init__(self, bookId)
        self.__title = title
        self.__description = description
        self.__author = author
        self.__available = True

    def setTitle(self, b):
        self.__title = b

    def setDescription(self, c):
        self.__description = c

    def setAuthor(self, d):
        self.__author = d

    def getTitle(self):
        return self.__title

    def getDescription(self):
        return self.__description

    def getAuthor(self):
        return self.__author

    def __str__(self):
        result = ''
        result += str(self.getID()).zfill(3) + '. ' + str(self.__title) + " by " + str(self.__author) + "\n"
        result += "->" + str(self.__description) + '\n'
        if self.get_available() is True:
            result += "Status: Available\n"
        else:
            result += "Status: Unavailable\n"
        return result

    def __eq__(self, other):
        return isinstance(other, self.__class__) and other.getID() == self.getID()

    def get_available(self):
        return self.__available

    def set_available(self, a):
        self.__available = a

    @staticmethod
    def create_book(a, b, c, d):
        return Book(a, b, c, d)

    @staticmethod
    def readBookFromLine(line):
        parts = line.split("|")
        return Book(int(parts[0]), parts[1], parts[2], parts[3])

    @staticmethod
    def writeBookToLine(book):
        return str(book.getID())+'|'+book.getTitle()+'|'+book.getDescription()+'|'+book.getAuthor()+'|'+str(book.get_available())

