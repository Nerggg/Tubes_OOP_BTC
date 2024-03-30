#ifndef __SLOWPRINTER_HPP
#define __SLOWPRINTER_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include <cstring>

using namespace std;

class SlowPrinter {
    private:
        // Static variables
        static SlowPrinter* slowcout;

        // Instance variables
        ostream& out;
        int delay;
        int delay_multiplier;

        int default_delay;
        int default_mult;


    public:
        // Constructors
        SlowPrinter(ostream&, int, int);
        SlowPrinter(const SlowPrinter&);

        // Static methods
        static SlowPrinter* getSlowPrinter() {
            return slowcout;
        }

        // Printers
        template<class T>
        SlowPrinter& operator<<(const T& value) {
            for (const auto& c : to_string(value)) {
                out << c << flush;
                this_thread::sleep_for(chrono::milliseconds(delay));
            }
            this_thread::sleep_for(chrono::milliseconds(delay * delay_multiplier));
            return *this;
        }

        SlowPrinter& operator<<(const std::string& str);                // Specialization for std::string
        SlowPrinter& operator<<(const char* str);                       // Specialization for char*
        SlowPrinter& operator<<(ostream& (*manipulator)(ostream&));     // Specialization for manipulators (endl, flush, etc.)

        // Getters
        int getDelay();
        int getMult();

        // Setters
        void setDelay(int);
        void setMult(int);

        void resetDelay();
        void resetMult();

        // Instance methods
};

#endif