;8
;a) Write a function to return the difference of two sets.
;b) Write a function to reverse a list with its all sublists, on all levels.
;c) Write a function to return the list of the first elements of all list elements of a given list with an odd
;number of elements at superficial level. Example:
; (1 2 (3 (4 5) (6 7)) 8 (9 10 11)) => (1 3 9).
;d) Write a function to return the sum of all numerical atoms in a list at superficial level.


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
;(lungime `(1 2 3 4))
;4
(defun lungime(L)
  (cond
   ((null L) 0)
   (t (+ 1 (lungime (cdr L))))))


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
;(firstElem `(1 2 3 (3 4 5) (6 7)))
;(1 3)
(defun firstElem(L)
  (firstElem1 L 1))


;sums(l1..ln) = { l1 + sums(l2..ln), l1 is number; sums(l2..ln), otherwise;}
; (sums `(1 2 (3 4) 5))
;8
(defun sums(L)
  (cond
   ((null L) 0)
   ((numberp (car L)) (+ (car L) (sums (cdr L))))
   (t (sums (cdr L)))))