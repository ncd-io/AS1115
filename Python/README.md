# About

This Library is intended for use with any AS1115 board available from ncd.io

### Developer information
NCD has been designing and manufacturing computer control products since 1995.  We have specialized in hardware design and manufacturing of Relay controllers for 20 years.  We pride ourselves as being the industry leader of computer control relay products.  Our products are proven reliable and we are very excited to support Particle.  For more information on NCD please visit ncd.io

### Requirements
- The Python SMBus Module: https://pypi.python.org/pypi/smbus-cffi/
- An I2C connection to an AS1115 Chip
- Knowledge base for developing and programming with Python

### Version
1.0.0

### How to use this library

The libary must be imported into your application. Once it is imported you can create an MCP23008 object and start to communicate to the chip.

When you create an instance of the MCP23008 object be sure to pass it the I2C bus and an array that contains which channels you want to configure as inputs.

The default values for these options are as follows:
{'address': 0x00, 'mode': 0x01, 'feature_shutdown': 0x00, 'font': 0x04}

### Publicly accessible methods
```cpp
set_intensity(intensity)
```
>This function accepts an integer from 0-255. Lower values will make the readout dimmer. Higher values will make the readout brighter.


```cpp
set_digit(digit, value, decimal_point)
```
>This function takes the digit at the index provided, changes it to the value provided, and adds a decimal point if passed a True for decimal_point


```cpp
set_digit(target_gpio)
```
>This method will toggle the given GPIO. If the GPIO is high then it will be set low. If it is low then it will be set high.
>The argument passed is an ingteger from 0-7 with 0 being the first GPIO on the chain.


```cpp
test_mode(onoff)
```
>This function just turns all the digits to 8 and accepts True or False to turn it on and off.
