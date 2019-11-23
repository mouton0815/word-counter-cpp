#pragma once
#include <filesystem>
#include "blocking-queue.hh"

typedef std::filesystem::path Path;
typedef BlockingQueue<Path> PathQueue;
