uml/classes.png: *.hpp
	./uml/mk_uml.sh uml/classes.png *.hpp

nblines:
	@wc -l *.h *.[ch]pp
