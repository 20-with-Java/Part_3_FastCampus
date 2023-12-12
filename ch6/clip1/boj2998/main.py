def o2d(binary):
    octal = [
        "000", "001", "010",
        "011", "100", "101",
        "110", "111"
    ]
    for i in range(8):
        if binary == octal[i]:
            return i
    return -1

def change(binary):
    length = len(binary)
    if length == 0:
        return

    change(binary[:-3])
    d = o2d(binary[-3:])
    print(d, end="")

binary = input()
if len(binary) % 3 == 1:
    binary = "00" + binary
elif len(binary) % 3 == 2:
    binary = "0" + binary

change(binary)
