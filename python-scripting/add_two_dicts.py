log1 = {"timeout": 3, "auth_fail": 5, "crash": 1}
log2 = {"timeout": 2, "disk_full": 4, "auth_fail": 1}

# expected output:
# {"timeout": 5, "auth_fail": 6, "crash": 1, "disk_full": 4}


for key, value in log2.items():
    if key in log1:
        log1[key] += value
    else:
        log1[key] = value

print(log1)