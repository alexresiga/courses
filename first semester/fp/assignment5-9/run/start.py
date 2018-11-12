from UI.UI import UI
from UI.GUI import GUI
from domain.Book import Book
from domain.Client import Client
from domain.Rental import Rental
from controller.BookController import BookController
from controller.ClientController import ClientController
from controller.RentalController import RentalController
from controller.UndoController import UndoController
from repository.repository import Repository, FileRepository
from datetime import date
from tkinter import *

Brepo = FileRepository('books.txt', Book.readBookFromLine, Book.writeBookToLine)

Crepo = FileRepository('clients.txt', Client.readClientFromLine, Client.writeClientToLine)

Rrepo = Repository()
Rrepo.add(Rental(16675, 16, 67, date(2017, 11, 10), date(2017, 12, 11)))
Rrepo.add(Rental(12675, 12, 67, date(2017, 11, 1), date(2017, 11, 11)))
Rrepo.add(Rental(13115, 13, 11, date(2017, 11, 21), date(2017, 11, 11)))
Rrepo.add(Rental(13678, 13, 67, date(2017, 11, 7), date(2017, 11, 20)))
Rrepo.add(Rental(12622, 12, 62, date(2017, 11, 18), date(2017, 1, 11)))
Rrepo.add(Rental(14675, 14, 67, date(2017, 11, 5), date(2017, 11, 24)))
Rrepo.add(Rental(14637, 14, 63, date(2017, 11, 10), date(2017, 10, 11)))
Rrepo.add(Rental(14671, 14, 67, date(2017, 11, 9), date(2017, 12, 11)))
Rrepo.add(Rental(16652, 16, 65, date(2017, 11, 4), date(2017, 11, 16)))
Rrepo.add(Rental(15661, 15, 66, date(2017, 11, 12), date(2017, 10, 30)))
Rrepo.add(Rental(12629, 12, 62, date(2017, 11, 13), date(2017, 11, 25)))
Rrepo.add(Rental(15695, 15, 69, date(2017, 11, 19), date(2017, 11, 24)))
Rrepo.add(Rental(16770, 16, 77, date(2017, 11, 2), date(2017, 11, 24)))

Ucontroller = UndoController()
Bcontroller = BookController(Brepo, Ucontroller, Rrepo)
Ccontroller = ClientController(Crepo, Ucontroller, Rrepo)
Rcontroller = RentalController(Rrepo, Brepo, Crepo, Ucontroller)

ui = UI(Bcontroller, Ccontroller, Rcontroller, Ucontroller)
# ui.mainMenu()

root = Tk()
gui = GUI(root, Bcontroller, Ccontroller, Rcontroller, Ucontroller)
root.mainloop()
