#include "tests.hh"

int main(int argc, char** argv) {
    testBlockingQueueSimple();
    testBlockingQueueWaiting();
    testBlockingQueueConcurrently();

    testWordCountMapperEmpty();
    testWordCountMapperSimple();
    testWordCountMapperSecondary();
    // testWordCountMapperUnicode(); // Does not work with MinGW, try with other compiler

    testWordCounterEmpty();
    testWordCounterSingle();
    testWordCounterMultiple();

    testTokenizerEmpty();
    testTokenizerTrim();
    testTokenizerMulti();
    testTokenizerSpecialSigns();
    testTokenizerUnderscore();
    testTokenizerUnicodeGerman();
    /*
    testTokenizerUnicodeRussian();
    testTokenizerUnicodeCzech();
    testTokenizerIgnoreNumbers();
    */

    testWorkerEmpty();
    testWorkerNormal();

    return 0;
}
