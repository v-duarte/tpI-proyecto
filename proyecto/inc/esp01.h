/*=====[Nombre del modulo]=====================================================
 * Copyright YYYY Nombre completo del autor <author@mail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: YYYY/MM/DD
 */

/*=====[Evitar inclusion multiple comienzo]==================================*/

#ifndef _ESP01_H_
#define _ESP01_H_

/*=====[Inclusiones de dependencias de funciones publicas]===================*/

//#include "main.h"
#include <main.h>
#include "sapi.h" 

/*=====[C++ comienzo]========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Macros de definicion de constantes publicas]=========================*/

//#define PI 3.14

/*=====[Macros estilo funcion publicas]======================================*/

//#define printInt(printer,number) printIntFormat((printer),(number),(DEC_FORMAT))

//#define printlnString(printer,string);   {printString((printer),(string));\
                                          printEnter((printer));}                                      

/*=====[Definiciones de tipos de datos publicos]=============================*/

// Tipo de datos que renombra un tipo basico
//typedef uint8_t bool_t;

// Tipo de datos de puntero a funcion
//typedef void (*callBackFuncPtr_t)(void *);

// Tipo de datos enumerado
/*typedef enum {
   GPIO_INPUT, 
   GPIO_OUTPUT
} gpioMode_t; */

/*typedef enum {
   HMC5883L_REG_X_MSB = 0x00, 
   HMC5883L_REG_X_LSB = 0x01,
   HMC5883L_REG_Y_MSB = 0x02,
   HMC5883L_REG_Y_LSB = 0x03,
   HMC5883L_REG_Z_MSB = 0x04,
   HMC5883L_REG_Z_LSB = 0x05
} hmc5883lRegisters_t; */

// Tipo de datos estructua, union o campo de bits
//typedef struct {
  // uint16_t year;	 /* 1 to 4095 */
   //uint8_t  month; /* 1 to 12   */
   //uint8_t  mday;	 /* 1 to 31   */
   //uint8_t  wday;	 /* 1 to 7    */
   //uint8_t  hour;	 /* 0 to 23   */
   //uint8_t  min;	 /* 0 to 59   */
   //uint8_t  sec;	 /* 0 to 59   */
//} rtc_t; 

/*=====[Prototipos de funciones publicas]====================================*/

/*
esp01Init: Inicializa el modulo ESP01
*/
bool_t esp01Init( uartMap_t uartForEsp, uartMap_t uartForDebug, uint32_t baudRate );

/*
esp01CleanRxBuffer: Limpia el buffer RX 
*/
void esp01CleanRxBuffer( void );

/*
esp01ShowWiFiNetworks: Muestra las redes Wi-Fi disponibles
*/
bool_t esp01ShowWiFiNetworks( void );

/*
esp01ConnectToWifiAP: Se conecta a la red de Wi-Fi especificada con el wiFiSSID con la contraseņa pasada en wiFIPassword
*/
bool_t esp01ConnectToWifiAP( char* wiFiSSID, char* wiFiPassword );

/*
esp01ConnectToServer: Realiza la conexion con el servidor
*/
bool_t esp01ConnectToServer( char* url, uint32_t port );

/*
esp01SendTCPIPData: Envia los datos al servidor.
*/
bool_t esp01SendTCPIPData( char* strData, uint32_t strDataLen );

/*
esp01SendTPCIPDataToServer: Envia lo que se encuentra en el parametro data al servidor definidfo en url por el puerto port
*/
bool_t esp01SendTPCIPDataToServer( char* url, uint32_t port, char* strData, uint32_t strDataLen );

int esp01_init( void );
int sendMessage( int64_t est_button, int64_t est_u_sensor, char time[100]);

/*=====[Prototipos de funciones publicas de interrupcion]====================*/

//void UART0_IRQHandler(void);

/*=====[C++ fin]=============================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Evitar inclusion multiple fin]=======================================*/

#endif /* _MODULE_NAME_H_ */