import serial 
from datetime import datetime

sensor = "TEMP"
serial_port = '/dev/ttyACM0'
baud_rate = 9600
path = "output/{0}_LOG_{1}.txt".format(str(datetime.now()), sensor)
ser = serial.Serial(serial_port, baud_rate)
with open(path, 'w+') as f:
	while True:
		line = ser.readline().decode("utf-8")        
		print("{0} - {1}".format(datetime.now(), line))
		f.writelines('{0} - {1}'.format(datetime.now(), line))        