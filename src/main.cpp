#include "configuracoes.h"
#include "display.h"
#include "botoes.h"

void setup()
{
  Serial.begin(115200);
  iniciarDisplay();
  iniciarBotoes();
}

void loop()
{
  lerTodosOsBotoes();
}