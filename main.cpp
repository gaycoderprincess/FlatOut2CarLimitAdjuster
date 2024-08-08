#include <windows.h>
#include <vector>
#include "toml++/toml.hpp"
#include "nya_commonhooklib.h"
#include "carlimitadjuster.h"

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
	switch( fdwReason ) {
		case DLL_PROCESS_ATTACH: {
			if (NyaHookLib::GetEntryPoint() != 0x202638) {
				MessageBoxA(nullptr, "Unsupported game version! Make sure you're using DRM-free v1.2 (.exe size of 2990080 bytes)", "nya?!~", MB_ICONERROR);
				exit(0);
				return TRUE;
			}

			auto config = toml::parse_file("FlatOut2CarLimitAdjuster_gcp.toml");
			gCarLimitAdjusterSettings.nMaxCars = config["main"]["max_cars"].value_or(260);
			gCarLimitAdjusterSettings.bExtendUpgrades = config["main"]["extend_upgrades"].value_or(true);
			gCarLimitAdjusterSettings.bCustomClasses = config["main"]["custom_classes"].value_or(false);
			gCarLimitAdjusterSettings.bOverrideSharedTextures = config["main"]["override_shared_textures"].value_or(true);
			gCarLimitAdjusterSettings.bMenuCarLoadCustomTextures = config["main"]["menucar_load_custom_textures"].value_or(true);
			gCarLimitAdjusterSettings.nMenuCarModelMemory = config["main"]["menucar_max_model_size"].value_or(524288);
			gCarLimitAdjusterSettings.nMenuCarSkinMemory = config["main"]["menucar_max_skin_size"].value_or(2097152);
			gCarLimitAdjusterSettings.nLUAMemory = config["main"]["lua_memory_pool_size"].value_or(0x900000);
			if (gCarLimitAdjusterSettings.bCustomClasses) {
				auto arr = config["main"]["custom_class_names"].as_array();
				int i = 4; // derby is 1, race is 2, street is 3, custom classes will start at 4
				for (auto &data: *arr) {
					aCustomCarClasses.push_back({i, i++, data.as_string()->get()});
				}
			}

			InitCarLimitAdjuster();
		} break;
		default:
			break;
	}
	return TRUE;
}