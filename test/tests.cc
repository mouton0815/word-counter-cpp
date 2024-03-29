#include "tests.hh"

int main(int argc, char** argv) {
    testBlockingQueueSimple();
    testBlockingQueueWaiting();
    testBlockingQueueConcurrently();

    testWordCountMapperEmpty();
    testWordCountMapperSimple();
    testWordCountMapperSecondary();
    testWordCountMapperUnicode();

    testWordCounterEmpty();
    testWordCounterSingle();
    testWordCounterMultiple();

    testTokenizerEmpty();
    testTokenizerTrim();
    testTokenizerMulti();
    testTokenizerSpecialSigns();
    testTokenizerUnderscore();
    // testTokenizerUnicodeGerman(); // Broken, need to try ICU
    // testTokenizerUnicodeRussian();
    // testTokenizerUnicodeCzech();
    testTokenizerIgnoreNumbers();

    testPathCollector();

    testFileReaderSuccess();
    testFileReaderNotFound();

    testWorkerEmpty();
    testWorkerNormal();

    testWorkerPoolNoInput();
    testWorkerPoolWithInput();

    return 0;
}
