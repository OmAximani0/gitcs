import socket

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
saddr = ("localhost", 12345)
server_socket.bind(saddr)
server_socket.listen(5)

client = None
caddr = None
while True:
    if not client:
        client, caddr = server_socket.accept()
    print(f"Connect to {caddr}")
    try:
        data = client.recv(1024)
        if data:
            print(f"Received Data: {data.decode()}")
    except Exception as e:
        print(f"Error {e}")
        client.close()
        break
server_socket.close()
