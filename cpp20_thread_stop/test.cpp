#include <algorithm>
#include <chrono>
#include <iostream>
#include <ranges>
#include <stop_token>
#include <thread>
#include <utility>

using namespace std::chrono_literals;

void worker_fun(int id, std::stop_source stop_source) {
  std::stop_token stoken = stop_source.get_token();

  for (int i = 10; i; --i) {
    std::this_thread::sleep_for(300ms);
    if (stoken.stop_requested()) {
      std::printf("  worker%d is requested to stop\n", id);
      return;
    }
    std::printf("  worker%d goes back to sleep\n", id);
  }
}

void worker_fun_1(int id, std::stop_source stop_source) {
  for (int i = 10; i; --i) {
    std::this_thread::sleep_for(300ms);
    if (stop_source.stop_requested()) {
      std::printf("  worker%d is requested to stop\n", id);
      return;
    }
    std::printf("  worker%d goes back to sleep\n", id);
  }
}

void print_stop_source(const std::stop_source& source) {
  std::printf("stop_source stop_possible = %s, stop_requested = %s\n", source.stop_possible() ? "true" : "false",
              source.stop_requested() ? "true" : "false");
};

void from_cppreference() {
  std::jthread threads[4];
  std::cout << std::boolalpha;

  std::stop_source stop_source;

  print_stop_source(stop_source);

  for (int i = 0; i < 4; ++i) {
    threads[i] = std::jthread(worker_fun, i + 1, stop_source);
  }

  std::this_thread::sleep_for(750ms);

  std::puts("Request stop");

  stop_source.request_stop();

  print_stop_source(stop_source);
}

void test1() {
  std::jthread threads[4];
  std::cout << std::boolalpha;

  std::stop_source stop_source;

  print_stop_source(stop_source);

  int counter = 0;
  std::ranges::for_each(threads,
                        [&counter, &stop_source](auto& t) { t = std::jthread(worker_fun_1, ++counter, stop_source); });

  std::this_thread::sleep_for(750ms);

  std::puts("Request stop");

  stop_source.request_stop();

  print_stop_source(stop_source);
}

int main() {
  // from_cppreference();
  test1();
}
