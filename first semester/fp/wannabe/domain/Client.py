class Client:
    def __init__(self, ident, name, flight):
        self.__ident = ident
        self.__name = name
        self.__flight = flight

    def get_ident(self):
        return self.__ident

    def set_name(self, a):
        self.__name = a

    def get_name(self):
        return self.__name

    def set_flight(self, a):
        self.__flight = a

    def get_flight(self):
        return self.__flight

    def __str__(self):
        result = str(self.__ident) + '.' + self.__name + ' -' + self.get_flight()
        return result

    @staticmethod
    def read_client_from_line(line):
        cuvinte = line.split(',')
        return Client(int(cuvinte[0]), cuvinte[1], cuvinte[2])

    @staticmethod
    def write_client_to_line(client):
        return str(client.get_ident()) + ', ' + client.get_name() + ', ' + client.get_flight() + '\n'
