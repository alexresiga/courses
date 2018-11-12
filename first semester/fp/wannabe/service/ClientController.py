from repository.ClientRepository import ClientRepository


class ClientController:
    def __init__(self, repo, validator):
        self.__repo = repo
        self.__validator = validator


def seq(word):
    maxim = 1
    lmax = 1
    for i in range(1, len(word)):
        if word[i] != word[i-1]:
            lmax = 1
        else:
            lmax += 1
            maxim = max(maxim, lmax)
    return maxim


alist = ['abba', 'accccda', 'abbcddd', 'abc']
alist.sort(key=seq)
print(alist)