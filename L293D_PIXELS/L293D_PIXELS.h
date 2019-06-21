#ifndef                       _L293D_
#define                       _L293D_

#define   motor1_Sentido_0    0b00100000   
#define   motor1_Sentido_1    0b00010000 

#define   motor2_Sentido_0    0b01000000   
#define   motor2_Sentido_1    0b00001000 

#define   motor3_Sentido_0    0b10000000   
#define   motor3_Sentido_1    0b00000010 

#define   motor4_Sentido_0    0b00000100   
#define   motor4_Sentido_1    0b00000001 

#define   SENTIDO_DIRETO      1
#define   SENTIDO_INVERSO     0
#define   PARADO              2
#define   MOTOR_UM            1
#define   MOTOR_DOIS          2
#define   MOTOR_TRES          3
#define   MOTOR_QUATRO        4
#define   SERVO_UM            1
#define   SERVO_DOIS          2

#define   pino_pwmMotor_1     11
#define   pino_pwmMotor_2     3
#define   pino_pwmMotor_3     5
#define   pino_pwmMotor_4     6
#define   pino_servo_1        10
#define   pino_servo_2        9

#define   pino_dados          8      
#define   pino_clock          4   
#define   pino_latch          12   
#define   pino_habilita       7 

#include  <Arduino.h>

#include <Servo.h>

class L293D_PIXELS{
  public:
    L293D_PIXELS(void);
    void giraMotor(byte, byte sentidoRotacao=1, byte valorVelocidade=255);
    void controleServo(byte, byte numeroServo=1);   
  private:
    byte controle=0, valor;
    void enviaByte(byte);  
    Servo servo_1, servo_2;
};

#endif
