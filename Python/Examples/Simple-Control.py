# import the smbus library for i2c communications
import smbus
# time is not a required module
import time
# import the board library
import as1115

# instantiate the i2c bus
bus = smbus.SMBus(1)

# define the settings to use for this board in kwargs. Refer the the datasheet for this device to learn more about these settings.
kwargs = {'address': 0x00, 'mode': 0x01, 'feature_shutdown': 0x00, 'font': 0x04}

# instantiate the board using the library and pass it the i2c bus and the arguments define above
board = as1115.AS1115(bus, kwargs)
# set instensity of the lights to full bright
board.set_intensity(255)
# Enable test mode
board.test_mode(True)
time.sleep(1)
# Disable Test Mode
board.test_mode(False)
# Set intensity to lowest setting
board.set_intensity(0)

# Set the far left digit to 1
board.set_digit(0, 1, False)
# Set the middle digit to 2
board.set_digit(1, 2, False)
# Set the far right digit to 3
board.set_digit(2, 3, False)
