

## open a file and read its contents
with open("log.txt", "r") as f:
    lines = f.readlines()
    
    
status_codes = {}
error_codes = {}
for line in lines:
    parts = line.split()
    if parts:
        status = parts[0]
        if status == "FAIL":
            error_code = parts[1]
            if error_code in error_codes:
                error_codes[error_code] += 1
            else:
                error_codes[error_code] = 1
            
            status_codes[status] = error_codes
        
        elif status == "PASS" and status in status_codes:
            status_codes[status] += 1
        else:
            status_codes[status] = 1


max_count = 0
most_freq_error = None

for error_code, count in error_codes.items():
    if count > max_count:
        max_count = count
        most_freq_error = error_code
    

print(status_codes)
print(f"The most frequent error code is: {most_freq_error} with {max_count} occurrences.")


