#include <lua.h>
#include <lauxlib.h> // luaL_error

static int luamod_add(lua_State* L)
{
	lua_pushinteger(L, lua_tointeger(L, 1) + lua_tointeger(L, 2));
	return 1;
}

static int luamod_error(lua_State* L)
{
	luaL_error(L, lua_tostring(L, 1));
}

__declspec(dllexport) extern "C" int luaopen_luamod(lua_State* L)
{
	lua_newtable(L);

	lua_pushstring(L, "add");
	lua_pushcfunction(L, &luamod_add);
	lua_settable(L, -3);

	lua_pushstring(L, "error");
	lua_pushcfunction(L, &luamod_error);
	lua_settable(L, -3);

	return 1;
}
