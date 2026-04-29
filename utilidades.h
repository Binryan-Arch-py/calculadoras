#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <ostream>
#include <thread>
#include <chrono>
#include <iostream>

namespace utils {
    inline void sleep(double segundos) {
        std::this_thread::sleep_for(std::chrono::duration<double>(segundos));
    }

    inline void clear() {
        std::cout << "\033[2J\033[1;1H" << std::flush;
    }
}

#endif
