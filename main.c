#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 1000
#include<string.h>
#include <limits.h>
#define ARRAY_SIZE  20
#define EPSILON 0.001
#include <stdbool.h>

void log_antilog(){
    int choice;
    double n,res;
    printf("1.log base e\n2.log base 10\n3.antilog for e or exponential\n4.antilog for 10\n5.Main menu\n");
    printf("Enter the choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the n\n");
                scanf("%lf",&n);
                res = log(n);
                break;

        case 2: printf("Enter the n\n");
                scanf("%lf",&n);
                res = log10(n);
                break;

        case 3: printf("Enter the n\n");
                scanf("%f",&n);
                res =(exp(n));
                break;

        case 4: printf("Enter the n\n");
                scanf("%f",&n);
                res = (double)pow(10,n);
                break;
        default: return;
    }
    printf("The obtained result is %lf\n",res);
}

void powerorroot(){
    /// Finding the root or power
    int choice;
    float m,n,res;
    printf("1.finding nth root of m\n2.finding m^n\n3.Main menu\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the value of m and n\n");
                scanf("%f%f",&m,&n);
                res=powf(m,(1.0/n));
                break;

        case 2: printf("Enter the value of m and n\n");
                scanf("%f%f",&m,&n);
                res=powf(m,n);
                break;

        default: return;
    }
    printf("The obtained result is %f\n",res);
}

int fact1(n){
    if(n==0)
        return 1;
    return(n*fact(n-1));
}
void fact(){
    int n,r,choice,res;
    printf("1.factorial\n2.permutation\n3.combination\n4.Main menu\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the value of n\n");
                scanf("%d",&n);
                res = fact1(n);
                break;
        case 2: printf("Enter the value of n and r\n");
                scanf("%d%d",&n,&r);
                res=(fact1(n)/(fact1(r) * fact1(n-r)));
                break;

        case 3: printf("Enter the value of n and r\n");
                scanf("%d%d",&n,&r);
                res=(fact1(n)/ fact1(n-r));
                break;

        default:return;
    }
    printf("The obtained result is %d\n",res);
}

float efunc(float a,float b){
    float c;
    c=a*a+b;
    return(c);
}
void euler(){
    ///Euler's  method code
    int i,j,c;
    float x[100],y[100],h,m[100],m1,m2,a,s[100],w;
    printf("Modified Euler Method solution\n");
    printf(" Enter the initial value of x:\n");
    scanf("%f",&x[0]);
    printf("Enter the value of increment h:\n");
    scanf("%f",&h);
    printf("Enter the final value of x:\n");
    scanf("%f",&a);
    printf("Enter the initial value of the variable y :\n");
    scanf("%f",&y[0]);
    s[0]=y[0];
    for(i=1;x[i-1]<a;i++)
    {
        w=100.0;
        x[i]= x[i-1]+h;
        m[i]=efunc(x[i-1],y[i-1]);
        c=0;
        while(w>0.0001)
        {
            m1=efunc(x[i],s[c]);
            m2=(m[i]+m1)/2;
            s[c+1]=y[i-1]+m2*h;
            w=s[c]-s[c+1];
            w=fabs(w);
            c=c+1;
        }
        y[i]=s[c];
    }
    printf("\n The respective values of x and y are\n     x  \t     y\n");
    for(j=0;j<i;j++)
    {
        printf("  %f\t%f",x[j],y[j]);
        printf("\n");
    }
}
void milnesm(){
    float xm0, xm1, xm2, xm3, xm4, ym0, ym1, ym2, ym3, ym0d, ym1d, ym2d, ym3d, ym4p, ym4c, mh;
    printf("Enter the values of x0\n");
    scanf("%f", &xm0);
    printf("Enter the values of y0, y1, y2, y3\n");
    scanf("%f %f %f %f", &ym0, &ym1, &ym2, &ym3);
    printf("Enter the values of y0', y1', y2', y3'\n");
    scanf("%f %f %f %f", &ym0d, &ym1d, &ym2d, &ym3d);
    printf("Enter the width h \n");
    scanf("%f", &mh);
    xm1 = xm0 + mh;
    xm2 = xm1 + mh;
    xm3 = xm2 + mh;
    xm4 = xm3 + mh;
    ym4p = ym0 + (4*mh*(2*ym1d - ym2d + 2*ym3d))/3;
    ym4c = ym2 + (mh*(ym2d + 4*ym3d + ym4p))/3;
    printf("Milne predictor solution = %f ", &ym4p);
    printf("Milne corrector solution = %f ", &ym4c);
}
void adamsm(){
    float xa0, xa1, xa2, xa3, xa4, ya0, ya1, ya2, ya3, ya0d, ya1d, ya2d, ya3d, ya4p, ya4c, ah;
    printf("Enter the values of x0\n");
    scanf("%f", &xa0);
    printf("Enter the values of y0, y1, y2, y3\n");
    scanf("%f %f %f %f", &ya0, &ya1, &ya2, &ya3);
    printf("Enter the values of y0', y1', y2', y3'\n");
    scanf("%f %f %f %f", &ya0d, &ya1d, &ya2d, &ya3d);
    printf("Enter the width h \n");
    scanf("%f", &ah);
    xa1 = xa0 + ah;
    xa2 = xa1 + ah;
    xa3 = xa2 + ah;
    xa4 = xa3 + ah;
    ya4p = ya3 + (ah*(55*ya3d - 59*ya2d + 37*ya1d - 9*ya0d))/24;
    ya4c = ya3 + (ah*(9*ya4p + 19*ya3d - 5*ya2d + ya1d))/24;
    printf("Adam predictor solution = %f ", &ya4p);
    printf("Adam corrector solution = %f ", &ya4c);
}
float frkm(float x,float y);
float frkm(float x,float y){
    float m;
    m=(x-y)/(x+y);
    return m;
}
void rkmethod(){
    ///Range-Kutta method
    float x0,y0,m1,m2,m3,m4,m,y,x,h,xn;
    printf("Enter x0,y0,xn,h:");
    scanf("%f %f %f %f",&x0,&y0,&xn,&h);
    x=x0;
    y=y0;
    printf("\n\nX\t\tY\n");
    while(x<xn)
    {
        m1=frkm(x0,y0);
        m2=frkm((x0+h/2.0),(y0+m1*h/2.0));
        m3=frkm((x0+h/2.0),(y0+m2*h/2.0));
        m4=frkm((x0+h),(y0+m3*h));
        m=((m1+2*m2+2*m3+m4)/6);
        y=y+m*h;
        x=x+h;
        printf("%f\t%f\n",x,y);
    }
    return;
}
void numerical_methods(){
    int choice;
    printf("1.Euler's method\n2.Adam's method\n3.Milne's method\4.RK method\n5.Main menu\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: euler();
                break;
        case 2: adamsm();
                break;
        case 3: milnesm();
                break;
        case 4: rkmethod();
                break;
        default: return;
    }
}

void AP(int terms,int first,int diff){
    int value,i;
    float sum;
    value = first;

    printf("AP SERIES\n");
    for(i = 0; i < terms; i++)
    {
      printf("%d ", value);
      sum += value;
      value = value + diff;

    }
    printf("\nSum of the AP series till %d terms is %f\n", terms, sum);
}
void GP(int terms,int first,int ratio){
    int i,value;
    float sum;
    sum=0.0;
    value = first;
    printf("GP SERIES\n");
    for(i = 0; i < terms; i++)
    {
      printf("%d ", value);
      sum += value;
      value = value * ratio;
    }
    printf("\nSum of the GP series till %d terms is %f\n", terms, sum);
}
void HP(int terms,int first,int diff){
    int denominator,i;
    float sum=0.0;
    denominator = first;
    printf("HP SERIES\n");
    for(i = 0; i < terms; i++)
    {
      printf("1/%d ", denominator);
      sum += 1/(float)denominator;
      denominator += diff;
    }
    printf("\nSum of the HP series till %d terms is %f\n", terms, sum);
}
void AM(double n){
    double a[100];
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    double sum=0.0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    double am=sum/n;
    printf("%lf",am);
    return;
}
void GM(double n){
    int i;
    double sum,gm=1.0,a[100];
    printf("Enter the series:");
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    for(i=0;i<n;i++)
     {
    	gm=gm*a[i] ;
     }
     printf("Geomatric mean=%lf\n", pow(gm, 1/n));
}
void HM(double n){
    int i;
    double z,add=0.0,hm,a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&a[i]);
    }
    for(i=0;i<n;i++)
    {
    	add= ( add + (1/a[i]) ) ;
    }
    z= pow(add,-1);
    hm= n*z;
    printf("Harmonic mean=%f\n", hm);
}
void progressionandmean(){
    int first, diff, terms,ratio;

    double n;
	int choice;

    for(;;)
    {
      printf("1.AP\n2.GP\n3.HP\n4.AM\n5.GM\n6.HM\n7.Main menu\n");
      printf("Enter the choice\n");
      scanf("%d",&choice);

    switch(choice)
      {

        case 1: printf("Enter the number of terms in AP series\n");
               scanf("%d", &terms);

               printf("Enter first term and common difference of AP series\n");
               scanf("%d%d", &first, &diff);

               AP(terms,first,diff);

               break;

        case 2: printf("Enter the number of terms in GP series\n");
                scanf("%d", &terms);

                printf("Enter first term and common ratio of GP series\n");
                scanf("%d %d", &first, &ratio);
                GP(terms,first,ratio);
                break;

        case 3 : printf("Enter the number of terms in HP series\n");
                 scanf("%d", &terms);

                printf("Enter denominator of first term and common difference of HP series\n");
                scanf("%d %d", &first, &diff);
                HP(terms,first,diff);
                break;

	    case 4 : printf("for how many number you want means\n");
	             scanf("%lf",&n);
	             printf("series\n");
	              AM(n);
	              break;

	   case 5 :printf("for how many number you want means\n");
	           scanf("%lf",&n);
	           printf("series\n");
               GM(n);
               break;

       case 6 : printf("for how many number you want means\n");
	             scanf("%lf",&n);
	             printf("series\n");
                 HM(n);
                 break;
        case 7 : return;


      }
    }
}

int convert(long long);
void bintodeci(){
    /// convert binary to decimal
    long long n;
    printf("Enter a binary number: ");
    scanf("%lld", &n);
    printf("%lld in binary = %lld in decimal", n, convert(n));
}
int convert(long long n){
    int dec = 0, i = 0, rem;
    while (n!=0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}
long long convert1(long long);
void decitobin(){
    /// convert decimal to binary
    long long bin,n;
    printf("Enter a decimal number: \n");
    scanf("%lld", &n);
    bin = convert1(n);
    printf("%lld in decimal =  %lld in binary", n, bin);
    return;
}
long long convert1(long long n){
    long long bin = 0;
    long long rem, i=1;
    while(n!=0){
        rem = n%2;
        n = n/2;
        bin=bin+rem*i;
        i=i*10;
    }
    return bin;
}
int convert2(long long);
void bintooct(){
    /// Binary to Hexadecimal
    long long bin;
    printf("Enter a binary number: ");
    scanf("%lld", &bin);
    printf("%lld in binary = %d in octal", bin, convert2(bin));
}
int convert2(long long bin){
    int oct = 0, dec = 0, i = 0;
    /// converting binary to decimal
    while (bin != 0) {
        dec += (bin % 10) * pow(2, i);
        ++i;
        bin /= 10;
    }
    i = 1;

    /// converting to decimal to octal
    while (dec != 0) {
        oct += (dec % 8) * i;
        dec /= 8;
        i *= 10;
    }
    return oct;
}
long long convert3(int);
void octtobin(){
    ///Octal to binary
    int oct;
    printf("Enter an octal number: ");
    scanf("%d", &oct);
    printf("%d in octal = %lld in binary", oct, convert3(oct));
    return 0;
}
long long convert3(int oct){
    int dec = 0, i = 0;
    long long bin = 0;

    /// converting octal to decimal
    while (oct != 0) {
        dec += (oct % 10) * pow(8, i);
        ++i;
        oct /= 10;
    }
    i = 1;

   /// converting decimal to binary
    while (dec != 0) {
        bin += (dec % 2) * i;
        dec /= 2;
        i *= 10;
    }
    return bin;
}
int convertDecimalToOctal(int decimalNumber);
void decitooct(){
    /// Decimal to octal
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    printf("%d in decimal = %d in octal", decimalNumber, convertDecimalToOctal(decimalNumber));
}
int convertDecimalToOctal(int decimalNumber){
    int octalNumber = 0, i = 1;
    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }
    return octalNumber;
}
long long convertOctalToDecimal(int octalNumber);
void octtodeci(){
    /// Octal to decimal
    int octalNumber;
    printf("Enter an octal number: ");
    scanf("%d", &octalNumber);
    printf("%d in octal = %lld in decimal", octalNumber, convertOctalToDecimal(octalNumber));
    return 0;
}
long long convertOctalToDecimal(int octalNumber){
    int decimalNumber = 0, i = 0;
    while(octalNumber != 0)
    {
        decimalNumber += (octalNumber%10) * pow(8,i);
        ++i;
        octalNumber/=10;
    }
    i = 1;
    return decimalNumber;
}
void bintohex(){
    /// Binary to hexadecimal
    long int binaryval, hexadecimalval = 0, i = 1, remainder;

    printf("Enter the binary number: ");
    scanf("%ld", &binaryval);
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("Equivalent hexadecimal value: %lX", hexadecimalval);
}
void hextobin(){
    ///Hexadecimal to binary
    char binarynum[MAX], hexa[MAX];
    long int i = 0;

    printf("Enter the value for hexadecimal ");
    scanf("%s", hexa);
    printf("\n Equivalent binary value: ");
    while (hexa[i])
    {
        switch (hexa[i])
        {
        case '0':
            printf("0000"); break;
        case '1':
            printf("0001"); break;
        case '2':
            printf("0010"); break;
        case '3':
            printf("0011"); break;
        case '4':
            printf("0100"); break;
        case '5':
            printf("0101"); break;
        case '6':
            printf("0110"); break;
        case '7':
            printf("0111"); break;
        case '8':
            printf("1000"); break;
        case '9':
            printf("1001"); break;
        case 'A':
            printf("1010"); break;
        case 'B':
            printf("1011"); break;
        case 'C':
            printf("1100"); break;
        case 'D':
            printf("1101"); break;
        case 'E':
            printf("1110"); break;
        case 'F':
            printf("1111"); break;
        case 'a':
            printf("1010"); break;
        case 'b':
            printf("1011"); break;
        case 'c':
            printf("1100"); break;
        case 'd':
            printf("1101"); break;
        case 'e':
            printf("1110"); break;
        case 'f':
            printf("1111"); break;
        default:
            printf("\n Invalid hexa digit %c ", hexa[i]);
            return;
        }
        i++;
    }
    return;
}
void decitohex(){
    ///Decimal to hexadecimal
    long decimalnum, quotient, remainder;
    int i, j = 0;
    char hexadecimalnum[100];

    printf("Enter decimal number: ");
    scanf("%ld", &decimalnum);

    quotient = decimalnum;

    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }

    // display integer into character
    for (i = j; i >= 0; i--)
            printf("%c", hexadecimalnum[i]);
    return 0;
}
void octtohex(){
    int OCTALVALUES[] = {0, 1, 10, 11, 100, 101, 110, 111};

    long long octal, tempOctal, binary, place;
    char hex[65] = "";
    int rem;

    place = 1;
    binary = 0;

    /// Input octal number from user
    printf("Enter any octal number: ");
    scanf("%lld", &octal);
    tempOctal = octal;

    ///Octal to binary conversion
    while(tempOctal > 0)
    {
        rem = tempOctal % 10;
        binary = (OCTALVALUES[rem] * place) + binary;
        tempOctal /= 10;

        place *= 1000;
    }

    ///Binary to hexadecimal conversion
    while(binary > 0)
    {
        rem = binary % 10000;
        switch(rem)
        {
            case 0:strcat(hex, "0");
                    break;
            case 1:strcat(hex, "1");
                    break;
            case 10:strcat(hex, "2");
                    break;
            case 11:strcat(hex, "3");
                    break;
            case 100:strcat(hex, "4");
                    break;
            case 101:strcat(hex, "5");
                    break;
            case 110:strcat(hex, "6");
                    break;
            case 111:strcat(hex, "7");
                    break;
            case 1000:strcat(hex, "8");
                    break;
            case 1001:strcat(hex, "9");
                    break;
            case 1010:strcat(hex, "A");
                    break;
            case 1011:strcat(hex, "B");
                    break;
            case 1100:strcat(hex, "C");
                    break;
            case 1101:strcat(hex, "D");
                    break;
            case 1110:strcat(hex, "E");
                    break;
            case 1111: strcat(hex, "F");
                    break;
        }

        binary /= 10000;
    }

    strrev(hex);

    printf("Octal number: %lld\n", octal);
    printf("Hexadecimal number: %s", hex);
}
void hextodeci(){
    char hex[ARRAY_SIZE];
    long long decimal = 0, base = 1;
    int i = 0, value, length;
    /* Get hexadecimal value from user */
    printf("Enter hexadecimal number: ");
    fflush(stdin);
    fgets(hex,ARRAY_SIZE,stdin);
    length = strlen(hex);
    for(i = length--; i >= 0; i--)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    printf("\nHexadecimal number = %s", hex);
    printf("is Decimal number = %lld\n", decimal);
}
int hexa_binary(char hex[]) {
    int binary, place;
   int i = 0, rem, val;
   int n = strlen(hex);
   binary = 0ll;
   place = 0ll;
   for (i = 0; hex[i] != '\0'; i++) {
      binary = binary * place;
      switch (hex[i]) {
      case '0':binary += 0;
         break;
      case '1':binary += 1;
         break;
      case '2':binary += 10;
         break;
      case '3':binary += 11;
         break;
      case '4':binary += 100;
         break;
      case '5':binary += 101;
         break;
      case '6':binary += 110;
         break;
      case '7':binary += 111;
         break;
      case '8':binary += 1000;
         break;
      case '9':binary += 1001;
         break;
      case 'a':
      case 'A':binary += 1010;
         break;
      case 'b':
      case 'B':binary += 1011;
         break;
      case 'c':
      case 'C':binary += 1100;
         break;
      case 'd':
      case 'D':binary += 1101;
         break;
      case 'e':
      case 'E':binary += 1110;
         break;
      case 'f':
      case 'F':binary += 1111;
         break;
      default:
         printf("Invalid hexadecimal input.");
         return;
      }
      place = 10000;
   }
   printf("Hexadecimal value of %s  is",hex);
   return binary;
}
int binary_oct(int binary) {
    ///To convert binary to octal
   int octal, place;
   int i = 0, rem, val;
   octal = 0ll;
   place = 0ll;
   place = 1;
  /// giving all binary numbers for octal conversion
   while (binary > 0) {
      rem = binary % 1000;
      switch (rem) {
      case 0:val = 0;
         break;
      case 1:val = 1;
         break;
      case 10:val = 2;
         break;
      case 11:val = 3;
         break;
      case 100:val = 4;
         break;
      case 101:val = 5;
         break;
      case 110:val = 6;
         break;
      case 111:val = 7;
         break;
      }
      octal = (val * place) + octal;
      binary /= 1000;
      place *= 10;
   }
   return octal;
}
int hexa_oct(char hex[]) {
    /// to convert the hexadecimal number to octal
   int octal, binary;
   /// convert HexaDecimal to Binary
   binary = hexa_binary(hex);
   /// convert Binary to Octal
   octal = binary_oct(binary);
   return octal;
}
void hextooct() {
   char hex[20];
   printf("Enter the hexadecimal to convert\n");
   scanf("%s",hex);
   printf(" Octal Value = %lld", hexa_oct(hex));
   return;
}
void conversions(){
    int choice;
    printf("1.Decimal to binary number\n");
    printf("2.Decimal to octal number\n");
    printf("3.Decimal to Hexadecimal number\n");
    printf("4.Binary to decimal number\n");
    printf("5.Binary to octal number\n");
    printf("6.Binary to Hexadecimal number\n");
    printf("7.Octal to Decimal number\n");
    printf("8.Octal to binary number\n");
    printf("9.Octal to Hexadecimal number\n");
    printf("10.Hexadecimal to Decimal number\n");
    printf("11.Hexadecimal to Binary number\n");
    printf("12.Hexadecimal to octal\n");
    printf("13.Main menu\nEnter your choice  \n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: decitobin();
                break;
        case 2: decitooct();
                break;
        case 3: decitohex();
                break;
        case 4: bintodeci();
                break;
        case 5: bintooct();
                break;
        case 6: bintohex();
                break;
        case 7: octtodeci();
                break;
        case 8: octtobin();
                break;
        case 9: octtohex();
                break;
        case 10:hextodeci();
                break;
        case 11:hextobin();
                break;
        case 12:hextooct();
               break;
        default : return;
    }
}

void addition(){
    int n,m,i,k,a[100],b[100],c[100];
    printf("Enter the number of digits in number1\n");
    scanf("%d",&m);
    printf("Enter the number of digits in number2\n");
    scanf("%d",&n);
    printf("Enter the number1 and give a space after entering every digit\n");
    for(i=m-1;i>=0;i--)
        scanf("%d",&a[i]);

    printf("Enter the number2 and give a space after entering every digit\n");
    for(i=n-1;i>=0;i--)
        scanf("%d",&b[i]);

    if(m>n)
        k=m;

    else
        k=n;

    for(i=k-1;i>=0;i--)
        c[i]=0;

    for(i=0;i<k;i++){
        c[i]=c[i]+a[i]+b[i];
        if(c[i]>9){
            c[i]=c[i]-10;
            (c[i+1])++;
        }
    }
    printf("the sum of 2 digits is\n");
    for(i=k;i>=0;i--)
        printf("%d",c[i]);

    printf("\n");
}
void subtraction(){
    /// Subtraction of large number
    int n,m,i,j,a[100],b[100],c[100];
    printf("Enter the number of digits in number1\n");
    scanf("%d",&m);
    printf("Enter the number of digits in number2\n");
    scanf("%d",&n);
    printf("Enter the number1 and give a space after entering every digit\n");
    for(i=m-1;i>=0;i--){
        scanf("%d",&a[i]);
    }
    printf("Enter the number2 and give a space after entering every digit\n");
    for(i=n-1;i>=0;i--){
        scanf("%d",&b[i]);
    }
    if(m<n){
        for(i=0;i<m;i++)
        {
            c[i]=b[i]-a[i];
            if(c[i]<0){
                c[i]=c[i]+10;
                (b[i+1])--;
            }
        }
        for(i=m;i<n;i++)
            c[i]=b[i];
        printf("The difference between entered numbers is  -");
        for(i=n-1;i>=0;i--)
            printf("%d",c[i]);

        printf("\n");
    }
    else if(m>n)
    {
        for(i=0;i<n;i++)
        {
            c[i]=a[i]-b[i];
            if(c[i]<0){
                c[i]=c[i]+10;
                a[i+1]=a[i+1]-1;
            }
        }
        for(i=n;i<m;i++)
            c[i]=a[i];

        printf("The difference between entered numbers is  ");
        for(i=m-1;i>=0;i--)
            printf("%d",c[i]);

        printf("\n");
    }
    else{
        for(j=m-1;j>=0;j--){
            if(a[j]>b[j]){
                for(i=0;i<n;i++){
                    c[i]=a[i]-b[i];
                    if(c[i]<0){
                        c[i]=c[i]+10;
                        a[i+1]=a[i+1]-1;
                    }
                }
                printf("The difference between entered numbers is  ");
                for(i=n-1;i>=0;i--)
                    printf("%d",c[i]);

                printf("\n");
                return;
            }
            if(a[j]<b[j]){
                for(i=0;i<m;i++){
                    c[i]=b[i]-a[i];
                    if(c[i]<0){
                        c[i]=c[i]+10;
                        b[i+1]=b[i+1]-1;
                    }
                }
                printf("The difference between entered numbers is  -");
                for(i=n-1;i>=0;i--)
                    printf("%d",c[i]);

                printf("\n");
                return;
            }
        }
        printf("The difference between entered numbers is %d\n",0);
    }
}
void multiplication(){
    /// multiplication of large number
    int n,m,i,j,k,a[100],b[100],c[100][100],d[100],temp;
    printf("Enter the number of digits in number1\n");
    scanf("%d",&m);
    printf("Enter the number of digits in number2\n");
    scanf("%d",&n);
    if(m==0 || n==0){
        printf("Multiplication with zero not possible\n");
        return;
    }
    printf("Enter the number1 and give a space after entering every digit\n");
    for(i=m-1;i>=0;i--){
        scanf("%d",&a[i]);
    }
    printf("Enter the number2 and give a space after entering every digit\n");
    for(i=n-1;i>=0;i--){
        scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m+n-1;j++){
            c[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            c[i][j+i]=c[i][j+i]+(a[j]*b[i]);
        }
    }
    k=0;
    for(j=0;j<m+n-1;j++){
        d[k]=0;
        for(i=0;i<n;i++){
            d[k]=d[k]+c[i][j];
        }
        k++;
    }
    for(i=0;i<k;i++){
        if(d[i]>10){
           temp=d[i];
           d[i+1]=d[i+1]+(temp/10);
           d[i]=d[i]%10;
        }
    }
    printf("The total product =  ");
    for(i=k;i>=0;i--)
        printf("%d",d[i]);

    printf("\n");
}
void division(){
    float a,b,res;
    printf("Enter a\n");
    scanf("%f",&a);
    printf("Enter b\n");
    scanf("%f",&b);
    if(b==0 && a==0){
        printf("Division by zero is not possible\n");
        return;
    }
    if(b==0){
        printf("Division by zero is not possible\n");
        return;
    }
    if(a==0){
        printf("The result = 0\n");
        return;
    }
    res=a/b;
    printf("The result=%f\n",res);
    return;
}
void operations(){
    int a;
    for(;;){
        printf("1.Addition\n2.Subtraction\n3.multiplication\n4.division\n5.Main menu\n");
        printf("Enter your choice\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: addition();
                    break;
            case 2: subtraction();
                    break;
            case 3: multiplication();
                    break;
            case 4: division();
                    break;
            default : return;
        }
    }
}

void matrix_operations(){
    /// Matrix operations
    int m,p,q,n,i,j,k,a[10][10],b[10][10],c[10][10],choice;
    printf("Enter the operation which you want to perform on the matrix\n1.Addition\n2.Subtraction\n3.Multiplication\n");
    printf("4.Main menu\nEnter your choice\n");
    scanf("%d",&choice);
    if(choice!=1 || choice!=2 || choice!=3)
        return;
    printf("Enter the order of matrix A\n");
    scanf("%d%d",&m,&n);
    printf("Enter the order of matrix B\n");
    scanf("%d%d",&p,&q);
    printf("Enter the elements of matrix A\n");
    for(i=0;i<m;i++)
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }


    printf("Enter the elements of matrix B\n");
    for(i=0;i<p;i++)
        for(j=0;j<q;j++)
            scanf("%d",&b[i][j]);

    if(choice==1){
        if(m!=p||n!=q){
            printf("Matrix addition is not possible\n");
            exit(0);
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                c[i][j]=a[i][j]+b[i][j];
            }
        }
        printf("The resultant matrix is\n");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }

    }
    else if(choice==2){
        if(m!=p||n!=q){
            printf("Matrix Subtraction is not possible\n");
            exit(0);
        }
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                c[i][j]=a[i][j]-b[i][j];
            }
        }
        printf("The resultant matrix is\n");
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
    }
    else if(choice==3){
        if(n!=p){
            printf("Matrix multiplication is not possible\n");
            exit(0);
        }
        for(i=0;i<m;i++){
            for(j=0;j<q;j++){
                for(k=0;k<n;k++){
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
                }
            }
        }
        printf("The resultant matrix is\n");
        for(i=0;i<m;i++){
            for(j=0;j<q;j++){
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
    }
}

void transpose(float num[100][100],float fac[100][100],float r);
float determinant(float a[100][100],float k){
   ///Finding transpose of matrix
  float s=1, det=0, b[100][100];
  int i,j,m,n,c;
  if(k==1)
    {
     return (a[0][0]);
    }
  else
    {
     det=0;
     for(c=0;c<k;c++)
       {
        m=0;
        n=0;
        for(i=0;i<k;i++)
          {
            for(j=0;j<k;j++)
              {
                b[i][j]=0;
                if(i!=0 && j!=c)
                 {
                   b[m][n]=a[i][j];
                   if(n<(k - 2))
                    n++;
                   else
                    {
                     n=0;
                     m++;
                     }
                   }
               }
             }
          det=det+s*(a[0][c]*determinant(b,k-1));
          s=-1*s;
          }
    }

    return (det);
}
void cofactor(float num[100][100],float f){
 float b[100][100],fac[100][100];
 int p,q,m,n,i,j;
 for(q=0;q<f;q++)
 {
   for(p =0;p<f;p++)
    {
     m=0;
     n=0;
     for(i=0;i<f;i++)
     {
       for(j=0;j<f;j++)
        {
          if(i!=q && j!=p)
          {
            b[m][n]=num[i][j];
            if(n<(f - 2))
             n++;
            else
             {
               n=0;
               m++;
               }
            }
        }
      }
      fac[q][p]=pow(-1,q+p)*determinant(b,f-1);
    }
  }
  transpose(num,fac,f);
}
void transpose(float num[100][100],float fac[100][100],float r){
    ///Finding transpose of matrix
  int i,j;
  float b[100][100],inverse[100][100],d;

  for(i=0;i<r;i++)
    {
     for(j=0;j<r;j++)
       {
         b[i][j]=fac[j][i];
        }
    }
  d=determinant(num,r);
  for(i=0;i<r;i++)
    {
     for(j=0;j<r;j++)
       {
        inverse[i][j]=b[i][j]/d;
        }
    }
   printf("The inverse of matrix is\n");

   for(i=0;i<r;i++)
    {
     for(j=0;j<r;j++)
       {
         printf("%f\t",inverse[i][j]);
        }
    printf("\n");
     }
}
void inverse_matrix(){
    /// INVERSE OF THE MATRIX
  float a[100][100],k,z,d;
  int i,j;
  printf("Enter the order of the Matrix\n");

  scanf("%f%f",&z,&k);
  if(z!=k)
  {
      printf("Order of matrix is not symmetric\n");
      printf("Inverse of Entered Matrix is not possible\n");
      exit(0);
  }
  printf("Enter the elements 0f Matrix\n");
  for(i=0;i<z;i++)
    {
     for(j=0;j<k;j++)
       {
          scanf("%f",&a[i][j]);
       }
    }
  d=determinant(a,k);
  if(d==0)
   {
      printf("Inverse of Entered Matrix is not possible\n");
      exit(0);
   }
  else
   {
      cofactor(a,k);
   }

}

void transpose_matrix(){
  int a[10][10], transpose[10][10], r, c;
  printf("Enter rows and columns: ");
  scanf("%d %d", &r, &c);

  printf("\nEnter matrix elements:\n");
  for (int i = 0; i < r; ++i){
     for (int j = 0; j < c; ++j){
    printf("Enter element %d%d ", i + 1, j + 1);
    scanf("%d", &a[i][j]);
    }
  }
  printf("\nEntered matrix: \n");
  for (int i = 0; i < r; ++i){
      for (int j = 0; j < c; ++j){
        printf("%d  ", a[i][j]);
        if (j == c - 1)
        printf("\n");
      }
  }

  for (int i = 0; i < r; ++i){
      for (int j = 0; j < c; ++j){
        transpose[j][i] = a[i][j];
      }
  }

  printf("\nTranspose of the matrix:\n");
  for (int i = 0; i < c; ++i){
    for (int j = 0; j < r; ++j){
    printf("%d  ", transpose[i][j]);
    if (j == r - 1)
    printf("\n");
    }
  }
}

void transpose_inverse(){
    int choice;
    printf("1.Transpose of Matrix\n2.Inverse of matrix\n3.Main menu\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: inverse_matrix();
                break;
        case 2: transpose_matrix();
                break;
        default: return;
    }
}

void converttouppertriangular(int n,float a[][n+1]){
    int i,j,k,x,y;
    float ratio;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j>i)
            {
                ratio=a[j][i]/a[i][i];
                for(k=0;k<n+1;k++)
                a[j][k]=a[j][k]-(ratio*a[i][k]);
                printf("intermediate forms\n");
                for(x=0;x<n;x++)
                {
                    for(y=0;y<n+1;y++)
                    printf("%f ",a[x][y]);
                    printf("\n");

                }
                printf("\n");
            }
        }
    }
}
void applybacksubstitution(int n,float a[][n+1],float value[]){
    int i,j;
    float sum;
    value[n-1]=a[n-1][n]/a[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<n;j++)
         sum=sum+a[i][j]*value[j];
         value[i]=(a[i][n]-sum)/a[i][i];
    }
}
void print(float value[],int n){
     int i;
     printf("values of unknowns are\n");
     for(i=0;i<n;i++)
     printf("value[%d]=%f\n",i,value[i]);
}
void converttodiagonal(int n,float a[][n+1] ){
    int i,j,x,k,y;
    float ratio;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j!=i)
            {
                ratio=a[j][i]/a[i][i];
                for(k=0;k<n+1;k++)
                a[j][k]=a[j][k]-ratio*a[i][k];
                printf("intermediate forms\n");
                for(x=0;x<n;x++)
                {
                    for(y=0;y<n;y++)
                    printf("%f ",a[x][y]);
                    printf("\n");

                }
            }
        }
    }
}
void printunknowns(int n,float a[][n+1]){
    int i;
    printf("unknown values:\n");
    for(i=0;i<n;i++)
        printf("value of variable %d=%f\n",i,a[i][n]/a[i][i]);
}

int flags,ns;
float findSum(int i,float a[][ns+1]){
     float sum=0;
     for(int j=0;j<ns;j++)
     {
       if(i!=j)
         sum+=a[i][j];
     }
     return sum;
}
bool isMethodApplicable(float a[][ns+1]){
   for(int i=0;i<ns;i++)
   {
       for(int j=0;j<ns;j++)
       {

           if(fabs(a[i][i])>findSum(i,a))
              continue;
           else
              return false;

       }
   }
   return true;
}
void printss(int iteration,float values[ns]) {
  printf("Iteration %d ",iteration);
  for(int i=0;i<ns;i++)
    printf("value[%d]=%f ",i+1,values[i]);
  printf("\n");
}
void findValues(float a[][ns+1],int maxIterations,float values_old[ns]){
    int i,j,k,iteration;
    float ratio,sum=0;
    float values_new[ns];
    for(int i=0;i<ns;i++)
     values_new[i]=0;
    for(iteration=1;iteration<=maxIterations;iteration++)
    {
        for(i=0;i<ns;i++)
        {
            sum=0;
            for(j=0;j<ns;j++)
            {
                if(i!=j)
                sum+=a[i][j]*values_new[j];
            }

            values_new[i]=(a[i][ns] - sum)/a[i][i];
        }

        //Now you have found the values of n unknowns for above iteration
        //Now check if your matching criteria satisfied , comparing with previous iteration values
        for(k=0;k<ns;k++)
        {
            if(fabs(values_old[k]-values_new[k])<EPSILON)
                continue;
            else
            {
               flags=1;
               break;
            }
        }
        if(flags==0)
        {
            printss(iteration,values_new);  // print final values of unknowns  and return
            return ;
        }
        flags=0; //resetting the flag

        printss(iteration,values_new); //To print intermediate roots

        //copy new values of unknowns to old value array
        for(k=0;k<ns;k++)
             values_old[k]=values_new[k];
    } //end of iteration loop
    printss(iteration,values_new) ;
}
void gauss_seidel(){
    int i,j,k,x,y,maxIterations;
    float ratio;
    printf("Enter no of Unknowns\n");
    scanf("%d",&ns);
    printf("Enter no. of iterations\n");
    scanf("%d",&maxIterations);
    float a[ns][ns+1];
    float values[ns];;

    printf("Enter the Augmented Matrix\n");
    for(int i=0;i<ns;i++)
    {
     for(int j=0;j<ns+1;j++)
        scanf("%f",&a[i][j]);
    }

   if(!isMethodApplicable(a))
   {
        printf("Gauss Seidel Method can't be applied");
        return 0;
   }
   printf("\n\nGauss Seidel Method is applicable\n");
   for(int i=0;i<ns;i++)
     values[i]=0;
   findValues(a,maxIterations,values);
   return;
}

int as[10][10],is,js,ms,nz;
int rank(int, int);
void swap(int,int,int);
void read(int, int);
void display(int, int);
void rank_matrix(){
   int rnk;
    printf("enter the order of matrix (row and col size):\n");
   scanf("%d%d",&ms,&nz);
   read(ms,nz);
   display(ms,nz);
   rnk= rank(ms,nz);
   printf("\n\nThe rank of above matrix is: %d\n", rnk);
   return 0;
}
void read(int r,int c){
   printf("Enter %d x %d order matrix values(Row by Row) :\n",r,c);
   for(is=0;is<r;is++)
      for(js=0;js<c;js++)
       scanf("%d",&as[is][js]);
}
void display(int r, int c){
   printf("Matrix is : \n");
   for(is=0;is<r;is++)
   {
      for(js=0;js<c;js++)
       printf("%4d",as[is][js]);
      printf("\n");
   }
}
void swap(int r1, int r2, int c){
   int t;
   for(is=0;is<c;is++)
   {
      t= as[r1][is];
      as[r1][is] = as[r2][is];
      as[r2][is]=t;
   }
}
int rank(int r1, int c1){
    int is,js,k;
    float ratio;
    for(is=0;is<c1;is++)
    {
       printf("\nSTEP = %d\n",is+1);
       display(ms,nz);
       if(as[is][is]!=0)    /* Diagonal element is not zero */
     for(js=0;js<r1;js++)
       if (js!=is)
       {
          /* Make all the element above and nelow the current principal
         diagonal element zero */
          ratio = as[js][is]/as[is][is];
          for(k=0;k<c1;k++)
         as[js][k]-=ratio*as[is][k];
       }
       else
         printf("\n");
         /* principal Diagonal element is zero */
       else
       {
       for(js=is+1;js<r1;js++)
          if(as[js][is]!=0)
          {   /* Find non zero elements in the same column */
          swap(is,js,c1);
          break;
          }
          if(js==r1)
          {
          c1--;
          for(js=0;js<r1;js++)
             as[js][is] = as[js][c1];
          }
          is--;
         }
     }
   return  c1;
}

void linear_algebra(){
    int i,j,k,x,y,n,ch;
    float sum,ratio;
     printf("\t\t\t\t\tLINEAR ALGEBRA\n");
    printf("1.Gauss elimination method 2.Gauss Jordan Method\n3.Gauss seidel method\n4.Rank of matrix\n\5.Main menu\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    printf("Enter the no. of unknowns\n");
    scanf("%d",&n);

    float a[n][n+1],value[n];
    switch(ch)
    {
        case 1: printf("Enter the augmented matrix\n");
                for(i=0;i<n;i++)
                {
                    for(j=0;j<n+1;j++)
                    scanf("%f",&a[i][j]);
                }
                converttouppertriangular(n,a);
                applybacksubstitution(n,a,value);
                print(value,n);
                break;
        case 2: printf("Enter the augmented matrix\n");
                for(i=0;i<n;i++){
                    for(j=0;j<n+1;j++)
                        scanf("%f",&a[i][j]);
                }
                converttodiagonal(n,a);
                printunknowns(n,a);
                break;
        case 3: gauss_seidel();
                break;
        case 4: rank_matrix();
                break;
        default: return;

    }
}

void derivative(){
    ///Derivative
    float x[20], y[20][20], xp, h, sum=0.0, first_derivative, term;
    int i,j, n, index, flag = 0;
    printf("Enter number of data: ");
    scanf("%d", &n);
    printf("Enter data:\n");
    for(i = 0; i < n ; i++)
    {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }
    printf("Enter at what value of x you want to calculate derivative: ");
    scanf("%f", &xp);
    for(i=0;i< n;i++)
    {
        if (fabs(xp - x[i])< 0.0001)
        {
            /* index of calculation point */
            index = i;
            flag = 1;
            break;
        }
    }
    if (flag==0)
    {
        printf("Invalid calculation point. Program exiting...");
        exit(0);
    }
    for(i = 1; i < n; i++)
    {
        for(j = n-1; j > i-1; j--)
        {
            y[j][i] = y[j][i-1] - y[j-1][i-1];
        }
    }
    h = x[1] - x[0];
    for(i=1; i<=index; i++)
    {
        term = pow(y[index][i], i)/i;
        sum = sum + term;
    }
    first_derivative = sum/h;
    printf("First derivative at x = %0.2f is %0.2f", xp, first_derivative);
    return;
}

void main()
{
    int choice;
    printf("===================================================================\n");
    printf("|                                                                 |\n");
    printf("|                                                                 |\n");
    printf("|                           MATHS SPLASH                          |\n");
    printf("|                                                                 |\n");
    printf("|                                                                 |\n");
    printf("===================================================================\n");
    for(;;){
        printf("1.Operations\n2.conversions\n3.Progression and mean\n4.Log and Antilog\n5.Power and root\n6.Numerical methods");
        printf("\n7.Factorial, permutation and combination\n");
        printf("8.Matrix operations\n9.Inverse and Transpose Matrix\n10.Linear Algebra\n11.derivative\n12.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: operations();
                    break;
            case 2: conversions();
                    break;
            case 3: progressionandmean();
                    break;
            case 4: log_antilog();
                    break;
            case 5: powerorroot();
                    break;
            case 6: numerical_methods();
                    break;
            case 7: fact();
                    break;
            case 8: matrix_operations();
                    break;
            case 9: transpose_inverse();
                    break;
            case 10: linear_algebra();
                    break;
            case 11: derivative();
                    break;
            default: exit(0);

        }
    }
}