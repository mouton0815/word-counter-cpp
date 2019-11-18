#include <iostream>
#include <map>
#include "constants.hh"
#include "blocking-queue.hh"
#include "tokenizer.hh"
#include "file-reader-impl.hh"
#include "string-queue.hh"

using namespace std;

int main(int argc, char** argv) {
    map<string, int> myMap;
    myMap["hello"] = 1;
    myMap["world"] = 1;
    myMap["world"]++;

    for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
        cout << it->first << " :: " << it->second << endl;
    }

    StringQueue myQueue;
    myQueue.push("Hello");
    myQueue.push("World");
    cout << myQueue.pop() << endl;
    cout << myQueue.pop() << endl;

    Tokenizer tokenizer(myQueue);
    FileReaderImpl reader(tokenizer);
    reader.read("./data/file1.txt");
    reader.close();

    std::string word;
    while ((word = myQueue.pop()) != STREAM_END) {
        std::cout << "---" << word;
    }
    std::cout << std::endl;
    return 0;
}
