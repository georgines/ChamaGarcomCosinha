#ifndef CONFIGURACOES_H
#define CONFIGURACOES_H
#include "Arduino.h"
#include "debug.h"
#include "LiquidCrystal_I2C.h"
#include "PushButton.h"
#include "WiFi.h"
#include <esp_now.h>

#define NUMERO_COLUNAS 20
#define NUMERO_LINHAS 4

#define NUMERO_MESA 1

#define TAMANHO_LISTA 5 
#define TAMANHO_FRASE 19

#define TOTAL_MESAS 2

char lista[TAMANHO_LISTA][TAMANHO_FRASE] = {
    "Chamando",
    "Suco maracuja",
    "Suco goiaba",
    "Cochinha",
    "Pastel"};

char lista_esxibicao[100][TAMANHO_FRASE];
//objeto LCD
LiquidCrystal_I2C lcd(0x27, NUMERO_COLUNAS, NUMERO_LINHAS);

//bojetos botoes
PushButton subir;
PushButton descer;
PushButton enviar;

typedef struct struct_message {
  int id;
  int x;
  int y;
}struct_message;

// Create a struct_message called myData
struct_message myData;

struct_message board1;
struct_message board2;
struct_message board3;

struct_message boardsStruct[3] = {board1, board2, board3};

#endif