from controller.ControllerException import ControllerException
from validation.validator import Validator
from controller.UndoController import FunctionCall, Operation


class BookController:
    def __init__(self, repo, undoController, rentalRepo):
        self.__bookRepo = repo
        self.validator = Validator()
        self.__rentalrepo = rentalRepo
        self._undoController = undoController

    def __str__(self):
        """

        :return: formatted string of the repo
        """
        result = ''
        for x in self.__bookRepo.getAll():
            result += str(x) + '\n'
        return result

    def addBook(self, book):
        """
        function that adds book to repo
        input: book of type Book
        """
        self.validator.validateBook(book)
        self.__bookRepo.add(book)

        # IF there are no errors we continue to append data for undo/repo

        redo = FunctionCall(self.addBook, book)
        undo = FunctionCall(self.removeBook, book.getID())
        operation = Operation(redo, undo)

        self._undoController.recordOperation(operation)

    def removeBook(self, ID):
        """
        handles removal of element from repository
        :param ID: ID for book to be removed
        :return:
        """
        redo = FunctionCall(self.removeBook, ID)
        undo = FunctionCall(self.addBook, self.__bookRepo.get(ID))
        operation = Operation(redo, undo)

        self.__bookRepo.remove(ID)

        for rental in self.__rentalrepo.getAll():
            if rental.getBookID() == ID:
                self.__rentalrepo.remove(rental.getID())
        self._undoController.recordOperation(operation)

    def updateBook(self, abook):
        """

        :param abook:
        :return:
        """
        redo = FunctionCall(self.updateBook, abook)
        undo = FunctionCall(self.updateBook, self.__bookRepo.get(abook.getID()))
        operation = Operation(redo, undo)
        self._undoController.recordOperation(operation)
        self.validator.validateBook(abook)
        self.__bookRepo.update(abook)

    def getBook(self, idx):
        """
        return the book having the ID idx
        :param idx: id of book retrieved
        :return: book having that ID
        """
        return self.__bookRepo.get(idx)

    def getAllBooks(self):
        """
        return the list of all books
        :return:
        """
        return self.__bookRepo.getAll()

    def searchBook(self, substring):
        """
        function that searches substring in book repository
        :param substring: keywords
        :return: list of books which contain searched keywords
        """
        if substring == '':
            raise ControllerException("no keywords were given")
        result = []
        for x in self.__bookRepo.getAll():
            if substring in str(x.getID()).lower() or substring in str(x.getAuthor()).lower() or substring in str(x.getTitle()).lower() or substring in str(x.getDescription()).lower() or substring in str(x.get_available).lower():
                result.append(x)
        if not result:
            raise ControllerException("No entries match your search")
        else:
            return result
