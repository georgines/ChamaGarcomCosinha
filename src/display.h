#ifndef DISPLAY_H
#define DISPLAY_H
#include "configuracoes.h"

#define CHAR_SETA_SELETORA 0

byte seta_seletora[8] = {
    B10000,
    B11000,
    B11100,
    B11110,
    B11110,
    B11100,
    B11000,
    B10000};

void iniciarDisplay()
{
    lcd.init();
    lcd.backlight();

    lcd.createChar(CHAR_SETA_SELETORA, seta_seletora);
    return;
}

void setarCaractereSeletor()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(CHAR_SETA_SELETORA);
}

void mostrarMenu()
{
    lcd.setCursor(0, 3);
    lcd.print(" [sub] [desc] [env]");
}

void escrever(char palavra[], int linha)
{
    lcd.setCursor(1, linha);
    lcd.print(palavra);
    DBG_LN(palavra);
}

int escreverLista(int indice)
{
    int indice2;
    
    if (indice < 0)
    {
        indice = TAMANHO_LISTA - 1;
    }
    else if (indice == TAMANHO_LISTA)
    {
        indice = 0;
    }

    indice2 = indice + 1;

    setarCaractereSeletor();
    mostrarMenu();

    escrever(lista[indice], 0);
    DBG_F_LN("indice %d", indice);

    if (indice2 < TAMANHO_LISTA)
    {
        escrever(lista[indice2], 1);
        DBG_F_LN("indice2 %d", indice2);
    }

    DBG_LN();

    return indice;
}
void escreverLista2(int indice)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write(CHAR_SETA_SELETORA);

    lcd.setCursor(1, 0);
    lcd.print(lista[indice]);
    DBG_LN(lista[indice]);

    // lcd.setCursor(1, 2);
    // lcd.print(lista[3]);
    lcd.setCursor(0, 3);
    lcd.print("[sub] [desc] [env]");
    return;
}

#endif