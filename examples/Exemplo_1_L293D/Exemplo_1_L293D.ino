/*                              ##### BIBLIOTECA L293D_PIXELS #####                              
  ====== Função giraMotor ======
    *Possui 3 parâmetros:
  -> 1º parâmetro: Define o motor a ser controlado, por exemplo, MOTOR_UM, 
  MOTOR_DOIS, MOTOR_TRES, ou MOTOR_QUATRO (ver placa).
  -> 2º parâmetro: Indica o sentido de rotação ou se o motor especificado está parado. Por exemplo,
  SENTIDO_DIRETO, SENTIDO_INVERSO e PARADO. 
  -> 3º parâmetro: Define a velocidade do motor especificado. O valor desse parâmetro varia de
  0 (motor parado) à 255 (motor em máxima velocidade).

  Obs.: O 2º e 3º parâmetros podem ser omitidos, sendo adotados por default o SENTIDO_DIRETO e 255. 
  
  ====== Função controleServo ======
    *Possui 2 parâmetros:
  -> 1º parâmetro: Define o posicionamento do servo em graus, com valores variando de 0 à 180.
  -> 2º parâmetro: Indica qual servo será controlado, por exemplo, SERVO_UM ou SERVO_DOIS (ver placa).

  Obs.: O 2º parâmetro pode ser omitido, sendo adotados por default o SERVO_UM.

  Por enquanto esta biblioteca (L293D_PIXELS) apresenta apenas essas duas funções.

  Código exemplo abaixo.
*/

#include <L293D_PIXELS.h> //Inclue biblioteca

L293D_PIXELS  pixels_1; //Declara instância

void setup(){
}

void loop(){
  pixels_1.giraMotor(MOTOR_UM); 
  delay(500);
  pixels_1.giraMotor(MOTOR_UM, SENTIDO_INVERSO, 100);
  delay(500);
  pixels_1.giraMotor(MOTOR_DOIS, SENTIDO_DIRETO, 30);
  delay(500);
  pixels_1.giraMotor(MOTOR_DOIS, PARADO);
  delay(500);
  pixels_1.controleServo(120, SERVO_UM);
  delay(500);
  pixels_1.controleServo(80);
  delay(500);
}
