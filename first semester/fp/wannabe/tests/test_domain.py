import unittest

from domain.Client import Client


class TestDomain(unittest.TestCase):

    def setUp(self):
        self.ident = 23
        self.name = "alex"
        self.flight = "Tarom23"

    def test_something(self):
        self.client = Client(self.ident, self.name, self.flight)
        self.client2 = Client(12, "ana", "Tarom402")
        self.assertEqual(self.client.get_name(), "alex")
        self.assertNotEqual(self.client, self.client2)


if __name__ == '__main__':
    unittest.main()
