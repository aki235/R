//make16関数にi(0~575)を入れるとchar型でパターンを出力
//main関数は検証用
//mallocを使っているがfreeを使ってないのでメモリ足りなくなるかも 要修正
#include <stdlib.h>
#define L00 "abcdbabccdabdcba"
#define L01 "abcdbadcdcbacdab"
#define L02 "abcdcdabbadcdcba"
#define L03 "abcscdabdcbabadc"
#define L04 "abcddcbabadccdab"
#define L05 "abcddcbacdabbadc"
#define L06 "abcdbadcdcabcdba"
#define L07 "abcdbadccdbadcab"
#define L08 "abcddcabbadccdba"
#define L09 "abcddcabcdbabadc"
#define L10 "abcdcdbabadcdcab"
#define L11 "abcdcdbadcabbadc"
#define L12 "abcdcadbbdacdcba"
#define L13 "abcdcadbdcbabdac"
#define L14 "abcdbdaccadbdcba"
#define L15 "abcdbdacdcbacadb"
#define L16 "abcddcbacadbbdac"
#define L17 "abcddcbabdaccadb"
#define L18 "abcddabccdabbcda"
#define L19 "abcddabcbcdacdab"
#define L20 "abcdcdabdabcbcda"
#define L21 "abcdcdabbcdadabc"
#define L22 "abcdbcdadabccdab"
#define L23 "abcdbcdacdabdabc"
#define R00 "1234"
#define R01 "1243"
#define R02 "1324"
#define R03 "1342"
#define R04 "1423"
#define R05 "1432"
#define R06 "2134"
#define R07 "2143"
#define R08 "2314"
#define R09 "2341"
#define R10 "2413"
#define R11 "2431"
#define R12 "3124"
#define R13 "3142"
#define R14 "3214"
#define R15 "3241"
#define R16 "3412"
#define R17 "3421"
#define R18 "4123"
#define R19 "4132"
#define R20 "4213"
#define R21 "4231"
#define R22 "4312"
#define R23 "4321"

char *get_L1(int i)
{
	if (i == 0)
		return (L00);
	if (i == 1)
		return (L01);
	if (i == 2)
		return (L02);
	if (i == 3)
		return (L03);
	if (i == 4)
		return (L04);
	if (i == 5)
		return (L05);
	if (i == 6)
		return (L06);
	if (i == 7)
		return (L07);
	if (i == 8)
		return (L08);
	if (i == 9)
		return (L09);
	if (i == 10)
		return (L10);
	if (i == 11)
		return (L11);
}

char *get_L2(int i)
{
	if (i == 12)
		return (L12);
	if (i == 13)
		return (L13);
	if (i == 14)
		return (L14);
	if (i == 15)
		return (L15);
	if (i == 16)
		return (L16);
	if (i == 17)
		return (L17);
	if (i == 18)
		return (L18);
	if (i == 19)
		return (L19);
	if (i == 20)
		return (L20);
	if (i == 21)
		return (L21);
	if (i == 22)
		return (L22);
	if (i == 23)
		return (L23);
}

char *get_R1(int j)
{
	if (j == 0)
		return (R00);
	if (j == 1)
		return (R01);
	if (j == 2)
		return (R02);
	if (j == 3)
		return (R03);
	if (j == 4)
		return (R04);
	if (j == 5)
		return (R05);
	if (j == 6)
		return (R06);
	if (j == 7)
		return (R07);
	if (j == 8)
		return (R08);
	if (j == 9)
		return (R09);
	if (j == 10)
		return (R10);
	if (j == 11)
		return (R11);
}

char	*get_R2(int j)
{
	if (j == 12)
		return (R12);
	if (j == 13)
		return (R13);
	if (j == 14)
		return (R14);
	if (j == 15)
		return (R15);
	if (j == 16)
		return (R16);
	if (j == 17)
		return (R17);
	if (j == 18)
		return (R18);
	if (j == 19)
		return (R19);
	if (j == 20)
		return (R20);
	if (j == 21)
		return (R21);
	if (j == 22)
		return (R22);
	if (j == 23)
		return (R23);
}

char	*convert(char *L, char *R)
{
	int	i;
	char *re;

	re = (char*)malloc(sizeof(char) * 16);
	i = 0;
	while (L[i] != '\0')
	{
		if (L[i] == 'a')
			re[i] = R[0];
		else if (L[i] == 'b')
			re[i] = R[1];
		else if (L[i] == 'c')
			re[i] = R[2];
		else if (L[i] == 'd')
			re[i] = R[3];
		i++;
	}
	return (re);
}

char	*make16(int n)
{
	char	*re;
	char	*L;
	char	*R;
	int		i;
	int		j;

	i = n / 24;
	j = n % 24;
	re = (char*)malloc(sizeof(char) * 16);
	if (i <= 11)
		L = get_L1(i);
	else if (12 <= i)
		L = get_L2(i);
	if (j <= 11)
		R = get_R1(j);
	else if (12 <= j)
		R = get_R2(j);
	re = convert(L, R);
	return (re);
}

#include <stdio.h>
int main(void)
{
	printf("%s", make16(575));
}
