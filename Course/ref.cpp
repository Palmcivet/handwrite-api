#include<stdio.h>
#include<time.h>
#include<stdlib.h>			//system("cls");刷新
#include<string.h>
#include <windows.h>
#include <conio.h>

int number[4][4]={0};
int board[4][4]={0};

int judge(int m,int n);
void A(int r);
void D(int r);
void W(int r);
void S(int r);
void changeA(int n1,int m1);
void changeD(int n1,int m1);
void changeS(int n1,int m1);
void changeW(int n1,int m1);
void print(void);
void give(void);
void sumA(int r,int o);
void sumD(int r,int o);
void sumW(int r,int o);
void sumS(int r,int o);
void color(short x) ;//自定义函根据参数改变颜色   

int main(){
		printf("按W，A，S,D控制上下左右，移动数字\n");
		printf("\n");
		srand(time(NULL));
		int x1=rand()%4;
		int y1=rand()%4;
		int x2=rand()%4;
		int y2=rand()%4;
		y2=judge(y2,y1);
		//printf("%d   %d\n",x1,y1);
		//printf("%d   %d\n",x2,y2);
		
		number[x1][y1]=2;
		number[x2][y2]=2;
		give();
		print();
	
		
		while(1){
			int key_command;
			key_command=getch();
			int x3,y3;
			x3=rand()%4;
			y3=rand()%4;
			
			
			memset(board,0,sizeof(board));
			if(key_command	=='a'||key_command	=='A'){
				for(int j=0;j<=3;j++){
					for(int i=0;i<4;i++){
						A(i);	
					}
				}
				for(int i=0;i<4;i++){
					sumA(i,3);
				}
				
			}
			
		 	if(key_command=='d'||key_command=='D'){
				for(int j=0;j<=3;j++){
					for(int i=0;i<4;i++){
						D(i);	
					}
				}
				for(int i=0;i<4;i++){
					sumD(i,0);
				}
				
			}
			
			if(key_command=='w'||key_command=='W'){
				for(int j=0;j<=3;j++){
					for(int i=0;i<4;i++){
						W(i);	
					}
				}
				for(int i=0;i<4;i++){
					sumW(4,i);
				}
				
			}
			
			if(key_command=='s'||key_command=='S'){
				for(int j=0;j<=3;j++){
					for(int i=0;i<4;i++){
						S(i);	
					}
				}
				for(int i=0;i<4;i++){
					sumS(0,i);
				}
				
			}
			if(key_command=='g')return 0;
			while(number[x3][y3]!=0){
				x3=rand()%4;
				y3=rand()%4;
			}
			number[x3][y3]=2*(1+rand()%2);
			//16个格子都满了，且，每个格子上下左右的数字都不一样 
			system("cls");
			give();
			print();

		}

}
void sumA(int r,int o){
	if((number[r][o]==number[r][o-1])&&(number[r][o]!=0)){
		number[r][o-1]=number[r][o]*2;
		number[r][o]=0;
		A(r);
	}
	else if(o>1){
		sumA(r,o-1);
	}
}

void sumD(int r,int o){
	if((number[r][o]==number[r][o+1])&&(number[r][o]!=0)){
		number[r][o+1]=number[r][o]*2;
		number[r][o]=0;
		D(r);
	}
	else if(o<2){
		sumD(r,o+1);
	}
}

void sumW(int r,int o){
	if((number[r][o]==number[r-1][o])&&(number[r][o]!=0)){
		number[r-1][o]=number[r][o]*2;
		number[r][o]=0;
	}
	else if(r>1){
		sumW(r-1,o);
	}

}

void sumS(int r,int o){
	if((number[r][o]==number[r+1][o])&&(number[r][o]!=0)){
		number[r+1][o]=number[r][o]*2;
		number[r][o]=0;
	}
	else if(r<2){
		sumS(r+1,o);
	}
}

int judge(int m,int n){
	if(m!=n){
		return m;
	}
	else {
		m=rand()%4;
		judge(m,n);
	}

}

void A(int r){
	if(number[r][0]==0){
		changeA(r,0);
	}
 	else if(number[r][1]==0){
		changeA(r,1);
	}
 	else if(number[r][2]==0){
		changeA(r,2);
	}
}

void changeA(int n1,int m1){
	for(int i=m1;i<=2;i++){
		number[n1][i]=number[n1][i+1];
	}
	number[n1][3]=0;
}

void D(int r){
	if(number[r][3]==0){
		changeD(r,3);
	}
	else if(number[r][2]==0){
		changeD(r,2);
	}
	else if(number[r][1]==0){
		changeD(r,1);
	}
}

void changeD(int n1,int m1){
	for(int i=m1;i>=1;i--){
		number[n1][i]=number[n1][i-1];
	}
	number[n1][0]=0;
	
}

void W(int r){
	if(number[0][r]==0){
		changeW(0,r);
	}
	else if(number[1][r]==0){
		changeW(1,r);
	}
	else if(number[2][r]==0){
		changeW(2,r);
	}
}

void changeW(int n1,int m1){
	for(int i=n1;i<3;i++){
		number[i][m1]=number[i+1][m1];
	}
	number[3][m1]=0;
	
}


void S(int r){
	if(number[3][r]==0){
		changeS(3,r);
	}
	else if(number[2][r]==0){
		changeS(2,r);
	}
	else if(number[1][r]==0){
		changeS(1,r);
	}
}

void changeS(int n1,int m1){
	for(int i=n1;i>=1;i--){
		number[i][m1]=number[i-1][m1];
	}
	number[0][m1]=0;
}




void print(){
			for(int i=0;i<4;i++){
				
				printf("\n");
				printf("\n");
				printf("		");
				for(int j=0;j<4;j++){
						if(board[i][j]==0){
							color(15);//亮白色 
							printf("*	");
						}
						else{
							color(12);//亮红色 
							printf("%d	",board[i][j]);
						}
				}
				printf("\n");
				printf("\n");
			}
			
			printf("输入g退出游戏\n\n");
}

void give(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			board[i][j]=number[i][j];
		}
	}

}

void color(short x) //自定义函根据参数改变颜色   
{  
    if(x>=0 && x<=15)//参数在0-15的范围颜色  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);    //只有一个参数，改变字体颜色   
    else//默认的颜色白色  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  
} 