class ControllerException(Exception):
    """
    Exception class for controller errors
    """
    def __init__(self, message):
        """
        Constructor for controller exception class
        message - A string representing the exception message
        """
        self.__message = message
