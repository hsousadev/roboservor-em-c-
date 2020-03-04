////////////////////////////////////////////////////////////////////PARTE 01//////////////////////////////////////////////////////////
///// O que será necessário usar - Variáveis - Portas - Itens - Bibliotecas

//Adicionando Biblioteca do Servo Motor
#include <Servo.h>

//Chamando configuração do Servo com nome meuServo
Servo meuServo;

//Declarando porta 1 para o botão da boca
int botaoBoca = 1;

//Declarando porta 2 para o botão da cebça
int botaoCabeca = 2;

////////////////////////////////////////////////////////////////////PARTE 02//////////////////////////////////////////////////////////
///// Setup - Fixo - Programa ler apenas uma vez. 

void setup() 
{
  pinMode(botaoBoca, INPUT_PULLUP); // define o botão como entrada de dados para a abrir a boca
  pinMode(botaoCabeca, INPUT_PULLUP); // define o botão como entrada de dados para a mexer a cabeca

}


////////////////////////////////////////////////////////////////////PARTE 03//////////////////////////////////////////////////////////
///// O CÉREBRO DO ROBÔ - O QUE ELE VAI PENSAR - SERÁ EXECUTADO SEMPRE ELE ESTIVER LIGADO 

void loop() //Repetição
{
  //MANDAR MEXER A BOCA PELO SERVO
  meuServo.attach(5); //Servo na porta 5
  if(digitalRead(botaoBoca) == LOW) //Quando o botão da boca for pressionado
  {
    for(int angulo=0; angulo<=90; angulo++) // Aumenta o angulo do servo ate chegar em 90 graus
    {
      meuServo.write(angulo);
      delay(01);
    }
    for(int angulo=90; angulo>=0; angulo--)// Diminui o angulo do servo
    {
      meuServo.write(angulo);
      delay(02);
    }
  }
  meuServo.detach();


//MANDAR MEXER A CABEÇA PELO SERVO
  meuServo.attach(6); //Servo na porta 6
  if(digitalRead(botaoCabeca) == LOW) //Quando o botão da cabeca for pressionado
  {
    for(int angulo=0; angulo<=90; angulo++) // Aumenta o angulo do servo ate chegar em 180 graus
    {
      meuServo.write(angulo);
      delay(01);
    }

    for(int angulo=90; angulo>=0; angulo--)// Diminui o angulo do servo
    {
      meuServo.write(angulo);
      delay(02);
    }
  }
  meuServo.detach(); 
}
