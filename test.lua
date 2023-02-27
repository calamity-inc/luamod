local luamod = require("luamod")
print(luamod.add(1, 2)) -- 3
print(table.pack(pcall(luamod.error, "Hello"))[2]) -- Hello
