import socket


def init():
    ip_address = input("Please enter the server IPv4 address: ").strip()
    port = int(input("Please enter the server port: "))
    address = (ip_address, port)

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(address)

    return s


if __name__ == "__main__":
    server_socket = init()

    server_socket.listen()
    print(f"[STATUS] The server is listening on {server_socket.getsockname()}")
