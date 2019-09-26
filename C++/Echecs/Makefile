SRC_CXX=Piece.cxx Joueur.cxx
EXE=testPiece

OBJ=${SRC_CXX:.cxx=.o}

CPP = g++ -g -std=c++11 --coverage
# -fsanitize=address -fno-omit-frame-pointer

all: $(EXE)

$(EXE): $(OBJ) $(EXE).o
	$(CPP) $(OBJ) $(EXE).o -o $(EXE)


cov: $(EXE)
	./$(EXE)
	lcov --directory . --capture --output-file coverage.lcov
	lcov --summary coverage.lcov
	python lcov_cobertura.py coverage.lcov --output coverage.xml
	gcovr -r .

cov-html: cov
	gcovr -r . --html -o coverage.html --html-details
	#open coverage.html

-include ${OBJ:.o=.d}

%.o: %.cxx
	$(CPP) -c $*.cxx -o $*.o
	$(CPP) -MM $*.cxx > $*.d

clean:
	@rm -f $(OBJ) $(EXE).o $(EXE) *~ *.xml *.html *.lcov *.gcda *.gcno *.d

