import unittest
from tests.test_domain import TestDomain
from repository.Repository import Repository, RepositoryException


class TestRepo(TestDomain):
    def setUp(self):
        TestDomain.setUp(self)
        self.repo = Repository()

    def testrepo(self):
        TestDomain.testdomain(self)
        self.repo.add(self.weapon)
        self.assertEqual(self.repo.size(), 1)
        self.repo.remove(self.weapon)
        self.assertEqual(self.repo.size(), 0)




if __name__ == '__main__':
    unittest.main()
