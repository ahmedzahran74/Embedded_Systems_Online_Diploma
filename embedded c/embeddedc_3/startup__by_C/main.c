#include <stdint.h>


typedef volatile unsigned int vint32_t;


#define RCC_BASE 0x40021000
#define PortA_BASE 0x40010800


#define RCC_APB2ENR   *((volatile uint32_t *) (RCC_BASE   + 0x18))
#define GPIOA_CRH     *((volatile uint32_t *) (PortA_BASE + 0x04))
#define GPIOA_ODR     *((volatile uint32_t *) (PortA_BASE + 0x0C))

typedef union{
	vint32_t all_pins;
	struct{
		vint32_t reserved:13;
		vint32_t pin13:1;
	}pin;


}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PortA_BASE + 0x0C);
unsigned char g_variables[3] = {1, 2, 3};
unsigned char const const_variables[3] = {1, 2, 3};
unsigned char bss_var[3];

int main()
{
	RCC_APB2ENR |= 1<<2;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1){
		int i;
		R_ODR->pin.pin13 = 1;
		
		for(i = 0; i < 5000; ++i);
		
		R_ODR->pin.pin13 = 0;

		for(i = 0; i < 5000; ++i);
	}

	return 0;
}