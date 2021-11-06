#include <cstdio>

using namespace std;

struct ClockTimes {
    int h, m, s;
    ClockTimes(): h(0), m(0), s(0){};
    void get(){ scanf("%d:%d:%d", &h, &m, &s); }
    void print(){ printf("%02d:%02d:%02d", h, m, s); }
    ClockTimes& operator=(const ClockTimes& t){
        h=t.h;
        m=t.m;
        s=t.s;

        return *this;
    }

    bool operator==(const ClockTimes& t)const{
        return (h==t.h && m==t.m && s==t.s);
    } 

    ClockTimes operator-(const ClockTimes& t)const{
        ClockTimes result;
        int temp = s-t.s;
        bool carry = (temp < 0);
        result.s = (temp + 60) % 60;
        temp = m-t.m-carry;
        carry=(temp<0);
        result.m=(temp+60)%60;
        result.h=(h-t.h-carry+24)%24;

        return result;
    }
};


int main(){
    ClockTimes now;
    ClockTimes when;
    scanf("%d:%d:%d", &now.h, &now.m, &now.s);
    scanf("%d:%d:%d", &when.h, &when.m, &when.s);
    
    if(now==when){
        printf("24:00:00");
        return 0;
    }

    when.h+=24;
    ClockTimes answer = when-now;
    answer.print();
}