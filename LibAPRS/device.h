#include "constants.h"

#ifndef DEVICE_CONFIGURATION
#define DEVICE_CONFIGURATION

// configure for tracker, otherwise for modem
#define USE_APRS_TRACKER
#define USE_AX25_CTX

// CPU settings
#ifndef TARGET_CPU
    #define TARGET_CPU m328p
#endif

#ifndef F_CPU
    #define F_CPU 16000000
#endif

#ifndef FREQUENCY_CORRECTION
    #define FREQUENCY_CORRECTION 0
#endif

// Sampling & timer setup
#define CONFIG_AFSK_DAC_SAMPLERATE 9600

#ifndef USE_APRS_TRACKER
#define SERIAL_PROTOCOL PROTOCOL_KISS
#endif

// Do not use tx led
#ifdef USE_APRS_TRACKER
#define CONFIG_AFSK_NO_TX_LED
#endif

// Port settings
#if TARGET_CPU == m328p
    #define DAC_PORT PORTD
    #define DAC_DDR  DDRD
#ifdef USE_APRS_TRACKER
    #define LED_PORT PORTC
    #define LED_DDR  DDRC
#else
    #define LED_PORT PORTB
    #define LED_DDR  DDRB
#endif
    #define ADC_PORT PORTC
    #define ADC_DDR  DDRC
#endif

#endif
