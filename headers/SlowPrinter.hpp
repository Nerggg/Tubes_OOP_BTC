#ifndef __SLOWPRINTER_HPP
#define __SLOWPRINTER_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>

using namespace std;

class SlowPrinter {
    private:
        ostream& out;
        int delay;
        int delay_multiplier;

    public:
        SlowPrinter(ostream&, int, int);

        template<class T>
        SlowPrinter& operator<<(const T& value) {
            for (const auto& c : to_string(value)) {
                out << c << flush;
                this_thread::sleep_for(chrono::milliseconds(delay));
            }
            this_thread::sleep_for(chrono::milliseconds(delay * delay_multiplier));
            return *this;
        }
        // Specialization for std::string
        SlowPrinter& operator<<(const std::string& str);
        SlowPrinter& operator<<(const char* str);
        SlowPrinter& operator<<(ostream& (*manipulator)(ostream&));
};

#endif