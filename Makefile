COMP=pdflatex
SRC=TP2.tex
OBJ=$(SRC:.tex=.pdf)

all: $(OBJ)

%.pdf: %.tex
	$(COMP) $<
	$(COMP) $<

clean:
	@rm -rf *.aux
	@rm -rf *.log
	
mrproper: clean
	@rm -rf $(OBJ)
