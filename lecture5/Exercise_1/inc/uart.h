/*! constant for USART1 baud rate */
#define BAUD_RATE 9600

/*! @brief initialization USART1 interface */
void init(void);

/*! @brief enable USART1 interface */
void open(void);

/*! 
	@brief read data from USART1 interface.
	@return char receive symbol
*/
char read(void);

/*! 
	@brief write data string to USART1 interface.
	@param buffer string fot send
*/
void write(char *buffer);

/*! @brief disable USART1 interface */
void close(void);

/*! @brief  default reset USART1 interface */
void deinit(void);

/*! @brief send symbol to USART1 interface */
inline void usart_putc(char c);





