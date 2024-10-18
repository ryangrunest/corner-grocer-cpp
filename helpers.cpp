#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

// clear the console
void CLEAR_CONSOLE() {
  std::cout << "\x1B[2J\x1B[H";
}

// display doubles with 2 decimals
void FIXED_FLOAT(double x) {
  std::cout << std::fixed << std::setprecision(2) << x;
}

/*
  causes the thread to go to sleep for a set amount of seconds.
  this is really useful when using a CLEAR_CONSOLE function, but you want to display
  data to the console for some time before doing so.
*/  
void SLEEP(int durationInSeconds) {
  std::this_thread::sleep_for(std::chrono::seconds(durationInSeconds));
}