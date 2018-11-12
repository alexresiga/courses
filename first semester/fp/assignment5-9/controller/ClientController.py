from controller.ControllerException import ControllerException
from validation.validator import Validator
from controller.UndoController import Operation, FunctionCall


class ClientController:
    def __init__(self, repo, undoController, rentalRepo):
        self.__clientRepo = repo
        self.validator = Validator()
        self._undoController = undoController
        self.rentalRepo = rentalRepo

    def addClient(self, client):
        """

        :param client:
        :return:
        """
        self.validator.validateClient(client)
        self.__clientRepo.add(client)

        # IF there are no errors we continue to append data for undo/repo

        redo = FunctionCall(self.addClient, client)
        undo = FunctionCall(self.removeClient, client.getID())
        operation = Operation(redo, undo)

        self._undoController.recordOperation(operation)

    def removeClient(self, ID):
        """

        :param ID:
        :return:
        """
        # IF there are no errors we continue to append data for undo/repo

        redo = FunctionCall(self.removeClient, ID)
        undo = FunctionCall(self.addClient, self.__clientRepo.get(ID))
        operation = Operation(redo, undo)

        self.__clientRepo.remove(ID)

        for rental in self.rentalRepo.getAll():
            if rental.getClientID() == ID:
                self.rentalRepo.remove(rental.getID())

        self._undoController.recordOperation(operation)

    def updateClient(self, aclient):
        """

        :param aclient:
        :return:
        """
        redo = FunctionCall(self.updateClient, aclient)
        undo = FunctionCall(self.updateClient, self.__clientRepo.get(aclient.getID()))
        operation = Operation(redo, undo)

        self._undoController.recordOperation(operation)
        self.validator.validateClient(aclient)
        self.__clientRepo.update(aclient)

    def getAllClients(self):
        return self.__clientRepo.getAll()

    def searchClient(self, substring):
        """

        :return:
        """
        if substring == '':
            raise ControllerException("no keywords given")
        result = []
        for x in self.__clientRepo.getAll():
            if substring in str(x.getID()).lower() or substring in str(x.getName()).lower():
                result.append(x)
        if not result:
            raise ControllerException("No entries match your search")
        else:
            return result
