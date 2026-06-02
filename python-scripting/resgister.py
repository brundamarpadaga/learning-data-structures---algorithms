#Create a Register class that holds a name, an address, and a value 
#(defaulting to 0).
#Give it a write(new_value) method and a read() method.
#Create a Device class that manages multiple registers.

class register:
    address = 0
    def __init__(self, name, address):
        self.name = name
        self.address = address
        self.value = 0

    def write(self,value):
        self.value = value
        
        
    def read(self):
        return self.value   


class Device:
    def __init__(self):
        self.registers = {}
        pass

    def add_register(self, name, address):
        self.registers[name] = register(name, address)
        pass

    def write_register(self, name, value):
        self.registers[name].write(value)
        pass

    def read_register(self, name):
        return self.registers[name].read()
    
device = Device()
device.add_register("reg1", 0x01)
device.write_register("reg1", 42)
print(device.read_register("reg1"))

print(device.registers["reg1"].name
      , hex(device.registers["reg1"].address)
      , device.registers["reg1"].value)


    