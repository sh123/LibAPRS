#ifndef UTIL_TIME_H
#define UTIL_TIME_H

#include <util/atomic.h>
#include "device.h"

#define DIV_ROUND(dividend, divisor)  (((dividend) + (divisor) / 2) / (divisor))
#define CLOCK_TICKS_PER_SEC CONFIG_AFSK_DAC_SAMPLERATE

typedef int32_t ticks_t;
typedef int32_t mtime_t;

ticks_t timer_clock(void);
ticks_t ms_to_ticks(mtime_t ms);
void cpu_relax(void);
void delay_ms(unsigned long ms);


#endif
