from datetime import datetime, date
from controller.ControllerException import ControllerException
from controller.UndoController import FunctionCall, Operation


class RentalController:
    def __init__(self, repo, brepo, crepo, undoController):
        self.__Rentalrepo = repo
        self.__Bookrepo = brepo
        self.__Clientrepo = crepo
        self.__UndoController = undoController

    def getRental(self, ID):
        """

        :param ID:
        :return:
        """
        return self.__Rentalrepo.get(ID)

    def addRental(self, rental):
        """

        :param rental:
        :return:
        """
        if self.__Bookrepo.findByID(rental.getBookID()) == -1:
            raise ControllerException("non existing book")
        elif self.__Clientrepo.findByID(rental.getClientID()) == -1:
            raise ControllerException("non existing client")
        elif self.__Bookrepo.get(rental.getBookID()).get_available() is False:
            raise ControllerException("unavailable book")
        self.__Rentalrepo.add(rental)
        self.__Bookrepo.get(rental.getBookID()).set_available(False)

        redo = FunctionCall(self.addRental, rental)
        undo = FunctionCall(self.deleteRental, rental.getID())
        operation = Operation(redo, undo)
        self.__UndoController.recordOperation(operation)

    def deleteRental(self, rentalID):
        """

        :param rentalID:
        :return:
        """
        self.__Rentalrepo.remove(rentalID)

    def returnBook(self, rentalID):
        """

        :param rentalID:
        :return:
        """

        if self.__Rentalrepo.findByID(rentalID) == -1:
            raise ControllerException("The rental doesn't exist.")
        else:
            now = datetime.now()
            self.__Rentalrepo.get(rentalID).setReturnedDate(date(2017, now.month, now.day))
            self.__Bookrepo.get(self.__Rentalrepo.get(rentalID).getBookID()).set_available(True)
            return self.__Rentalrepo.get(rentalID)

    def getAllRental(self):
        """

        :return:
        """
        return self.__Rentalrepo.getAll()

    def filterRentals(self, ID, tip):
        """

        :param ID:
        :param tip:
        :return:
        """
        result = []
        if tip == 1:
            for rental in self.__Rentalrepo.getAll():
                if ID == rental.getBookID():
                    result.append(rental)
        elif tip == 2:
            for rental in self.__Rentalrepo.getAll():
                if ID == rental.getClientID():
                    result.append(rental)
        elif tip == 3:
            for rental in self.__Rentalrepo.getAll():
                if ID == self.__Bookrepo.get(rental.getBookID()).getAuthor():
                    result.append(rental)
        elif tip == 4:
            for rental in self.__Rentalrepo.getAll():
                if ID == rental.getBookID() and rental.getReturnedDate() is None and rental.getDelay() > 0:
                    result.append(rental)
        return result

    def mostRentedBooks(self):
        """
        return the list of most rented books in descending order by the number of times they were rented
        :return:
        """

        temp_result = {}

        for book in self.__Bookrepo.getAll():
            if book.getID() not in temp_result.keys():
                temp_result[book.getID()] = 0
                rentals = self.filterRentals(book.getID(), 1)
                temp_result[book.getID()] += len(rentals)

        final_result = []
        for bookID in temp_result.keys():
            final_result.append(BookRentalCount(bookID, temp_result[bookID]))

        final_result.sort(reverse=True)
        return final_result

    def mostActiveClients(self):
        """
        out: final_result: sorted list of most active clients, sorted by number of rented books measured in days
        :return:
        """
        temp_results = {}
        for client in self.__Clientrepo.getAll():
            if client.getID() not in temp_results.keys():
                temp_results[client.getID()] = 0
            rentals = self.filterRentals(client.getID(), 2)
            rentalCount = 0
            for rental in rentals:
                rentalCount += len(rental)
            temp_results[client.getID()] += rentalCount

        final_result = []
        for clientID in temp_results.keys():
            final_result.append(ClientRentalCount(clientID, temp_results[clientID]))
        final_result.sort(reverse=True)
        return final_result

    def mostRentedAuthors(self):
        """
        returns sorted list of most rented authors, sorted by number of rented books having that author
        :return:
        """
        temp_result = {}
        for book in self.__Bookrepo.getAll():
            if book.getAuthor() not in temp_result.keys():
                temp_result[book.getAuthor()] = 0
                rentals = self.filterRentals(book.getAuthor(), 3)
                temp_result[book.getAuthor()] += len(rentals)
        final_result = []
        for bookAuthor in temp_result.keys():
            final_result.append(AuthorRentalCount(bookAuthor, temp_result[bookAuthor]))
        final_result.sort(reverse=True)
        return final_result

    def lateRentals(self):
        """
        returns the list of rentals for which the returned date is overdue sorted by number of days of delay
        :return:
        """
        temp_results = {}
        for book in self.__Bookrepo.getAll():
            if book.getID() not in temp_results.keys():
                temp_results[book.getID()] = 0
                rentals = self.filterRentals(book.getID(), 4)
                rentalCount = 0
                for rental in rentals:
                    rentalCount += rental.getDelay()
                temp_results[book.getID()] += rentalCount
        final_results = []
        for bookID in temp_results.keys():
            if temp_results[bookID] != 0:
                final_results.append(LateRentalCount(bookID, temp_results[bookID]))
        final_results.sort(reverse=True)
        return final_results


class BookRentalCount:
    def __init__(self, bookID, count):
        self.__book = bookID
        self.__count = count

    def getBook(self):
        return self.__book

    def getCount(self):
        return self.__count

    def __lt__(self, other):
        return self.getCount() < other.getCount()

    def __str__(self):

        result = "Book " + str(self.__book) + ' was rented ' + str(self.__count) + ' times'
        return result


class ClientRentalCount:
    def __init__(self, clientID, count):
        self.__client = clientID
        self.__count = count

    def getBook(self):
        return self.__client

    def getCount(self):
        return self.__count

    def __lt__(self, other):
        return self.getCount() < other.getCount()

    def __str__(self):
        result = "Client " + str(self.__client) + ' has rented books for ' + str(self.__count) + ' days'
        return result


class AuthorRentalCount:
    def __init__(self, author, count):
        self.__author = author
        self.__count = count

    def getBook(self):
        return self.__author

    def getCount(self):
        return self.__count

    def __lt__(self, other):
        return self.getCount() < other.getCount()

    def __str__(self):
        result = "Author " + str(self.__author) + ' was rented for ' + str(self.__count) + ' times'
        return result


class LateRentalCount:
    def __init__(self, book, count):
        self.__book = book
        self.__count = count

    def getBook(self):
        return self.__book

    def getCount(self):
        return self.__count

    def __lt__(self, other):
        return self.getCount() < other.getCount()

    def __str__(self):
        return 'Book ' + str(self.__book) + ' has been overdue for ' + str(self.getCount()) + ' days'
