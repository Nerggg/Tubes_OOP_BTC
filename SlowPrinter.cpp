#include "headers/SlowPrinter.hpp"

SlowPrinter::SlowPrinter(ostream& out, int delay, int mult) : out(out), delay(delay), delay_multiplier(mult) {}

// template<class T>
// SlowPrinter& SlowPrinter::operator<<(const T& value) {
//     for (const auto& c : to_string(value)) {
//         out << c << flush;
//         this_thread::sleep_for(chrono::milliseconds(delay));
//     }
//     this_thread::sleep_for(chrono::milliseconds(delay * 20));
//     return *this;
// }

SlowPrinter& SlowPrinter::operator<<(const char* str) {
    for (size_t i = 0; i < strlen(str); ++i) {
        out << str[i] << std::flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    this_thread::sleep_for(chrono::milliseconds(delay * delay_multiplier));
    return *this;
}

SlowPrinter& SlowPrinter::operator<<(const std::string& str) {
    for (const auto& c : str) {
        out << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
    this_thread::sleep_for(chrono::milliseconds(delay * delay_multiplier));
    return *this;
}

SlowPrinter& SlowPrinter::operator<<(ostream& (*manipulator)(ostream&)) {
    manipulator(out);
    return *this;
}