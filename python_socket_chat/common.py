def read_server_address():
    ip_address = input("Please enter the server IPv4 address: ").strip()
    port = int(input("Please enter the server port: "))
    return (ip_address, port)
