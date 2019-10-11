cmake_minimum_required (VERSION 2.6)

set (SRC Piece.cxx Joueur.cxx Echiquier.cxx)
set (EXE testPiece)

set (SRCTEST PieceTest.cxx JoueurTest.cxx EchiquierTest.cxx)
set (EXETEST testCppUnit)

set (EXEGTEST testGtest)

# C++11
macro(use_cxx11)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
  else ()
    set (CMAKE_CXX_STANDARD 11)
  endif ()
endmacro(use_cxx11)

# target doxygen : doc/html/index.html
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)

# target valgrind : ctest -D ExperimentalTest -V
find_program( MEMORYCHECK_COMMAND valgrind )
set( MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full" )

# target sonarqube
add_custom_target(sonarqube
COMMAND sonar-scanner -Dproject.settings=${CMAKE_CURRENT_SOURCE_DIR}
)

# target cppcheck : check/index.html
add_custom_target(cppcheck
# analysis
COMMAND cppcheck -v -f --language=c++ --xml --xml-version=2 --enable=all  ${CMAKE_CURRENT_SOURCE_DIR} 2> check.xml
# htmlreport
COMMAND cppcheck-htmlreport --source-dir=${CMAKE_CURRENT_SOURCE_DIR} --report-dir=check --file=check.xml
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
COMMENT "Running cppcheck to produce code analysis report."
)

# target cppunit
macro(find_cppunit)
  FIND_PATH(CPPUNIT_INCLUDE_DIR cppunit/Test.h)
  FIND_LIBRARY(CPPUNIT_LIBRARY NAMES cppunit)
  IF (CPPUNIT_INCLUDE_DIR AND CPPUNIT_LIBRARY)
      SET(CPPUNIT_FOUND TRUE)
  ENDIF (CPPUNIT_INCLUDE_DIR AND CPPUNIT_LIBRARY)
  IF (CPPUNIT_FOUND)
      # show which CppUnit was found only if not quiet
      IF (NOT CppUnit_FIND_QUIETLY)
      	 MESSAGE(STATUS "Found CppUnit: ${CPPUNIT_LIBRARY}")
      ENDIF (NOT CppUnit_FIND_QUIETLY)
  ELSE (CPPUNIT_FOUND)
      # fatal error if CppUnit is required but not found
      IF (CppUnit_FIND_REQUIRED)
      	 MESSAGE(FATAL_ERROR "Could not find CppUnit")
      ENDIF (CppUnit_FIND_REQUIRED)
  ENDIF (CPPUNIT_FOUND)
endmacro(find_cppunit)

# target cov : coverage.html
add_custom_target(cov
# tests
COMMAND ${EXE}
# gcovr
COMMAND lcov --directory ${CMAKE_CURRENT_SOURCE_DIR} --capture --output-file coverage.lcov
COMMAND	python ${CMAKE_CURRENT_SOURCE_DIR}/lcov_cobertura.py coverage.lcov --output coverage.xml
COMMAND gcovr -r ${CMAKE_CURRENT_SOURCE_DIR} --html -o coverage.html --html-details
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
COMMENT "Running gcovr to produce code coverage report."
)

# target etags/tags
add_custom_target(tags etags --members --declarations  `find ${CMAKE_CURRENT_SOURCE_DIR} -name *.cxx -or -name *.h`)
add_custom_target(etags DEPENDS tags)

project (Echecs)
use_cxx11()
add_compile_options(-g -O0 --coverage)
#add_executable(${EXE} MACOSX_BUNDLE ${EXE}.cxx ${SRC})
add_executable(${EXE} ${EXE}.cxx ${SRC})
target_link_libraries(${EXE} --coverage)

enable_testing()

find_cppunit()
include_directories(${CPPUNIT_INCLUDE_DIR})
add_executable(${EXETEST} ${EXETEST}.cxx ${SRC} ${SRCTEST})
target_link_libraries(${EXETEST} --coverage ${CPPUNIT_LIBRARY})
add_test(${EXETEST} ${EXETEST})

find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(${EXEGTEST} ${EXEGTEST}.cxx ${SRC})
target_link_libraries(${EXEGTEST} --coverage ${GTEST_LIBRARIES})
add_test(${EXEGTEST} ${EXEGTEST})

INCLUDE(InstallRequiredSystemLibraries)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Chess")
SET(CPACK_PACKAGE_VENDOR "Bordeaux University, Inria")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/../README.md")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/../LICENSE")
SET(CPACK_PACKAGE_VERSION_MAJOR "1")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")

SET(CPACK_STRIP_FILES "testPiece")
SET(CPACK_SOURCE_STRIP_FILES "")
SET(CPACK_PACKAGE_EXECUTABLES "testPiece" "testPiece")

#SET(CPACK_GENERATOR "DEB")
#SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Pierre Ramet") #required
INCLUDE(CPack)

