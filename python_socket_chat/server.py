from common import read_server_address
import socket


if __name__ == "__main__":
    server_address = read_server_address()
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(server_address)
    server_socket.listen()
    print(
        f"[STATUS] The server is listening on {server_socket.getsockname()[0]}:{server_socket.getsockname()[1]}")

    #client_socket, client_address = server_socket.accept()
    # print(client_socket)
    # print(client_address)
