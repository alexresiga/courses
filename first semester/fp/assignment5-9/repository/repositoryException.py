class RepositoryException(Exception):
    """
    class for handling exceptions
    """
    def __init__(self, message):
        """
        constructor for exceptions class
        :param message: the message passed with the error
        """
        self.__message = message
