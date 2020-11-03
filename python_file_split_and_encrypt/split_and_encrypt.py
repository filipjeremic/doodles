import sys
from cryptography.fernet import Fernet


def get_key():
    with open("key", "br") as key_file:
        return key_file.read()


def split_and_encrypt(file_name, part_size):
    with open(file_name, "br") as in_file:
        key = get_key()
        enc = Fernet(key)

        i = 0

        while True:
            data = in_file.read(part_size)
            data_len = len(data)
            if data_len == 0:
                break

            with open(file_name + "_part_" + str(i), "bw") as out_file:
                data = enc.encrypt(data)
                out_file.write(data)

            i += 1


if __name__ == "__main__":
    split_and_encrypt(sys.argv[1], int(sys.argv[2]))
