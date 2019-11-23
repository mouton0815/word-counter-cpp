# Word Counter (C++ Version)
Counts the number of occurrences of every word in all text files within a folder.

Goals of this project were:
* Refresh my C++ knowledge and get acquainted to C++ 11.
* Compare with implementations of the same project in C++, [Go](https://github.com/mouton0815/word-counter-go),
[Java](https://github.com/mouton0815/word-counter-java), Node, Python, Rust.

The project consists of
* A [path collector](src/path-collector.cc) that retrieves the path names of all `*.txt` files
in a given folder and its subdirectories and passes them to a channel named `pathQueue`.
* A [file reader](src/file-reader-impl.cc) that reads the files and passes the content text to
a [tokenizer](src/tokenizer.cc), which splits the text into words and passes them to a channel name `wordQueue`.
* A number of [workers](src/worker.cc) that receive path names from a `pathQueue` and hands
them over to the file reader.
* A [worker pool](src/worker-pool.cc) that spawns a worker for every available CPU and waits for their terminations.
* A [word counter](src/word-counter.cc) that listens to `wordQueue` and counts the number of
occurrences for every word.
* A [main](src/main.cc) program that wires the classes, starts the path collector, the worker pool,
and the word counter. Finally, it outputs the word lists ordered by decreasing number of occurrences. 

Some observations:
* With version 11, C++ became an even more complex beast than it had already been with older versions.
There are lot's of new and mostly *good* features that make the code more concise and programs safer.
But since all old stuff remains, C++ is much harder to learn than other languages, especially Go. 
* Compiler errors are hard to read, especially if the compile fills the terminal completely with
candidate functions that do _not_ match or with functions that get "deleted".
* In contrast to Go or Java, the C++ standard library does not provide a blocking queue.
I had to copy [this one](https://stackoverflow.com/a/12805690) from StackOverflow
and added some unit tests.
* Unicode support in C++ is just terrible (see [here](https://stackoverflow.com/a/17106065)).
I was not able to make unicode-aware regular expressions working, so the C++ version splits
correctly on ASCII texts only.
I may do a later attempt using the [ICU library](http://site.icu-project.org/design/cpp).
* Lots of hassle with `<filesystem>`, which is available since C++ 17. Ubuntu 18.04.3 LTS comes with GCC 7.4.0,
which supports C++ 17, but _not_ `<filesystem>`. To use it, one has to include `<experimental/filesystem>`
and link with `-lstdc++fs`. But then class `directory_entry` does not support the standard method
`is_regular_file()` ... aargh.
* Last but not least, the C++ variant is more than 3 times _slower_ than the Java variant, and nearly
5 times slower than the Go variant. Of course this smells like serious programming mistakes, but it
also shows that writing performant C++ programs is not trivial. 

# Building
The project has been developed on Ubuntu 18.04.1 LTS with GCC 9.2.1. It uses many C++ 11 features
and the C++ 17 `<filesystem>` package. The project may compile with GCC 8.x, but _not_ with
GCC 7.x, because GCCC 7 one only supports an `<experimental/filesystem>` implementation.
The project does _not_ compile with MinGW due to its lack of locales support. 
```
make
```

# Running
```
./main.exe <folder>
```
For example, count the words of all files in folder `./data` and write the results in file `wordcounts.txt`:
```
./main.exe ./data > wordcounts.txt
```

# Testing
```
make test.exe && ./test.exe
```

# License
MIT
