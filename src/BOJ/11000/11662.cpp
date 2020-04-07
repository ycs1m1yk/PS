#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// 삼분탐색 공부하고 풀기
double getP2PDist(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// double ternary(double lo, double hi){
//     for(int i=0; i<100; i++){
//         double a = (2*lo+hi) / 3.0;
//         double b = (lo+2*hi) / 3.0;
//         if(getP2PDist(a)<getP2PDist(b)) hi=b;
//         else lo=a;
//     }
//     return (lo+hi)/2.0;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    double deltaStep = 1000000;
    double deltaMinhoX = abs(Ax - Bx) / deltaStep;
    double deltaMinhoY = abs(Ay - By) / deltaStep;
    double deltaKanghoX = abs(Cx - Dx) / deltaStep;
    double deltaKanghoY = abs(Cy - Dy) / deltaStep;
    double min1 = getP2PDist(Ax, Ay, Cx, Cy);

    double result = min1;
    for (int i = 1; i <= deltaStep; i++)
    {
        double tmp = getP2PDist(Ax + deltaMinhoX, Ay + deltaMinhoY, Cx + deltaKanghoX, Cy + deltaKanghoY);
        result = min(min1, tmp);
    }

    cout.precision(10);
    cout << fixed;
    cout << result;
}
