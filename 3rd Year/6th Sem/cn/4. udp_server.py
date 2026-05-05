import socket

serv = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
addr = ("localhost", 12345)
serv.bind(addr)
while True:
    data, client = serv.recvfrom(1024)
    print(f"Received message {data.decode()} from {client}")
    if data == "STOP":
        serv.close()
        break
