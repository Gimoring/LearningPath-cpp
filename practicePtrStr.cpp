#include <iostream>
using namespace std;
// 1) 문자열 길이 반환 
int StrLen(const char* str)
{
	// str 문자열의 길이 반환
	int length = 0;
	while (true)
	{
		if (*(str + length) == '\0')
			return length;
		else
			length++;
	}
}

// 2) 문자열 복사
void StrCpy(char* dest, char* src)
{
	int len = StrLen(src);
	for (int i = 0; i < len; i++)
	{
		if (i+1 == len)
			dest[i + 1] = '\0';
		dest[i] = (src[i]);
	} 

}

// 3) 문자열 합체
char* StrCat(char* dest, char* src)
{
	int destLen = strlen(dest);
	int cnt = 0;
	while (src[cnt] != '\0')
	{
		dest[destLen + cnt] = src[cnt];
		cnt++;
	}

	dest[destLen + cnt] = '\0';

	return dest;
}

// 4) 문자열 비교
int StrCmp(char* a, char* b)
{
	int cnt = 0;
	while (a[cnt] != 0 || b[cnt] != 0)
	{

		if (a[cnt] > b[cnt])
			return 1;
		else if (a[cnt] < b[cnt])
			return -1;

		cnt++;
	}
	return 0;
}

// 5) 문자열 뒤집기
void ReverseStr(char* str)
{
	int len = StrLen(str);

	for (int i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int main()
{
	const int BUF_SIZE = 100;

	// [H][e][l][l][o]['\0'][][][][][]....
	char a[BUF_SIZE] = "Kello";
	char b[BUF_SIZE] = "Hello";

	// int len2 = StrLen(a);
	// cout << len2 << endl;

	// StrCpy(b, a);
	// cout << b;

	/*char* res = StrCat(a, b);
	cout << res << endl;*/
	// cout << StrCmp(a, b);
	ReverseStr(b);
	cout << b;
}