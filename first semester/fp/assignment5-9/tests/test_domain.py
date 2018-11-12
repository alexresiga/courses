import unittest
from domain.Client import Client
from domain.Book import Book
from domain.Rental import Rental
from datetime import date


class TestDomain(unittest.TestCase):

    def setUp(self):
        self.client = Client(23, 'alex')
        self.client2 = Client(12, 'diana')
        self.book = Book(21, 'titlu', 'descriere', 'author')
        self.book2 = Book(22, 'titlu2', 'descriere2', 'author2')
        self.rental = Rental(21236, 21, 23, date(2017, 11, 5), date(2017, 12, 6), date(2017, 12, 5))
        self.rental2 = Rental(21236, 21, 23, date(2017, 11, 5), date(2017, 12, 6), date(2017, 12, 5))

    def tearDown(self):
        pass

    def test_create_Client(self):
        # CLIENTS TESTS
        self.assertEqual(23, self.client.getID())
        self.assertEqual('alex', self.client.getName())
        self.client.setName('da')
        self.assertEqual('da', self.client.getName())
        self.assertFalse(self.client == self.client2)
        self.assertEqual(str(self.client), '023. da\n')
        self.assertEqual(self.client.create_client(23, 'alex'), self.client)

    def test_create_book(self):
        self.assertEqual(21, self.book.getID())
        self.assertEqual('titlu', self.book.getTitle())
        self.assertEqual('descriere', self.book.getDescription())
        self.assertEqual('author', self.book.getAuthor())
        self.assertEqual(True, self.book.get_available())
        self.book.setTitle('lol')
        self.assertEqual('lol', self.book.getTitle())
        self.book.setAuthor('da')
        self.assertEqual('da', self.book.getAuthor())
        self.book.setDescription('da')
        self.assertEqual('da', self.book.getDescription())
        self.assertEqual(str(self.book), '021. lol by da\n->da\nStatus: Available\n')
        self.book.set_available(False)
        self.assertEqual(False, self.book.get_available())
        self.assertEqual(str(self.book), '021. lol by da\n->da\nStatus: Unavailable\n')
        self.assertNotEqual(self.book, self.book2)
        self.assertEqual(self.book.create_book(21, 'titlu', 'descriere', 'author'), self.book)

    def test_create_rental(self):
        self.assertEqual(21236, self.rental.getID())
        self.assertEqual(21, self.rental.getBookID())
        self.assertEqual(23, self.rental.getClientID())
        self.assertEqual(date(2017, 12, 6), self.rental.getDueDate())
        self.assertEqual(date(2017, 11, 5), self.rental.getRentedDate())
        self.assertEqual(date(2017, 12, 5), self.rental.getReturnedDate())
        self.assertEqual('Rental 21236: book: 21 rented by client 23 on 05.11.2017 and is due by 06.12.2017', str(self.rental))
        self.rental.setBookID(21)
        self.rental.setClientID(23)
        self.rental.setReturnedDate(date(2017, 12, 12))
        self.rental.setDueDate(date(2017, 11, 21))
        self.rental.setRentedDate(date(2017, 9, 23))
        self.assertEqual(len(self.rental), 80)
        self.rental.setReturnedDate(None)
        self.assertEqual(len(self.rental), 0)
        self.assertEqual(self.rental.getDelay(), (date.today()-self.rental.getDueDate()).days)
        self.assertEqual(self.rental, self.rental2)
        self.rental.setReturnedDate(date(2017, 12, 12))
        self.assertEqual(self.rental.create_rental(21, 23, 12, 5).getBookID(), 21)
        self.assertEqual(self.rental.printReturned(self.rental), 'Rental 21236: book: 21 rented by client 23 on 23.09.2017 was returned on 12.12.2017')
