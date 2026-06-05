#Given a list of error messages, return the most frequently occurring one.

errors = ["timeout", "mismatch", "timeout","overflow", "timeout", "mismatch"]

#Expected output: "timeout"

def freq_error(errors):
    error_count = {}
    max_count = 0
    for error in errors:
        if error in error_count:
            error_count[error] += 1
        else:
            error_count[error] = 1

        if(error_count[error] > max_count):
            max_count = error_count[error]
            most_freq_error = error
    return most_freq_error

print(freq_error(errors))
    
