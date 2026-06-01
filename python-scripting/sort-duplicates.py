# Write a function that takes a list of register addresses and returns any duplicates.

addresses = [0x100, 0x200, 0x100, 0x300, 0x200, 0x400]

def return_duplicates(addresses):
    duplicates = set()
    seen = set()
    for address in addresses:
        if( address in seen):
            duplicates.add(address)
        else:
            seen.add(address)
    return duplicates

duplicates = return_duplicates(addresses)
print( [hex(addr) for addr in duplicates])

