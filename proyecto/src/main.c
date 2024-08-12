/*=====[Nombre del programa]===================================================
 * Copyright YYYY Nombre completo del autor <author@mail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: YYYY/MM/DD
 */

/*=====[Inclusiones de dependencias de funciones]============================*/
#include "hc_sr04.h"
#include "esp01.h"
#include "pulsador.h"
#include <string.h>   // <= Biblioteca de manejo de Strings
#include "rtc.h"
#include "sapi.h"              // <= sAPI header
#include "build_defs.h"


/*=====[Macros de definición de constantes privadas]=========================*/

//#define PI 3.1415f
#define	DS3231_I2C_ADDRESS	0x68
//#define	anio	BUILD_YEAR
//#define	mes	BUILD_MONTH
//#define	dia	BUILD_DATE
//#define	hora	BUILD_HOUR
//#define	minuto	BUILD_MIN
//#define	segundo	BUILD_SEC


/*=====[Definiciones de variables globales externas]=========================*/

//int var;

/*=====[Definiciones de variables globales publicas]=========================*/

//int var = 0;

/*=====[Definiciones de variables globales privadas]=========================*/

//static int var = 0;
  uint32_t dist = 0;
  i2cMap_t i2cNumber = I2C0;
  uint32_t clockRateHz = 100000;
  rtcDS3231_t rtc;
  char date[100];
/*=====[Funcion principal, punto de entrada al programa luegp de encender]===*/
void setup();
void loop();


int main (void)
{
   // ----- Configuraciones -------------------------
   // Completar estructura RTC
   
   setup();

   // ----- Repetir por siempre ---------------------
   //while(TRUE) {
   while(1) {
      loop();
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontrolador y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}

void setup()
{
   // Inicializar la placa
   boardConfig();
   // Inicializar UART_USB a 115200 baudios
   uartConfig( UART_USB, 115200 );
   // Inicializar pulsador.
   init_pulsador();
   // Inicializar sensor ultrasonido. 
   HC_init();
   delay(200); // Retardo inicial de 200 ms 
   // Inicializar modulo wifi
   esp01_init();
   // Inicializar rtc
   i2cInit(i2cNumber, clockRateHz);
  delay(100); // Retardo inicial de 100 ms 
}

void loop()
{  
   RTC_read_control_registers( &rtc, i2cNumber, DS3231_I2C_ADDRESS); //leo los registros para ver el estado de control_status
   uint8_t c = (rtc.control_status & (1<<7));
   // si control_status es distinto de 0, es porque nunca se inicializo, o esta mal la fecha y hora q tiene el chip.
   if (c != 0){
      RTC_Init(&rtc, BUILD_YEAR, BUILD_MONTH, BUILD_DATE, 1, BUILD_HOUR, BUILD_MIN, BUILD_SEC);
      RTC_write_time(&rtc, i2cNumber, DS3231_I2C_ADDRESS);  // cargo la hora en el RTC DS3231
   }
   
   RTC_read_time( &rtc, i2cNumber, DS3231_I2C_ADDRESS);  // leo los registros horarios del RTC y los guardo en la estructura time
   date[0] = 0; 
   strcat( date, intToStringGlobal(bcdToDec(rtc.year)));
   strcat( date, "-" );
   strcat( date, intToStringGlobal(bcdToDec(rtc.month)));
   strcat( date, "-" );
   strcat( date, intToStringGlobal(bcdToDec(rtc.mday)));
   strcat( date, "T" );
   strcat( date, intToStringGlobal(bcdToDec(rtc.hour)));
   strcat( date, ":" );
   strcat( date, intToStringGlobal(bcdToDec(rtc.min)));
   strcat( date, ":" );
   strcat( date, intToStringGlobal(bcdToDec(rtc.sec)));
   
   dist = HC_Scan();  //Recive la distancia del sensor.
   int pulsador = flotantecarga();  // Lee el pulsador
   
   sendMessage(pulsador, dist, date);  // envia por internet la informacion
   
   delay(5000); // Espero 1 s hasta la proxima lectura (minimo 50 ms)
   
}

// Pulsador
/*void loop()
{
   int mensaje = flotantecarga();
   if (mensaje){
   printf( "Estado del flotante: Cargando. \r\n");
   }
   else printf( "Estado del flotante: carga completa. \r\n");
   delay(5000); // Espero 1 s hasta la proxima lectura (minimo 50 ms)
}
*/











