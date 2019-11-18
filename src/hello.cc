#include <iostream>
#include <map>
#include "blocking-queue.hh"

using namespace std;

int main(int argc, char** argv) {
    map<string, int> myMap;
    myMap["hello"] = 1;
    myMap["world"] = 1;
    myMap["world"]++;

    for (map<string, int>::iterator it = myMap.begin(); it != myMap.end(); it++) {
        cout << it->first << " :: " << it->second << endl;
    }

    WordQueue myQueue;
    myQueue.push("Hello");
    myQueue.push("World");
    cout << myQueue.pop() << endl;
    cout << myQueue.pop() << endl;

    return 0;
}
