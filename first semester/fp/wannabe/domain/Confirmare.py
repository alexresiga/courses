class Confirmation:
    def __init__(self, client, data):
        self.__client = client
        self.__data = data

    def get_client(self):
        return self.__client

    def get_data(self):
        return self.__data

    def set_client(self, b):
        self.__client = b

    def set_data(self, b):
        self.__data = b
