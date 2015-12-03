#include <util/atomic.h>
#include "time.h"
#include "device.h"

volatile ticks_t _clock;

ticks_t timer_clock(void) {
    ticks_t result;

    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        result = _clock;
    }

    return result;
}


ticks_t ms_to_ticks(mtime_t ms) {
    return ms * DIV_ROUND(CLOCK_TICKS_PER_SEC, 1000);
}

void cpu_relax(void) {
    // Do nothing!
}

void delay_ms(unsigned long ms) {
    ticks_t start = timer_clock();
    unsigned long n_ticks = ms_to_ticks(ms);
    while (timer_clock() - start < n_ticks) {
        cpu_relax();
    }
}

