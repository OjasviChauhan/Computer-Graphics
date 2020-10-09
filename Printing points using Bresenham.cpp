#include <bits/stdc++.h>
using namespace std;

int main(){
    int x1 = 20; int y1 = 10;
    int x2 = 30; int y2 = 18;
    
    int dx = x2-x1;
    int dy = y2-y1;
    
    int p0 = 2*dy - dx;
    int p = p0;
    
    cout<<'('<<x1<<','<<y1<<')'<<endl;
    
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
    return 0;
}
