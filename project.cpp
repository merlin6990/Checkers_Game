#include<iostream>
#include <Windows.h>
#include<string>
#include<cmath>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
using namespace std;
void board(){
	cout<<"     a   b   c   d   e   f   g   h   \n"<<"   ";
	   for(int i=1;i<=33;i++){
		cout<<"-";
		if(i==33){
			cout<<"\n";
		}
    }
    for(int i=8;i>=1;i--){
    	cout<<" "<<i<<" ";
    	cout<<"|   |   |   |   |   |   |   |   |"<<"\n   ";	
	   for(int i=1;i<=33;i++){
		cout<<"-";
		if(i==33){
			cout<<"\n";
		}
    }	    	
    	
	}
	for(int i=9;i<=33;i=i+8){
		gotoxy(i,2);
		cout<<"O";
		gotoxy(i,6);
		cout<<"O";
		if(i==33){
			for(int j=5;j<=29;j=j+8){
				gotoxy(j,4);
				cout<<"O";
			}
		}
	}
	for(int i=5;i<=29;i=i+8){
		gotoxy(i,12);
		cout<<"X";
		gotoxy(i,16);
		cout<<"X";
		if(i==29){
			for(int j=9;j<=33;j=j+8){
				gotoxy(j,14);
				cout<<"X";
			}
		}
	}	
	gotoxy(0,18);
}

//background
//backend
int back[8][8]={{0,-1,0,-1,0,-1,0,-1},{-1,0,-1,0,-1,0,-1,0},{0,-1,0,-1,0,-1,0,-1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{1,0,1,0,1,0,1,0},{0,1,0,1,0,1,0,1},{1,0,1,0,1,0,1,0}};
bool isvalid=true,bonus=false;
bool X_won=false,O_won=false;
int countx=0,county=0;
void change(char y1,int x1,char y2,int x2,int i){
	int xs=-1*(x1)+8;
	int ys=int(y1)-97;
	int xf=-1*(x2)+8;
	int yf=int(y2)-97;	

	
	
	
	
	if((i%2==1)&&(back[xs][ys]!=11)){
		
		if(back[xs][ys]!=1){
			isvalid= false;
			return;
		}
		if((back[xf][yf]==-1) || (back[xf][yf]==1)){
			isvalid= false;
			return;
		}
		if(((xf%2==0) &&(yf%2==0)) || ((xf%2==1) && (yf%2==1))){
			isvalid= false;
			return;			
		}
		if((xs-xf>2) || (xs-xf<=0)){
			isvalid= false;
			return;				
		}
		if((xs-xf ==2) && ((back[(xf+xs)/2][(ys+yf)/2]!=-1) && (back[(xf+xs)/2][(ys+yf)/2]!=-11))){
			isvalid= false;
			return;			
		}
		if((xs-xf==1) && ((back[xs+1][ys-1]==-1) ||(back[xs+1][ys-1]==-11) ||  (back[xs+1][ys+1]==-1) ||(back[xs+1][ys+1]==-11)  || (back[xs-1][ys+1]==-1) ||(back[xs-1][ys-1]==-1)  || (back[xs-1][ys+1]==-11) ||(back[xs-1][ys-1]==-11)  )){
			if(((back[xs-1][ys-1]==-1) ||(back[xs-1][ys-1]==-11))&& (back[xs-2][ys-2]==0) &&((xs-2<8)&&(ys-2<8))){
				isvalid=false;
				return;
			}
			if(((back[xs-1][ys+1]==-1) ||(back[xs-1][ys+1]==-11))&& (back[xs-2][ys+2]==0) &&((xs-2<8)&&(ys+2<8))){
				isvalid=false;
				return;
			}			
		}
		if(xs-xf ==1){
			back[xs][ys]=0;
			back[xf][yf]=1;
		}
		else if(xs-xf ==2){
			back[xs][ys]=0;
			back[(xs+xf)/2][(ys+yf)/2]=0;
			back[xf][yf]=1;
			bonus=true;			
		}
		for(int i=0;i<=7;i++){
			if(back[0][i]==1){
				back[0][i]=11;
			}
		}
	}
	else if((i%2==1)&&(back[xs][ys]==11)){
		if((back[xf][yf]==-1) || (back[xf][yf]==1)){
			isvalid= false;
			return;
		}
		if(((xf%2==0) &&(yf%2==0)) || ((xf%2==1) && (yf%2==1))){
			isvalid= false;
			return;			
		}
		if((xs-xf>2) || (xs-xf<-2)){
			isvalid= false;
			return;				
		}		
		if(((xs-xf ==2) || (xs-xf ==-2)) && ((back[(xf+xs)/2][(ys+yf)/2]!=-1) && (back[(xf+xs)/2][(ys+yf)/2]!=-11))){
			isvalid= false;
			return;			
		}	
		if(((xs-xf==1) || (xs-xf==-1)) && ((back[xs+1][ys-1]==-1) ||(back[xs+1][ys-1]==-11) ||  (back[xs+1][ys+1]==-1) ||(back[xs+1][ys+1]==-11)  || (back[xs-1][ys+1]==-1) ||(back[xs-1][ys-1]==-1)  || (back[xs-1][ys+1]==-11) ||(back[xs-1][ys-1]==-11)  )){
			if(((back[xs+1][ys-1]==-1) ||(back[xs+1][ys-1]==-11)) &&(back[xs+2][ys-2]==0) &&((xs+2<8)&&(ys-2<8))){
					isvalid=false;
					return;
			}
			if(((back[xs+1][ys+1]==-1) ||(back[xs+1][ys+1]==-11)) &&(back[xs+2][ys+2]==0) &&((xs+2<8)&&(ys+2<8))){
					isvalid=false;
					return;
			}
			if(((back[xs-1][ys-1]==-1) ||(back[xs-1][ys-1]==-11)) &&(back[xs-2][ys-2]==0) &&((xs-2<8)&&(ys-2<8))){
					isvalid=false;
					return;
			}
			if(((back[xs-1][ys+1]==-1) ||(back[xs-1][ys+1]==-11)) &&(back[xs-2][ys+2]==0)&&((xs-2<8)&&(ys+2<8))){
					isvalid=false;
					return;
			}						
		}
		if((xs-xf==1) ||(xs-xf==-1)){
			back[xs][ys]=0;
			back[xf][yf]=11;			
		}
		else if(((xs-xf ==2) || (xs-xf ==-2))){
			back[xs][ys]=0;
			back[(xs+xf)/2][(ys+yf)/2]=0;
			back[xf][yf]=11;
			bonus=true;			
		}						
	}
	else if((i%2==0) && (back[xs][ys]!=-11)){
		if(back[xs][ys]!=-1){
			isvalid= false;
			return;
		}		
		if((back[xf][yf]==-1) || (back[xf][yf]==1)){
			isvalid= false;
			return;
		}
		if(((xf%2==0) &&(yf%2==0)) || ((xf%2==1) && (yf%2==1))){
			isvalid=false;
			return;
		}
		if((xs-xf<-2) || (xs-xf>=0)){
			isvalid= false;
			return;				
		}
		if((xs-xf ==-2) && ((back[(xf+xs)/2][(ys+yf)/2]!=1) && (back[(xf+xs)/2][(ys+yf)/2]!=11))){
			isvalid= false;
			return;			
		}
		if((xs-xf==-1) && ((back[xs+1][ys-1]==1) ||(back[xs+1][ys-1]==11) ||  (back[xs+1][ys+1]==1) ||(back[xs+1][ys+1]==11)  || (back[xs-1][ys+1]==1) ||(back[xs-1][ys-1]==1)  || (back[xs-1][ys+1]==11) ||(back[xs-1][ys-1]==11)  )){
			if(((back[xs+1][ys-1]==1) ||(back[xs+1][ys-1]==11))&& (back[xs+2][ys-2]==0)&&((xs+2<8)&&(ys-2<8))){
				isvalid=false;
				return;
			}
			if(((back[xs+1][ys+1]==1) ||(back[xs+1][ys+1]==11))&& (back[xs+2][ys+2]==0)&&((xs+2<8)&&(ys+2<8))){
				isvalid=false;
				return;
			}
		}				
		if(xs-xf ==-1){
			back[xs][ys]=0;
			back[xf][yf]=-1;
		}
		else if(xs-xf ==-2){
			back[xs][ys]=0;
			back[(xs+xf)/2][(ys+yf)/2]=0;
			back[xf][yf]=-1;
			bonus=true;			
		}		
		for(int i=0;i<=7;i++){
			if(back[7][i]==-1){
				back[7][i]=-11;
			}
		}					
	}
	else if((i%2==0)&&(back[xs][ys]==-11)){		
		if((back[xf][yf]==-1) || (back[xf][yf]==1)){
			isvalid= false;
			return;
		}		
		if(((xf%2==0) &&(yf%2==0)) || ((xf%2==1) && (yf%2==1))){
			isvalid= false;
			return;			
		}
		if((xs-xf>2) || (xs-xf<-2)){
			isvalid= false;
			return;				
		}
		if(((xs-xf ==2) || (xs-xf ==-2)) && ((back[(xf+xs)/2][(ys+yf)/2]!=1) && (back[(xf+xs)/2][(ys+yf)/2]!=11) )){
			isvalid= false;
			return;			
		}
		if(((xs-xf==1) || (xs-xf==-1)) && ((back[xs+1][ys-1]==1) ||(back[xs+1][ys-1]==11) ||  (back[xs+1][ys+1]==1) ||(back[xs+1][ys+1]==11)  || (back[xs-1][ys+1]==1) ||(back[xs-1][ys-1]==1)  || (back[xs-1][ys+1]==11) ||(back[xs-1][ys-1]==11)  )){
			if(((back[xs+1][ys-1]==1) ||(back[xs+1][ys-1]==11)) &&(back[xs+2][ys-2]==0)&&((xs+2<8)&&(ys-2<8))){
					isvalid=false;
					return;
			}
			if(((back[xs+1][ys+1]==1) ||(back[xs+1][ys+1]==11)) &&(back[xs+2][ys+2]==0)&&((xs+2<8)&&(ys+2<8))){
					isvalid=false;
					return;
			}
			if(((back[xs-1][ys-1]==1) ||(back[xs-1][ys-1]==11)) &&(back[xs-2][ys-2]==0)&&((xs-2<8)&&(ys-2<8))){
					isvalid=false;
					return;
			}
			if(((back[xs-1][ys+1]==1) ||(back[xs-1][ys+1]==11)) &&(back[xs-2][ys+2]==0)&&((xs-2<8)&&(ys+2<8))){
					isvalid=false;
					return;
			}
		}		
		if((xs-xf==1) ||(xs-xf==-1)){
			back[xs][ys]=0;
			back[xf][yf]=-11;			
		}
		else if(((xs-xf ==2) || (xs-xf ==-2))){
			back[xs][ys]=0;
			back[(xs+xf)/2][(ys+yf)/2]=0;
			back[xf][yf]=-11;
			bonus=true;			
		}								
	}
	
	
	if(i%2==1){
	for(int i=0;i<=7;i++){
		for(int j=0;j<=7;j++){
			if((back[i][j]==0)  || (back[i][j]==1) || (back[i][j]==11)){
				countx++;
			}
		}
	}	
	if(countx==64){
		X_won=true;
		return;
	}
	else{
	countx=0;}
	return;
}
else{
	for(int i=0;i<=7;i++){
		for(int j=0;j<=7;j++){
			if((back[i][j]==0)  || (back[i][j]==-1) || (back[i][j]==-11)){
				county++;
			}
		}
	}
	if(county==64){
		O_won=true;
		return;
	}
	else{
	county=0;}		
}
}
//moves
void move(char x,int s,char y,int f,int i){
	int xs,ys,xf,yf;
	xs=4*(int(x)-96)+1;
	ys=16-(2*(s-1));
	xf=4*(int(y)-96)+1;
	yf=16-(2*(f-1));
	
	
	int xars=-1*(s)+8;
	int yars=int(x)-97;
	int xarf=-1*(f)+8;
	int yarf=int(y)-97;
	
	change(x,s,y,f,i);



















}