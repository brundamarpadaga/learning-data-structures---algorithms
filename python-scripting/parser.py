# Given a list of log lines, write a function that returns the count of lines containing "ERROR".

lines = [
  "INFO: Test started",
  "ERROR: Register mismatch at 0x100",
  "INFO: Read complete",
  "ERROR: Timeout on PCIe link",
  "INFO: Test done"
  "ERROR: Memory leak detected"
] 


def count_error_lines(log_lines):
    error_count = 0
    for line in lines:
        if "ERROR" in line:
            error_count += 1
    return error_count

print(count_error_lines(lines))