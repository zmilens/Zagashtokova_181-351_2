#include "crypto.h"



crypto::crypto()
{
}


crypto::~crypto()
{
}

QByteArray crypto::encrypt(QByteArray message)
{
	//unsigned char plaintext[1024];
	/*char cryptedtext[1024]; 
	//char text[1024];
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, // ������ �� ������/���������, ���� ��������� ���������
		EVP_aes_256_cbc(), // ������ �� ��������� ���� AES 256 (������� � ����������)
		NULL,
		key, // ����/������/������
		iv); // ����������� (��������� ��������� ������)
	int len = 0;
	int crypt_len = 0;
	
	//strcpy_s(text, message.data());
	int plaintext_len = strlen(message.data());
		EVP_EncryptUpdate(ctx, // ������ � �����������
			(unsigned char*)cryptedtext, // ������� ��������: ������, ���� �������� ������������� ������
			&len, // �������� ��������: ����� ����������� �����
			(unsigned char*)message.constData(), // ������� ��������: ��� ���������
			plaintext_len); // ������� �������� : ����� ������� ������
		crypt_len = len;
		
	
	// 5. ����������� �������� ����������
	// ����������, ���� ��������� ���� �������� ������� �� ���������

	EVP_EncryptFinal_ex(ctx, (unsigned char*)cryptedtext, &len);
	crypt_len += len;
	/*str_mes.clear();
	str_mes.append(cryptedtext);*/
	
	//arr.append(cryptedtext, crypt_len);
	
	//cryptedtext_len += len;

	// 6. �������� ���������
	//EVP_CIPHER_CTX_free(ctx);
	QByteArray arr;
	TinyAES aes;
	arr = aes.Encrypt(message, password);

	return arr;
}

QByteArray crypto::decrypt(QByteArray message)
{
	/*char plaintext[1024];
	char decryptedtext[1024]; 
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new();
	int len;
	int decrypt_len;
	
	//strcpy_s(plaintext, message.data());
	int cryptedtext_len = strlen(message.data());

	
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); 
	
	
	
		
	EVP_DecryptUpdate(ctx, (unsigned char* )decryptedtext, &len, (unsigned char*)message.constData(), cryptedtext_len);  // ����������, ����������
	decrypt_len = len;
		

	
	// 4.

	EVP_DecryptFinal_ex(ctx, (unsigned char*)decryptedtext, &len);
	decrypt_len += len;
	
	/*str_mes.clear();
	str_mes.append(decryptedtext);
	message = QString::fromStdString(str_mes);*/
	
	//arr.append(decryptedtext, decrypt_len);
	// 5.
	
	//EVP_CIPHER_CTX_free(ctx);
	QByteArray arr;
	TinyAES aes;
	arr = aes.Decrypt(message, password);

	return arr;
}
