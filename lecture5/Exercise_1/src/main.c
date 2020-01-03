/*!
   @brief Exercise_1 - Application that communicates with PC through UART  
   @details Task: Develop application that communicates with PC trough UART 
	 1.Application should send just echo. 
	 2.You should use only CMSIS library.
	 3.UART driver should contains following functions:
	 -init;
	 -open;
	 -read;
	 -write;
	 -close;
	 -deinit
   @author Dmytro Lytvyniuk
   @date January
   @warning This program was created for educational purposes.
 */

#include "stm32f3xx.h"                  
#include "uart.h"
#include "led.h"

int main(void)
{
		init();
		open();	
		led_init();

		/*! user command manual */
		write("For [BLUE-LED] send symbol: b\r");
		write("For [RED-LED] send symbol: r\r");
		write("For [ORANGE-LED] send symbol: o\r");
		write("For [GREEN-LED] send symbol: g\r");
		write("For disconnect send symbol: x\r");
	
		while(1)
		{
			/*! read data */
			char data = read();
			
			switch(data) {
				case 'b':
					toggleBlue();
				break;
				
				case 'r':
					toggleRed();
				break;
				
				case 'o':
					toggleOrange();
				break;
				
				case 'g':
					toggleGreen();
				break;
				
				case 'x':				
					close();
					deinit();
					led_shutdown();
				
				break;
				default:
					/*! write data */
					write(&data);
			}
		}
}
