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