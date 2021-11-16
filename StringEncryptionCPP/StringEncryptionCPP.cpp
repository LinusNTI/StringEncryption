#include <Windows.h>
#include <conio.h>
#include <iostream>

#include "Classes/EncryptedString.h"

using namespace std;

int main()
{
    bool hasWritten = false;
    bool bIsRunning = true;
    
    while (bIsRunning) {
        if (!hasWritten) {
            cout << "[1] Encrypt strings" << endl << "[2] Decrypt strings" << endl;
            hasWritten = true;
        }
        int get = _getch();
        if (get == '1') {
            system("cls");
            string input;
            cout << "Please enter a string to encrypt:" << endl;
            getline(cin, input);
            EncryptedString enc(input);
            auto encryptedData = enc.GetEncrypted();
            std::cout << "Encrypted: \"" << encryptedData.c_str() << "\"" << std::endl;

            bool didFail = false;

            if (!OpenClipboard(GetConsoleWindow()))
                didFail = true;
            if (!didFail && !EmptyClipboard())
                didFail = true;

            if (!didFail) {
                auto memAddr = GlobalAlloc(GMEM_MOVEABLE,
                    (encryptedData.size() + 1) * sizeof(TCHAR));

                if (memAddr == NULL) {
                    CloseClipboard();
                    didFail = true;
                }

                if (!didFail) {
                    auto strData = encryptedData.c_str();
                    char* copyAddr = (char*)GlobalLock(memAddr);
                    memcpy(copyAddr, strData,
                        encryptedData.size() * sizeof(char));
                    copyAddr[encryptedData.size()] = 0;
                    GlobalUnlock(memAddr);

                    SetClipboardData(CF_OEMTEXT, memAddr);

                    GlobalFree(memAddr);
                    CloseClipboard();

                    cout << "Copied text to clipboard!" << endl;
                }
            }
            else
                cout << "Unable to copy data to the clipboard" << endl;

            system("pause");
            system("cls");

            hasWritten = false;
        } else if (get == '2') {
            system("cls");
            string input;
            cout << "Please enter a string to decrypt:" << endl;
            getline(cin, input);
            EncryptedString enc = EncryptedString::FromEncrypted(input);
            std::cout << "Decrypted: " << enc.Decrypt() << std::endl;

            system("pause");
            system("cls");

            hasWritten = false;
        }
    }
}
