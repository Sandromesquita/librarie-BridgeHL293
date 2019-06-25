#include <L293D_PIXELS.h>

L293D_PIXELS::L293D_PIXELS(void){
  for(int i=3; i<13; i++) pinMode(i, OUTPUT);  
  enviaByte(0x00);
  digitalWrite(0, pino_habilita); //Habilita shift-register 74HC595
}

void L293D_PIXELS::giraMotor(byte numeroMotor, byte sentidoRotacao, byte valorVelocidade){
  if(numeroMotor==1){
    analogWrite(pino_pwmMotor_1, valorVelocidade);
    if(sentidoRotacao==0){
      valor=(controle|motor1_Sentido_1)&(~motor1_Sentido_0);
    }
    else if(sentidoRotacao==1){
      valor=(controle|motor1_Sentido_0)&(~motor1_Sentido_1);
    }
    else if(sentidoRotacao==2){
      valor=(controle&(~motor1_Sentido_0))&(~motor1_Sentido_1);
    }
    else;
    enviaByte(valor);
  }
  else if(numeroMotor==2){
    analogWrite(pino_pwmMotor_2, valorVelocidade);
    if(sentidoRotacao==0){
      valor=(controle|motor2_Sentido_1)&(~motor2_Sentido_0);
    }
    else if(sentidoRotacao==1){
      valor=(controle|motor2_Sentido_0)&(~motor2_Sentido_1);
    }
    else if(sentidoRotacao==2){
      valor=(controle&(~motor2_Sentido_0))&(~motor2_Sentido_1);
    }
    else;
    enviaByte(valor);
  }
  else if(numeroMotor==3){
    analogWrite(pino_pwmMotor_3, valorVelocidade);
    if(sentidoRotacao==0){
      valor=(controle|motor3_Sentido_1)&(~motor3_Sentido_0);
    }
    else if(sentidoRotacao==1){
      valor=(controle|motor3_Sentido_0)&(~motor3_Sentido_1);
    }
    else if(sentidoRotacao==2){
      valor=(controle&(~motor3_Sentido_0))&(~motor3_Sentido_1);
    }
    else;
    enviaByte(valor);
  }
  else if(numeroMotor==4){
    analogWrite(pino_pwmMotor_4, valorVelocidade);
    if(sentidoRotacao==0){
      valor=(controle|motor4_Sentido_1)&(~motor4_Sentido_0);
    }
    else if(sentidoRotacao==1){
      valor=(controle|motor4_Sentido_0)&(~motor4_Sentido_1);
    }
    else if(sentidoRotacao==2){
      valor=(controle&(~motor4_Sentido_0))&(~motor4_Sentido_1);
    }
    else;
    enviaByte(valor);
  }
  else;
  controle=valor;
}

void L293D_PIXELS::controleServo(byte valorServo, byte numeroServo){
  if(numeroServo==1){
    servo_1.attach(pino_servo_1);  
    servo_1.write(valorServo);
  }
  else if(numeroServo==2){
    servo_2.attach(pino_servo_2);
    servo_2.write(valorServo);
  }
  else;
}

void L293D_PIXELS::enviaByte(byte valorByte){
  digitalWrite(pino_latch, 0);
  shiftOut(pino_dados, pino_clock, LSBFIRST, valorByte);
  digitalWrite(pino_latch, 1); 
}
