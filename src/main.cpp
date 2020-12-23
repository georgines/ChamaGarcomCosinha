#include "configuracoes.h"
#include "display.h"
#include "botoes.h"

void quandoDadosRecebidos(const uint8_t *mac_addr, const uint8_t *dadosRecebidos, int len)
{

  memcpy(&Dados, dadosRecebidos, sizeof(Dados));

  sniprintf(lista_esxibicao[indiceAtualPedido], TAMANHO_FRASE, "M%d - %s", Dados.mesa, lista[Dados.pedido]);

  Serial.printf("%s", lista_esxibicao[indiceAtualPedido]);
  Serial.println();

  atualizarTela = true;

  indiceAtualPedido++;

  if (indiceAtualPedido >= TAMANHO_LISTA_EXIBICAO)
  {
    indiceAtualPedido = 0;
  } 

  somClique();
}

void setup()
{

  Serial.begin(115200);
  Serial.setTimeout(10);

  for (int i = 0; i < TAMANHO_LISTA_EXIBICAO; i++)
  {
    memset(lista_esxibicao[i], 0, sizeof(lista_esxibicao[i]));
  }

  Serial.print("MAC ADDRES: ");
  Serial.println(WiFi.macAddress());

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK)
  {
    Serial.println("Erro ao inicializar o ESPNOW");
    return;
  }

  esp_now_register_recv_cb(quandoDadosRecebidos);

  iniciarDisplay();

  atualizarTela = true;

  iniciarBotoes();
}

void loop()
{

  lerTodosOsBotoes();

  if (atualizarTela)
  {
    escreverLista(indiceAtualListaExibicao);
    atualizarTela = false;
  }
}