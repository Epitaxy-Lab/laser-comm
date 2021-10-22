from ncd2chchurrent import *

### Temperatures in Celsius
MIN_TEMP = 200 
MAX_TEMP = 2200 

### Possible Current Values 
MIN_CURR = 4
MAX_CURR = 20

reader = CurrentSensor()

def read_temp(CS): 
    '''
    Takes in a current sensor object, and returns the pyrometer temperature reading
    '''
    c = reader.read_channel(0)
    return MIN_TEMP + (c - MIN_CURR)*(MAX_TEMP - MIN_TEMP)/(MAX_CURR - MIN_CURR)

