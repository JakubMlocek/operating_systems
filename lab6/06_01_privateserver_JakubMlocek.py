import socket
import select
import rsa
import os

IP = "127.0.0.1"
PORT = 4201
HEADER_LENGTH = 10


server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM) #AW_INET - ipv4, SOCK_STREAM - TCP
server_socket.bind((IP, PORT)) #rezerwowanie socketu
server_socket.listen() 
clients = {}
socket_list = [server_socket]


pub_key, priv_key = rsa.newkeys(1024)
a = priv_key.save_pkcs1('PEM')
a2 = pub_key.save_pkcs1('PEM')
server_priv_key = rsa.PrivateKey.load_pkcs1(a)
server_pub_key = rsa.PublicKey.load_pkcs1(a2)
os.system("rm -rf *.txt")
os.system("touch pub_key.txt")
file = open("pub_key.txt", 'w')
file.write(str(server_pub_key))
file.close()


print(f'Waitin {IP}:{PORT}...')

def recieving_message(client_socket):
    try:
        message_header = client_socket.recv(HEADER_LENGTH)
        message_length = int(message_header.decode('utf-8').strip())
        return {'header': message_header, 'data': client_socket.recv(message_length)}
    except:
        return False

while True:
    read_sockets, _, _ = select.select(socket_list, [], [])

    for notified_socket in read_sockets:
        if notified_socket == server_socket: #nowe polaczenie
            for notified_socket in read_sockets:
                client_socket, client_addres = server_socket.accept()
                user = recieving_message(client_socket) 
                socket_list.append(client_socket)
                clients[client_socket] = user
                print('Nowe polaczenie: {}'.format(user['data'].decode('utf-8')))
        
        else: #wiadomosc od istniejacego polaczenia
            message = recieving_message(notified_socket)
            user = clients[notified_socket]

            message["data"] = rsa.decrypt(message["data"], server_priv_key)
            
            print(f'{user["data"].decode("utf-8")}: {message["data"].decode("utf-8")}')

            for client_socket in clients:
                if client_socket != notified_socket:
                    client_socket.send(user['header'] + user['data'] + message['header'] + message['data'])

