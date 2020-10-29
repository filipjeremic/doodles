from common import read_server_address


if __name__ == "__main__":
    server_address = read_server_address()
    print(
        f"[STATUS] Trying to connect to {server_address[0]}:{server_address[1]}")
