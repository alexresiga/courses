import unittest
from repository.repository import Repository, RepositoryException
from domain.question import Question


class MyTestCase(unittest.TestCase):
    def setUp(self):
        self.repo = Repository('test_repo.txt', Question.read_line, Question.write_line)
        self.q1 = Question(1, 'text', 3, 4, 3, 4, 'easy')

    def test_something(self):
        self.assertEqual(self.repo.size(), 1)
        self.assertRaises(RepositoryException, self.repo.store_question, self.q1)
        self.assertEqual(len(self.repo.get_all()), 1)


if __name__ == '__main__':
    unittest.main()
