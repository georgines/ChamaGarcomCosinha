#ifndef BUTTOES_H
#define BUTTOES_H
#include "configuracoes.h"
#include "display.h"

void somClique()
{
    digitalWrite(4, HIGH);
    delay(50);
    digitalWrite(4, LOW);
}

void subirLista(byte estado)
{
}

void descerLista(byte estado)
{
}

void atendePedido(byte estado)
{
    if (lista_atendimento[indice_atendimento][0] != 0)
    {
        indice_atendimento++;
        indice_atendimento = imprimirLista(indice_atendimento);
    }
}

void iniciarBotoes()
{
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);

    subir.begin(33, INPUT_PULLUP);
    subir.registerAction(subirLista);

    descer.begin(25, INPUT_PULLUP);
    descer.registerAction(descerLista);

    atender.begin(27, INPUT_PULLUP);
    atender.registerAction(atendePedido);
}

void lerTodosOsBotoes()
{
    subir.read();
    descer.read();
    atender.read();
}

#endif