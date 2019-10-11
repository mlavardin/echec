SRC= Piece.cxx Joueur.cxx Echiquier.cxx
EXE= testPiece
OBJ=${SRC:.cxx=.o}

SRCTEST=PieceTest.cxx JoueurTest.cxx EchiquierTest.cxx
EXETEST=testCppUnit
OBJTEST=${SRCTEST:.cxx=.o}

GTEST=testGtest

CPP = g++ -g -std=c++11 --coverage
# -fsanitize=address -fno-omit-frame-pointer

.PHONY: all
all: $(EXE)

# pour construire Doxyfile : doxygen -g
.PHONY: doc
doc:
	doxygen
	#open doc/html/index.html

.PHONY: valgrind
valgrind:
	valgrind --leak-check=full ./$(EXE)

filelist.txt:
	git ls-files | grep "\.[ch]" > filelist.txt

.PHONY: cppcheck
cppcheck: filelist.txt
	cppcheck -v -f --language=c++ --enable=all --xml --xml-version=2 --file-list=./filelist.txt 2> check.xml
.PHONY: cppcheck-html
cppcheck-html: cppcheck
	cppcheck-htmlreport --source-dir=. --report-dir=check --file=check.xml
	#open check/index.html

.PHONY: sonarqube
sonarqube:
	sonar-scanner
	#open http://localhost:9000/dashboard/index/my:chess
	#(first start : sonar console)
	#(admin/admin)

.PHONY: cppunit
cppunit: $(OBJ) $(OBJTEST) $(SRCTEST)
  	#`cppunit-config --cflags` `cppunit-config --libs`
	$(CPP) $(OBJ) $(OBJTEST) $(EXETEST).cxx -lcppunit -o $(EXETEST)
	./$(EXETEST)
	#xsltproc cppunit2junit.xsl cppunit-report.xml > junit-report.xml

.PHONY: gtest
gtest: $(OBJ)
	$(CPP) $(OBJ) $(GTEST).cxx -lgtest -lpthread -o $(GTEST)
	./$(GTEST)

.PHONY: cov
cov: $(EXE)
	./$(EXE)
	lcov --directory . --capture --output-file coverage.lcov
	lcov --summary coverage.lcov
	python lcov_cobertura.py coverage.lcov --output coverage.xml
	gcovr -r .
.PHONY: cov-html
cov-html: cov
	gcovr -r . --html -o coverage.html --html-details
	#open coverage.html

.PHONY: rats
rats: filelist.txt
	rats -w 3 --xml `cat filelist.txt` > rats.xml
.PHONY: rats-html
rats-html:
	rats -w 3 --html `cat filelist.txt` > rats.html
	#open rats.html

.PHONY: etags
etags:
	rm -f TAGS
	git ls-files | xargs etags

$(EXE): $(OBJ) $(EXE).cxx
	$(CPP) $(OBJ) $(EXE).cxx -o $(EXE)

-include $(OBJ:.o=.d)
-include $(OBJTEST:.o=.d)

%.o: %.cxx
	$(CPP) -c $*.cxx -o $*.o
	$(CPP) -MM $*.cxx > $*.d

clean:
	@rm -f $(OBJ) $(EXE) $(EXETEST) $(GTEST) *~ TAGS *.gcov *.gcno *.gcda *.html *.xml *.d *.o *.lcov filelist.txt
	@rm -rf doc check *.dSYM

