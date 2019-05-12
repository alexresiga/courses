; 14. Write a function that returns the number of atoms in a list, at any level
;atomCount(lst) = { 1, lst = atom}
;                  {SUM atomCount(listi), lst = list}
(defun atomCount(list)
  (cond
   ((atom list) 1)
   (t (apply ` + (mapcar `atomCount list)))))
; (atomCount '(1 2 (3 A (B 4 (C))))) => 7


; 2. Write a function that returns the sum of numeric atoms in a list, at any level.
;naSum(lst) = { lst, lst = number}
;             {0, lst = atom}
;             {SUM atomCount(listi), lst = list}
(defun naSum(lst)
  (cond
   ((numberp lst) lst)
   ((atom lst) 0)
   (t (apply `+(mapcar `naSum lst)))))
; (naSum '(1 2 3 A B 4 (32 (5) (3) (1 (1)) C))) => 52

;11. Write a function to determine the depth of a list.
;listDepthBack(tree, level) = {level, tree=atom}
;                             {MAX(listDepthBack(treei, level+1))}
(defun listDepthBack (tree level)
  (cond
   ((atom tree) level)		
   ((listp tree) (apply 'max (mapcar(lambda (a) (listDepthBack a (+ 1 level))) tree)))))

(defun listDepth (tree) (listDepthBack tree 0))
; (listDepth '(1 2 3 (4 5 6) (7) (8 (9)))) => 3


; 4. Write a function that returns the product of numeric atoms in a list, at any level.
;naProd(lst) = {lst, lst=number}
;              {1, lst=atom}
;              {PRODUCT(naProd(lsti))}
(defun naProd(lst)
  (cond
   ((numberp lst) lst)
   ((atom lst) 1)
   (t (apply `*(mapcar `naProd lst)))))
; (naProd '(1 2 (3 A (B 4 (C))))) => 24