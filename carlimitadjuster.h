// this stays at the default size, just used for a safe space to store the extra data at the end
auto gNewCarStatData = new uint8_t[0x430];

struct tUpgradeData1 {
	uint8_t _0[0xC];
};
tUpgradeData1* pNewUpgradeData1; // +6C

struct tUpgradeData2 {
	uint8_t _0[0x10];
};
tUpgradeData2* pNewUpgradeData2; // +66C

uintptr_t CalculateStatsASM_call = 0x453FC0;
uintptr_t CalculateStatsASM_jmp = 0x456909;
void __attribute__((naked)) CalculateStatsASM() {
	__asm__ (
		"mov ebx, %2\n\t"
		"call %0\n\t"
		"jmp %1\n\t"
			:
			:  "m" (CalculateStatsASM_call), "m" (CalculateStatsASM_jmp), "m" (gNewCarStatData)
	);
}

uintptr_t UpgradesWrite1ASM_jmp = 0x467212;
void __attribute__((naked)) UpgradesWrite1ASM() {
	__asm__ (
		"mov [esp+0x10], eax\n\t"
		"mov edi, %0\n\t"
		"add edi, 8\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData1), "m" (UpgradesWrite1ASM_jmp)
	);
}

uintptr_t UpgradesWrite2ASM_jmp = 0x46728C;
void __attribute__((naked)) UpgradesWrite2ASM() {
	__asm__ (
		"mov ebp, %0\n\t"
		"xor eax, eax\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData2), "m" (UpgradesWrite2ASM_jmp)
	);
}

uintptr_t UpgradesRead1ASM_jmp = 0x46833D;
void __attribute__((naked)) UpgradesRead1ASM() {
	__asm__ (
		"mov ebx, %0\n\t"
		"mov [esp+0x0C], edi\n\t"
		"mov [esp+0x6C], eax\n\t"
		"mov [esp+0x14], ebx\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData1), "m" (UpgradesRead1ASM_jmp)
	);
}

uintptr_t UpgradesRead2ASM_jmp = 0x46835F;
void __attribute__((naked)) UpgradesRead2ASM() {
	__asm__ (
			// back up esi, mov the new data in, read from that, restore
		"push esi\n\t"
		"mov esi, %0\n\t"
		"mov al, [ecx+esi]\n\t"
		"pop esi\n\t"
		"test al, dl\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData2), "m" (UpgradesRead2ASM_jmp)
	);
}

uintptr_t UpgradesRead3ASM_jmp = 0x46762D;
void __attribute__((naked)) UpgradesRead3ASM() {
	__asm__ (
		"mov eax, %0\n\t"
		"add eax, 4\n\t"
		"mov edx, 2\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData1), "m" (UpgradesRead3ASM_jmp)
	);
}

uintptr_t UpgradesRead4ASM_jmp = 0x46768A;
void __attribute__((naked)) UpgradesRead4ASM() {
	__asm__ (
		"add eax, %0\n\t"
		"test [ebx+eax], dl\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData2), "m" (UpgradesRead4ASM_jmp)
	);
}

uintptr_t UpgradesRead5ASM_jmp = 0x467708;
void __attribute__((naked)) UpgradesRead5ASM() {
	__asm__ (
		"add eax, %0\n\t"
		"test [ebx+eax], dl\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData2), "m" (UpgradesRead5ASM_jmp)
	);
}

uintptr_t UpgradesRead6ASM_jmp = 0x467783;
void __attribute__((naked)) UpgradesRead6ASM() {
	__asm__ (
		"add eax, %0\n\t"
		"test [ebx+eax], dl\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData2), "m" (UpgradesRead6ASM_jmp)
	);
}

uintptr_t UpgradesRead7ASM_jmp = 0x467800;
void __attribute__((naked)) UpgradesRead7ASM() {
	__asm__ (
		"add eax, %0\n\t"
		"test [ebx+eax], dl\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData2), "m" (UpgradesRead7ASM_jmp)
	);
}

uintptr_t UpgradesRead8ASM_jmp = 0x46815C;
void __attribute__((naked)) UpgradesRead8ASM() {
	__asm__ (
		"mov ecx, %0\n\t"
		"add ecx, 8\n\t"
		"mov [esp+0x10], edi\n\t"
		"mov [esp+0x24], ebp\n\t"
		"mov [esp+0x14], ecx\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData1), "m" (UpgradesRead8ASM_jmp)
	);
}

uintptr_t UpgradesRead9ASM_jmp = 0x46817E;
void __attribute__((naked)) UpgradesRead9ASM() {
	__asm__ (
		"push esi\n\t"
		"mov esi, %0\n\t"
		"mov cl, [esi+ebp]\n\t"
		"pop esi\n\t"
		"test cl, dl\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData2), "m" (UpgradesRead9ASM_jmp)
	);
}

uintptr_t UpgradesRead10ASM_jmp = 0x46636C;
void __attribute__((naked)) UpgradesRead10ASM() {
	__asm__ (
		"add     eax, %0\n\t"
		"mov     edx, 1\n\t"
		"shl     edx, cl\n\t"
		"shl     edi, 4\n\t"
		"test    [edi+eax], dl\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData2), "m" (UpgradesRead10ASM_jmp)
	);
}

uintptr_t UpgradesRead11ASM_jmp = 0x46739D;
void __attribute__((naked)) UpgradesRead11ASM() {
	__asm__ (
		"push esi\n\t"
		"mov esi, %0\n\t"
		"add esi, 8\n\t"
		"mov edi, [esi+eax*4]\n\t"
		"pop esi\n\t"
		"test edi, edi\n\t"
		"jmp %1\n\t"
			:
			:  "m" (pNewUpgradeData1), "m" (UpgradesRead11ASM_jmp)
	);
}

struct tCustomClass {
	int id[2];
	std::string name;
};
std::vector<tCustomClass> aCustomCarClasses;

uint32_t nCarClassId1;
uint32_t nCarClassId2;
void __fastcall FindCustomClassStrings(const char* string) {
	nCarClassId1 = 1;
	nCarClassId2 = 1;
	for (auto& carClass : aCustomCarClasses) {
		if (string == carClass.name) {
			nCarClassId1 = carClass.id[0];
			nCarClassId2 = carClass.id[1];
			return;
		}
	}
}

uintptr_t CustomClassesASM_string = 0x66D0E8;
uintptr_t CustomClassesASM_jmp = 0x466E2E;
void __attribute__((naked)) CustomClassesASM() {
	__asm__ (
		"pushad\n\t"
		"mov ecx, eax\n\t"
		"call %2\n\t"
		"popad\n\t"

		"mov ebx, %4\n\t"
		"mov dword ptr [esp+0x10], ebx\n\t"
		"mov ebx, %3\n\t"
		"mov edi, %0\n\t"
		"mov esi, eax\n\t"
		"mov ecx, 6\n\t"
		"jmp %1\n\t"
			:
			:  "m" (CustomClassesASM_string), "m" (CustomClassesASM_jmp), "i" (FindCustomClassStrings), "m" (nCarClassId1), "m" (nCarClassId2)
	);
}

uintptr_t CullModeASM_jmp = 0x5A6A72;
void __attribute__((naked)) CullModeASM() {
	__asm__ (
		"push eax\n\t"
		"mov eax, 0x8E56B4\n\t"
		"mov dword ptr [eax], 3\n\t"
		"pop eax\n\t"
		"jmp %0\n\t"
			:
			:  "m" (CullModeASM_jmp)
	);
}

void __fastcall LoadDevTexture(DevTexture* pTexture) {
	if (pTexture->pD3DTexture) return;

	auto path = pTexture->sPath;
	if (pTexture->nPathLength < 16) path = (char*)&pTexture->sPath;

	pDeviceD3d->CreateTextureFromFile(pTexture, path, pTexture->pSomePtr);
}

uintptr_t LoadMenuTexturesASM_jmp = 0x4A4FCE;
void __attribute__((naked)) LoadMenuTexturesASM() {
	__asm__ (
		"pushad\n\t"
		"mov ecx, eax\n\t"
		"call %1\n\t"
		"popad\n\t"

		"mov esi, [esp+0x1C]\n\t"
		"mov edx, [esp+0xB4]\n\t"
		"jmp %0\n\t"
			:
			:  "m" (LoadMenuTexturesASM_jmp), "i" (LoadDevTexture)
	);
}

// todo check if 4FDDEF ever reads the upgrades

struct tCarLimitAdjusterSettings {
	int nMaxCars = 260;
	bool bExtendUpgrades = true;
	bool bCustomClasses = false;
	bool bOverrideSharedTextures = true;
	bool bMenuCarLoadCustomTextures = true;
	int nMenuCarModelMemory = 524288;
	int nMenuCarSkinMemory = 2097152;
	int nLUAMemory = 0x900000;
} gCarLimitAdjusterSettings;

void InitCarLimitAdjuster() {
	auto& settings = gCarLimitAdjusterSettings;

	NyaHookLib::Patch(0x6500AE + 1, settings.nLUAMemory);

	NyaHookLib::Patch(0x4ABAD0 + 1, settings.nMenuCarModelMemory);
	NyaHookLib::Patch(0x4ABADB + 3, settings.nMenuCarModelMemory);
	NyaHookLib::Patch(0x4ABAEA + 1, settings.nMenuCarSkinMemory);
	NyaHookLib::Patch(0x4ABAEF + 3, settings.nMenuCarSkinMemory);

	// menucar backface culling fix
	NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x5A6A6C, &CullModeASM);

	pNewUpgradeData1 = new tUpgradeData1[settings.nMaxCars];
	pNewUpgradeData2 = new tUpgradeData2[settings.nMaxCars];
	memset(pNewUpgradeData1, 0, sizeof(tUpgradeData1) * settings.nMaxCars);
	memset(pNewUpgradeData2, 0, sizeof(tUpgradeData2) * settings.nMaxCars);

	// allocate more memory for more cars
	NyaHookLib::Patch(0x521103 + 1, 0x200 + (4 * settings.nMaxCars));

	NyaHookLib::Patch(0x4685F7 + 1, &gNewCarStatData);
	NyaHookLib::Patch(0x4687B4 + 1, &gNewCarStatData);
	NyaHookLib::Patch(0x46893C + 1, &gNewCarStatData);

	if (settings.bExtendUpgrades) {
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x456900, &CalculateStatsASM);

		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x467209, &UpgradesWrite1ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x467284, &UpgradesWrite2ASM);

		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x46832E, &UpgradesRead1ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x468356, &UpgradesRead2ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x467625, &UpgradesRead3ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x467681, &UpgradesRead4ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x4676FF, &UpgradesRead5ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x46777A, &UpgradesRead6ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x4677F7, &UpgradesRead7ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x46814D, &UpgradesRead8ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x468175, &UpgradesRead9ASM);

		// lua stuff
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x466359, &UpgradesRead10ASM);
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x467397, &UpgradesRead11ASM);

		// upgrade reader 128 checks
		//NyaHookLib::Patch(0x4683DB + 2, nMaxUpgrades);
		//NyaHookLib::Patch(0x468260 + 2, nMaxUpgrades);
		//NyaHookLib::Patch(0x46783A + 2, nMaxUpgrades);
	}

	if (settings.bCustomClasses) {
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x466E22, &CustomClassesASM);
	}

	if (settings.bOverrideSharedTextures) {
		// remove hardcoded shared path from lights_damaged
		static const char lightsDamagedPath[] = "lights_damaged.tga";
		NyaHookLib::Patch(0x42FCF3 + 1, lightsDamagedPath);

		// swap folder priorities
		NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x42FC8D, 0x54D860);
		NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x42FCA0, 0x54D7F0);
		NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x431B6D, 0x54D860);
		NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x431B75, 0x54D7F0);
	}

	if (settings.bMenuCarLoadCustomTextures) {
		NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x4A4FC3, &LoadMenuTexturesASM);
	}
}