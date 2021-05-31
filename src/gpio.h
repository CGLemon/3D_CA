#pragma once

#include <thread>
#include <atomic>
#include <chrono>

class Listener {
public:
    static Listener& get();

    void run();
    void stop();
    bool probe();

private:
    bool scan_pin(int pin);

    std::thread m_worker;
    int m_pin;

    std::atomic<bool> running;
    std::atomic<bool> voice;
};

