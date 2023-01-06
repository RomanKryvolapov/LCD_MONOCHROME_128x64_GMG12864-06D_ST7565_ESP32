#include <Arduino.h>
#include <ST7565-i2c.h>

const uint8_t PIN_SPI_RST_RES_RESET = 2; // Used for ST7565
const uint8_t PIN_SPI_DC_RS_A0 = 4; // Used for ST7565
const uint8_t PIN_SPI_CS_SS = 15; // Used for ST7565
const uint8_t PIN_SPI_SDA_SDI_DARA_IN_MOSI = 13;
const uint8_t PIN_SPI_SDO_DATA_OUT_MISO = 12; // Used for ST7565, = SI
const uint8_t PIN_SPI_SCK_CLK_SCL_SCLK = 14; // Used for ST7565
const uint8_t PIN_I2C_SDA = 21;
const uint8_t PIN_I2C_SCL = 22;
const uint8_t PIN_UART_TX = 17;
const uint8_t PIN_UART_RX = 16;
const uint8_t PIN_DISPLAY_BRIGHTNESS = 5; // Used for ST7565, You can connect A pin to 5V for full brightness

const uint8_t DISPLAY_CONTRAST = 206;
const uint8_t DISPLAY_BRIGHTNESS = 255;

// SI = PIN_SPI_SDO_DATA_OUT_MISO
// VDD = A = Anode = VCC
// VSS = K = Cathode = GND

// You must change
// #define ST7565_STARTBYTES
// in ST7565-i2c.cpp
// to 0

// size 21x8 symbols
ST7565 display(
        PIN_SPI_SDO_DATA_OUT_MISO,
        PIN_SPI_SCK_CLK_SCL_SCLK,
        PIN_SPI_DC_RS_A0,
        PIN_SPI_RST_RES_RESET,
        PIN_SPI_CS_SS
);

TaskHandle_t Task1;
TaskHandle_t Task2;

void setupDisplay() {
    pinMode(PIN_DISPLAY_BRIGHTNESS, OUTPUT);
//    analogWrite(PIN_DISPLAY_BRIGHTNESS, DISPLAY_BRIGHTNESS * 8421504);
    digitalWrite(PIN_DISPLAY_BRIGHTNESS, HIGH);
    display.begin(DISPLAY_CONTRAST);
//    display.st7565_command(CMD_SET_COM_REVERSE);
//    display.st7565_command(CMD_SET_DISP_REVERSE);
//    display.st7565_command(CMD_SET_DISP_START_LINE);
    display.st7565_command(CMD_SET_DISP_NORMAL);
    display.clear();
    display.drawstring_P(46, 3, "Start");
    display.display();
}

void task1(void *pvParameters) {
    while (true) {

    }
}

void task2(void *pvParameters) {
    while (true) {

    }
}

void setupTasks() {
    xTaskCreatePinnedToCore(
            task1,
            "task1",
            50000,
            NULL,
            1,
            &Task1,
            0);
    xTaskCreatePinnedToCore(
            task2,
            "task2",
            50000,
            NULL,
            1,
            &Task2,
            1);
}

void setup() {
    setupDisplay();
//    setupTasks();
}

void loop() {

}