import unittest
from controller.ClientController import ClientController, ControllerException
from repository.repository import Repository
from domain.Client import Client
from controller.UndoController import UndoController


class TestClientController(unittest.TestCase):
    def setUp(self):
        self.repo = Repository()
        self.rentalRepo = Repository()
        self.Ucontroller = UndoController()
        self.client = Client(11, 'alex')
        self.client2 = Client(12, 'ana')
        self.controller = ClientController(self.repo, self.Ucontroller, self.rentalRepo)

    def test_something(self):
        self.assertRaises(Exception, self.Ucontroller.undo)
        self.assertRaises(Exception, self.Ucontroller.redo)
        self.Ucontroller.newOperation()
        self.controller.addClient(self.client)
        self.assertEqual(len(self.repo), 1)
        self.Ucontroller.newOperation()
        self.controller.removeClient(11)
        self.assertEqual(len(self.repo), 0)
        self.Ucontroller.newOperation()
        self.controller.addClient(self.client)
        self.Ucontroller.newOperation()
        self.controller.updateClient(self.client)
        self.Ucontroller.newOperation()
        self.controller.addClient(self.client2)
        self.assertEqual(len(self.controller.getAllClients()), 2)
        self.assertRaises(ControllerException, self.controller.searchClient, 'nu')
        self.assertRaises(ControllerException, self.controller.searchClient, '')
        self.assertEqual(len(self.controller.searchClient('a')), 2)
        self.Ucontroller.newOperation()
        self.controller.removeClient(12)
        self.Ucontroller.undo()
        self.assertEqual(len(self.controller.getAllClients()), 2)
        self.Ucontroller.redo()
        self.assertEqual(len(self.controller.getAllClients()), 1)
