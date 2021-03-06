// STRING_CHAR.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void CharBase();
void XroTest();
void caesarEncrypt();
void caesarDecrypt();
void xorEncrypt();
void xorDecrypt();

int _tmain(int argc, _TCHAR* argv[])
{
	//CharBase();
	//caesarEncrypt();
	//caesarDecrypt();
	//XroTest();
	xorEncrypt();
	xorDecrypt();
	return 0;
}

void CharBase()
{
	{
		int c1 = 'a';
		int c2 = 'a' + 4;
		cout << "c1:\t" << c1 << endl;
		cout << "c2:\t" << c2 << endl;
	}


	{
		char str[] = "JulyEdu";
		printf("%d\n", sizeof(char));
		printf("%d\n", sizeof(str));
		printf("%d\n", strlen(str));
	}

	{
		char str[] = "Julyedu";
		str[4] = 'a';
		str[5] = 'p';
		str[6] = 'p';
		printf("%s\n", str);
	}

	{
		//错误
		char* str = "JulyEdu";
		str[4] = 'a';
	}

	{
		//字符串常量，这样写诗对的
		const char* str = "JulyEdu";
		//编译器报错
		//str[4] = 'a';
	}

	{
	char* str = new char[8];
	strcpy(str, "JulyEdu");
	printf("%s\n", str);

	str[4] = 'a';
	str[5] = 'p';
	str[6] = 'p';
	printf("%s\n", str);
	printf("%d\n", sizeof(str));
	printf("%d\n", strlen(str));

	delete[] str;
	}

	{
		char str[100] = "JulyEdu";
		printf("%d\n", strlen(str));
		printf("%d\n", sizeof(str));
	}
}

void XroTest()
{
	char a = 'a';
	char b = 'b';

	char c = a ^ b;

	printf("\n%02x", a);
	printf("\n%02x", b);
	printf("\n%02x", c);
	printf("\n%d\n", c);
}

void caesarEncrypt()
{
	FILE* pFile = fopen("D:\\GitHub\\JULY\\AlgorithmTest\\bigger.txt", "rb");
	fseek(pFile, 0, SEEK_END);
	int nFileLen = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	char* str = new char[nFileLen + 1];
	fread(str, nFileLen, 1, pFile);
	fclose(pFile);
	str[nFileLen] = 0;

	int nCaesar = 3;
	int n = 0;
	for (int i = 0; i < nFileLen;i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			str[i] += nCaesar;
			if (str[i] > 'z')
			{
				str[i] -= 26;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += nCaesar;
			if (str[i] > 'Z')
			{
				str[i] -= 26;
			}
		}
		else if (str[i] == '\n')
		{
			n++;
		}
	}

	FILE* pFile2 = fopen("D:\\GitHub\\JULY\\AlgorithmTest\\bigger_caesarEncrypt.txt", "wb");
	fwrite(str, nFileLen - n, 1, pFile2);
	fclose(pFile2);

	delete[] str;
}

void caesarDecrypt()
{
	FILE* pFile = fopen("D:\\GitHub\\JULY\\AlgorithmTest\\bigger_caesarEncrypt.txt", "rb");
	fseek(pFile, 0, SEEK_END);
	int nFileLen = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	char* str = new char[nFileLen + 1];
	fread(str, nFileLen, 1, pFile);
	fclose(pFile);
	str[nFileLen] = 0;

	int nCaesar = -3;
	int n = 0;
	for (int i = 0; i < nFileLen;i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			str[i] += nCaesar;
			if (str[i] > 'z')
			{
				str[i] -= 26;
			}
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += nCaesar;
			if (str[i] > 'Z')
			{
				str[i] -= 26;
			}
		}
		else if (str[i] == '\n')
		{
			n++;
		}
	}

	FILE* pFile2 = fopen("D:\\GitHub\\JULY\\AlgorithmTest\\bigger_caesarDecrypt.txt", "wb");
	fwrite(str, nFileLen - n, 1, pFile2);
	fclose(pFile2);

	delete[] str;

}

//异或加密
void xorEncrypt()
{
	FILE* pFile = fopen("D:\\GitHub\\JULY\\AlgorithmTest\\bigger.txt", "rb");
	fseek(pFile, 0, SEEK_END);
	int nFileLen = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	char* str = new char[nFileLen + 1];
	fread(str, nFileLen, 1, pFile);
	fclose(pFile);
	str[nFileLen] = 0;

	char* secret = "JulyEdu";
	int nLen = (int)strlen(secret);
	int j = 0;
	for (int i = 0; i < nFileLen; i++)
	{
		str[i] ^= secret[j];
		j++;
		if (j >= nLen)
		{
			j -= nLen;
		}
	}
	FILE* pFile2 = fopen("D:\\GitHub\\JULY\\AlgorithmTest\\bigger_xorEncrypt.txt", "wb");
	fwrite(str, nFileLen, 1, pFile2);
	fclose(pFile2);

	delete[] str;
}

//异或加密
void xorDecrypt()
{
	FILE* pFile = fopen("D:\\GitHub\\JULY\\AlgorithmTest\\bigger_xorEncrypt.txt", "rb");
	fseek(pFile, 0, SEEK_END);
	int nFileLen = ftell(pFile);
	fseek(pFile, 0, SEEK_SET);
	char* str = new char[nFileLen + 1];
	fread(str, nFileLen, 1, pFile);
	fclose(pFile);
	str[nFileLen] = 0;

	char* secret = "JulyEdu";
	int nLen = (int)strlen(secret);
	int j = 0;
	for (int i = 0; i < nFileLen; i++)
	{
		str[i] ^= secret[j];
		j++;
		if (j >= nLen)
		{
			j -= nLen;
		}
	}
	FILE* pFile2 = fopen("D:\\GitHub\\JULY\\AlgorithmTest\\bigger_xorDecrypt.txt", "wb");
	fwrite(str, nFileLen, 1, pFile2);
	fclose(pFile2);

	delete[] str;
}
