import unittest
from tests.test_domain import TestDomain
from repository.ClientRepository import ClientRepository
from domain.Client import Client


class TestRepo(TestDomain):
    def setUp(self):
        TestDomain.setUp(self)
        self.repo = ClientRepository('test-clients.txt', Client.read_client_from_line, Client.write_client_to_line)

    def test_domain(self):
        TestDomain.test_something(self)
        self.assertEqual(0, self.repo.size())
        self.repo.store_client(self.client)
        self.assertEqual(1, self.repo.size())
