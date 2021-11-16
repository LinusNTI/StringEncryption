#pragma once
#include <string>

using namespace std;

class EncryptedString
{
public:
	EncryptedString(string text);

	string Decrypt();
	string GetEncrypted();

	static EncryptedString FromEncrypted(string text);

	inline operator string() {
		return InternalDecrypt(_data);
	}

private:
	inline string InternalEncrypt(string text);
	inline string InternalDecrypt(string encrypted);

	inline int StringChecksum(const char* str);
	inline int StringChecksum(string str);

	string _data;
};

