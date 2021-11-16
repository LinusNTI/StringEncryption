#include "EncryptedString.h"

EncryptedString::EncryptedString(string text)
{
	_data = InternalEncrypt(text);
}

string EncryptedString::Decrypt()
{
	return InternalDecrypt(_data);
}

string EncryptedString::GetEncrypted()
{
	return _data;
}

EncryptedString EncryptedString::FromEncrypted(string text)
{
	auto outEnc = EncryptedString("");
	outEnc._data = text;
	return outEnc;
}

inline string EncryptedString::InternalEncrypt(string text)
{
	char* ptr_cText = (char*)text.c_str();

	srand(text.size());
	for (size_t i = 0; i < text.size(); i++) {
		ptr_cText[i] = ptr_cText[i] + (rand() % StringChecksum(__TIME__));
	}
	
	return string(ptr_cText, text.size());
}

inline string EncryptedString::InternalDecrypt(string encrypted)
{
	char* ptr_cEncrypted = (char*)encrypted.c_str();

	srand(strlen(ptr_cEncrypted));
	for (size_t i = 0; i < strlen(ptr_cEncrypted); i++) {
		ptr_cEncrypted[i] = ptr_cEncrypted[i] - (rand() % StringChecksum(__TIME__));
	}

	return string(ptr_cEncrypted, strlen(ptr_cEncrypted));
}

inline int EncryptedString::StringChecksum(const char* str) {
	int checksum = 0;
	for (size_t i = 0; i < strlen(str); i++) {
		checksum += str[i];
	}
	return checksum;
}

inline int EncryptedString::StringChecksum(string str) {
	return StringChecksum(str.c_str());
}
