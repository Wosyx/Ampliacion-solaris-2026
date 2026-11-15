#include <stdio.h>
#include <stdint.h>

bool SPP_watchdog_caused_reboot(void);

void SPP_watchdog_disable(void);

void SPP_watchdog_enable(uint32_t delay_ms, bool paused_on_debug);

uint32_t SPP_watchdog_get_time_remaining_ms(void);

bool SPP_watchdog_enable_caused_reboot (void);

uint32_t SPP_watchdog_get_time_remaining_us (void);

void SPP_watchdog_reboot (uint32_t pc, uint32_t sp, uint32_t delay_ms);

void SPP_watchdog_start_tick (unsigned int cycles);

void SPP_watchdog_update(void);
