logs = [
    ("PASS", None),
    ("FAIL", 80),
    ("FAIL", 1),
    ("PASS", None),
    ("FAIL", 80),
    ("FAIL", 28),
]

# expected output:
# {
#   "PASS": ["OK", "OK"],
#   "FAIL": [80, 1, 80, 28]
# }

# dict = {}

# for log in logs:
#     if log[0] in dict:
#         if log[0] == "PASS":
#             dict[log[0]].append("OK")
#         else:
#             dict[log[0]].append(log[1])
#     else:       
#         if log[0] == "PASS":
#             lst = []
#             lst.append("OK")
            
#         elif log[0] == "FAIL":
#             lst = []
#             lst.append(log[1])

#         dict[log[0]] = lst

# print(dict)
grouped_logs = {}
for key,value in logs:
    item_to_add = "OK" if key == "PASS" else value
    grouped_logs.setdefault(key,[]).append(item_to_add)
print(grouped_logs)
