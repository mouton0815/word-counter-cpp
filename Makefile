word-counter-test: word-counter-test.o word-counter.o word-count-mapper.o constants.o
	c++ -o word-counter-test.exe test/word-counter-test.o src/word-counter.o src/word-count-mapper.o src/constants.o

word-counter-test.o: test/word-counter-test.cc src/word-counter.hh src/word-count-mapper.hh src/constants.hh
	c++ -o test/word-counter-test.o -c test/word-counter-test.cc

word-counter.o: src/word-counter.cc src/word-counter.hh src/word-count-mapper.hh src/constants.hh
	c++ -o src/word-counter.o -c src/word-counter.cc

word-count-mapper.o: src/word-count-mapper.cc src/word-count-mapper.hh src/constants.hh
	c++ -o src/word-count-mapper.o -c src/word-count-mapper.cc

constants.o: src/constants.cc src/constants.hh
	c++ -o src/constants.o -c src/constants.cc
