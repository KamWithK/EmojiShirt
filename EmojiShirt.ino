#include <Adafruit_GFX.h>
#include <RGBmatrixPanel.h>

#define CLK 8
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2

RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

uint16_t data[16][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 10593, 25347, 21187, 353, 417, 356, 2214, 0, 0, 0}, {0, 0, 2080, 29154, 47939, 50566, 61320, 65512, 36454, 1187, 1250, 3148, 10973, 6609, 99, 0}, {0, 8352, 45795, 64483, 64837, 65511, 65447, 59239, 15684, 1155, 1187, 5104, 11007, 11103, 12755, 2048}, {0, 26785, 64387, 64451, 64869, 63431, 65447, 57159, 5315, 1187, 1188, 9050, 11039, 11039, 37301, 22730}, {0, 40960, 64131, 64483, 64772, 63431, 65479, 28165, 1187, 1157, 7062, 11007, 11039, 17117, 41364, 24811}, {12288, 53249, 64099, 64547, 64483, 64997, 54983, 17573, 7044, 15207, 17234, 15122, 13044, 25076, 41298, 16519}, {22528, 63489, 63617, 56035, 37830, 29478, 25513, 19112, 29644, 31885, 23495, 27657, 21224, 29581, 31247, 4130}, {22528, 59392, 47395, 27655, 19496, 29805, 44373, 6339, 25324, 61342, 50744, 46518, 6307, 38034, 52889, 8516}, {4096, 25092, 25768, 25865, 25768, 27850, 31981, 17127, 27725, 46287, 58156, 51946, 17094, 27788, 27755, 4289}, {4321, 23688, 25832, 25800, 25832, 25800, 27623, 31719, 27752, 41475, 51297, 43040, 31687, 31719, 25092, 0}, {12868, 27881, 25800, 25800, 25800, 25800, 31559, 37478, 37510, 39396, 39009, 35010, 39493, 41606, 20835, 0}, {17157, 27912, 25800, 25800, 25800, 23656, 25800, 25768, 27623, 31623, 31591, 31623, 31655, 31783, 6466, 0}, {8717, 23626, 27879, 27911, 27912, 25799, 27788, 25770, 23752, 23784, 25769, 25770, 21609, 13168, 2214, 0}, {409, 2619, 8915, 15183, 17326, 15213, 42523, 42554, 29839, 29839, 42521, 38266, 2523, 543, 373, 1}, {508, 575, 543, 511, 511, 509, 42557, 44669, 25558, 23478, 44636, 34108, 479, 575, 575, 271}};
int data_size[2] = {16, 16};

uint16_t Color888(uint8_t r, uint8_t g, uint8_t b) {
  return ((uint16_t)(r & 0xF8) << 8) | ((uint16_t)(g & 0xFC) << 3) | (b >> 3);
}

void setup() {
  matrix.begin();
  delay(3000);

  for (int i = 0; i < data_size[0]; i++){
    for (int j = 0; j < data_size[1]; j++) {
      matrix.drawPixel(i, j, data[i][j]);
    }
  }
}

void loop() {
}
