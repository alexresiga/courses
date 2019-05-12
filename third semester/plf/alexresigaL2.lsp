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