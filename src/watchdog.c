#include "include/types.h"


bool SPP_watchdog_caused_reboot(void){
    volatile uint32_t *watchdog_reboot=(volatile uint32_t *)(WATCHDOG_BASE+WATCHDOG_REASON_REGISTER_OFFSET);
    if ((*watchdog_reboot & 1u) | (*watchdog_reboot & 1u<<1)){
        return true;
    }
    else{
        return false;
    }
}

void SPP_watchdog_disable(void){
    volatile uint32_t *p_watchdog_crtl=(volatile uint32_t *)(WATCHDOG_BASE+WATCHDOG_CTRL_REGISTER_OFFSET+ATOMIC_CLEARON_WRITE);
    *p_watchdog_crtl=1u<<30;
}

void SPP_watchdog_enable(uint32_t delay_ms, bool paused_on_debug){
    volatile uint32_t *p_watchdog_crtl_seton=(volatile uint32_t *)(WATCHDOG_BASE+WATCHDOG_CTRL_REGISTER_OFFSET+ATOMIC_SETON_WRITE);
    volatile uint32_t *p_watchdog_crtl_clearon=(volatile uint32_t *)(WATCHDOG_BASE+WATCHDOG_CTRL_REGISTER_OFFSET+ATOMIC_CLEARON_WRITE);
    volatile uint32_t *p_watchdog_load=(volatile uint32_t *)(WATCHDOG_BASE+WATCHDOG_LOAD_REGISTER_OFFSET);
    if (delay_ms<=WATCHDOG_MAXIMUM_TIMER/1000){
        uint32_t delay_us=delay_ms*1000;
        *p_watchdog_load=delay_us;
    }
    else{
        printf("Error argumento invalido");
    }
    if (paused_on_debug==true){
        *p_watchdog_crtl_seton=(1u<<26) | (1u<<25); // | (1u<<24) no sei se se deberia parar o o jtag bus tamen pero en principio penso que non 
    }
    else{
        *p_watchdog_crtl_clearon=(1u<<26) | (1u<<25);
    }
    *p_watchdog_crtl_seton=1u<<30;
}

uint32_t SPP_watchdog_get_time_remaining_ms(void){
    volatile uint32_t *p_watchdog_crtl=(volatile uint32_t *)(WATCHDOG_BASE+WATCHDOG_CTRL_REGISTER_OFFSET);
    uint32_t time_remaning_ms=(*p_watchdog_crtl & ((1u<<24)-1))/1000;
    return time_remaning_ms;
}  

bool SPP_watchdog_enable_caused_reboot (void){
    watchdog_enable_caused_reboot();
}

uint32_t SPP_watchdog_get_time_remaining_us (void){
    volatile uint32_t *p_watchdog_crtl=(volatile uint32_t *)(WATCHDOG_BASE+WATCHDOG_CTRL_REGISTER_OFFSET);
    uint32_t time_remaning_us=(*p_watchdog_crtl & ((1u<<24)-1));
    return time_remaning_us;
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