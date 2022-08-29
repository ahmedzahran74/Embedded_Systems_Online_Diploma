/*
 * lcd.c
 *
 * Created: Aug 29, 2022
 *  Author: Ahmed Zahran
 */

#include "lcd.h"
#include "Keypad.h"
void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}

static GPIO_pin_configue_t PinCfg ;

void LCD_GPIO_init()
{									///////////////done
	PinCfg.GPIO_pin_number = RS_SWITCH;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF =GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_pin_number = RW_SWITCH;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_pin_number = EN_SWITCH;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);



	PinCfg.GPIO_pin_number = GPIO_PIN_0;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_1;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_2;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_3;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_4;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_5;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_6;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_7;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	//	DataDir_LCD_CTRL |= (1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	MCAL_GPIO_Write_Pin(LCD_CTRL, EN_SWITCH, LOW);
	MCAL_GPIO_Write_Pin(LCD_CTRL, RS_SWITCH, LOW);
	MCAL_GPIO_Write_Pin(LCD_CTRL, RW_SWITCH, LOW);

}

void LCD_clear_screen() {
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_kick() {//////////done
	MCAL_GPIO_Write_Pin(LCD_CTRL, EN_SWITCH, HIGH);
	delay_ms(50);
	MCAL_GPIO_Write_Pin(LCD_CTRL, EN_SWITCH, LOW);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position) {/////////done
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void LCD_INIT() {			//////////////done

	delay_ms(20);
	// SET THE FIRST 3 PINS AS OUPUT
	LCD_GPIO_init();
	//	LCD_CTRL &= ~(1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	//	DataDir_LCD_PORT = 0xFF;
	delay_ms(15);
	LCD_check_lcd_isbusy();
	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_check_lcd_isbusy() {/////////////done
	//	DataDir_LCD_PORT &= ~(0xFF << DATA_shift);
	PinCfg.GPIO_pin_number = GPIO_PIN_0;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT;
	PinCfg.GPIO_pin_CNF = GPIO_IN_FLOATING;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_1;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT;
	PinCfg.GPIO_pin_CNF = GPIO_IN_FLOATING;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_2;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT;
	PinCfg.GPIO_pin_CNF = GPIO_IN_FLOATING;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_3;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT;
	PinCfg.GPIO_pin_CNF = GPIO_IN_FLOATING;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_4;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT;
	PinCfg.GPIO_pin_CNF = GPIO_IN_FLOATING;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_5;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT;
	PinCfg.GPIO_pin_CNF = GPIO_IN_FLOATING;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_6;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT;
	PinCfg.GPIO_pin_CNF = GPIO_IN_FLOATING;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_7;
	PinCfg.GPIO_pin_mode = GPIO_MODE_INPUT;
	PinCfg.GPIO_pin_CNF = GPIO_IN_FLOATING;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	MCAL_GPIO_Write_Pin(LCD_CTRL, RW_SWITCH, HIGH);
	MCAL_GPIO_Write_Pin(LCD_CTRL, RS_SWITCH, LOW);


	LCD_kick();



	PinCfg.GPIO_pin_number = GPIO_PIN_0;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_1;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_2;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_3;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_4;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_5;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_6;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_pin_number = GPIO_PIN_7;
	PinCfg.GPIO_pin_mode = GPIO_MODE_OUTPUT_10M;
	PinCfg.GPIO_pin_CNF = GPIO_OUT_PUSHPULL;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

}

void LCD_WRITE_COMMAND(unsigned char command) {/////////done
	LCD_check_lcd_isbusy();
	MCAL_GPIO_Write_port(LCD_PORT, command);
	MCAL_GPIO_Write_Pin(LCD_PORT, RW_SWITCH, LOW);
	MCAL_GPIO_Write_Pin(LCD_PORT, RS_SWITCH, LOW);
	delay_ms(1);
	LCD_kick();

}

void LCD_WRITE_CHAR(unsigned char character) {/////////done
	LCD_check_lcd_isbusy();
	MCAL_GPIO_Write_port(LCD_PORT, character);
	MCAL_GPIO_Write_Pin(LCD_PORT, RW_SWITCH, LOW);
	MCAL_GPIO_Write_Pin(LCD_PORT, RS_SWITCH, HIGH);
	delay_ms(1);
	LCD_kick();

}

void LCD_WRITE_STRING(char *string)
{											 ///////done
	int count = 0;
	while (*string > 0) {
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) {
			LCD_GOTO_XY(2, 0);
		} else if (count == 32) {
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}
