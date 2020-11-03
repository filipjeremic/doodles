from cryptography.fernet import Fernet


if __name__ == "__main__":
    with open("key", "bw") as key_file:
        key_file.write(Fernet.generate_key())
