import unittest

from domain.Client import Client
from validation.validator import Validator, ValidateException
from domain.Book import Book


class TestValidare(unittest.TestCase):
    def setUp(self):
        self.validator = Validator()
        self.book = Book(12, '', '', '')
        self.book2 = Book(22, 'da', 'desc', 'aut')

        self.client = Client(13, '')
        self.client2 = Client(14, 'da')

    def test_validare(self):
        self.assertRaises(ValidateException, self.validator.validateBook, self.book)
        self.assertRaises(ValidateException, self.validator.validateClient, self.client)
        self.assertTrue(self.validator.validateClient(self.client2))
        self.assertTrue(self.validator.validateBook(self.book2))

