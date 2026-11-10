#include <stdio.h>
#include "watchdog.h"


int main() {
    
    SPP_watchdog_start_tick(12);

    if (SPP_watchdog_caused_reboot()){
        printf("Ha sido rebooteado por watchdog\n");
    }
    else{
        printf("Boot normal\n");
    }   

    printf("Activamos watchdog\n");
    SPP_watchdog_enable(2000, 1);

      for (int i=0;i<10;i++){
        printf("Quedan: %d ms\n",SPP_watchdog_get_time_remaining_ms());
        printf("Quedan: %d us\n", SPP_watchdog_get_time_remaining_us());
    }


    printf("Desactivamos watchdog\n");

    
    SPP_watchdog_disable();

    SPP_watchdog_enable(2000, 1);
  
    printf("Recargamos el watchdog\n");
    SPP_watchdog_update();

    while(1);
    
}