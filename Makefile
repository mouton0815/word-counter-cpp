CXX = g++
CXXFLAGS = -Wall -pthread
LDFLAGS = -Wall -pthread

objects = \
    src/constants.o \
    src/word-count-mapper.o \
    src/word-counter.o \
    src/tokenizer.o \
    src/path-collector.o \
    src/file-reader-impl.o \
    src/worker.o

main_objects = $(objects) \
    src/main.o

test_objects = \
    test/tests.o \
    test/blocking-queue-test.o \
    test/word-count-mapper-test.o \
    test/tokenizer-test.o \
    test/word-counter-test.o \
    test/path-collector-test.o \
    test/file-reader-test.o \
    test/worker-test.o

main: $(main_objects)
	$(CXX) $(LDFLAGS) -o main.exe $(main_objects)

test: $(test_objects) $(objects)
	$(CXX) $(LDFLAGS) -o test.exe $(test_objects) $(objects)

$(main_objects): src/*.hh
$(test_objects): src/*.hh test/*.hh

.PHONY: clean
clean:
	rm $(main_objects) $(test_objects) main.exe test.exe
