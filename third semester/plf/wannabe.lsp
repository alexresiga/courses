(defun square(x)
  (* x x))

(defun main(L)
  (mapcar 'square L))

(defun mainL(list)
  (mapcar #'(lambda (x) (* x x)) list))

(defun suma(list)
  (cond
   ((numberp list) 0)
   ((atom list) 1)
   (t (apply ` + (mapcar `suma list)))))

; leftChild(l1...ln, children) = NIL, children = 0
;                              = l1, l2 U leftChild(l3...ln, children - 1 + l2), otherwise

(defun leftChild(l children)
(COND
( (= children 0) NIL )
( T ( cons (car l)  ( cons (cadr l) ( leftChild (cddr  l) (+ (- children 1) (cadr l))))))
)
)

;rightChild(l1...ln, children) = l1...ln, children = 0
;                              = rightChild(l3...ln, children - 1 + l2), otherwise
(defun rightChild(l children)
(COND
( (= children 0) l )
( T ( rightChild (cddr l) (+ (- children 1) (cadr l))))
)
)


;pb 2

(defun nodesOnLevel(l k level)
(COND
((null l) nil)
((= level k) (list (car l)))
((eq (cadr l) 0) nil)
(T (append (nodesOnLevel (leftChild (cddr l) 1) k (+ 1 level)) (nodesOnLevel (rightChild (cddr l) 1) k (+ 1 level))))
)
)

(defun cmmdc(a b)
  (cond
   ( (and (= a 0) (= b 0)) 0)
   ( (= (* a b) 0) (+ a b))
   ( (> a b) (cmmdc (- a b) b))
   ( (< a b) (cmmdc a (- b a)))
   ( (= a b) a)))

(defun cmList(l)
  (cond
   ((null l) 0)
   ((numberp (car l)) (cmmdc (car l) (cmList (cdr l))))
   ((listp (car l)) (cmmdc (cmList (car l)) (cmList (cdr l)) ) ) 
   ) 
)

(defun onlyNum(l)
  (cond
   ((null l) nil)
   ((numberp (car l)) (cons (car l) (onlyNum (cdr l))))
   ((listp (car l)) (append (onlyNum (car l)) (onlyNum (cdr l))))
   ((atom (car l))  (onlyNum (cdr l)))))

(defun _find(l e)
  (cond
   ((null l) 0)
   ((equal (car l) e) (+ 1 (_find (cdr l) e)))
   (t (_find (cdr l) e))))

(defun _set(L)
  (cond
   ((null L) nil)
   ((= (_find (cdr L) (car L)) 0) (cons (car L) (_set (cdr L))))
   (t (_set (cdr L)))))

(defun rev(L)
  (cond
   ((null L) nil)
   ((listp (car L)) (append (rev (cdr L)) (list (rev (car L)))))
   (t (append (rev (cdr L)) (list (car L))))))

(defun wow() (mapcon #'APPEND `(A B C) `(1 2 3)))

(defun _remove(l e)
  (cond
   ((null l) nil)
   ((and (atom (car l)) (equal (car l) e)) (_remove (cdr l) e))
   ((and (atom (Car l)) (not (equal (Car l) e))) (cons (car l) (_remove (cdr l) e)))
   (t (cons (_remove (car l) e) (_remove (cdr l) e)))))

(defun linz(l)
  (cond
   ((NULL l) nil)
   ((numberp (Car l)) (cons (Car l) (linz (cdr l))))
   ((atom (Car l))  (linz (cdr l)))
   (t (append (linz (Car l)) (linz (cdr l))))))

(defun check(lst)
  (cond
   ((equal 5 (car (linz lst))) t)
   (t nil)))

(defun solve(l)
  (cond
   ((atom l) 0)
   ((and (listp l) (check l)) (+ 1 (apply `+(mapcar `solve l))))
   (t (apply `+(mapcar `solve l)))))

(defun _last(lst)
  (cond
   ((null lst) nil)
   ((equal (cdr lst) nil) (car lst))
   (t (_last (cdr lst)))))

(defun check2(lst)
  (cond
   ((numberp (_last (linz lst))) nil)
   (t t)))

(defun solve2(l)
  (cond
   ((atom l) 0)
   ((and (listp l) (check2 l)) (+ 1 (apply `+(mapcar `solve2 l))))
   (t (apply `+(mapcar `solve2 l)))))

(defun liniz(lst)
  (cond
   ((numberp lst) (list lst))
   ((listp lst) (apply #'append(mapcar `liniz lst)))))

(defun linizA(lst)
  (cond
   ((atom lst) (list lst))
   ((list lst) (apply #'append(mapcar `linizA lst)))))

(defun checkA(lst)
  (cond
   ((and (atom (car (linizA lst))) (not (numberp (car (linizA lst))))) t)
   (t nil)))

(defun solveA(l)
  (cond
   ((atom l) 0)
   ((and (listp l) (checkA l)) (print l) (+ 1 (apply `+(mapcar `solveA l))))
   (t (apply `+(mapcar `solveA l)))))

(defun repl(arb n k e)
  (cond
   ((and (= (- n 1) k) (atom arb)) e)
   ((and (/= (- n 1) k) (atom arb)) arb)
   (t (mapcar #'(lambda(x) (repl x (+ n 1) k e)) arb))))

(defun replMain(arb k e)
  (repl arb 0 k e))

(defun getNodeOdd(l lvl)
  (cond
    ((null l) l)
    ((and (numberp (car l)) (oddp lvl)) (append (list (car l)) (getNodeOdd (cdr l) lvl)))
    ((listp (car l)) (append (getNodeOdd (car l) (+ 1 lvl)) (getNodeOdd (cdr l) lvl)))
    (t (getNodeOdd (cdr l) lvl))
    )
  )

(defun maximL(l)
  (evenp (apply #'max (getNodeOdd l 1)))
  )

(defun nrLists(l)
  (cond
    ((and (listp l) (not (equal (getNodeOdd l 1) nil)) (maximL l)) (print l) (+ 1 (apply #'+ (mapcar #'nrLists l))))
    ((listp l) (apply #'+ (mapcar #'nrLists l)))
    (t 0)
    )
  )

(defun checkOdd (l n)
  (cond
   ((and (numberp l) (= (mod n 2) 1)) l)
   ((and (numberp l) (/= (mod n 2) 0)) 0)
   ((atom l) 0) 
   ((listp l) (apply `+(mapcar #'(lambda(x) (checkOdd x (+ n 1))) l)))))

(defun mainc(l)
  (checkOdd l 0))

(defun solvec(l)
  (cond
   ((atom l) 0)
   ((and (listp l) (= (mod (mainc l) 2) 0)) (print l) (+ 1 (apply `+(mapcar `solvec l))))
   (t (apply `+(mapcar `solvec l)))))

(defun min2(a b)
  (cond
   ((<= a b) a)
   (t b)))

(defun max2(a b)
  (cond
   ((<= a b) b)
   (t a)))

(defun checkMin(l n)
  (cond
   ((null l) 99999)
   ((and (numberp (car l)) (= (mod n 2) 1)) (min2 (car l) (checkMin (cdr l) n)))
   ((listp (car l)) (min2 (checkMin (car l) (+ n 1)) (checkMin (cdr l) n))) 
   (t (checkMin (cdr l) n))))

(defun solveMin(l)
  (cond
   ((atom l) 0)
   ((and (listp l) (= (mod (checkMin l 1) 2) 0)) (print l) (+ 1 (apply `+(mapcar `solveMin l))))
   (t (apply `+(mapcar `solveMin l)))))


(defun checkMax(l n)
  (cond
   ((null l) -1)
   ((and (numberp (car l)) (= (mod n 2) 1)) (max2 (car l) (checkMax (cdr l) n)))
   ((listp (car l)) (max2 (checkMax (car l) (+ n 1)) (checkMax (cdr l) n))) 
   (t (checkMax (cdr l) n))))

(defun solveMax(l)
  (cond
   ((atom l) 0)
   ((and (listp l) (= (mod (checkMax l 1) 2) 0)) (print l) (+ 1 (apply `+(mapcar `solveMax l))))
   (t (apply `+(mapcar `solveMax l)))))

(defun inloc(arb n k)
  (cond
   ((and (atom arb) (= n k)) 0)
   ((and (atom arb) (/= n k)) arb)
   (t (mapcar #'(lambda(x) (inloc x (+ n 1) k)) arb))))

(defun _inloc(arb k)
  (inloc arb 0 k))


(defun isThere(l n)
  (cond
   ((null l) nil)
   ((and (equal (car l) n) (atom (car l))) t)
   ((listp (car l)) (or (isThere (car l) n) (isThere (cdr l) n)))
   (t (isThere (cdr l) n))))
 

(defun pathToNode(l node)
(cond
((null l) nil)
((equal (car l) node) (list node))
((isThere (cadr l) node) (cons (car l) (pathToNode (cadr l) node)))
((isThere (cddr l) node) (cons (car l) (pathToNode (caddr l) node)))
)
)


(defun prime2(a d)
  (cond
   ((equal a d) t)
   ((and (> a 2) (/= (mod a d) 0)) (prime2 a (+ d 1)))))  


(defun removv(l e)
  (cond
   
   ((and (ATOM l)  (not (equal l e)) ) l)
   
   ((listp l) (mapcar #'(lambda(x) (removv x e)) l))))

(defun removeMain(l e)
  (removv (removv l e) nil))
   

