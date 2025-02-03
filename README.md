Este projeto é uma aplicação embarcada para a Raspberry Pi Pico utilizando o SDK do Raspberry Pi Pico. O código foi desenvolvido para controlar LEDs RGB e botões, implementando funcionalidades básicas de interação com o usuário através desses periféricos.

## Descrição

O projeto implementa a funcionalidade de incrementar e decrementar um contador através de dois botões. O valor do contador será exibido na matriz de LEDs WS2812 (a ser integrada futuramente). O LED vermelho pisca periodicamente enquanto o sistema está em execução.

### Funcionalidades:
- **Botão A**: Incrementa o valor do contador.
- **Botão B**: Decrementa o valor do contador.
- **LED Vermelho**: Pisca a cada 100 ms.
- **Debounce**: Implementação de debounce para os botões, evitando múltiplos acionamentos devido a ruídos.

## Estrutura do Projeto

A estrutura de pastas do projeto é organizada da seguinte maneira:


## Como Compilar

1. **Instalar o SDK do Raspberry Pi Pico:**
   - Certifique-se de ter o SDK do Raspberry Pi Pico instalado em seu sistema. Você pode seguir as instruções oficiais de instalação [aqui](https://github.com/raspberrypi/pico-sdk).

2. **Compilar o Projeto:**
   - Abra um terminal na raiz do projeto e crie um diretório de compilação:
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```

3. **Carregar na Raspberry Pi Pico:**
   - Conecte sua Raspberry Pi Pico ao computador e carregue o arquivo `.uf2` gerado na pasta `build` na sua Raspberry Pi Pico.

## Funcionalidades Futuras

- **Integração com a matriz WS2812:** Exibição do contador na matriz de LEDs.
- **Expansão de funcionalidades:** Implementação de mais funcionalidades, como controle de brilho dos LEDs ou interação com outros sensores.
