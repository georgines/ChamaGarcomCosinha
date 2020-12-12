#ifndef CONFIGURACOES_H
#define CONFIGURACOES_H
#include "Arduino.h"
#include "debug.h"
#include "LiquidCrystal_I2C.h"
#include "PushButton.h"

#define NUMERO_COLUNAS 20
#define NUMERO_LINHAS 4

#define NUMERO_MESA 1

#define TAMANHO_LISTA 5 
#define TAMANHO_FRASE 19

char lista[TAMANHO_LISTA][TAMANHO_FRASE] = {
    "[1] Apenas chamar",
    "[2] Suco maracuja",
    "[3] Suco goiaba",
    "[4] Cochinha",
    "[5] Pastel"};

//objeto LCD
LiquidCrystal_I2C lcd(0x27, NUMERO_COLUNAS, NUMERO_LINHAS);

//bojetos botoes
PushButton subir;
PushButton descer;
PushButton enviar;

#endif