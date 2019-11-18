Some observations:
* With version 11, C++ became an even more complex beast than it had already been with older versions.
There are lot's of new and mostly *good* features that make the code more concise and programs safer.
But since all old stuff remains, C++ is much harder to learn than other languages, especially Go. 
* In contrast to Go or Java, the C++ standard library does not provide a blocking queue.
I had to copy [this one](https://stackoverflow.com/a/12805690) from StackOverflow
and added some unit tests.
* Unicode support in C++ is just terrible (see [here](https://stackoverflow.com/a/17106065)).
I was not able to make unicode-aware regular expressions working, so the C++ version splits
correctly on ASCII texts only.
I may do a later attempt using the [ICU library](http://site.icu-project.org/design/cpp).
