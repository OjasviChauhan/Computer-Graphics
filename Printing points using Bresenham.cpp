#include<bits/stdc++.h> 
using namespace std; 
  
// function for line generation 
void bresenham(int X1, int Y1, int X2, int Y2) { 
    float M,p,dx,dy,x,y,t;
	if(X2-X1==0)
		M = Y2-Y1;
	else
		M = (Y2-Y1)/(X2-X1);

	if(fabs(M)<1)				// for values btw -1.0 to 1.0
	{
		if(X1>X2){				// if values are interchanged
			t = X1;
			X1 = X2;
			X2 = t;

			t = Y1;
			Y1 = Y2;
			Y2 = t;
		}

		dx = fabs(X2-X1);
		dy = fabs(Y2-Y1);

		p = 2*dy - dx;

		x=X1;
		y=Y1;
		while(x<=X2){
			cout<<x<<" "<<y<<endl;
			x=x+1;
		
			if(p>=0){
			    if(M>0)				// handling the case where slope will be +ve and btw 0.0 to 1.0
					y=y+1;
				else				// handling the case where slope will be -ve and btw -1.0 to 0.0
					y=y-1;

				p = p+2*dy-2*dx;
			}
			else{
				y=y;
				p = p+2*dy;
			}
		}
	}
	
	if(fabs(M)>=1)				// for values less than -1.0 and greater than 1.0
	{
		if(Y1>Y2){
			t = X1;
			X1 = X2;
			X2 = t;

			t = Y1;
			Y1 = Y2;
			Y2 = t;
		}

		dx = fabs(X2-X1);
		dy = fabs(Y2-Y1);

		p = 2*dx - dy;

		x=X1;
		y=Y1;
		while(y<=Y2){
			cout<<x<<" "<<y<<endl;
			y=y+1;
			if(p>=0){
				if(M>=0)
					x=x+1;
				else
					x=x-1;
				p = p+2*dx-2*dy;
			}
			else{
				x=x;
				p = p+2*dx;
			}
		}
	}
} 
  
// driver function 
int main() 
{ 
  int x1 = 10, y1 = 15, x2 = 20, y2 = 30; 
  bresenham(x1, y1, x2, y2); 
  return 0; 
} 
