class RepositoryException(Exception):
    pass


class Repository:
    def __init__(self, filename, read_line, write_line):
        self.__filename = filename
        self.read_line = read_line
        self.write_line = write_line
        try:
            with open(self.__filename, 'r') as f:
                linii = f.readlines()
                print(linii)
        except FileNotFoundError:
            f = open(self.__filename, 'w')
            f.close()

    def get_all(self):
        with open(self.__filename, 'r') as f:
            for line in f.readlines():
                line = line.strip()
                if len(line) > 0:
                    print(self.read_line(line))

    def store_item(self, item):
        with open(self.__filename, 'r') as f:
            if self.write_line(item) in [line for line in f.readlines()]:
                raise RepositoryException("existing item")
        with open(self.__filename, 'a') as f:
            f.write(self.write_line(item))
