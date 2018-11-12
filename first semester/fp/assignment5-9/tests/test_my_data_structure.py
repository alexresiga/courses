import unittest
from repository.Assignment9 import MyDataStructure


class MyTestCase(unittest.TestCase):
    def setUp(self):
        self.data_structure = MyDataStructure()

    def test_dataStructure(self):
        self.assertEqual(len(self.data_structure), 0)
        self.data_structure.append(-2)
        self.data_structure.append(3)
        self.data_structure.append(3)
        self.data_structure.append(-3)
        self.data_structure.append(-4)
        self.data_structure.append(2)
        self.data_structure.append(44)
        self.assertEqual(len(self.data_structure), 7)
        self.assertEqual(self.data_structure[6], 44)
        self.data_structure.sort(self.data_structure, cmp=lambda x, y: x < y)
        print(self.data_structure.filter(self.data_structure, filtru=lambda x: x < 0))
