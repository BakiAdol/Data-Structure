/*
* You are given too many numbers all numbers are present in even times and only one number is present odd time.
* Your task is to find this number which is present in odd times.
* Constraint : Total numbers maybe 10^9 and each number size 10^12.
*
* Suppose given numbers ar[]={4,1,2,3,1,2,4,3,4}, n=9
* We know how xor property works, if a bit is 1 then again 1 bit is come then this bit is off.
* So here ans=0 = 0000, iterate 9 times:
* ar[0]=4 ans^=4 = 0^4 = 0000 ^ 0100 = 0100 = 4
* ar[1]=1 ans^=1 = 4^1 = 0100 ^ 0001 = 0101 = 5
* ar[2]=2 ans^=2 = 5^2 = 0101 ^ 0010 = 0111 = 7
* ar[3]=3 ans^=3 = 7^3 = 0111 ^ 0011 = 0100 = 4
* ar[4]=1 ans^=1 = 4^1 = 0100 ^ 0001 = 0101 = 5
* ar[5]=2 ans^=2 = 5^2 = 0101 ^ 0010 = 0111 = 7
* ar[6]=4 ans^=4 = 7^4 = 0111 ^ 0100 = 0011 = 3
* ar[7]=3 ans^=3 = 3^3 = 0011 ^ 0011 = 0000 = 0
* ar[8]=4 ans^=4 = 0^4 = 0000 ^ 0100 = 0100 = 4
*
* ans = 4, only this number is come in this array odd times
*
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long ar[]={4,1,2,3,1,2,4,3,4};
    long n=9;
    long ans=0;
    for(int i=0;i<n;i++) ans^=ar[i];
    cout << ans << endl;
    return 0;
}

