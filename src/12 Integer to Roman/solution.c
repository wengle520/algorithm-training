/*
 * solution.c
 *
 *  Created on: 2016年3月27日
 *      Author: wengle
 */

// Symbol	Value
// I	    1
// V	    5
// X	    10
// L	    50
// C	    100
// D	    500
// M	    1,000
char* intToRoman(int num) {
    char *chM[] = {"","M","MM","MMM"};
    char *chC[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char *chX[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char *chI[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    int step[] = {0,1,2,3,2,1,2,3,4,2};
    char *p = (char *)malloc(100);
    memset(p,0,100);
    int i = 0;
    int mod = 0;

    mod = num/1000;
    int j = 0;
    for(j=0;j<step[mod];j++)
    {
        *(p+i)= *(chM[mod]+j);
        i++;
    }

    mod = num/100%10;
    for(j=0;j<step[mod];j++)
    {
        *(p+i)= *(chC[mod]+j);
        i++;
    }

    mod = num/10%10;
    for(j=0;j<step[mod];j++)
    {
        *(p+i)= *(chX[mod]+j);
        i++;
    }

    mod = num%10;
    for(j=0;j<step[mod];j++)
    {
        *(p+i)= *(chI[mod]+j);
        i++;
    }
    return p;
    // other solution
//    char *M[] = {"", "M", "MM", "MMM"};
//	char *C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
//	char *X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
//	char *I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
//	char *result = malloc(20*(sizeof(char)));
//	memset(result, 0, 20);
//	char *temp = result;
//	strlink(temp, M[num/1000]);
//	strlink(temp, C[(num%1000)/100]);
//	strlink(temp, X[(num%100)/10]);
//	strlink(temp, I[num%10]);
//	return result;
}

void strlink(char *lstr, char *rstr){
	while(*lstr != '\0'){
		lstr++;
	}
	while(*rstr != '\0'){
		*lstr = *rstr;
		lstr++;
		rstr++;
	}
	*lstr = *rstr;
}
