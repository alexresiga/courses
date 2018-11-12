import unittest
from repository.repository import Repository, RepositoryException, FileRepository
from domain.Client import Client


class TestRepository(unittest.TestCase):
    def setUp(self):
        self.repo = Repository()
        self.c = Client(12, 'alex')
        self.c1 = Client(121, 'ana')
        self.repo2 = FileRepository('testclient.txt', Client.readClientFromLine, Client.writeClientToLine)
        self.repo3 = FileRepository('testclient4.txt', Client.readClientFromLine, Client.writeClientToLine)

    def test_repo(self):
        self.assertEqual(len(self.repo), 0)
        self.repo.add(self.c)
        self.assertEqual(str(self.repo), '012. alex\n\n')
        self.assertEqual(len(self.repo), 1)
        self.assertRaises(RepositoryException, self.repo.add, self.c)
        self.assertEqual(len(self.repo.getAll()), 1)
        self.assertEqual(self.repo.findByID(12), 12)
        self.assertEqual(self.repo.findByID(13), -1)
        self.assertEqual(self.repo.get(12), self.c)
        self.assertRaises(RepositoryException, self.repo.get, 13)
        self.assertRaises(RepositoryException, self.repo.remove, 13)
        self.assertRaises(RepositoryException, self.repo.update, 13)
        self.repo.update(self.c)
        self.repo.remove(12)
        self.assertEqual(len(self.repo), 0)
        self.repo2.add(self.c)
        self.repo2.upd(self.c)
        self.repo2.rem(self.c.getID())
        self.assertEqual(len(self.repo2), 1)
