import coder
import huffman

import sender

with open("files/huffman_frequency.txt", 'r', encoding="utf-8") as file:
    codes_dictionary = ''.join(file.readlines())
codes = huffman.get_codes_for_characters_in_message(codes_dictionary)


with open("files/pasta.txt", 'r', encoding="utf-8") as file_message:
    input_list = file_message.readlines()
input_string = ''.join(input_list)

codes_list = []
for line_string in input_list:
    for character in line_string:
        print("'", character, "'", sep='', end='\t')
        code_string = coder.code_symbol(character, codes)
        print(code_string)
        codes_list.append(code_string)
coded_string = ''.join(codes_list)
print(coded_string)

sender.send_string(coded_string)
