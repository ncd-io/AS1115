#include "spark_wiring_i2c.h"
#include "spark_wiring.h"

#define REG_DIGIT0        0x01
#define REG_DIGIT1        0x02
#define REG_DIGIT2        0x03
#define REG_DIGIT3        0x04
#define REG_DIGIT4        0x05
#define REG_DIGIT5        0x06
#define REG_DIGIT6        0x07
#define REG_DIGIT7        0x08
  
#define REG_DECODE_MODE   0x09
#define REG_GLOBAL_INTEN  0x0A
#define REG_SCAN_LIMIT    0x0B
#define REG_SHUTDOWN      0x0C
#define REG_SELF_ADDR     0x2D
#define REG_FEATURE       0x0E
#define REG_DISP_TEST     0x0F

#define REG_DIGIT01_INTEN 0x10
#define REG_DIGIT23_INTEN 0x11
#define REG_DIGIT45_INTEN 0x12
#define REG_DIGIT67_INTEN 0x13

#define REG_DIGIT0_DIAG   0x14
#define REG_DIGIT1_DIAG   0x15
#define REG_DIGIT2_DIAG   0x16
#define REG_DIGIT3_DIAG   0x17
#define REG_DIGIT4_DIAG   0x18
#define REG_DIGIT5_DIAG   0x19
#define REG_DIGIT6_DIAG   0x1A
#define REG_DIGIT7_DIAG   0x1B

#define REG_KEYA          0x1C
#define REG_KEYB          0x1D

#define DECODE_RAW        0x00
#define DECODE_FONT       0x01
#define DECODE_ALL_RAW    0x00
#define DECODE_ALL_FONT   0xFF

#define FONT_CODEB        0x00
#define FONT_HEX          0x04

#define REG_FEATURE_EXTCLK      0x00
#define REG_FEATURE_RESET       0x01
#define REG_FEATURE_FONT        0x02
#define REG_FEATURE_BLINK       0x04
#define REG_FEATURE_BLINKFREQ   0x05
#define REG_FEATURE_BLINKSYNC   0x06
#define REG_FEATURE_BLINKSTART  0x07

#define REG_SHUTDOWN_SHUTDOWN             0x00
#define REG_SHUTDOWN_RUNNING              0x01

#define REG_SHUTDOWN_RESET_FEATUREREG     0x00
#define REG_SHUTDOWN_PRESERVE_FEATUREREG  0x80

#define DP_OFF  0x00
#define DP_ON   0x01


class AS1115{
public:
    int address = 0;
    void setAddress(int a0, int a1);
    void init();
    
    int mode = REG_SHUTDOWN_RUNNING;
    int feature_shutdown = REG_SHUTDOWN_RESET_FEATUREREG;
    
    int font = FONT_HEX;
    
    void testMode(byte onoff);
    
    //intensity should be between 1-16
    void setIntensity(int intensity);
    void setIntensity(int digit, int intensity);
    
    void setDigit(int digit, int value, bool dp);
private:
    void begin();
    void writeByte(int reg, int data);
    void readBuffer(int reg, int *buff, int length);
    int readByte(int reg);
};
