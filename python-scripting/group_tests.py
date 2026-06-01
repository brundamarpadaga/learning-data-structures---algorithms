#Group test results by status

#Given a list of test result dicts, group them into "pass" and "fail" lists.

results = [
  {"name": "test_dma", "status": "pass"},
  {"name": "test_pcie", "status": "fail"},
  {"name": "test_mem", "status": "pass"},
  {"name": "test_irq", "status": "fail"},
]

def group_test_results(results):
    passed = []
    failed = []
    for result in results:
        if result.get("status") == "pass":
            passed.append(result)
        else:
            failed.append(result)
    return {"passed": passed, "failed": failed}

print(group_test_results(results))

