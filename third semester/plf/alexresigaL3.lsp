; 14. Write a function that returns the number of atoms in a list, at any level
;atomCount(lst) = { 1, lst = atom}
;                  {SUM atomCount(listi), lst = list}
(defun atomCount(list)
  (cond
   ((atom list) 1)
   (t (apply ` + (mapcar `atomCount list)))))
; (atomCount '(1 2 (3 A (B 4 (C))))) => 7