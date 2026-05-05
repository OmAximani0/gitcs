import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
saddr = ('localhost', 12345)
client.connect(saddr)

while True:
    message = input("Enter the message('quit' to exit): ")
    if message == "quit":
        client.close()
        break
    try:
        client.sendall(message.encode())
    except Exception as e:
        print("Closing: ", e)
        client.close()
