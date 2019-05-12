;PROBLEM 2. Return the list of nodes on the k-th level of a tree of type (1).
;leftChild(l1...ln, children) = NIL, children = 0
;                              = l1, l2 U leftChild(l3...ln, children - 1 + l2), otherwise
(defun leftChild(l children)
  (COND
   ( (= children 0) NIL )
   ( T ( cons (car l)  ( cons (cadr l) ( leftChild (cddr  l) (+ (- children 1) (cadr l))))))))

;rightChild(l1...ln, children) = l1...ln, children = 0
;                              = rightChild(l3...ln, children - 1 + l2), otherwise
(defun rightChild(l children)
  (COND
   ( (= children 0) l )
   ( T ( rightChild (cddr l) (+ (- children 1) (cadr l))))))

;nodesOnLevel(l1..ln k lvl) = {nil, n=0}
;                             {list(l1), k = lvl}
;                             {nil, l2 = 0}
;                             {nodesOnLevel(leftChild(l3..ln, 1), k, lvl+1) U nodesOnLevel(rightChild(l3..ln, 1), k, lvl+1)}
(defun nodesOnLevel(l k level)
  (COND
   ((null l) nil)
   ((= level k) (list (car l)))
   ((eq (cadr l) 0) nil)
   (T (append (nodesOnLevel (leftChild (cddr l) 1) k (+ 1 level)) (nodesOnLevel (rightChild (cddr l) 1) k (+ 1 level))))))
;(nodesOnLevel `(A 2 B 0 C 2 D 0 E 0) 2 0) => (D E)


;PROBLEM 3. Return the number of levels of a tree of type (1).
;depth(l1..ln k lvl) = {0, n=0}
;                      {lvl, l2 = 0}
;                      {max(depthl((leftChild(l3..ln, 1),lvl+1), depth(rightChild(l3..ln, 1), lvl+1)}
(defun _depth(lst lvl)
  (cond
   ((null lst) 0)
   ((eq (cadr lst) 0) lvl)
   (T (max (_depth (leftChild (cddr lst) 1)  (+ 1 lvl)) (_depth (rightChild (cddr lst) 1)  (+ 1 lvl))))))
;(_depth `(A 2 B 0 C 2 D 0 E 0) 1) => 3

;PROBLEM 10. Return the level of a node X in a tree of type (2). The level of the root element is 0.
(defun _findLevel(arb x n)
  (cond
   ((and (atom arb) (equal arb x)) (- n 1))
   ((and (atom arb) (not (equal arb x))) 0)
   (t (apply '+(mapcar #'(lambda(a) (_findLevel a x (+ n 1))) arb)))))
 
(defun findLevel(arb x)
  (_findLevel arb x 0))
;(findLevel `(A (B) (C (D) (E))) `C) => 1


;PROBLEM 12. Determine the list of nodes accesed in preorder in a tree of type (2).

;   preorder(l1..ln) = {nil, n=0 }
;                 {(L), n = 1 }
;                 {(L1) U preorder(L2) U preorder(L3) ... U preorder(Ln)}
; 
(defun preorder(x)
    (cond
        ((null x) nil)
        ((atom x) (cons x nil))
        (T (apply 'append (mapcar 'preorder x)))))
;(preorder `(A (B) (C (D) (E)))) => (A B C D E)
