// This #include statement was automatically added by the Particle IDE.
#include "AS1115.h"

AS1115 display;

void setup() {
    display.init();
    display.setDigit(0, 0, false);
    display.setDigit(1, 0, false);
    display.setDigit(2, 0, false);
}
int last_checked = 0;
void loop() {
    int now = millis();
    if(now-last_checked > 1000){
        int secs = now/1000;
        
        String Ssecs = String(secs);
        if(Ssecs.length() > 3) Ssecs = Ssecs.substring(Ssecs.length()-4);
        int offset = 3-Ssecs.length();
        
        display.setDigit(offset+0, (int)Ssecs.substring(0, 1).toInt(), false);
        if(offset < 2) display.setDigit(offset+1, (int)Ssecs.substring(1, 2).toInt(), false);
        if(!offset) display.setDigit(2, (int)Ssecs.substring(2).toInt(), false);
    }
}
