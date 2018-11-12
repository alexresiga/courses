from domain.domain import IDObj
from datetime import date
from random import randint


class Rental(IDObj):
    def __init__(self, rentalID, bookID, clientID, rentedDate, dueDate, returnedDate=None):
        IDObj.__init__(self, rentalID)
        self.__bookID = bookID
        self.__clientID = clientID
        self.__rentedDate = rentedDate
        self.__dueDate = dueDate
        self.__returnedDate = returnedDate

    def getBookID(self):
        return self.__bookID

    def getClientID(self):
        return self.__clientID

    def setBookID(self, a):
        self.__bookID = a

    def setClientID(self, b):
        self.__clientID = b

    def setRentedDate(self, d):
        self.__rentedDate = d

    def setDueDate(self, e):
        self.__dueDate = e

    def setReturnedDate(self, f):
        self.__returnedDate = f

    def getRentedDate(self):
        return self.__rentedDate

    def getDueDate(self):
        return self.__dueDate

    @staticmethod
    def create_rental(BID, CID, input_day, input_month):
        rentalID = int(str(BID) + str(CID) + str(randint(0, 9)))
        rentedDate = date(2017, input_month, input_day)
        returned_date = None
        dueDate = date(2018, rentedDate.month % 12 + 1, randint(1, 31))
        return Rental(rentalID, BID, CID, rentedDate, dueDate, returned_date)

    def getReturnedDate(self):
        return self.__returnedDate

    def __len__(self):
        if self.getReturnedDate() is None:
            return 0
        else:
            return (self.getReturnedDate() - self.getRentedDate()).days

    def getDelay(self):
        if self.getReturnedDate() is None:
            return (date.today() - self.getDueDate()).days

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.getID() == other.getID()

    @staticmethod
    def printReturned(rental):
        return 'Rental {}: book: {} rented by client {} on {}.{}.{} was returned on {}.{}.{}'.format(str(rental.getID()),
                                                                                                     str(rental.getBookID()),
                                                                                                     str(rental.getClientID()),
                                                                                                     str(rental.getRentedDate().day).zfill(2),
                                                                                                     str(rental.getRentedDate().month).zfill(2),
                                                                                                     str(rental.getRentedDate().year),
                                                                                                     str(rental.getReturnedDate().day).zfill(2),
                                                                                                     str(rental.getReturnedDate().month).zfill(2),
                                                                                                     str(rental.getReturnedDate().year))

    def __str__(self):
        return 'Rental {}: book: {} rented by client {} on {}.{}.{} and is due by {}.{}.{}'.format(str(self.getID()), str(self.__bookID),
                                                                                                   str(self.__clientID),
                                                                                                   str(self.__rentedDate.day).zfill(2),
                                                                                                   str(self.__rentedDate.month).zfill(2),
                                                                                                   str(self.__rentedDate.year),
                                                                                                   str(self.__dueDate.day).zfill(2),
                                                                                                   str(self.__dueDate.month).zfill(2),
                                                                                                   str(self.__dueDate.year))
