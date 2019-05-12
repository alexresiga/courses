;PROBLEM 2. 
;a) Write a function to return the product of two vectors.
;dot_product(a1..an, b1..bn) = {0, n = 0;}
;                              {a1 * b1 + dot_product(a2..an, b2..bn), otherwise}
(defun dot_product(A B)
  (cond
   ((or (null A) (null B)) 0)
   (t (+(* (car A) (car B)) (dot_product (cdr A) (cdr B))))))
;(dot_product `(1 3 -5) `(4 -2 -1)) => 3

;b) Write a function to return the depth of a list. Example: the depth of a linear list is 1.

(defun max2(a b)
  (cond
   ((>= a b) a)
   (t b)))

;depth(l1..ln, d) = {d, n=0 } 
;                   {depth(l2..ln, d), atom(l1)}
;                   {max(depth(l1, d+1), depth(l2..ln, d)), list(l1) }

(defun depth(L d)
   (cond
    ((null L) d)
    ((or (atom (car L)) (numberp (car L))) (depth (cdr L) d))
    (t (max2 (depth (car L) (+ d 1)) (depth (cdr L) d)))))

(defun main_depth(L)
  (depth L 1))
;(main_depth `(1 2 (3) (4 5 (6 2 (7))) 4 5 6)) => 4

;c) Write a function to sort a linear list without keeping the double values.
;_remove(e, a1..an) =
;	{ null, n = 0 }
;	{ remove(e, a2..an, e = a1 }
;	{ a1 U remove(e, a2..an), otherwise }
(defun _remove( e lst)
  (cond
   ((null lst) nil)
   ((equal e (car lst)) (_remove e (cdr lst)))
   (t (cons (car lst) (_remove e (cdr lst))))))

;minList(a1, ..., an, currentMin) =
;	{ currentMin,  n = 0 }
;	{ minList(a2..an, a1),a1 < currentMin }
;	{ minList(a2..an, currentMin), otherwise }
(defun minListHelper( lst currMin)
  (cond
   ((null lst) currMin)
   ((< (car lst) currMin) (minListHelper (cdr lst) (car lst)))
   (t (minListHelper (cdr lst) currMin))))

;setting the currentMin at the beginning as the first element of the list
(defun minList(lst)
  (minListHelper lst (car lst)))

;sortList(a1..an) =
;	{minElem, n = 0}
;       {minELem U sorList(a1..an)}
(defun _sort(lst)
   (setq minE (minList lst))
   (setq lst (_remove minE lst))
   (cond
    ( (null lst) (list minE))
    (t (cons minE (_sort lst)))))
;(_sort `(5 5 4 3 2 1)) => (1 2 3 4 5)

;d) Write a function to return the intersection of two sets.

;in(l1..ln, e) = { 0, n=0}
;                {1 + in(l2..ln, e), e = l1}
;                {in(l2..ln, e), e != l1}
(defun in(lst e)
  (cond
   ((null lst) 0)
   ((equal (car lst) e) (+ 1 (in (cdr lst) e)))
   (t (in (cdr lst) e))))

;also computing which list is shorter to make sure we check the right elements
(defun _length(lst)
  (cond
   ((null lst) 0)
   (t (+ 1 (_length (cdr lst))))))

(defun shorter(a b)
  (setq lena (_length a))
  (setq lenb (_length b))
  (cond
   ((<= lena lenb) a)
   (t b)))

(defun longer(a b)
  (setq lena (_length a))
  (setq lenb (_length b))
  (cond
   ((<= lena lenb) b)
   (t a)))

;intersect(a1..an, b1..bm) = {null, n=0 or m=0}
;                            {a1 U intersect(a2..an, b1..bm), a1 in b}
;                            {intersect(a2..an, b1..bm), a1 not in b}
(defun intersect(a b)
  
  (setq ll (longer a b))
  (setq sl (shorter a b)) 
  (cond
   ((or (null a) (null b)) nil)
   ((/= (in ll (car sl)) 0) (cons (car sl) (intersect (cdr sl) ll)))
   (t (intersect (cdr sl) ll))))
;(intersect `(1 2 3 4) `(3 4 5 6 7 3)) => (3 4)

;------------------------------------------------------------

;PROBLEM 8.
;a) Write a function to return the difference of two sets.

;MYfind(l1..ln, e) = { 0, n=0; 1 + find(l2..ln, e), l1 = e; find(l2..ln, e), l1 != e }
;(MYfind `(1 2 3 1) 1)
; 2
(defun MYfind(L e)
  (cond
   ((null L) 0)
   ((= (car L) e) (+ 1 (MYfind (cdr L) e)) )
   (t (MYfind (cdr L) e)) 
  )
)

;diff(l1..ln, k1..km) = { [], n=0; l1..ln, m=0; l1 U diff(l2..ln, k1..km), find(k1..km, l1) = 0; diff(l2..ln, k1..km), t }
;(diff `(1 2 3) `(1 2 3))
;NIL
;(diff `(1 2 3 4 5 6) `(1 2 3))
;(4 5 6)
(defun diff(L K)
  (cond
   ((null L) nil)
   ((null K) L)
   ((= (MYfind K (car L)) 0) (cons (car L) (diff (cdr L) K)))
   (t (diff (cdr L) K))
   )
)

;b) Write a function to reverse a list with its all sublists, on all levels.

;rev(l1..ln) = { [], n=0; rev(l2..ln) U rev(l1), l1 = list ;rev(l2..ln) U l1, otherwise}
;(rev `(1 2 (3 4)))
;((4 3) 2 1)
;(rev `(1 2 (3 4 6) (1 2 3)))
;((3 2 1) (6 4 3) 2 1)
(defun rev(L)
  (cond
   ((null L) nil)
   ((listp (car L)) (append (rev (cdr L)) (list (rev (car L)))))
   (t (append (rev (cdr L)) (list (car L))))))

;lungime(l1..ln) = { 0, n=0; 1 + lungime(l2..ln), otherwise }
;(lungime `(1 2 3 4)) => 4
(defun lungime(L)
  (cond
   ((null L) 0)
   (t (+ 1 (lungime (cdr L))))))

;c) Write a function to return the list of the first elements of all list elements of a given list with an odd
;number of elements at superficial level. Example:
; (1 2 (3 (4 5) (6 7)) 8 (9 10 11)) => (1 3 9).

; firstElem1(l1..ln, i) = { [], n=0; l1 U firstElem1(l2..ln, l+1), length(l1..ln)%2 != 0;
; l1 U firstEleme1(l2..ln, i+1), l1 is list ^ length(l1)%2 != 0
; firstElem1(l2..ln, i+1), l1 is list ^ length(l1) %2 == 0
; firstElem1(l2..ln, i+1), otherwise }
(defun firstElem1(L i)
  (cond
   ((null L) nil)
   ((and (= (mod (lungime L) 2) 1) (= i 1)) (cons (car L) (firstElem1 (cdr L) (+ i 1))))
   ((and (listp (car L)) (= (mod (lungime(car L)) 2) 1)) (cons (car (car L)) (firstElem1 (cdr L) (+ i 1))))
   ((and (listp (car L)) (= (mod (lungime(car L)) 2) 0)) (firstElem1 (cdr L) (+ i 1)))
   (t (firstElem1 (cdr L) (+ i 1)))))
;(firstElem `(1 2 3 (3 4 5) (6 7))) => (1 3)
(defun firstElem(L)
  (firstElem1 L 1))

;d) Write a function to return the sum of all numerical atoms in a list at superficial level.

;sums(l1..ln) = { l1 + sums(l2..ln), l1 is number; sums(l2..ln), otherwise;}
; (sums `(1 2 (3 4) 5)) => 8
(defun sums(L)
  (cond
   ((null L) 0)
   ((numberp (car L)) (+ (car L) (sums (cdr L))))
   (t (sums (cdr L)))))

;-------------------------------------

;PROBLEM 14.
;a) Write a function to return the union of two sets.
;inList(l1..ln, e) = { nil, n=0}
;                {1, e = l1}
;                {in(l2..ln, e), otherwise}
(defun inList(lst e)
  (cond
   ((null lst) nil)
   ((= (car lst) e) 1)
   (t (inList (cdr lst) e))))

;setUnion(a1, ..., an, b1, ..., bm) =
;	{ a1..an, m=0}
;	{ b1 U setUnion(a1..an, b2..bm), b1 NOT IN a1..an }
;	{ setUnion(a1,..an, b2..bm), otherwise }

(defun setUnion(a b)
  (cond
   ( (null b) a)
   ((NOT (inList a (car b))) (append (cons (car b) (setUnion a (cdr b)))))
   (t (setUnion a (cdr b)))))
;(setUnion '(1 3 2) '(2 334 5 4)) => (334 5 4 1 3 2)

;b) Write a function to return the product of all numerical atoms in a list, at any level.
;prod(a1, ..., an) =
;	{ 1, n=0 }
;	{ a1 * prod(a2..an), a1 is number }
;	{ prod(a1) * prod(a2..an), a1 is list }
;	{ prod(a2..an), otherwise}

(defun prod (lst)
  (cond
   ( (null lst) 1)
   ( (numberp (car lst)) (* (car lst) ( prod (cdr lst) ) ) )
   ( (listp (car lst)) (* ( prod (car lst) ) ( prod (cdr lst) ) ) )
   ( ( atom (car lst) ) ( prod (cdr lst)))))
; (prod '(1 2 3 (1 2 a (3)))) => 36

;c) Write a function to sort a linear list with keeping the double values.

;removing only first occurence so that we keep double values
;_removeFirst(e, a1..an) =
;	{ null, n = 0 }
;	{ a2..an, e = a1 }
;	{ a1 U remove(e, a2..an), otherwise }
(defun _removeFirst( e lst)
  (cond
   ((null lst) nil)
   ((equal e (car lst)) (cdr lst))
   (t (cons (car lst) (_removeFirst e (cdr lst))))))

;minListr(a1, ..., an, currentMin) =
;	{ currentMin,  n = 0 }
;	{ minListr(a2..an, a1),a1 < currentMin }
;	{ minListr(a2..an, currentMin), otherwise }
(defun minListHelperr( lst currMin)
  (cond
   ((null lst) currMin)
   ((< (car lst) currMin) (minListHelperr (cdr lst) (car lst)))
   (t (minListHelperr (cdr lst) currMin))))

;setting the currentMin at the beginning as the first element of the list
(defun minListr(lst)
  (minListHelperr lst (car lst)))

;sortListr(a1..an) =
;	{minElem, n = 0}
;       {minELem U sorLisr(a1..an)}
(defun _sortr(lst)
   (setq minE (minListr lst))
   (setq lst (_removeFirst minE lst))
   (cond
    ( (null lst) (list minE))
    (t (cons minE (_sortr lst)))))
;(_sortr `(5 5 4 3 2 1)) => (1 2 3 4 5 5)

;d) Build a list which contains positions of a minimum numeric element from a given linear list.

;indexList(l1..ln, e, idx) = { null, n=0 }
;                    { idx U indexList(l2..ln, e, idx+1), l1 =e }
;                    { indexList(l2..ln, e, idx+1, othewise }
(defun indexListHelper(e lst idx)
  (cond
   ((null lst) nil)
   ((= e (car lst)) (cons idx (indexListHelper e (cdr lst) (+ 1 idx))))
   (t (indexListHelper e (cdr lst) (+ 1 idx)))))

(defun indexList(lst)
  (indexListHelper (minListr lst) lst 0))
;(indexList '(1 2 3 1 4 5 1)) => (0 3 6)