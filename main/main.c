
//this is  a simple freertos example code.

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "driver/gpio.h"
#include "driver/adc.h"

//#define GPIO_AIN 4  //GPIO PIN4 as analog input.
//#define ADC_WIDTH_BIT 12
//#define ADC1_CHANNEL 0
//#define ADC_ATTEN_DB 0
int sampled_val=0;
int sample_array[20000];

void task_Audio_Sampler(void *param);
void task_LED2(void *param);


void app_main(void){
	//gpio_pad_select_gpio(GPIO_AIN);
	/* Set the GPIO as a push/pull output */
	//gpio_set_direction(GPIO_AIN, GPIO_MODE_INPUT);

	adc1_config_width(ADC_WIDTH_BIT_12);
	adc1_config_channel_atten(ADC1_CHANNEL_0,ADC_ATTEN_DB_0);
	xTaskCreate(task_Audio_Sampler,"Audio_Sampler",1024*2,&sampled_val,3,NULL);
	sample_array[i]=sampled_val;
	xTaskCreate(task_LED2,"task2",1024*2,NULL,3,NULL);



}

//task functions.
//task first.
void task_Audio_Sampler(int *sampled_val){

	for(;;){
		//tasks exists here.
		sampled_val = adc1_get_raw(ADC1_CHANNEL_0);
	}
	//tasks must be deleted before finishing a task,

	vTaskDelete(NULL);

}

//task second.
void task_LED2(int *sampled_array){


	for(;;){
		//tasks exists here.
		printf("this is task 2");

	}

	//tasks must be deleted before finishing a task,

	vTaskDelete(NULL);

}



