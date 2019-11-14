//
// Credits: https://stackoverflow.com/a/12805690
//
#pragma once

#include <condition_variable>
#include <mutex>
#include <queue>

template <typename T>
class BlockingQueue {
private:
    std::condition_variable m_cond;
    std::queue<T>           m_queue;
    std::mutex              m_mutex;
public:
    void push(T const& item) {
        {
            std::unique_lock<std::mutex> lock(this->m_mutex);
            m_queue.push(item);
        }
        m_cond.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cond.wait(lock, [this]{ return !m_queue.empty(); });
        const T item = m_queue.front();
        m_queue.pop();
        return item;
    }
};
