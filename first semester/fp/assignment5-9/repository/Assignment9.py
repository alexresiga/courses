class MyDataStructure:
    def __init__(self):
        self._data = []
        self.index = 0

    def __str__(self):
        res = ''
        for x in self._data:
            res += str(x) + '\n'
        return res

    def __setitem__(self, key, value):
        self._data[key] = value

    def __getitem__(self, idx):
        return self._data[idx]

    def __delitem__(self, item):
        if item not in self._data:
            raise Exception("nu putem sterge un element ce nu exista nu?")
        idx = self._data.index(item)
        self._data.pop(idx)

    def __iter__(self):
        return self

    def __next__(self):
        if self.index >= len(self._data):
            raise StopIteration

        self.index += 1
        return self._data[self.index - 1]

    def __len__(self):
        return len(self._data)

    def append(self, value):
        self._data.append(value)

    @staticmethod
    def sort(alist, cmp):
        """
        implementation of GnomeSort for a custom data structure and custom comparison criteria
        :param alist: an iterable set of mutable data
        :param cmp: comparison criteria
        :return: sorted set
        """
        position = 0
        while position < len(alist):
            if position == 0 or not cmp(alist[position], alist[position-1]):
                position += 1
            else:
                alist[position], alist[position-1] = alist[position-1], alist[position]
                position -= 1
        return alist

    @staticmethod
    def filter(mystruct, filtru):
        return [x for x in mystruct if filtru(x)]
