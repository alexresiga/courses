import unittest
from controller.RentalController import RentalController, ControllerException, LateRentalCount, BookRentalCount, AuthorRentalCount, ClientRentalCount
from repository.repository import Repository
from domain.Rental import Rental
from domain.Client import Client
from domain.Book import Book
from datetime import date
from controller.UndoController import UndoController


class TestRentalController(unittest.TestCase):
    def setUp(self):
        self.repo = Repository()
        self.brepo = Repository()
        self.crepo = Repository()
        self.Ucontroller = UndoController()
        self.book = Book(21, 'titlu', 'descriere', 'author')
        self.book2 = Book(22, 'titlu2', 'descriere2', 'author')
        self.brepo.add(self.book)
        self.brepo.add(self.book2)
        self.client = Client(23, 'alex')
        self.client2 = Client(24, 'ana')
        self.client3 = Client(29, 'ana')

        self.crepo.add(self.client)
        self.crepo.add(self.client2)
        self.rental = Rental(21236, 21, 24, date(2017, 11, 5), date(2017, 12, 6), date(2017, 12, 5))
        self.rental2 = Rental(21238, 22, 24, date(2017, 11, 5), date(2017, 12, 6), date(2017, 12, 5))
        self.rental3 = Rental(21238, 23, 24, date(2017, 11, 5), date(2017, 12, 6), date(2017, 12, 5))
        self.rental4 = Rental(21238, 21, 29, date(2017, 11, 5), date(2017, 12, 6), date(2017, 12, 5))
        self.rental5 = Rental(21231, 21, 23, date(2017, 11, 5), date(2017, 10, 6), None)

        self.controller = RentalController(self.repo, self.brepo, self.crepo, self.Ucontroller)
        self.ceva = LateRentalCount(12, 32)
        self.altceva = BookRentalCount(12, 23)
        self.nu = AuthorRentalCount('da', 23)
        self.da = ClientRentalCount(32, 12)

    def test_controller(self):
        self.Ucontroller.newOperation()
        self.controller.addRental(self.rental2)
        self.assertEqual(len(self.repo), 1)
        self.assertEqual(self.controller.getRental(21238).getID(), 21238)
        self.assertRaises(ControllerException, self.controller.addRental, self.rental3)
        self.assertRaises(ControllerException, self.controller.addRental, self.rental4)
        self.book2.set_available(False)
        self.assertRaises(ControllerException, self.controller.addRental, self.rental2)
        self.assertRaises(ControllerException, self.controller.returnBook, 13123124)
        self.Ucontroller.newOperation()
        self.controller.addRental(self.rental)
        self.assertEqual(self.controller.returnBook(21236), self.rental)
        self.assertEqual(len(self.controller.getAllRental()), 2)
        self.assertEqual(len(self.controller.mostRentedBooks()), 2)
        self.assertEqual(len(self.controller.mostActiveClients()), 2)
        self.assertEqual(len(self.controller.mostRentedAuthors()), 1)
        self.controller.deleteRental(self.rental.getID())
        self.Ucontroller.newOperation()
        self.controller.addRental(self.rental5)
        self.assertEqual(len(self.controller.lateRentals()), 1)
        self.assertEqual(self.ceva.getBook(), 12)
        self.assertEqual(self.ceva.getCount(), 32)
        self.assertFalse(self.ceva > self.ceva)
        self.assertEqual(str(self.ceva), 'Book 12 has been overdue for 32 days')
        self.assertEqual(self.altceva.getCount(), 23)
        self.assertEqual(self.altceva.getBook(), 12)
        self.assertFalse(self.altceva > self.altceva)
        self.assertEqual(str(self.altceva), 'Book 12 was rented 23 times')
        self.assertEqual(self.nu.getBook(), 'da')
        self.assertEqual(self.nu.getCount(), 23)
        self.assertEqual(str(self.nu), 'Author da was rented for 23 times')
        self.assertFalse(self.nu > self.nu)
        self.assertFalse(self.da > self.da)
        self.assertEqual(str(self.da), 'Client 32 has rented books for 12 days')
        self.assertEqual(self.da.getCount(), 12)
        self.assertEqual(self.da.getBook(), 32)
