import socket


def initiate():
    ip_address = input("Please enter the server IPv4 address: ").strip()
    port = int(input("Please enter the server port: "))
    address = (ip_address, port)

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.bind(address)

    return s


if __name__ == "__main__":
    s = initiate()

    s.listen()
    print(f"[STATUS] The server is listening on {s.getsockname()}")
