CXX = g++
CXXFLAGS = -Wall -pthread
LDFLAGS = -Wall -pthread

objects = src/constants.o src/word-count-mapper.o src/word-counter.o
test_objects = test/tests.o test/blocking-queue-test.o test/word-count-mapper-test.o test/word-counter-test.o

main: $(objects)
	$(CXX) $(LDFLAGS) -o main.exe $(objects)

tests: $(test_objects) $(objects)
	$(CXX) $(LDFLAGS) -o tests.exe $(test_objects) $(objects)

$(objects): src/*.hh
$(test_objects): src/*.hh test/tests.hh

.PHONY: clean
clean:
	rm $(test_objects) $(objects) tests.exe