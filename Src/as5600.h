#ifndef _AS5600_H
#define _AS5600_H

#include "stm32f4xx_hal.h"
#include "i2c_soft.h"

#define AS5600_ADDR 0x36
#define AS5600_ZPOS_H 0x01
#define AS5600_ZPOS_L 0x02
#define AS5600_MPOS_H 0x03
#define AS5600_MPOS_L 0x04
#define AS5600_MANG_H 0x05
#define AS5600_MANG_L 0x06
#define AS5600_CONF_H 0x07
#define AS5600_CONF_L 0x08
#define AS5600_RAW_ANGLE_H 0x0C
#define AS5600_RAW_ANGLE_L 0x0D
#define AS5600_ANGLE_H 0x0E
#define AS5600_ANGLE_L 0x0F
#define AS5600_STATUS 0x0B
#define AS5600_AGC 0x1A
#define AS5600_MAGNITUDE_H 0x1B
#define AS5600_MAGNITUDE_L 0x1C
#define AS5600_BURN 0xFF

#define AS5600_CONF_PM_BIT 1
#define AS5600_CONF_PM_LENGTH 2

#define AS5600_CONF_HYST_BIT 3
#define AS5600_CONF_HYST_LENGTH 2

#define AS5600_CONF_OUTS_BIT 5
#define AS5600_CONF_OUTS_LENGTH 2

#define AS5600_CONF_PWMF_BIT 7
#define AS5600_CONF_PWMF_LENGTH 2

#define AS5600_CONF_SF_BIT 9
#define AS5600_CONF_SF_LENGTH 2

#define AS5600_CONF_FTH_BIT 12
#define AS5600_CONF_FTH_LENGTH 3

#define AS5600_CONF_WD_BIT 13
#define AS5600_CONF_WD_LENGTH 1

#define AS5600_PWM_115HZ 0x00
#define AS5600_PWM_230HZ 0x01
#define AS5600_PWM_460HZ 0x02
#define AS5600_PWM_920HZ 0x03

#define AS5600_OUT_ANALOG_1 0x00
#define AS5600_OUT_ANALOG_2 0x01
#define AS5600_OUT_PWM 0x02

//u8 AS5600_Init();
//void AS5600_SET_PWM(u8 pwm_hz);
void AS5600_Angle_Read(void);
void AS5600_Data(uint16_t *RawAngle);
void AS5600_DaTa_Angle(u16 *Angle);
void Burn_Angle_Check(u8 *buffer);
//u8 Burn_Angle_Command();
//u8 Angle_Pro_MPOS();
//u8 Angle_Pro_ZPOS();
#endif
