from service.validation import Validator
from domain.question import Question


class ControllerException(Exception):
    pass


class Controller:
    def __init__(self, repo):
        self.__repo = repo
        self.validator = Validator()

    def add_question(self, qtn):
        """
        controller method to add question to master question list
        :param qtn: input question
        :return:
        """

        if self.validator.validate_qtn(qtn):
            question = Question(qtn[0], qtn[1], qtn[2], qtn[3], qtn[4], qtn[5], qtn[6])
            self.__repo.store_question(question)
            print("question added to master list")

    def create_quiz(self, params):
        """
        controller method for creating quiz from existing questions
        :param params: list of parameters
        :return: if no error encountered add the .txt file in the program
        """
        if self.validator.validate_create(params):
            dif = params[0]
            counter = params[1]
            filename = params[2]
            cnt = 0
            questions = []
            for x in self.__repo.get_all():
                if x.get_dif() == dif:
                    questions.append(x)
                    cnt += 1
                    self.__repo.get_all().remove(x)
            if int(cnt) < int(counter)//2:
                raise ControllerException("not enough questions")
            left = int(counter) - int(cnt)
            if left > 0:
                cnt2 = 0
                for x in self.__repo.get_all():
                    if x.get_dif() != dif:
                        questions.append(x)
                        cnt2 +=1
                        left -= 1
                        if left == 0:
                            break
            for x in questions:
                with open(filename, 'a+') as f:
                    f.write(str(x)+'\n')
            return cnt + cnt2

    def start_quiz(self, params):
        """
        start solving the given quiz
        :param params: name of the quiz
        :return:
        """
        filename = params[0]
        questions = []
        with open(filename, 'r') as f:
            for line in f.readlines():
                line = line.strip()
                if len(line) > 0:
                    questions.append(Question.read_line(line))
        rank = {"easy": 1, "medium": 2, "hard": 3}
        questions.sort(key=lambda x: rank[x.get_dif()])
        score = 0
        for x in questions:
            print(str(x.get_text()))
            print(x.get_choice_a(), x.get_choice_b(), x.get_choice_c())
            answer = input("Enter your answer: ")
            if str(answer) == str(x.get_correct()):
                score += rank[x.get_dif()]
        return score
