from common import read_server_address
import socket


if __name__ == "__main__":
    server_address = read_server_address()
    print(
        f"[STATUS] Trying to connect to {server_address[0]}:{server_address[1]}")

    my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    my_socket.connect(server_address)
    server_address = my_socket.getpeername()
    print(
        f"[STATUS] Successfully connected to {server_address[0]}:{server_address[1]}")
