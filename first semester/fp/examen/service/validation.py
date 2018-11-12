class ValidatorException(Exception):
    pass


class Validator:

    @staticmethod
    def validate_qtn(qtn):
        """
        method for validating a question
        :param qtn: input question formed as a list of parameters
        :return: True if everything is ok, False otherwise
        """
        try:
            if len(qtn) != 7:
                raise ValidatorException("not enough fields")
            qtn[0] = int(qtn[0])
            if int(qtn[0]) < 0:
                raise ValueError("id cannot be negative integer")

            if qtn[5] not in [qtn[4], qtn[3], qtn[2]]:
                raise ValidatorException("correct choice doesn't appear")

            if qtn[6] not in ['easy', 'medium', 'hard']:
                raise ValidatorException("incorrect difficulty")
            return True
        except Exception as exc:
            print(str(exc))
            return False

    @staticmethod
    def validate_create(params):
        """
        validate creating a new quiz
        :param params: list of parameters from the input
        :return: True if all is valid, False otherwise
        """
        try:
            if len(params) != 3:
                raise ValidatorException("invalid format")

            if params[0] not in ['easy', 'medium', 'hard']:
                raise ValidatorException("incorrect difficulty")
            return True
        except Exception as exc:
            print(str(exc))
            return False
