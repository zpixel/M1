
;implementation de la vm
;construit la vm -> initialisation
(defun make-vm(nom-vm taille code)
  (progn 
    (setf (get nom-vm 'ram) 10000)
    (setf (get nom-vm 'R0) 0)
    (setf (get nom-vm 'R1) 0) 
    ))

(defun exec-vm(instruction)
  ;analyse par cas des instructions
  ;(case (car intruction)
  ;  (move ...)
  ;  (push ...)
  )

;charge le code dans le registre d'instruction
;vm : la vm que l'on manipule
;code : liste plate des intructions 
(defun load-vm(vm code)
  (loop for instruction in code
	do
	;instru->(move ('1 ) R0)
	)
  )

(defun get-registre(nom reg)
  (get nom reg))
(defun set-registre(nom reg)
  (setf ())

(defun lire-mem(vm adresse)
  (aref (get vm 'MEM) adresse))

(defun ecrire-mem(vm adresse valeur)
  (setf (aref (get vm 'MEM) adresse) valeur))


