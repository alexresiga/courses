from validation.validator import Validator
from interval import interval
from datetime import date
from domain.Book import Book
from domain.Client import Client
from domain.Rental import Rental
from random import randint


class UI:
    def __init__(self, controller1, controller2, controller3, controller4):
        self.__Bcontroller = controller1
        self.__Ccontroller = controller2
        self.__Rcontroller = controller3
        self.__Ucontroller = controller4
        self.validator = Validator()

    @staticmethod
    def printMenu():
        string = '\nAvailable commands:\n'
        string += '\t 1 - Add book\n'
        string += '\t 2 - add client\n'
        string += '\t 3 - Remove book\n'
        string += '\t 4 - remove client\n'
        string += '\t 5 - update book\n'
        string += '\t 6 - update client\n'
        string += '\t 7 - list all books\n'
        string += '\t 8 - list all clients\n'
        string += '\t 9 - Rent a book\n'
        string += '\t 10 - List all rentals\n'
        string += '\t 11 - Return a book\n'
        string += '\t 12 - Search books\n'
        string += '\t 13 - Search clients\n'
        string += '\t 14 - Most rented books\n'
        string += '\t 15 - Most active clients\n'
        string += '\t 16 - Most rented authors\n'
        string += '\t 17 - Late rentals\n'
        string += '\t 18 - Undo\n'
        string += '\t 19 - Redo\n'
        string += '\t 0 - Exit\n'
        print(string)

    @staticmethod
    def readInt(msg):
        """

        :param msg:
        :return:
        """
        while True:
            try:
                result = int(input(msg))
                if result < 0:
                    raise ValueError
                return result
            except ValueError:
                print("ID must be positive integer")

    @staticmethod
    def readDate():
        """

        :return:
        """
        while True:
            try:
                day = int(input("input day: "))
                month = int(input("input month: "))
                if day not in interval[1, 31] or month not in interval[1, 12]:
                    raise ValueError
                return date(2017, month, day)
            except ValueError:
                print("Invalid date format")

    @staticmethod
    def read_book():
        bookID = UI.readInt("Enter book ID: ")
        title = input("Enter title: ")
        author = input("Enter author: ")
        desc = input("Enter description: ")
        return Book(bookID, title, desc, author)

    @staticmethod
    def read_client():
        clientID = UI.readInt("Enter client ID: ")
        name = input("Enter client name: ")
        return Client(clientID, name=name)

    @staticmethod
    def read_rental():
        bookID = UI.readInt("enter book ID: ")
        clientID = UI.readInt("enter client ID: ")
        rentalID = int(str(bookID) + str(clientID) + str(randint(0, 9)))
        rentedDate = UI.readDate()
        dueDate = date(2017, rentedDate.month % 12 + 1, randint(1, 31))
        returnedDate = None
        return Rental(rentalID, bookID, clientID, rentedDate, dueDate, returnedDate)

    def mainMenu(self):
        UI.printMenu()
        while True:
            try:
                command = input("enter command ").strip()
                if command == '1':

                    book = UI.read_book()
                    self.__Ucontroller.newOperation()
                    self.__Bcontroller.addBook(book)
                    print("book added")
                elif command == '2':
                    client = UI.read_client()
                    self.__Ucontroller.newOperation()
                    self.__Ccontroller.addClient(client)
                    print("client added")
                elif command == '3':
                    ID = self.readInt("Book ID to be removed: ")
                    self.__Ucontroller.newOperation()
                    self.__Bcontroller.removeBook(ID)
                    print("Book removed")
                elif command == '4':
                    ID = self.readInt("Client ID to be removed: ")
                    self.__Ucontroller.newOperation()
                    self.__Ccontroller.removeClient(ID)
                    print("Client removed")
                elif command == '5':
                    print("Book to be updated: ")
                    newbook = UI.read_book()
                    self.__Ucontroller.newOperation()
                    self.__Bcontroller.updateBook(newbook)
                    print("book updated")
                elif command == '6':
                    print("client to be updated: ")
                    self.__Ucontroller.newOperation()
                    newclient = UI.read_client()
                    self.__Ccontroller.updateClient(newclient)
                    print("client updated")
                elif command == '7':
                    for x in self.__Bcontroller.getAllBooks():
                        print(str(x))
                elif command == '8':
                    for x in self.__Ccontroller.getAllClients():
                        print(str(x))
                elif command == '9':
                    rental = UI.read_rental()
                    self.__Ucontroller.newOperation()
                    self.__Rcontroller.addRental(rental)
                    print(rental)
                elif command == '10':
                    for x in self.__Rcontroller.getAllRental():
                        print(str(x))
                elif command == '11':
                    rentalID = self.readInt("Enter rental ID: ")
                    self.__Rcontroller.returnBook(rentalID)
                    print(Rental.printReturned(self.__Rcontroller.getRental(rentalID)))
                elif command == '12':
                    substring = input("Enter keywords: ").lower()
                    for x in self.__Bcontroller.searchBook(substring):
                        print(str(x))
                elif command == '13':
                    substring = input("Enter keywords: ").lower()
                    for x in self.__Ccontroller.searchClient(substring):
                        print(str(x))
                elif command == '14':
                    for x in self.__Rcontroller.mostRentedBooks():
                        print(x)
                elif command == '15':
                    for x in self.__Rcontroller.mostActiveClients():
                        print(x)
                elif command == '16':
                    for x in self.__Rcontroller.mostRentedAuthors():
                        print(x)
                elif command == '17':
                    for x in self.__Rcontroller.lateRentals():
                        print(x)
                elif command == '18':
                    self.__Ucontroller.undo()
                elif command == '19':
                    self.__Ucontroller.redo()
                elif command == 'help':
                    UI.printMenu()
                else:
                    print("Invalid command. Type 'help' to see available commands")
            except Exception as exc:
                print(str(exc))
