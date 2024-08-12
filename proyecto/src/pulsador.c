/*=====[Nombre del modulo]=====================================================
 * Copyright YYYY Nombre completo del autor <author@mail.com>
 * All rights reserved.
 * Licencia: Texto de la licencia o al menos el nombre y un link
         (ejemplo: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.0.0
 * Fecha de creacion: YYYY/MM/DD
 */

/*=====[Inclusion de su propia cabecera]=====================================*/

#include "pulsador.h"

/*=====[Inclusiones de dependencias de funciones privadas]===================*/

//#include <dependencia.h>
#include "sapi.h"              // <= sAPI header

/*=====[Macros de definicion de constantes privadas]=========================*/

//#define QMC5883L_REG_Y_LSB       0x02
//#define MAX_AMOUNT_OF_RGB_LEDS   9

/*=====[Macros estilo funcion privadas]======================================*/

//#define rtcConfig rtcInit

/*=====[Definiciones de tipos de datos privados]=============================*/

// Tipo de datos que renombra un tipo basico
//typedef uint32_t gpioRegister_t;

// Tipo de datos de puntero a funcion
//typedef void (*FuncPtrPrivado_t)(void *);

// Tipo de datos enumerado
/*typedef enum {
   GPIO_INPUT_PULLUP, 
   GPIO_INPUT_PULLDOWN,
   GPIO_REPEATER
} gpioLPC4337Modes_t;
*/

// Tipo de datos estructua, union o campo de bits
/*typedef struct {
   uint8_t scuPort;
   uint8_t scuPin;
   uint8_t func;
   uint8_t gpioPort;
   uint8_t gpioPin;
} gpioLpc4337_t;*/

/*=====[Definiciones de Variables globales publicas externas]================*/

//extern int32_t varGlobalExterna;

/*=====[Definiciones de Variables globales publicas]=========================*/

//int32_t varGlobalPublica = 0;

/*=====[Definiciones de Variables globales privadas]=========================*/

//static int32_t varGlobalPrivada = 0;

/*=====[Prototipos de funciones privadas]====================================*/

//static void funPrivada(void);

/*=====[Implementaciones de funciones publicas]==============================*/

void init_pulsador( void )
{
 //gpioInit( gpioMap_t pin, gpioConfig_t config );
   gpioInit( GPIO0, GPIO_INPUT_PULLUP );// Gpio0 como Entrada señal del pulsador 
}


/*=====[Implementaciones de funciones de interrupcion publicas]==============*/

int flotantecarga( void )
{
   return (gpioRead( GPIO0 ));  //Retorna 0 = desactivado, 1 = Activado. 
}

/*=====[Implementaciones de funciones privadas]==============================*/

/*static void funPrivada(void)
{
   // ...
}*/

