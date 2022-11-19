import socket
import select
import sys
import errno

IP = "127.0.0.1"
PORT = 1234

HEADER_LENGTH = 10
client_username = input("Username: ")

client_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM) #AW_INET - ipv4, SOCK_STREAM - TCP
client_socket.connect((IP, PORT)) #polaczenie do socketu
client_socket.setblocking(False) 

username = client_username.encode('utf-8')
username_header = f"{len(username):<{HEADER_LENGTH}}".encode('utf-8')
client_socket.send(username_header + username)


while True:

    message = input(f'{client_username} > ')

    if message:
        message = message.encode('utf-8')
        message_header = f"{len(message):<{HEADER_LENGTH}}".encode('utf-8')
        client_socket.send(message_header + message)

    try:
        username_header = client_socket.recv(HEADER_LENGTH)
        if not len(username_header):
            print('Connection closed by the server')
            sys.exit()

        username_length = int(username_header.decode('utf-8').strip())
        username = client_socket.recv(username_length).decode('utf-8')
        message_header = client_socket.recv(HEADER_LENGTH)
        message_length = int(message_header.decode('utf-8').strip())
        message = client_socket.recv(message_length).decode('utf-8')

        print(f'{username} > {message}')
    
    except IOError as e: #brak przychodzacych wiadomosci
        if e.errno != errno.EAGAIN and e.errno != errno.EWOULDBLOCK:
            print('Reading error: {}'.format(str(e)))
            sys.exit()
        continue
