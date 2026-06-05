

## open a file and read its contents
with open("log.txt", "r") as f:
    lines = f.readlines()
    
    
status_codes = {}
error_codes = []
for line in lines:
    parts = line.split()
    if parts:
        status = parts[0]
        if status == "FAIL":
            error_code = parts[1]
            error_codes.append(error_code)
            status_codes[status] = error_codes
        
        elif status == "PASS" and status in status_codes:
            status_codes[status] += 1
        else:
            status_codes[status] = 1


list_of_errors = status_codes.get("FAIL", [])
max_count = 0
most_freq_error = None
for error in list_of_errors:
    if list_of_errors.count(error) > max_count:
        max_count = list_of_errors.count(error)
        most_freq_error = error
print(f"Most frequent error code: {most_freq_error} with count: {max_count}")
    

print(status_codes)


