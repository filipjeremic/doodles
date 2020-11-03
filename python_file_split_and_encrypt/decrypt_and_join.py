import sys
from cryptography.fernet import Fernet


def get_key():
    with open("key", "br") as key_file:
        return key_file.read()


def decrypt_and_join(file_name):
    with open(file_name, "bw") as out_file:
        dec = Fernet(get_key())
        i = 0

        while True:
            try:
                with open(file_name + "_part_" + str(i), "br") as in_file:
                    out_file.write(dec.decrypt(in_file.read()))
            except:
                break

            i += 1


if __name__ == "__main__":
    decrypt_and_join(sys.argv[1])
