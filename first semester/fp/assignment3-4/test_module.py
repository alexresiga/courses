from features_module import *

def testInit(list):
    list.append(('31', 112, 'housekeeping'))
    list.append(('31', 112, 'housekeeping'))
    list.append(('31', 112, 'housekeeping'))
    list.append(('2', 124, 'food'))
    list.append(('11', 11, 'transport'))
    list.append(('11', 212, 'food'))
    list.append(('13', 30, 'food'))
    list.append(('11', 110, 'food'))
    list.append(('11', 210, 'clothing'))
    list.append(('11', 54, 'others'))
    list.append(('23', 22, 'clothing'))
    list.append(('1', 112, 'internet'))
    list.append(('1', 303, 'transport'))


def test_addExpense():
    alist = [('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('31', 112, 'housekeeping')]
    addExpense(alist, ('1', 112, 'internet'))
    assert alist == [('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('1', 112, 'internet')]


def test_removeExpense():
    alist = [('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('1', 112, 'housekeeping'), ('12', 112, 'internet')]
    removeExpense(alist, ['internet'], 2)
    assert alist == [('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('1', 112, 'housekeeping')]


def test_listExpense():
    assert listExpenses([('1', 10, 'internet'), ('12', 110, 'food'), ('12', 130, 'food')], ["food"]) == [('12', 110, 'food'), ('12', 130, 'food')]
    assert listExpenses([('1', 110, 'internet'), ('12', 110, 'internet'), ('22', 130, 'transport')], ['internet', '=', '110']) == [('1', 110, 'internet'), ('12', 110, 'internet')]


def test_SumExpense():
    anewlist = [('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('1', 112, 'housekeeping'), ('12', 112, 'internet')]
    assert sumExpense(anewlist, ['internet']) == 112


def test_MaxExpense():
    alist = [('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('1', 112, 'housekeeping'), ('12', 112, 'internet')]
    assert maxExpense(alist) == 31, maxExpense(alist)


def test_sortExpenseDay():
    alist = [('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('1', 112, 'housekeeping'),
             ('12', 112, 'internet')]
    assert sortExpenseDay(alist) == [(1, 112), (12, 112), (31, 224)]


def test_sortExpenseCategory():
    newlist = [('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('12', 112, 'internet')]
    assert sortExpenseCategory(newlist, ['housekeeping']) == [(31, 336, 'housekeeping')], sortExpenseCategory(newlist, ['housekeeping'])


def test_filterExpense():
    alist = [('31', 112, 'housekeeping'), ('31', 112, 'housekeeping'), ('1', 112, 'housekeeping'), ('12', 112, 'internet')]
    filterExpense(alist, ['internet'])
    assert alist == [('12', 112, 'internet')]


def run_test():
    test_addExpense()
    test_removeExpense()
    test_listExpense()
    test_SumExpense()
    test_MaxExpense()
    test_sortExpenseDay()
    test_sortExpenseCategory()
    test_filterExpense()
