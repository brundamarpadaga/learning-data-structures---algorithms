logs = [
    ("device_A", 80),
    ("device_B", 1),
    ("device_A", 1),
    ("device_A", 80),
    ("device_B", 80),
    ("device_A", 1),
]

# expected output:
# {
#   "device_A": {80: 2, 1: 2},
#   "device_B": {1: 1, 80: 1}
# }

device_errors = {}
for device,error in logs:
    if device in device_errors:
        errors = device_errors[device]
    else:
        errors = {}

    if error in errors:
        errors[error]+=1
    else:
        errors[error] = 1
    device_errors[device] = errors

print(device_errors)
    
    
    