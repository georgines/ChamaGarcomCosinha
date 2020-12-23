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
#define TAMANHO_LISTA_EXIBICAO 100
#define TAMANHO_FRASE 19

#define TOTAL_MESAS 2

char lista[TAMANHO_LISTA][TAMANHO_FRASE] = {
    "Chamando",
    "Suco maracuja",
    "Suco goiaba",
    "Cochinha",
    "Pastel"};

char lista_atendimento[TAMANHO_LISTA_EXIBICAO][TAMANHO_FRASE];
//objeto LCD
LiquidCrystal_I2C lcd(0x27, NUMERO_COLUNAS, NUMERO_LINHAS);

//bojetos botoes
PushButton subir;
PushButton descer;
PushButton atender;

typedef struct struct_message
{
    int mesa;
    int pedido;
} struct_message;

struct_message Dados;

int indiceAtendimento = 0;

bool atualizarTela = false;
int indiceRecebimento = 0;

#endif