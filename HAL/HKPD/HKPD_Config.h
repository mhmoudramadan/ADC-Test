/*
 * HKPD_Config.h
 *
 *  Created on: Jan 22, 2022
 *      Author: Dell
 */

#ifndef HAL_HKPD_HKPD_CONFIG_H_
#define HAL_HKPD_HKPD_CONFIG_H_

/*** ROW PORT OPTION
 * 1-MDIO_PORTA
 * 2-MDIO_PORTB
 * 3-MDIO_PORTC
 * 4-MDIO_PORTD
 */
 #define HKPD_ROWPORT  MDIO_PORTA

/* ROW PINS : PIN0:PIN8*/

#define HKPD_ROWPIN0   PIN0
#define HKPD_ROWPIN1   PIN1
#define HKPD_ROWPIN2   PIN2
#define HKPD_ROWPIN3   PIN3


#define HKPD_ROWINIT  0
#define HKPD_ROWEND   4

#define HKPD_COLINIT  4
#define HKPD_COLEND   8

/* COLOUM PORT OPTION
 *1-MDIO_PORTA
 * 2-MDIO_PORTB
 * 3-MDIO_PORTC
 * 4-MDIO_PORTD
 * */

#define HKPD_COLPORT   MDIO_PORTB

/* COLOUM PINS : PIN0:PIN8*/

#define HKPD_COLPIN0  PIN4
#define HKPD_COLPIN1  PIN5
#define HKPD_COLPIN2  PIN6
#define HKPD_COLPIN3  PIN7
/*not pressed */

#define HKPD_NOTPRESSED 255

#endif /* HAL_HKPD_HKPD_CONFIG_H_ */
