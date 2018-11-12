class RepositoryException(Exception):
    pass


class Repository:
    def __init__(self, filename, read_line, write_line):
        self._data = []
        self.__filename = filename
        self._read_from_line = read_line
        self._write_to_line = write_line

    def get_all(self):
        """
        method for iterating through the questions in the files
        :return: slice of the list of the questions
        """
        questions = []
        with open(self.__filename, 'r') as f:
            for line in f.readlines():
                line = line.strip()
                if len(line) > 0:
                    questions.append(self._read_from_line(line))
        return questions[:]

    def store_question(self, question):
        """
        add question to master file
        :param question:
        :return:
        """
        with open(self.__filename, 'r') as f:
            if question in [self._read_from_line(line) for line in f.readlines()]:
                raise RepositoryException("existing question")
        with open(self.__filename, 'a') as f:
            f.write(self._write_to_line(question) + '\n')

    def size(self):
        """
        returns size of file
        :return: number of elements in file
        """
        c = 0
        with open(self.__filename, 'r') as f:
            for line in f.readlines():
                line = line.strip()
                if len(line) > 0:
                    c += 1
        return c
