SRC_CXX=Piece.cxx
EXE=testPiece

OBJ=${SRC_CXX:.cxx=.o}

all: $(EXE)

$(EXE): $(OBJ) $(EXE).o
	g++ --coverage $(OBJ) $(EXE).o -o $(EXE)

%.o: %.cxx
	g++ -c -g --coverage $<

cov: $(EXE)
	./$(EXE)
	lcov --directory . --capture --output-file coverage.lcov
	lcov --summary coverage.lcov
	python lcov_cobertura.py coverage.lcov --output coverage.xml
	gcovr -r .

cov-html: cov
	gcovr -r . --html -o coverage.html --html-details
	#open coverage.html

clean:
	@rm -f $(OBJ) $(EXE).o $(EXE) *~ *.xml *.html *.lcov *.gcda *.gcno

