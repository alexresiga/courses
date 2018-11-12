import unittest
from controller.BookController import BookController, ControllerException
from repository.repository import Repository
from domain.Book import Book
from controller.UndoController import UndoController


class TestBookController(unittest.TestCase):
    def setUp(self):
        self.repo = Repository()
        self.rentalRepo = Repository()
        self.Ucontroller = UndoController()
        self.book = Book(21, 'titlu', 'descriere', 'author')
        self.book2 = Book(22, 'titlu2', 'descriere2', 'author2')
        self.controller = BookController(self.repo, self.Ucontroller, self.rentalRepo)

    def test_something(self):
        self.Ucontroller.newOperation()
        self.controller.addBook(self.book)
        self.assertEqual(len(self.repo), 1)
        self.Ucontroller.newOperation()
        self.controller.removeBook(21)
        self.assertEqual(len(self.repo), 0)
        self.Ucontroller.newOperation()
        self.controller.addBook(self.book)
        self.Ucontroller.newOperation()
        self.controller.updateBook(self.book)
        self.Ucontroller.newOperation()
        self.controller.addBook(self.book2)
        self.assertEqual(len(self.controller.getAllBooks()), 2)
        self.assertEqual(self.controller.getBook(22), self.book2)
        self.assertRaises(ControllerException, self.controller.searchBook, 'nu')
        self.assertRaises(ControllerException, self.controller.searchBook, '')
        self.assertEqual(len(self.controller.searchBook('tit')), 2)
        self.Ucontroller.newOperation()
        self.controller.removeBook(22)
        self.assertEqual(str(self.controller), '021. titlu by author\n->descriere\nStatus: Available\n\n')


