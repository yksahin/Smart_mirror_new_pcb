/*
 * FUNCTIONS.c
 *
 *  Created on: Apr 27, 2020
 *      Author: Controllerstech
 */


#include "UartRingbuffer.h"
#include "FUNCTIONS.h"
#include "stdio.h"
#include "string.h"
#include "MY_ILI9341.h"


void bufclr (char *buf)
{
	int len = strlen (buf);
	for (int i=0; i<len; i++) buf[i] = '\0';
}


/*****************************************************************************************************************************************/

void ESP_Init (char *SSID, char *PASSWD)
{
	char data[80];

	Ringbuf_init();

	Uart_sendstring("AT+RST\r\n");
	HAL_Delay(5000);

	/********* AT **********/
	//AT –> to check if the ESP is responding
	Uart_sendstring("AT\r\n");
	while(!(Wait_for("AT\r\r\n\r\nOK\r\n")));


	/********* AT+CWMODE=1 **********/
	//AT+CWMODE=1 –> to set the ESP into the station mode
	Uart_sendstring("AT+CWMODE=1\r\n");
	while (!(Wait_for("AT+CWMODE=1\r\r\n\r\nOK\r\n")));


	/********* AT+CWJAP="SSID","PASSWD" **********/
	sprintf (data, "AT+CWJAP=\"%s\",\"%s\"\r\n", SSID, PASSWD);
	Uart_sendstring(data);
	while (!(Wait_for("WIFI GOT IP\r\n\r\nOK\r\n")));

	/********* AT+CIPMUX=0 **********/
	Uart_sendstring("AT+CIPMUX=0\r\n");
	while (!(Wait_for("AT+CIPMUX=0\r\r\n\r\nOK\r\n")));

}
/*
void ESP_GetData (char *api_key, char *Total)
	char local_buf[100] = {0};
	char local_buf2[30] = {0};
	//char local_buf3[30] = {0};

	Uart_sendstring("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
	while (!(Wait_for("CONNECT\r\n\r\nOK\r\n")));

	sprintf (local_buf, "GET /apps/thinghttp/send_request?api_key=%s\r\n", api_key);
	int len = strlen (local_buf);

	sprintf (local_buf2, "AT+CIPSEND=%d\r\n", len);
	Uart_sendstring(local_buf2);
	while (!(Wait_for(">")));

	bufclr(local_buf2);

	Uart_sendstring (local_buf);
	while (!(Wait_for("SEND OK\r\n")));

	while (!(Wait_for (":")));
	while (!(Copy_upto ("\r", local_buf2)));

	len = strlen (local_buf2);
	snprintf (Total, len,local_buf2);
}
*/

void ESP_GetData_1 (char *api_key, char *Total)
{
	char local_buf[100] = {0};
	char local_buf2[30] = {0};
	//char local_buf3[30] = {0};

	Uart_sendstring("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
	while (!(Wait_for("CONNECT\r\n\r\nOK\r\n")));
	
	sprintf (local_buf, "GET /apps/thinghttp/send_request?api_key=%s\r\n", api_key);
	int len = strlen (local_buf);
	
	sprintf (local_buf2, "AT+CIPSEND=%d\r\n", len);
	Uart_sendstring(local_buf2);
	while (!(Wait_for(">")));
	
	bufclr(local_buf2);

	Uart_sendstring (local_buf);
	while (!(Wait_for("SEND OK\r\n")));
	
	while (!(Wait_for (">")));
	while (!(Copy_upto ("°", local_buf2)));

	len = strlen (local_buf2);
	snprintf (Total, len,local_buf2);
}

void ESP_GetData_2 (char *api_key, char *Total) /*, char *Deaths, char *Recovered)*/
{
	char local_buf[100] = {0};
	char local_buf2[30] = {0};
	//char local_buf3[30] = {0};

	Uart_sendstring("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
	while (!(Wait_for("CONNECT\r\n\r\nOK\r\n")));

	sprintf (local_buf, "GET /apps/thinghttp/send_request?api_key=%s\r\n", api_key);
	int len = strlen (local_buf);

	sprintf (local_buf2, "AT+CIPSEND=%d\r\n", len);
	Uart_sendstring(local_buf2);
	while (!(Wait_for(">")));

	bufclr(local_buf2);

	Uart_sendstring (local_buf);
	while (!(Wait_for("SEND OK\r\n")));

	//while (!(Wait_for (":")));
	while (!(Wait_for ("is")));
	while (!(Copy_upto ("C", local_buf2)));

	len = strlen (local_buf2);
	snprintf (Total, len,local_buf2);
}

void ESP_GetData_3 (char *api_key, char *Total) /*, char *Deaths, char *Recovered)*/
{
	char local_buf[100] = {0};
	char local_buf2[30] = {0};
	//char local_buf3[30] = {0};

	Uart_sendstring("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n");
	while (!(Wait_for("CONNECT\r\n\r\nOK\r\n")));

	sprintf (local_buf, "GET /apps/thinghttp/send_request?api_key=%s\r\n", api_key);
	int len = strlen (local_buf);

	sprintf (local_buf2, "AT+CIPSEND=%d\r\n", len);
	Uart_sendstring(local_buf2);
	while (!(Wait_for(">")));

	bufclr(local_buf2);

	Uart_sendstring (local_buf);
	while (!(Wait_for("SEND OK\r\n")));

	while (!(Wait_for (":")));
	//while (!(Wait_for (" ")));
	//while (!(Copy_upto ("o", local_buf2)));
	while (!(Copy_upto ("C", local_buf2)));

	len = strlen (local_buf2);
	snprintf (Total, len,local_buf2);
}
