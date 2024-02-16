#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdlib>
#include<array>
#include<vector>
using namespace std;
/*char* getname(){
	char temp[80];
	cin>>temp;
	char* pn=new char[strlen(temp)+1];
	strcpy(pn,temp);
	return pn;
}*/
int main()
{
	
	//int a(4);
	//int s[10]{234};	
	//char st1[10];
	//cin.get(st1,10).get();//接下来要读入字符时要用.get()
	//cout<<st1;
	//string a,b,c;
	//getline(cin,a);
	//cin.get();
	//cin>>b;
	//cin.get();
	//c=a+b;
	//cout<<c;
	//enum spectrum{a=-1,b=8,c=10,d=-5,e=200,f=100,g=1000};
	//spectrum band=spectrum(1099);
	//cout<<band;
	/*int x=20;
	{
		cout<<x<<endl;
		int x=200;
		cout<<x<<endl;
	}
	cout<<x<<endl;
	string word="asd";
	char st[20]="asd";
	if(word=="asd"){
		printf("1\n");//TODO
	}
	if(st=="asd"){
		printf("1");//TODO
	}
	int a[10]{2,3,4,5,6,7,8};
	for(int x:a){
		cout<<x<<endl;//TODO
	}
	for(int y:{1,2,3,4,4})
		cout<<y<<endl;*/
	/*char ch;
	int num=0;
	cin.get(ch);
	while(cin){
		cout<<ch+1;//TODO
		++num;
		cin.get(ch);
	}
	cout<<endl<<num;*/
	int num[10];
	/*ofstream fp;
	fp.open("num.txt");
	for(int i=0;i<3;i++){
		cin>>num[i];
	}
	fp<<"hello ";
	for(int i=0;i<3;i++){
		fp<<num[i];
	}
	fp.close();*/
	/*ifstream fp1;
	fp1.open("num.txt");
	if(!fp1.is_open()){
		cout<<"NO!";
	}
	int i=0;
	while(fp1.good()){
		fp1>>num[i];
		cout<<num[i]<<" ";
		i++;
	}*/
	//char *name=getname();
	//cout <<(int *)name;
	//delete name;
	//vector<double>a1={1,2,3,4,5};
	//int a,b;
	//cin>>a>>b;
	//cout<<a<<b;
	
	
}
template<typename Any>
void Swap(Any &a,Any &b)
{
	Any temp;
	temp=a;
	a=b;
	b=temp;
}
