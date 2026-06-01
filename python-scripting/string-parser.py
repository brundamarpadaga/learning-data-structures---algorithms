#Parse a config string of key=value pairs (space-separated) into a dictionary.

config = "freq=1200 voltage=0.85 mode=turbo width=256"

#Expected output: {'freq': '1200', 'voltage': '0.85', 'mode': 'turbo', 'width': '256'}

def parse_config(config):
    elements = config.split()
    result_dict = {}
    for element in elements:
        key, value = element.split("=")
        result_dict[key] = value
    return result_dict    

print(parse_config(config))