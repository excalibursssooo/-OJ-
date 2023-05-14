#include<stdio.h>

int poww(int n,int m){
    int a = n;
    for(int i = 0;i<m-1;i++){
        n=n*a;
    }
    return n;
}