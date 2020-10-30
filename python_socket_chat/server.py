from common import read_server_address
import socket


if __name__ == "__main__":
    server_address = read_server_address()
    read_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    read_socket.bind(server_address)
    read_socket.listen()
    print(
        f"[STATUS] The server is listening on {read_socket.getsockname()[0]}:{read_socket.getsockname()[1]}")

    # write_socket, client_address = read_socket.accept()
    # print(client_socket)
    # print(client_address)
