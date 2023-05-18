#include <Adafruit_GFX.h> // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h> // Arduino SPI library
// ST7789 TFT module connections
#define TFT_CS 10
#define TFT_RST 8 // define reset pin, or set to -1 and connect to Arduino RESET pin
#define TFT_DC 9 // define data/command pin
#define ST7735_PINK 0xF8FF
#define ST7735_GRAY 0x8410
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
#define BA 3
#define BB 6
typedef struct {
 char jogador[3];
 int pontos = 0;
} jogadores;

jogadores jogadordados[4];

int BotaoA = 1;
int BotaoB = 1;
int aperto = 0;
int opc = 75;
int Y = 0;
int opc_sub = 95;
char letras[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int i = 0;
int q = 0;
int z = 0;
int jogador = 0;

void jogo (void);
void menu(void);
void cursor_menu(void);
void Switch (void);
void sub_cursor (void);
void sub_switch (void);
void sub_menu_print (void);
void sub_menu_escreve(void);
void escreve_nome (void);
void apaga(void);
void fundo_start (void);
void PIG (void);
void PIG_apaga (void);
void obstacles1 (void);
void obstacles2 (void);
void obstacles3 (void);
void sair (void);
void volta (void);
void setup() {

 Serial.begin(9600);
 tft.init(240, 240, SPI_MODE2);
 tft.setRotation(2);
 tft.fillRect(0, 0, 240, 240, ST77XX_YELLOW);
 tft.fillRect(10, 10, 220, 220, ST77XX_WHITE);
 
 pinMode(BA, INPUT_PULLUP);// ligando o boatao a
 pinMode(BB, INPUT_PULLUP);// ligando o botao b
 menu();
 cursor_menu();// chamar função da seta
}
void loop() {
 jogo();
}
void jogo (void) {
 BotaoA = digitalRead (BA);//leitura dos botoes
 BotaoB = digitalRead (BB);
 //menu();
 cursor_menu();
 if (BotaoA == 0)
 {
 if (opc < 160)
 {
 tft.fillRect(10, opc, 40, 22, ST77XX_WHITE);
 opc += 30;
 delay(100);
 }
 else
 {
 tft.fillRect(10, opc, 40, 22, ST77XX_WHITE);//apagando seta
 opc = 75;
 delay(100);
 }
 while (BotaoA != 1)
 {
 BotaoA = digitalRead(BA);// para o botao nao ficar doido
 }
 }
 if (BotaoB == 0) {
 Switch();
 }
}
void menu(void) {
 tft.setTextSize(3);
 tft.setTextColor(ST77XX_BLACK);
 tft.setCursor(30, 15);
 tft.println("FLAPPY-PIG");
 tft.setTextColor(ST77XX_RED);
 tft.setCursor(60, 75);
 tft.println("JOGAR");
 tft.setCursor(60, 105);
 tft.println("RANKING");
 tft.setCursor(60, 135);
 tft.println("CREDITOS");
 tft.setCursor(60, 165);
 tft.println("SAIR");
}
void cursor_menu(void) {
 tft.setCursor(15, opc);
 tft.setTextColor(ST77XX_BLACK);
 tft.print(F("->"));
 delay(20);
}
void Switch (void) {
 switch (opc) {
 case 75:
 tft.fillScreen(ST77XX_WHITE);
 while (1)
 {
 sub_switch();//chamando a função do sub menu
 }
 break;
 case 105:
 break;
 case 135:
 break;
 case 165:
 break;
 }
}
void sub_cursor (void) {
 tft.drawRoundRect(20, opc_sub, 200, 30, 10, ST77XX_BLACK);
 BotaoA = digitalRead(BA);// ler botão
 if (BotaoA == 0)
 {
 tft.drawRoundRect(20, opc_sub, 200, 30, 10, ST77XX_WHITE);// printa o quadrado em volta da opção do sub menu
 delay(10);
 opc_sub += 30;// = opc_sub+30
 if (opc_sub >= 155)
 {
 opc_sub = 95;
 }
 }
 while (BotaoA != 1)
 {
 BotaoA = digitalRead(BA);
 }
}
void sub_switch (void) {
 sub_menu_print();
 sub_cursor();
 BotaoB = digitalRead(BB);
 if (BotaoB == 0) {
 switch (opc_sub) {
 case 95:
 tft.fillScreen(ST77XX_WHITE);
 sub_menu_escreve();
 break;
 case 125:
 break;
 }
 }
}
void sub_menu_print (void) {
 tft.setTextSize(3);
 tft.setTextColor(ST77XX_BLACK);
 tft.setCursor(40, 20);
 tft.print(F("OPCOES DE "));
 tft.setCursor(40, 50);
 tft.print(F("INICIACAO "));
 tft.setCursor(30, 100);
 tft.print(F("NEW PLAYER"));
 tft.setCursor(30, 130);
 tft.print(F("OLD PLAYER"));
}
void sub_menu_escreve(void) {
 tft.setCursor(120, 120);
 tft.print(letras[i]);
 while (z != 3)
 {
 BotaoA = digitalRead(BA);
 BotaoB = digitalRead(BB);
 if (i == 26)
 {
 i = -1;
 }
 if (BotaoA == 0 )
 {
 escreve_nome();
 BotaoA = 0;
 while (BotaoA != 1)
 {
 BotaoA = digitalRead(BB);
 }
 delay(300);
 }
 if (BotaoB == 0 )
 {
 jogadordados[q].jogador[z] = letras[i];
 apaga();
 z += 1;
 i = 0;
 tft.setCursor(120, 120);
 tft.setTextColor(ST77XX_BLACK);
 tft.print(letras[i]);
 while (BotaoB != 1)
 {
 BotaoB = digitalRead(BB);
 }
 }

 }
 apaga();
 tft.setCursor(120, 120);
 tft.setTextColor(ST77XX_BLACK);
 tft.print(jogadordados[q].jogador);
 Serial.println(jogadordados[q].jogador);
 delay(5000);
 if (z == 3){
 play();
 }
}
void escreve_nome (void) {
 tft.setCursor(120, 120);
 tft.setTextColor(ST77XX_WHITE);
 tft.print(letras[i]);
 i += 1;
 tft.setCursor(120, 120);
 tft.setTextColor(ST77XX_BLACK);
 tft.print(letras[i]);
}
void apaga(void) {
 tft.setCursor(120, 120);
 tft.setTextColor(ST77XX_WHITE);
 tft.print(letras[i]);
}
void fundo_start (void) {
 tft.fillRect(0, 0, 240, 240, ST77XX_GREEN);
 tft.fillRect(0, 0, 240, 180, ST77XX_BLUE);
}
void PIG (void) {
 tft.fillRect(20, 145 + Y, 40, 20, ST7735_PINK); //BASE DO CORPO
 tft.fillRect(20, 160 + Y, 10, 20, ST7735_PINK); // PERNA ESQUERDA
 tft.fillRect(50, 160 + Y, 10, 20, ST7735_PINK); // PERNA DIREITA
 tft.fillRect(50, 135 + Y, 25, 20, ST7735_PINK); //CABEÇA
 tft.fillRect(71, 145 + Y, 8, 8, ST7735_PINK); //NARIZ
 tft.fillCircle(70, 140 + Y, 4, ST77XX_BLACK); //OLHO
 tft.fillCircle(72, 140 + Y, 1, ST77XX_WHITE); //OLHO BRANCO DO OLHO
 tft.fillRect(53, 137 + Y, 8, 13, ST77XX_BLACK); //ORELHA
 tft.fillRect(55, 137 + Y, 4, 11, ST7735_PINK); //ORELHA
}
void PIG_apaga (void) {
 tft.fillRect(20, 145 + Y, 40, 20, ST77XX_BLUE); //BASE DO CORPO
 tft.fillRect(20, 160 + Y, 10, 20, ST77XX_BLUE); // PERNA ESQUERDA
 tft.fillRect(50, 160 + Y, 10, 20, ST77XX_BLUE); // PERNA DIREITA
 tft.fillRect(50, 135 + Y, 25, 20, ST77XX_BLUE); //CABEÇA
 tft.fillRect(71, 145 + Y, 8, 8, ST77XX_BLUE); //NARIZ
 tft.fillCircle(70, 140 + Y, 4, ST77XX_BLUE); //OLHO
 tft.fillCircle(72, 140 + Y, 1, ST77XX_BLUE); //OLHO BRANCO DO OLHO
 tft.fillRect(53, 137 + Y, 8, 13, ST77XX_BLUE); //ORELHA
 tft.fillRect(55, 137 + Y, 4, 11, ST77XX_BLUE); //ORELHA
}
void obstacles1 (void) {
 tft.fillRect(200, 135, 30, 45, ST7735_GRAY);
}
void sair (void)
{
 tft.fillScreen(ST77XX_BLACK);
 tft.setCursor(0, 90);
 tft.print("volte sempre");
 delay(15000);
 tft.fillScreen(ST77XX_BLACK);
 delay(15000);
 volta();
}
void volta (void)
{
 tft.fillScreen(ST77XX_BLACK);
 opc = 75;
 menu();
 cursor_menu();
}
void play (void){
 BotaoA = digitalRead(BA);
 fundo_start();
 PIG();
 if (BotaoA ==0){
 Y -= 40;
 }
}