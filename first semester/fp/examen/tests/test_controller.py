import unittest
from service.controller import Controller, ControllerException
from repository.repository import Repository, RepositoryException
from domain.question import Question


class MyTestCase(unittest.TestCase):
    def setUp(self):
        self.q1 = Question(1, 'text', 3, 4, 3, 4, 'easy')
        self.__repo = Repository('test_controller.txt', Question.read_line, Question.write_line)
        self.controller = Controller(self.__repo)
        self.lista = [12, 'da', 1, 2, 3, 1, 'easy']

    def test_something(self):

        self.assertRaises(RepositoryException, self.controller.add_question, self.lista)
        self.assertRaises(ControllerException, self.controller.create_quiz, ['hard', 100, 'hardquiztest.txt'])
        self.assertEqual(self.controller.create_quiz(['hard', 6, 'altquiz.txt']), 6)


if __name__ == '__main__':
    unittest.main()
