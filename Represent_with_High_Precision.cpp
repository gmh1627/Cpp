#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
//用高精度计算出 S =1!+2!+3!+...+ n!（n<=50），此时用long double也会溢出
int main(){
    int n,fac[100]={0},res[100]={0},i=0,j=0;
	cin >> n;
	fac[0]=1;
	res[0]=1;
    for( i = 2; i <= n; ++i) {
        for(j=0;j<100;j++)
			fac[j]*=i;
		for(j=0;j<100;j++){
			if(fac[j]>9){
				fac[j+1]+=fac[j]/10;//进位操作
				fac[j]%=10;
			}		
		}
		for(j=0;j<100;j++){
			res[j]+=fac[j];
			if(res[j]>9){
				res[j+1]+=res[j]/10;
				res[j]%=10;
			}	
		}
    }
    for(i=100;i>=0&&!res[i];i--);
    for(j=i;j>=0;j--)
		cout << res[j];
    return 0;
}
    
