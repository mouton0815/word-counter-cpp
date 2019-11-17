objects = src/constants.o src/word-count-mapper.o src/word-counter.o
test_objects = test/tests.o test/blocking-queue-test.o test/word-count-mapper-test.o test/word-counter-test.o

main: $(objects)
	c++ -o main.exe $(objects)

test: $(test_objects) $(objects)
	c++ -o tests.exe $(test_objects) $(objects)

$(objects): src/*.hh
$(test_objects): src/*.hh test/tests.hh

.PHONY: clean
clean:
	rm $(objects)