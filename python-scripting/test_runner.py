#Create a TestSuite class that:
#- Stores a list of test names
#- Has an add_test(name) method
#- Has a run_all() method that prints each test name and returns a count

# You can simulate each test always passing for now.

class TestSuite:
    def __init__(self):
        self.test_names = []
    
    def add_test(self,name):
        self.test_names.append(name)

    def run_all(self):
        for test in self.test_names:
            print(f"Runing (test).. Passed!")
        return len(self.test_names)
    
suite = TestSuite()
suite.add_test("test1")
suite.add_test("test2")


count = suite.run_all()
print(f"\nTotal tests run:{count}")
