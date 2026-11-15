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

    for (int i=0; i<30;i++){
      for (int k=0;k<10;k++){
        printf("Quedan: %u ms\n",(unsigned)SPP_watchdog_get_time_remaining_ms());
        printf("Quedan: %u us\n", (unsigned)SPP_watchdog_get_time_remaining_us());
    }
    printf("Recargamos el watchdog\n");
    SPP_watchdog_update();
    }

    printf("Desactivamos watchdog\n");

    
    SPP_watchdog_disable();

    SPP_watchdog_enable(2000, 1);
  
    

    while(1);
    
}