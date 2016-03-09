import socket

UDP_IP = "HappyHatch.byod.gmu.edu" #IP of device to send to
UDP_PORT = 5005

print "UDP target IP:", UDP_IP
print "UDP target port:", UDP_PORT

while(1):
	dir = raw_input('Choose Direction (w,a,s,d) :')

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

	sock.sendto(dir, (UDP_IP, UDP_PORT))
	
	# r = sock.recvfrom(1024)
	# reply = data[0]
	# print "Now traveleing:", reply
