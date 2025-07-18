#include "pypp_time.h"
#include <cstdlib> // Required for EXIT_FAILURE
#include <iostream>
#include <pypp_util/main_error_handler.h>

int main() {
    try {

        auto time_start = pypp_time::start();
        pypp_time::sleep(0.1);
        auto elapsed = pypp_time::end(time_start);
        std::cout << "Elapsed time: " << elapsed << " seconds" << std::endl;

        auto perf_start = pypp_time::perf_counter_start();
        pypp_time::sleep(0.1);
        auto perf_elapsed = pypp_time::perf_counter_end(perf_start);
        std::cout << "High-resolution elapsed time: " << perf_elapsed
                  << " seconds" << std::endl;

        return 0;
    } catch (...) {
        handle_fatal_exception();
        return EXIT_FAILURE;
    }
}
