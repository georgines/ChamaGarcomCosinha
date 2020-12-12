#ifndef BUTTOES_H
#define BUTTOES_H
#include "configuracoes.h"
#include "display.h"
int valor_atual = 0;

void somClique()
{
    digitalWrite(4, HIGH);
    delay(50);
    digitalWrite(4, LOW);
}

void subirLista(byte estado)
{
    valor_atual++;
    valor_atual = escreverLista(valor_atual);
    DBG_LN("subir lista");
    somClique();
}

void descerLista(byte estado)
{
    valor_atual--;
    valor_atual = escreverLista(valor_atual);
    DBG_LN("descer lista");
    somClique();
}

void enviarSelecionado(byte estado)
{
    DBG_LN("enviar selecionado");
    somClique();
}

void iniciarBotoes()
{
    pinMode(4, OUTPUT);
    digitalWrite(4, LOW);

    subir.begin(33, INPUT_PULLUP);
    subir.registerAction(subirLista);

    descer.begin(25, INPUT_PULLUP);
    descer.registerAction(descerLista);

    enviar.begin(27, INPUT_PULLUP);
    enviar.registerAction(enviarSelecionado);
}

void lerTodosOsBotoes()
{
    subir.read();
    descer.read();
    enviar.read();
}

#endif