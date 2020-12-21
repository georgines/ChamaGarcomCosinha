#include "configuracoes.h"
#include "display.h"
#include "botoes.h"

void OnDataRecv(const uint8_t *mac_addr, const uint8_t *dadosRecebidos, int len)
{

  memcpy(&myData, dadosRecebidos, sizeof(myData));

  sniprintf(lista_esxibicao[pedidoAtual], TAMANHO_FRASE, "M%d - %s", myData.mesa, lista[myData.pedido]);

  Serial.printf("%s", lista_esxibicao[pedidoAtual]);
  Serial.println();

  atualizarTela = true;

  pedidoAtual++;

  if (pedidoAtual >= TAMANHO_LISTA_EXIBICAO)
  {
    pedidoAtual = 0;
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
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_recv_cb(OnDataRecv);

  iniciarDisplay();

  atualizarTela = true;

  iniciarBotoes();
}

void loop()
{

  lerTodosOsBotoes();

  if (atualizarTela)
  {
    escreverLista(valor_atual);
    atualizarTela = false;
  }
}