#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <bitset>
#define MAXLEN 3000

using namespace std;

void Remove(int16_t *memory, int16_t n, int16_t &move);
void Put(int16_t *memory, int16_t n, int16_t &move);
int16_t Baguenaudier(int16_t *memory, int16_t n);
int fun(int n);

int main(){
    int n;
    cin>>n;
    cout<<"取下"<<n<<"个环所需最少次数为"<<fun(n)<<endl;
    int16_t memory[MAXLEN], move;
    move = Baguenaudier(memory, n);
    for(int j = 0; j < move; ++j)
        cout << bitset<16>(memory[j]) << endl;
}

int fun(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return 2*fun(n-2)+fun(n-1)+1;
}

int16_t Baguenaudier(int16_t *memory, int16_t n) {
    int16_t move=0;
    Remove(memory, n,move);
    return move;//move is the number of steps
}
 
void Remove(int16_t *memory, int16_t n, int16_t &move) {
    if (!n) 
        return;
    else if(n==1){
        if(!move)
            memory[move] =1;
        else
            memory[move]=memory[move-1]+1;
        move++;
        return;
    }
    Remove(memory, n - 2,move);
    int16_t temp=1,i=0;
    for(i=1;i<n;i++)
        temp+=temp;
    if(!move)
        memory[move] =temp;
    else
        memory[move]=memory[move-1]+temp;
    move++;
    Put(memory, n - 2,move);
    Remove(memory, n - 1,move);
}
 
void Put(int16_t *memory, int16_t n, int16_t &move) {
    if (!n) 
        return;
    else if(n==1){
        memory[move]=memory[move-1]-1;
        move++;
        return;
    }
    Put (memory, n - 1,move);
    Remove(memory, n - 2,move);
    int16_t temp=1,i=0;
    for(i=1;i<n;i++)
        temp+=temp;
    memory[move]=memory[move-1]-temp;
    move++;
    Put(memory, n - 2,move);
}