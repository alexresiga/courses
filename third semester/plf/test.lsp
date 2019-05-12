;checkNeg(l, n) = {l, atom l and l <0 and nmod2=1
;                 {append(checkNeg(li, n+1) l=list

(defun checkNeg(l n)
  (cond
   ((and (numberp l) (< l 0) (= (mod l 2) 1) (= (mod (- n 1) 2) 1)) (list l))
   ((listp l) (apply #'append(mapcar #'(lambda(x) (checkNeg x (+ n 1))) l)))))


;rev(l) = {[], l = []
;         {rev(l2..ln) U rev(l1), l1 list
;         {rev(l2..ln) U l1, otherwise
(defun revv(l)
  (cond
   ((null l) nil)
   ((listp (car l)) (append (revv (cdr l)) (list (revv (car l)))))
   (t (append (revv (cdr l)) (list (car l))))))


;myfind2(l e) = {0, l= []
;               { 1 +myfind2(l2..ln, e), l=e
;               {myfind2(l2..ln, e), otherwise
(defun myfind2(l e)
  (cond
   ((null l) 0)
   ((equal (car l) e) (+ 1 (myfind2 (cdr l) e)))
   (t (myfind2 (cdr l) e))))

;makeset(l) = {[], l=[]}
;             {l1 U makeset(l2..ln), myfind(l2..ln, l1) = 0}
;             {makeset(l2..ln), myfind(l2..ln, l1) != 0}
(defun _makeSet(l)
  (cond
   ((null l) nil)
   ((= (myfind2 (cdr l) (car l)) 0) (cons (car l) (_makeSet (cdr l))))
   (t (_makeSet (cdr l)))))

(defun mainTest(l)
  (_makeSet  (checkNeg (revv l) 0)))