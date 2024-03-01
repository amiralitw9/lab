#include<bits/stdc++.h>
using namespace std ;
//اول تعداد داده ها
//بعد داده ها به صورتی که اول ایکس و بعد ایگرگ 
int main() {
    int n ;
    cin>>n ;
    double list_y[n];
    double list_x[n];
    double list_Y[n];
    double Y_bar;
    double y_bar;
    double x_bar;
    double shib ;
    double regression;
    double arz_mabda;
    double delta_a ;
    double delta_b;
    for(int i = 0 ; i<n ; i++){
        double a,b ;
        cin>>a>>b;
        list_x[i]=a;
        list_y[i]=b;
    }
    double sum_1 =0 , sum_2 = 0;
    for(int i =0 ; i<n ; i++){
        sum_1+=list_y[i];
        sum_2+=list_x[i];
    }
    y_bar= sum_1/n;
    x_bar = sum_2/n;
    sum_1 = 0 ;
    sum_2= 0 ;
    for(int i = 0 ; i<n ; i++) {
        sum_1+=(list_x[i]-x_bar)*list_y[i];
        sum_2+=pow((list_x[i]-x_bar),2);
    }
    shib= sum_1/sum_2;
    arz_mabda=y_bar-shib*x_bar;
    sum_1=0;
    sum_2=0;
    for(int i = 0 ; i<n ; i++) {
        list_Y[i]=276.66*list_x[i]+1.09;
    }
    for(int i = 0 ; i<n ; i++) {
        sum_1+=list_Y[i];
    }
    Y_bar=sum_1/n;
    sum_1=0;
    for(int i = 0 ; i<n ; i++) {
        sum_1+=pow((list_y[i]-Y_bar),2);
        sum_2+=pow((list_Y[i]-y_bar),2);
    }
    regression=sqrt(sum_2/sum_1);
    sum_1=0;
    sum_2=0;
    for(int i = 0 ; i<n ; i++) {
        sum_1+=pow((list_y[i]-shib*list_x[i]-arz_mabda),2);
        sum_2+=pow((list_x[i]-x_bar),2);
    }
    delta_a = sqrt(sum_1/sum_2/(n-2));
    delta_b= sqrt((((1/n)+(pow(x_bar,2)/sum_2))/(n-2)*sum_1));
    //**********************
    printf("shib= %f \n arzazmabda = %f \n x_bar = %f \n y_bar = %f \n Y_bar = %f \n regression = %f \n delta a = %f \n delta b = %f \n" , shib,arz_mabda,x_bar,y_bar,Y_bar,regression,delta_a,delta_b);

}
