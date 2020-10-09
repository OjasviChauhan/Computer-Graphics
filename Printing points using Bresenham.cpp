#include <bits/stdc++.h>
using namespace std;

int main(){
    int x1 = 20; int y1 = 18;
    int x2 = 30; int y2 = 10;
    
    double dx = x2-x1;
    double dy = y2-y1;
    
    double m = dy/dx;
    
    int p0 = 2*dy - dx;
    int p = p0;
    
    cout<<'('<<x1<<','<<y1<<')'<<endl;
    
    if(m>0){
        for(int i=0;i<dx;i++){
            if(p<0){
                x1++;
                cout<<'('<<x1<<','<<y1<<')'<<endl;
                p += 2*dy;
            }
            else{
                x1++; y1++;
                cout<<'('<<x1<<','<<y1<<')'<<endl;
                p += 2*dy - 2*dx;
            }
        }
    }
    else{
        for(int i=0;i<dx;i++){
            //cout<<p<<endl;
            if(p<0){
                x1++;
                cout<<'('<<x1<<','<<y1<<')'<<endl;
                p += 2*dx;
            }
            else{
                x1++; y1--;
                cout<<'('<<x1<<','<<y1<<')'<<endl;
                p += 2*dx - 2*dy;
            }
        }
    }
    return 0;
}
