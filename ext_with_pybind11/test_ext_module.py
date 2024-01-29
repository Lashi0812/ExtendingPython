import ext_module

print(f"Adding the 2 + 3 = {ext_module.add(2,3)}")
human = ext_module.Human("test")
print(f"Hi , my name is {human.name}")
print(f"Hi , my name is {human.getName()}")
human.setName("Changed")
print("Changing the name to changed")
print(f"Hi , my name is {human.name}")
print(f"Hi , my name is {human.getName()}")
