from domain import createCircle


def testInit(alist):
    alist.append(createCircle(1, 2, 3, colour='asd'))
    alist.append(createCircle(1, 2, 3, 'bcd'))
    alist.append(createCircle(1, 2, 3, 'bcc'))
    alist.append(createCircle(1, 2, 3, 'dfv'))
    alist.append(createCircle(1, 2, 3, 'faa'))
