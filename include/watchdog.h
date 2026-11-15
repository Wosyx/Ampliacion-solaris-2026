/**
 * \file watchdog.h
 * \brief Public library 
 */

#include <stdint.h>
#include <stdbool.h>

/**
 * \brief Determines if watchdog caused last reboot.
 * \retval true The watchdog caused the last reboot.
 * \retval false The watchdog did not cause the last reboot.
 */

bool SPP_watchdog_caused_reboot(void);

/**
 * \brief Disables the watchdog.
 */

void SPP_watchdog_disable(void);

/**
 * \brief Enables the watchdog.
 * \param delay_ms Timeout of the watchdog in milliseconds maximum ~16000.
 * \param paused_on_debug If true, the watchdog will pause during debugging.
 * \note Time values are only accurate if the watchdog tick frequency is 1 MHz.
 */
void SPP_watchdog_enable(uint32_t delay_ms, bool paused_on_debug);

/**
 * \brief Gets the time remaining in milliseconds.
 * \return The time remaining in milliseconds.
 */
uint32_t SPP_watchdog_get_time_remaining_ms(void);

/**
 * \brief Determines if the last reboot was caused by a watchdog timeout initiated by SPP_watchdog_enable.
 * \retval true if watchdog timeout was the cause of last reboot initiated by SPP_watchdog_enable.
 * \retval false if the watchdog timeout was not the cause of last reboot initiated by SPP_watchdog_enable. 
 */
bool SPP_watchdog_enable_caused_reboot (void);

/**
 * \brief Gets the time remaining in microseconds.
 * \return The time remaining in microseconds.
 */
uint32_t SPP_watchdog_get_time_remaining_us (void);

/**
 * \brief Define actions to perform at watchdog timeout.
 * \param pc If Zero, a standard boot will be performed, if non-zero this is the program counter to jump to on reset.
 * \param  	sp If pc is non-zero, this will be the stack pointer used.
 * \param delay_ms Initial load value maximum ~8388ms.
 * \note Time values are only accurate if the watchdog tick frequency is 1 MHz.
 */
void SPP_watchdog_reboot (uint32_t pc, uint32_t sp, uint32_t delay_ms);

/**
 * \brief Start the watchdog tick (clock).
 * \param cycles Clock divider used to generate a 1 MHz tick.
 * If the reference clock frequency is 24 MHz, cycles must be 24.
 */
void SPP_watchdog_start_tick (unsigned int cycles);

/**
 * \brief Reload the watchdog counter with the amount of time set in watchdog_enable.
 */
void SPP_watchdog_update(void);
