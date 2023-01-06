<h1>Simple Platformio / CLion project</h1>
<h2>128x64 LCD monochrome display 21x8 symbols with ST7565 controller</h2>
<h2>ESP32 DEVKIT V1 board</h2>
<h3>Pins:</h3>
<p>PIN_SPI_RST_RES_RESET = 2, Used for ST7565</p>
<p>PIN_SPI_DC_RS_A0 = 4, Used for ST7565</p>
<p>PIN_SPI_CS_SS = 15, Used for ST7565</p>
<p>PIN_SPI_SDA_SDI_DARA_IN_MOSI = 13</p>
<p>PIN_SPI_SDO_DATA_OUT_MISO = 12, Used for ST7565, = SI</p>
<p>PIN_SPI_SCK_CLK_SCL_SCLK = 14, Used for ST7565</p>
<p>PIN_I2C_SDA = 21</p>
<p>PIN_I2C_SCL = 22</p>
<p>PIN_UART_TX = 17</p>
<p>PIN_UART_RX = 16</p>
<p>PIN_DISPLAY_BRIGHTNESS = 5, Used for ST7565, You can connect A pin to 5V for full brightness</p>

<h3>SI = PIN_SPI_SDO_DATA_OUT_MISO</h3>
<h3>VDD = A = Anode = VCC</h3>
<h3>VSS = K = Cathode = GND</h3>

<h3>You must change</h3>
<h3>#define ST7565_STARTBYTES</h3>
<h3>in ST7565-i2c.cpp</h3>
<h3>to 0</h3>

![1!](https://github.com/RomanKryvolapov/1.3_OLED_128x64_SH1106_ESP32/blob/master/Display_OLED.jpg "1")

![2!](https://github.com/RomanKryvolapov/1.3_OLED_128x64_SH1106_ESP32/blob/master/ESP32-Pinout.png "2")

