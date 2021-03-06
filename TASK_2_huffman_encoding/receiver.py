from datetime import datetime
from socket import AF_INET, SOCK_DGRAM, socket

import coder
import huffman


s = socket(AF_INET, SOCK_DGRAM)
s.bind(("IP HERE", 69))
received_data = ""

buffer = bytearray(512)

begin_time = datetime.now()

i = 0
while True:
    print(len(buffer))
    client_address = s.recvfrom_into(buffer)
    client_data = buffer.decode('utf-8')

    if client_data[0:3] == "END":
        print("check_1")
        break

    if client_data[0:5] == "SIZE=":
        print("check_2")
        print(client_data[5:8])
        buffer = bytearray(int(client_data[5:8]))
    else:
        received_data += client_data
    print("START-", client_data, "-END\n", sep='')


print(received_data)

with open("files/huffman_frequency.txt", 'r', encoding="utf-8") as file:
    codes_dictionary = ''.join(file.readlines())
codes = huffman.get_codes_for_characters_in_message(codes_dictionary)


decoded = coder.decode_binary(received_data, codes)
print(decoded)
