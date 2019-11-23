#pragma once
#include <experimental/filesystem> // TODO: Upgrade to GCC 8 and remove "experimental" (+ make requirements clear in README.md)
#include "blocking-queue.hh"

typedef std::experimental::filesystem::path Path;
typedef BlockingQueue<Path> PathQueue;
