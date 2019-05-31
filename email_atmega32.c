#include<avr/io.h>
#include<util/delay.h>
#define		KEYPAD_PORT		PORTC
#define		KEYPAD_PIN		PINC

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define     BAUD_PRESCALE   (F_CPU / (USART_BAUDRATE * 16UL)) - 1

unsigned char read_keypad(void);
void UART_init(long USART_BAUDRATE);
void UART_TxChar(char c);
void UART_sendString(char *str);

int main(void)
{
	UART_init(9600);
	UART_sendString("TEST");
	DDRC=0x0f;
	PORTC=0xff;	
	DDRB=0x0f;
	DDRA=0xff;
	DDRD=0x07;
	unsigned char keypad_value,count=0,status=0;
	char password_entered[5];
	char password_set0[5]="2932";
	char password_set1[5]="2964";
	char password_set2[5]="2895";
	char password_set3[5]="2926";

	while(1)
	{
		while(count<4)
		{
			keypad_value = read_keypad();
			if(keypad_value != 0xff)
			{
				if(keypad_value < 0x0a)
				{
					password_entered[count]=48+keypad_value;
					count++;
					_delay_ms(300);
				}
				else
				{
					;
				}
			}
			else
			{
				;
			}
		}
		
		count=0;	
		
		password_entered[4]='\0';
		if(!(strcmp(password_entered,password_set0)))
		{
			//password match
			status=0;
			PORTB = 0X02;
			_delay_ms(50);
			UART_sendString("SEN0");
			_delay_ms(1200);
			PORTB = 0X01;
		}
		else if(!(strcmp(password_entered,password_set1)))
		{
			//password match
			status=0;
			PORTB = 0X02;
			_delay_ms(50);
			UART_sendString("SEN1");
			_delay_ms(1200);
			PORTB = 0X01;
		}
		else if(!(strcmp(password_entered,password_set2)))
		{
			//password match
			status=0;
			PORTB = 0X02;
			_delay_ms(50);
			UART_sendString("SEN2");
			_delay_ms(1200);
			PORTB = 0X01;
		}
		else if(!(strcmp(password_entered,password_set3)))
		{
			//password match
			status=0;
			PORTB = 0X02;
			_delay_ms(50);
			UART_sendString("SEN3");
			_delay_ms(1200);
			PORTB = 0X01;
		}
		else
		{
			PORTB = 0X00;
			_delay_ms(1200);
			PORTB = 0X01;
		}
	}
}

unsigned char read_keypad(void)
{
	unsigned char keypad_input=0xff,keypad_output=0xff;
	KEYPAD_PORT=0xfe;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
	keypad_output=0x01;
	else if(keypad_input==0xd0)
	keypad_output=0x02;
	else if(keypad_input==0xb0)
	keypad_output=0x03;
	else if(keypad_input==0x70)
	keypad_output=0x0c;
	else
	;

	KEYPAD_PORT=0xfd;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
	keypad_output=0x04;
	else if(keypad_input==0xd0)
	keypad_output=0x05;
	else if(keypad_input==0xb0)
	keypad_output=0x06;
	else if(keypad_input==0x70)
	keypad_output=0x0d;
	else
	;

	KEYPAD_PORT=0xfb;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
	keypad_output=0x07;
	else if(keypad_input==0xd0)
	keypad_output=0x08;
	else if(keypad_input==0xb0)
	keypad_output=0x09;
	else if(keypad_input==0x70)
	keypad_output=0x0e;
	else
	;
	
	KEYPAD_PORT=0xf7;
	_delay_us(2);
	keypad_input=KEYPAD_PIN & 0xf0;

	if(keypad_input==0xe0)
	keypad_output=0x0a;
	else if(keypad_input==0xd0)
	keypad_output=0x00;
	else if(keypad_input==0xb0)
	keypad_output=0x0b;
	else if(keypad_input==0x70)
	keypad_output=0x0f;
	else
	;

	return keypad_output;
}

void UART_init(long USART_BAUDRATE)
{
	UCSRB |= (1 << RXEN) | (1 << TXEN);         				// Turn on transmission and reception by setting RX Tx bits
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);    	// Use 8-bit character sizes
	UBRRL = BAUD_PRESCALE; 										// Load lower 8-bits of the baud rate value
	UBRRH = (BAUD_PRESCALE >> 8); 								// Load upper 8-bits of the baud rate value
}

void UART_TxChar(char c)       
{
	while (! (UCSRA & (1<<UDRE))); 							// Wait for empty transmit buffer
	UDR = c;
}
 
void UART_sendString(char *str)
{
	unsigned char s=0;
	while (str[s]!=0) 											// string till null 
	{
		UART_TxChar(str[s]);    								// send s to UART_TxChar(s) function
		s++;   
	}
}
