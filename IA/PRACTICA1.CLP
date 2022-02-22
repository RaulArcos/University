(clear)

(deftemplate ubicacion
	(slot c1)
	(slot pos (allowed-values norte sur este oeste noroeste noreste suroeste sureste))
	(slot c2)
)

(deffacts inicio
	(ubicacion (c1 A) (pos norte) (c2 D))
	(ubicacion (c1 A) (pos oeste) (c2 B))
	(ubicacion (c1 B) (pos norte) (c2 E))
	(ubicacion (c1 B) (pos oeste) (c2 C))
	(ubicacion (c1 C) (pos norte) (c2 F))
	(ubicacion (c1 D) (pos norte) (c2 G))
	(ubicacion (c1 D) (pos oeste) (c2 E))
	(ubicacion (c1 E) (pos norte) (c2 H))
	(ubicacion (c1 E) (pos oeste) (c2 F))
	(ubicacion (c1 F) (pos norte) (c2 I))
	(ubicacion (c1 G) (pos oeste) (c2 H))
	(ubicacion (c1 H) (pos oeste) (c2 I))
)

(defrule R1_sur
	(ubicacion (c1 ?x) (pos norte) (c2 ?y))
	=>
	(assert (ubicacion (c1 ?y) (pos sur) (c2 ?x)))
)
(defrule R1_este
	(ubicacion (c1 ?x) (pos oeste) (c2 ?y))
	=>
	(assert (ubicacion (c1 ?y) (pos este) (c2 ?x)))
)
(defrule R2_transitividad
	(ubicacion (c1 ?x) (pos ?p) (c2 ?y))
	(ubicacion (c1 ?y) (pos ?p) (c2 ?z))
	=>
	(assert (ubicacion (c1 ?x) (pos ?p) (c2 ?z)))
)
(defrule R3_noroeste
	(ubicacion (c1 ?x) (pos norte) (c2 ?y))
	(ubicacion (c1 ?y) (pos oeste) (c2 ?z))
	=>
	(assert (ubicacion (c1 ?x) (pos noroeste) (c2 ?z)))
)
(defrule R3_noreste
	(ubicacion (c1 ?x) (pos norte) (c2 ?y))
	(ubicacion (c1 ?y) (pos este) (c2 ?z))
	=>
	(assert (ubicacion (c1 ?x) (pos noreste) (c2 ?z)))
)
(defrule R3_suroeste
	(ubicacion (c1 ?x) (pos sur) (c2 ?y))
	(ubicacion (c1 ?y) (pos oeste) (c2 ?z))
	=>
	(assert (ubicacion (c1 ?x) (pos suroeste) (c2 ?z)))
)
(defrule R3_sureste
	(ubicacion (c1 ?x) (pos sur) (c2 ?y))
	(ubicacion (c1 ?y) (pos este) (c2 ?z))
	=>
	(assert (ubicacion (c1 ?x) (pos sureste) (c2 ?z)))
)
(defrule inicio
	?f1 <-(situacion ?x ?y)
	(ubicacion (c1 ?x) (pos ?u) (c2 ?y))
	=>
	(printout t ?x " esta al " ?u " de " ?y crlf)
	(retract ?f1)
)


