#include "gpio.h"

#include <random>

Listener& Listener::get() {
    static Listener l;
    return l;
}

void Listener::run() {
  running.store(true);
  voice.store(false);

  const auto worker = [this]() {
    while(running.load()) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1));

      if (voice.load()) {
        continue;
      }

      if (scan_pin(m_pin)) {
        voice.store(true);;
      }
    }
  };

  m_worker = std::move(
      std::thread(worker)
  );
}

bool Listener::scan_pin(int pin) {
#ifdef USE_WIRING_PI
  return digitalRead(pin);
#else
  (void) pin;
  static std::random_device rd;
  static auto dummy_gen = std::default_random_engine(rd());
  static auto dummy_dist = std::uniform_int_distribution<int>(0, 1000);

  return dummy_dist(dummy_gen) == 3;
#endif
}

bool Listener::probe() {
  auto test_val = true;
  voice.compare_exchange_weak(test_val, false);

  return test_val;
}

void Listener::stop() {
  running.store(false);
  m_worker.join();
}
