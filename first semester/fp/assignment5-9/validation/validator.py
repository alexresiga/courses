class ValidateException(Exception):
    def __init__(self, message):
        self.__message = message


class Validator:

    def validateBook(self, book):
        errors = ''
        if book.getTitle() == '':
            errors += '\t->empty name\n'
        if book.getAuthor() == '':
            errors += '\t->empty author\n'
        if book.getDescription() == '':
            errors += '\t->empty desc \n'
        if errors:
            raise ValidateException('Invalid book:\n' + errors)
        return True

    def validateClient(self, client):
        errors = ''
        if client.getName() == '':
            errors += '\t->name cannot be empty'
        if errors:
            raise ValidateException('Invalid client:\n' + errors)
        return True
