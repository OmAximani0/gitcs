import socket

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
addr = ("localhost", 12345)
while True:
    msg = input("Enter a message: ")
    client.sendto(msg.encode(), addr)
    if msg == "STOP":
        client.close()
        break
