#include<stdio.h>
#include<stdlib.h>
int point[14] = {4,4,4,4,4,4,0,4,4,4,4,4,4,0};
int k,l,f=0,sumi,sumj,i,j;
int player1,player2,player,answer;
int gameboard(),result(),player1calc(),player2calc(),playerChange(int a),enterNumber(int a,int b,int c,int d);
void playercalc(int a,int b,int c,int d,int e,int f,int g,int h,int k,int l);
int main(){
	gameboard();
	player=2;
	do{	
	player=playerChange(player);
	if(player==1){
			if(l!=13){
			player1=enterNumber(player1,1,6,1);
			player1calc();
			result();
			}	
	}else{
			if(k!=6){
			player2=enterNumber(player2,8,13,2);
			player2calc();
			result();
			}	
	}
	}while(f!=1);
}
int playerChange(int a){
	if(a==1){
	return 2;
	}	
	else{
	return 1;
	}	
}
int enterNumber(int a,int b,int c,int d){
	int e=1;
	while(e==1){
	printf("player %d please choose between %d to %d point: \n",d,b,c);
	scanf("%d",&a);
	if(b<=a && a<=c){
	e=0;
	}
	if(a<b || c<a){
		printf("You have to choose a point between %d to %d. \n",b,c);
		e=1;
		continue;
	}
	}
}	
int gameboard(){
	printf("   |  |-p6- -p5- -p4- -p3- -p2- -p1-|  |\n");
	printf("   |  | |%d | |%d | |%d | |%d | |%d| |%d| |  |\n",point[5],point[4],point[3],point[2],point[1],point[0]);
	printf(" p7|%d |-----------------------------|%d |p14\n",point[6],point[13]);
	printf("   |  | |%d | |%d | |%d | |%d | |%d| |%d| |  |\n",point[7],point[8],point[9],point[10],point[11],point[12]);
	printf("   |  |-p8- -p9- -p10 -p11 -p12 -p13|  |\n");	
}
int result(){
	if(point[5]==0 && point[4]==0 && point[3]==0 && point[2]==0 && point[1]==0 && point[0]==0){
		f=1;	
	}
	if(point[12]==0 && point[11]==0 && point[10]==0 && point[9]==0 && point[8]==0 && point[7]==0){
		f=1;	
	}
	if(f==1)
	{
		if(point[6]>point[13]){
			printf("First player won the game\n");
		}
		else if(point[6]<point[13]){
			printf("Second player won the game\n");
		}
		else if(point[6]==point[13]){
			printf("Draw...\n");
		}
	}
	return f;
}
int player1calc(){
	if(0<player1 && player1<7)
	{
	for(int i=0;i<point[player1-1];i++)
	{	
				
		if(player1+i>=13)
		{
			if(player1+i>=13){
				if(player1+i==13){
					point[13]=point[13]-1;
					point[player1+i-13]=point[player1+i-13]+1;
				}
				else if(player1+i>13){
					point[(player1+i)-14]=point[(player1+i)-14]-1;
					point[player1+i-13]=point[player1+i-13]+1;
				}
				
			}	
				point[player1+i-14]=point[player1+i-14]+1;	
		}	
		point[player1+i]=point[player1+i]+1;
		sumi=i;
	}
	
	point[player1-1]=0;		
	k=(player1+sumi);	
		if(player1+sumi>=13)
		{	
			k=k-13;	
		}
		if(point[k]==1 && k!=6 && k!=13 && k!=7 && k!=8 && k!=9 && k!=10 && k!=11 && k!=12)
		{			
			point[6]=point[6]+point[12-(k)]+1;
			point[12-(k)]=point[k]=0;
		}
	}
	gameboard();	
}
int player2calc(){
	if(7<player2 && player2<14)
	{
	for(int j=0;j<point[player2-1];j++)
	{	
				
		if((player2+j)>=14)
		{
			if(player2+j>=20)
		{	
			if(player2+j==20){
				point[6]=point[6]-1;
				point[player2+j-13]=point[player2+j-13]+1;
			}
			else if(player2+j>20){
				point[(player2+j)-14]=point[(player2+j)-14]-1;
				point[player2+j-13]=point[player2+j-13]+1;
			}	
		}
		point[(player2+j)-14]=point[(player2+j)-14]+1;
		}	
		point[player2+j]=point[player2+j]+1;
		sumj=j;
	}
		point[player2-1]=0;
		l=(player2+sumj);
				
		if((player2+sumj)>13)
		{	
				l=l-13;	
		}	
			if(point[l]==1 && l!=6 && l!=13 && l!=0 && l!=1 && l!=2 && l!=3 && l!=4 && l!=5)
				{
					point[13]=point[13]+point[12-(l)]+1;
					point[12-(l)]=point[l]=0;	
				}
	}
	gameboard();
}
