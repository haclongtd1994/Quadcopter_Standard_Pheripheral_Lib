#include "delay.h"

void delay(uint32_t tick){
	for (int i=0; i<tick;i++){
		for (int j=0; j<10000; j++){
			; // Just delay by increase variable j
		}
	}
}

void delay_option(){
	if(Is_ON == 1){
		delay(1000);
	}
	else{
		delay(2000);
	}
}
