#include "lib/SlowPrinter.hpp"

// Static Attributes
SlowPrinter* SlowPrinter::slowcout = new SlowPrinter(cout, 20, 10);

// Methods
SlowPrinter::SlowPrinter(ostream& out, int delay, int mult) : out(out), delay(delay), delay_multiplier(mult), default_delay(delay), default_mult(mult) {}

SlowPrinter::SlowPrinter(const SlowPrinter& other) : out(other.out), delay(other.delay), delay_multiplier(other.delay_multiplier) {}

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

int SlowPrinter::getDelay() {
    return this->delay;
}

int SlowPrinter::getMult() {
    return this->delay_multiplier;
}

void SlowPrinter::setDelay(int delay) {
    this->delay = delay;
}

void SlowPrinter::setMult(int mult) {
    this->delay_multiplier = mult;
}

void SlowPrinter::resetDelay() {
    this->delay = default_delay;
}

void SlowPrinter::resetMult() {
    this->delay_multiplier = default_mult;
}