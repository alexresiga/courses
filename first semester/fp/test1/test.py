from features import *
from validation import validatePoem


def test_add():
    assert addPoem([], {"id": 1, "lyrics": ["da", "nu", "da"]}) == [{"id": 1, "lyrics": ["da", "nu", "da"]}]


def testInit(alist):
    alist.append({"id": 1, "lyrics": ["ada", "nu ada", "ada"]})
    alist.append({"id": 2, "lyrics": ["dacan alanada dacan alanada"]})


def test_haikus():
    assert haikus([{"id": 2, "lyrics": ["dacan alanada dacan alanada"]}, {"id": 2, "lyrics": ["dacan alanada dacan alanada"]}]) == []


def test():
    assert validatePoem({"id": '1', 'lyrics': ['da', 'lol']}) == False
    assert validatePoem({"id": '1', 'lyrics': ['ana aer mere', 'ana are pere']}) == True

test()