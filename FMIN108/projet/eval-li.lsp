;evalue les expression contenu dans lexpr liste
;return  : expressions evalués 
(defun map-eval-li (lexpr env)
  (if (atom lexpr)
      ()
    (cons (eval-li (car lexpr) env) (map-eval-li (cdr lexpr) env)) 
    )
)

(defun eval-li (expr env)
  (case (car expr)

    (:const 
     (cadr expr))

    (:var 
     (aref env (cadr expr)))

    (:set-var 
     (setf (aref env (cadr expr)) (eval-li (cddr expr) env)))
    
	   

    (:if 
     (if (eval-li (second expr) env)
	 (eval-li (third expr) env)
       (eval-li (fourth expr) env)))

    (:call
     (apply (second expr) (map-eval-li (cddr expr) env))
    
    )

    (:unknown (eval-li
    )
)



