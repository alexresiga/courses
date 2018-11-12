class Question:
    def __init__(self, ident, text, choice_a, choice_b, choice_c, correct, dif):
        self.__id = ident
        self.__text = text
        self.__choice_a = choice_a
        self.__choice_b = choice_b
        self.__choice_c = choice_c
        self.__correct = correct
        self.__dif = dif

    def get_id(self):
        return self.__id

    def get_choice_a(self):
        return self.__choice_a

    def get_choice_b(self):
        return self.__choice_b

    def get_choice_c(self):
        return self.__choice_c

    def get_correct(self):
        return self.__correct

    def get_dif(self):
        return self.__dif

    def get_text(self):
        return self.__text

    def __eq__(self, other):
        return isinstance(other, self.__class__) and self.get_id() == other.get_id()

    def __str__(self):
        return str(self.get_id()) + ';' + str(self.get_text()) + ';' + str(self.get_choice_a()) + ';' + str(self.get_choice_b()) + ';' + str(self.get_choice_c()) + ';' + str(self.get_correct()) + ';' + str(self.get_dif())


    @staticmethod
    def read_line(line):
        """
        read question from file
        :param line:
        :return:
        """
        parts = line.split(";")
        return Question(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5], parts[6])

    @staticmethod
    def write_line(qt):
        """
        write a question to quiz
        :param qt:
        :return:
        """
        return str(qt.get_id()) + ';' + str(qt.get_text()) + ';' + str(qt.get_choice_a()) + ';' + str(qt.get_choice_b()) + ';' + str(qt.get_choice_c()) + ';' + str(qt.get_correct()) + ';' + str(qt.get_dif())

