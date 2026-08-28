/*
 * servos.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Alcides Ramos
 */

#ifndef INC_SERVOS_H_
#define INC_SERVOS_H_

#include "main.h"

// Configuración del rango de ángulo deseado (-90° a +90°)
#define ser_sup          90.0f
#define ser_inf         -90.0f

// Configuración de los tiempos límite en milisegundos del servomotor
// 0.5 ms (-90°) a 2.5 ms (+90°)
#define ser_lim_sup_ms   2.5f
#define ser_lim_inf_ms   0.5f

// Estructura de control para el servomotor
typedef struct {
    TIM_HandleTypeDef *htim; // Puntero al temporizador HAL
    volatile uint32_t *ccr;  // Puntero al registro CCR del canal del Timer
    uint32_t channel;        // Canal de PWM (ej. TIM_CHANNEL_1)
} SERVOS;

// Prototipe de funciones
void SERVO_init(SERVOS *servo);
void SERVO_ANG(SERVOS *servo, float posi);
void SERVO_MICRO(SERVOS *servo, float micro);
void SERVO_MILI(SERVOS *servo, float milis);
void SERVO_MUEVE(SERVOS *servo, float ini, float final, float paso, float ret);

#endif /* INC_SERVOS_H_ */