Código para Arduino - Flappy Pig
Este é um código para Arduino que implementa o jogo Flappy Pig. O jogo utiliza uma placa Arduino, um display TFT ST7789 e dois botões para controlar o personagem do jogo.

Arquivos necessários
Para executar o código, você precisará das seguintes bibliotecas:

Adafruit_GFX.h: Biblioteca de gráficos para o display.
Adafruit_ST7789.h: Biblioteca específica para o display TFT ST7789.
SPI.h: Biblioteca para comunicação SPI no Arduino.
Certifique-se de instalar essas bibliotecas no seu ambiente de desenvolvimento Arduino.

Conexões do display TFT ST7789
O display TFT ST7789 deve ser conectado ao Arduino nas seguintes pinagens:

TFT_CS: Pino CS (Chip Select) conectado ao pino 10 do Arduino.
TFT_RST: Pino de reset conectado ao pino 8 do Arduino (ou pode ser conectado diretamente ao pino de reset do Arduino se configurado como -1).
TFT_DC: Pino DC (Data/Command) conectado ao pino 9 do Arduino.
Certifique-se de fazer as conexões corretamente antes de carregar o código no Arduino.

Funcionamento
O código implementa um menu principal com quatro opções: JOGAR, RANKING, CRÉDITOS e SAIR. O jogador pode navegar pelas opções usando os botões conectados ao Arduino. Ao selecionar a opção JOGAR, o jogo Flappy Pig é iniciado.

Durante o jogo, o jogador pode pressionar um dos botões para fazer o personagem do jogo ("Flappy Pig") pular. O objetivo é evitar os obstáculos que se movem pela tela e marcar pontos. O jogo utiliza o display TFT ST7789 para exibir os gráficos do jogo.

O código inclui várias funções auxiliares para controlar o menu, as opções do sub-menu e os elementos do jogo, como o personagem e os obstáculos.

Observações
Certifique-se de ter as bibliotecas necessárias instaladas e o display TFT ST7789 corretamente conectado antes de executar o código.

Lembre-se de adaptar as conexões de pinagem caso estejam diferentes das especificadas no código.

Este código é fornecido como exemplo e pode ser modificado e aprimorado conforme suas necessidades.

Divirta-se jogando Flappy Pig no seu Arduino! 
