#include<stdio.h>
#include<math.h>
float function1(int),function2(int),function3(int),function4(int),function5(int),function6(int),function7(int),function8(int),function9(int),function10(int),function11(int);
int main(){
    int a=1;
    printf("%f\n",function4(3));
    for(int i=1;i<=20;i++){
        printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n",function1(i),function2(i),function3(i),function4(i),function5(i),function6(i),function7(i),function8(i),function9(i),function10(i));
        printf("\n%f ",function11(i));
    }
    return 0;
}
float function1(int n){//n
    return n;
}
float function2(int n){//n^3
    return n*n*n;
}
float function3(int n){//1.5^n
    return pow(1.5,n);
}
float function4(int n){//2^n
    return pow(2,n);
}
float function5(int n){//2^(2^n)
    return pow(2,pow(2,n));
}
float function6(int n){//2^(2^(n+1))
    return pow(2,pow(2,n+1));
}
float function7(int n){//n*(2^n)
    return n*pow(2,n);
}
float function8(int n){//log(n)
    return log(n);
}
float function9(int n){//n*log(n)
    return n*log(n);
}
float function10(int n){//2^(log(n))
    return pow(2,log(n));
}
float function11(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*function11(n-1);
    }
}