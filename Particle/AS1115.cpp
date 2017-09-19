#include "AS1115.h"

void AS1115::begin(){
    if(!Wire.isEnabled()) Wire.begin();
}

void AS1115::init(){
    begin();
    writeByte(REG_SHUTDOWN, mode | feature_shutdown);
    
    setIntensity(0xFF);
    writeByte(REG_FEATURE, font);
    writeByte(REG_SCAN_LIMIT, 0x02);
    writeByte(REG_DECODE_MODE, 0x07);
    delay(300);
}

void AS1115::setAddress(int a0, int a1){
    int addr = a0 + (a1 << 1);
    writeByte(REG_SELF_ADDR, addr);
    address = addr;
}

void AS1115::testMode(byte onoff){
    writeByte(REG_DISP_TEST, onoff);
}

void AS1115::setIntensity(int intensity){
    writeByte(REG_GLOBAL_INTEN, intensity);
}

void AS1115::setIntensity(int digit, int intensity){
    int reg = digit == 2 ? REG_DIGIT23_INTEN : REG_DIGIT01_INTEN;
    int value = readByte(reg);
    if(digit == 1){
        value &= (value & 0xF0) | intensity;
    }else{
        value = (value & 0x0F) | (intensity << 4);
    }
    writeByte(reg, value);
}

void AS1115::setDigit(int digit, int value, bool dp){
    if(dp) value |= 0x80;
    writeByte(REG_DIGIT0 + digit, value);
}

void AS1115::writeByte(int reg, int data){
    Wire.beginTransmission(address);
    Wire.write(reg);
    if(data < 256) Wire.write(data);
    Wire.endTransmission();
}

int AS1115::readByte(int reg){
    writeByte(reg, 256);
    Wire.requestFrom(address, 1);
    return Wire.read();
}

void AS1115::readBuffer(int reg, int *buff, int len){
    writeByte(reg, 256);
    Wire.requestFrom(address, len);
    for(int i=0;i<len;i++){
        buff[i] = Wire.read();
    }
}
