class UI:
    def __init__(self, repo, controller):
        self.__repo = repo
        self.__controller = controller

    @staticmethod
    def print_menu():
        pass

    @staticmethod
    def read_command(cmd):
        """
        separate command from params
        :param cmd:
        :return:
        """
        command = cmd[:cmd.find(" ")]
        params = cmd[cmd.find(" ")+1:]
        params = params.split(";")
        return command, params

    def start(self):
        """
        entry point in the program
        :return:
        """
        while True:
            try:
                command, params = UI.read_command(input(">>>"))
                if command == 'add':
                    self.__controller.add_question(params)
                elif command == "create":
                    params[0] = params[0].split(" ")
                    self.__controller.create_quiz(params[0])
                elif command == "start":
                    print("Your score is: " + str(self.__controller.start_quiz([params[0]])))
                else:
                    print("invalid command")
            except Exception as exc:
                print(str(exc))
