from socket import socket
HOST = '172.18.104.158'     # Endereco IP do Servidor
PORT = 33333            # Porta que o Servidor esta
tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
dest = (HOST, PORT)
tcp.connect(dest)
respota = tcp.recv(4096)
print respota
tcp.close()

