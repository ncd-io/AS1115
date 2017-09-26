REG_DIGIT0        = 0x01
REG_DIGIT1        = 0x02
REG_DIGIT2        = 0x03
REG_DIGIT3        = 0x04
REG_DIGIT4        = 0x05
REG_DIGIT5        = 0x06
REG_DIGIT6        = 0x07
REG_DIGIT7        = 0x08
  
REG_DECODE_MODE   = 0x09
REG_GLOBAL_INTEN  = 0x0A
REG_SCAN_LIMIT    = 0x0B
REG_SHUTDOWN      = 0x0C
REG_SELF_ADDR     = 0x2D
REG_FEATURE       = 0x0E
REG_DISP_TEST     = 0x0F

REG_DIGIT01_INTEN = 0x10
REG_DIGIT23_INTEN = 0x11
REG_DIGIT45_INTEN = 0x12
REG_DIGIT67_INTEN = 0x13

REG_DIGIT0_DIAG   = 0x14
REG_DIGIT1_DIAG   = 0x15
REG_DIGIT2_DIAG   = 0x16
REG_DIGIT3_DIAG   = 0x17
REG_DIGIT4_DIAG   = 0x18
REG_DIGIT5_DIAG   = 0x19
REG_DIGIT6_DIAG   = 0x1A
REG_DIGIT7_DIAG   = 0x1B

REG_KEYA          = 0x1C
REG_KEYB          = 0x1D

DECODE_RAW        = 0x00
DECODE_FONT       = 0x01
DECODE_ALL_RAW    = 0x00
DECODE_ALL_FONT   = 0xFF

FONT_CODEB        = 0x00
FONT_HEX          = 0x04

REG_FEATURE_EXTCLK      = 0x00
REG_FEATURE_RESET       = 0x01
REG_FEATURE_FONT        = 0x02
REG_FEATURE_BLINK       = 0x04
REG_FEATURE_BLINKFREQ   = 0x05
REG_FEATURE_BLINKSYNC   = 0x06
REG_FEATURE_BLINKSTART  = 0x07

REG_SHUTDOWN_SHUTDOWN             = 0x00
REG_SHUTDOWN_RUNNING              = 0x01

REG_SHUTDOWN_RESET_FEATUREREG     = 0x00
REG_SHUTDOWN_PRESERVE_FEATUREREG  = 0x80

DP_OFF  = 0x00
DP_ON   = 0x01

class AS1115():
    def __init__(self, smbus, kwargs = {}):
        self.__dict__.update(kwargs)
        if not hasattr(self, 'address'):
            self.address = 0x00
        if not hasattr(self, 'mode'):
            self.mode = REG_SHUTDOWN_RUNNING
        if not hasattr(self, 'feature_shutdown'):
            self.feature_shutdown = REG_SHUTDOWN_RESET_FEATUREREG
        if not hasattr(self, 'font'):
            self.font = FONT_HEX
        self.smbus = smbus
        
        self.smbus.write_byte_data(self.address, REG_SHUTDOWN, self.mode | self.feature_shutdown)
        self.set_intensity(0xFF)
        self.smbus.write_byte_data(self.address, REG_FEATURE, self.font)
        self.smbus.write_byte_data(self.address, REG_SCAN_LIMIT, 0x02)
        self.smbus.write_byte_data(self.address, REG_DECODE_MODE, 0x07)
        
    def test_mode(self, onoff):
        if onoff:
            self.smbus.write_byte_data(self.address, REG_DISP_TEST, 0x07)
        else:
            self.smbus.write_byte_data(self.address, REG_DISP_TEST, 0x00)
        
    def set_intensity(self, intensity):
        self.smbus.write_byte_data(self.address, REG_GLOBAL_INTEN, intensity)
        
    def set_digit(self, digit, value, dp):
        if dp:
            value = value | 0x80
        self.smbus.write_byte_data(self.address, REG_DIGIT0 + digit, value)
        
