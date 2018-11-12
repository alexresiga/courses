from domain.Client import Client


class RepositoryException(Exception):
    pass


class ClientRepository:
    def __init__(self, filename, read_student_from_line, write_client_to_line):
        self._data = []
        self.__filename = filename
        self._read_student_from_line = read_student_from_line
        self._write_client_to_line = write_client_to_line
        try:
            self.get_all()
        except FileNotFoundError:
            f = open(self.__filename, 'w')
            f.close()

    def __str__(self):
        result = ''
        for x in self._data:
            result += str(x) + '\n'
        return result

    def get_all(self):
        with open(self.__filename, 'r') as f:
            for line in f.readlines():
                line = line.strip()
                if len(line) > 0:
                    print(self._read_student_from_line(line))

    def store_client(self, client):
        with open(self.__filename, 'r') as f:
            if self._write_client_to_line(client) in [line for line in f.readlines()]:
                raise RepositoryException("existing client")
        with open(self.__filename, 'a') as f:
            f.write(self._write_client_to_line(client) + '\n')

    def find_user(self, substring):
        result = ''
        if substring == '':
            raise RepositoryException("Keyword search cannot be empty")
        with open(self.__filename, 'r') as f:
            for line in f.readlines():
                elem = self._read_student_from_line(line)
                if substring in elem.get_name():
                    result += str(elem) + '\n'
        if result == '':
            return 'No entries matched your search'
        return result

    def find_flight(self, code):
        pass

    def size(self):
        c = 0
        with open(self.__filename, 'r') as f:
            for line in f.readlines():
                if len(line) > 0:
                    c += 1
        return c


# repo = ClientRepository('clients.txt', Client.read_client_from_line, Client.write_client_to_line)
# repo.get_all()
# print(repo.find_user(' '))