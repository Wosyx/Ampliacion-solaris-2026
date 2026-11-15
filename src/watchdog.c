#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/watchdog.h"

bool SPP_watchdog_caused_reboot(void){
    return watchdog_caused_reboot();
}

void SPP_watchdog_disable(void){
    watchdog_disable();
}

void SPP_watchdog_enable(uint32_t delay_ms, bool paused_on_debug){
    watchdog_enable(delay_ms, paused_on_debug);
}

uint32_t SPP_watchdog_get_time_remaining_ms(void){
    watchdog_get_time_remaining_ms();
}  

bool SPP_watchdog_enable_caused_reboot (void){
    watchdog_enable_caused_reboot();
}

uint32_t SPP_watchdog_get_time_remaining_us (void){
    watchdog_get_time_remaining_us();
}

void SPP_watchdog_reboot (uint32_t pc, uint32_t sp, uint32_t delay_ms){
    watchdog_reboot(pc,sp, delay_ms);
}


void SPP_watchdog_start_tick (unsigned int cycles){
    watchdog_start_tick(cycles);
}

void SPP_watchdog_update(void){
    watchdog_update();
}