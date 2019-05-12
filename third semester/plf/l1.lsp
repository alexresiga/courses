(defun averagenum (n1 n2 n3 n4)
  (/ (+ n1 n2 n3 n4) 4)
)

(defun factorial (num) 
  (cond ((zerop num) 1)
        (t (* num(factorial(- num 1))))
  )
)

(defun addN (l e pc n)
(cond
 ( (null l) nil)
 ( (equal 0 (mod pc n)) (cons e (addN l e (+ 1 pc) n)))
 (t (cons (car l) (addN (cdr l) e (+ 1 pc) n)))
)
)

(defun addNMain (l e n)
(cond (t(addN l e 1 n)))
)

(defun remove (l e)
(cond 
( (null l) nil)
( (listp (car l)) (cons (remove (car l) e) (remove (cdr l) e)))
( (equal (car l) e) (remove (cdr l) e))
( t (cons (car l) (remove (cdr l) e)))