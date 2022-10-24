// Game QvsK for Linux
// If you want to play it on Windows, you should change the function cls().

#include<bits/stdc++.h>
using namespace std;
// Clear the screen
// If you want to play it on Windows, change it to this:
// int cls(){return system("cls");}
int cls(){return system("clear");}
struct point{
	int x,y;
	point(int _x=0,int _y=0):x(_x),y(_y){}
	bool operator == (const point &b)const{
		return x==b.x&&y==b.y;
	}
};
bool isHacked(const point &k,const point &q){
	return k.x==q.x||k.y==q.y||k.x+k.y==q.x+q.y||k.x-k.y==q.x-q.y;
}
int mxn=9,mxm=9;
struct Queen{
	private:
		point now;
	public:
		int l(int step){
			if(step<=0||now.y-step<0) return 1;
			now.y-=step;
			return 0;
		}
		int r(int step){
			if(step<=0||now.y+step>mxm) return 1;
			now.y+=step;
			return 0;
		}
		int d(int step){
			if(step<=0||now.x+step>mxn) return 1;
			now.x+=step;
			return 0;
		}
		int u(int step){
			if(step<=0||now.x-step<0) return 1;
			now.x-=step;
			return 0;
		}
		int ld(int step){
			point _now=now;
			if(l(step)||d(step)){
				now=_now;
				return 1;
			}
			return 0;
		}
		int lu(int step){
			point _now=now;
			if(l(step)||u(step)){
				now=_now;
				return 1;
			}
			return 0;
		}
		int rd(int step){
			point _now=now;
			if(r(step)||d(step)){
				now=_now;
				return 1;
			}
			return 0;
		}
		int ru(int step){
			point _now=now;
			if(r(step)||u(step)){
				now=_now;
				return 1;
			}
			return 0;
		}
		point getLocation(){
			return now;
		}
		int setLocation(point loc){
			if(loc.x>=0&&loc.x<=mxn&&loc.y>=0&&loc.y<=mxm){
				now=loc;
				return 0;
			}
			return 1;
		}
		int setLocation(int x,int y){
			return setLocation(point(x,y));
		}
};
struct King{
	private:
		point now;
		int l(int step){
			if(step<0||now.y-step<0) return 1;
			now.y-=step;
			return 0;
		}
		int r(int step){
			if(step<0||now.y+step>mxm) return 1;
			now.y+=step;
			return 0;
		}
		int d(int step){
			if(step<0||now.x+step>mxn) return 1;
			now.x+=step;
			return 0;
		}
		int u(int step){
			if(step<0||now.x-step<0) return 1;
			now.x-=step;
			return 0;
		}
		int ld(int step){
			point _now=now;
			if(l(step)||d(step)){
				now=_now;
				return 1;
			}
			return 0;
		}
		int lu(int step){
			point _now=now;
			if(l(step)||u(step)){
				now=_now;
				return 1;
			}
			return 0;
		}
		int rd(int step){
			point _now=now;
			if(r(step)||d(step)){
				now=_now;
				return 1;
			}
			return 0;
		}
		int ru(int step){
			point _now=now;
			if(r(step)||u(step)){
				now=_now;
				return 1;
			}
			return 0;
		}
	public:
		int l() {return l(1);}
		int r() {return r(1);}
		int d() {return d(1);}
		int u() {return u(1);}
		int ld(){return ld(1);}
		int lu(){return lu(1);}
		int rd(){return rd(1);}
		int ru(){return ru(1);}
		point getLocation(){return now;}
		int setLocation(point loc){
			if(loc.x>=0&&loc.x<=mxn&&loc.y>=0&&loc.y<=mxm){
				now=loc;
				return 0;
			}
			return 1;
		}
		int setLocation(int x,int y){
			return setLocation(point(x,y));
		}
};
bool isHacked(King &k,Queen &q){
	return isHacked(k.getLocation(),q.getLocation());
}
struct ChessState{
	King k;
	Queen q;
	bool judge(){
		if(k.d()==0){
			if(!isHacked(k,q)){
				k.u();
				return 0;
			}
			k.u();
		}
		if(k.u()==0){
			if(!isHacked(k,q)){
				k.d();
				return 0;
			}
			k.d();
		}
		if(k.l()==0){
			if(!isHacked(k,q)){
				k.r();
				return 0;
			}
			k.r();
		}
		if(k.r()==0){
			if(!isHacked(k,q)){
				k.l();
				return 0;
			}
			k.l();
		}
		if(k.rd()==0){
			if(!isHacked(k,q)){
				k.lu();
				return 0;
			}
			k.lu();
		}
		if(k.ld()==0){
			if(!isHacked(k,q)){
				k.ru();
				return 0;
			}
			k.ru();
		}
		if(k.ru()==0){
			if(!isHacked(k,q)){
				k.ld();
				return 0;
			}
			k.ld();
		}
		if(k.lu()==0){
			if(!isHacked(k,q)){
				k.rd();
				return 0;
			}
			k.rd();
		}
		return 1;
	}
	void printState(const bool isKing=1){
		printf("\\");
		for(int j=0;j<=mxm;j++){
			printf(" %d",j);
		}
		printf("\n");
		for(int i=0;i<=mxn;i++){
			printf(" +");
			for(int j=0;j<=mxm;j++){
				printf("-+");
			}
			printf("\n%d|",i);
			for(int j=0;j<=mxm;j++){
				if(point(i,j)==q.getLocation()){
					printf("Q|");
					continue;
				}
				if(point(i,j)==k.getLocation()&&isKing){
					printf("K|");
					continue;
				}
				if(isHacked(point(i,j),q.getLocation())){
					printf("*|");
				}
				else{
					printf(" |");
				}
			}
			printf("\n");
		}
		printf(" +");
		for(int j=0;j<=mxm;j++){
			printf("-+");
		}
		printf("\n");
	}
}chess;
string line;
stringstream input;
vector<int> kingsMove;
vector<pair<int,int> > queensMove;
int main(){
	cls();
	printf("King's turn.\nPress `Enter' to continue...");
	getline(cin,line);
	cls();
	printf("Please input King's location.\n");
	while(1){
		getline(cin,line);
		input.clear();
		input<<line;
		int x,y;
		if(input>>x>>y&&!chess.k.setLocation(x,y)){
			cls();
			break;
		}
		cls();
		printf("Something wrong...\nPlease input King's location again.\n");
	}
	printf("Queen's turn.\nPress `Enter' to continue...");
	getline(cin,line);
	cls();
	printf("Please input Queen's location.\n");
	while(1){
		getline(cin,line);
		input.clear();
		input<<line;
		int x,y;
		if(input>>x>>y&&!chess.q.setLocation(x,y)){
			cls();
			break;
		}
		cls();
		printf("Something wrong...\nPlease input Queen's location again.\n");
	}
	cls();
	while(!chess.judge()){
		printf("King's turn.\nPress `Enter' to continue...");
		getline(cin,line);
		cls();
		while(1){
			chess.printState();
			printf("Please input the next step(direction).\nDirections:\n7\\ 8^ 9/\n4<    6>\n1/ 2v 3\\\n");
			getline(cin,line);
			input.clear();
			input<<line;
			int x;
			bool somethingWrong=0;
			point _now=chess.k.getLocation();
			if(input>>x){
				switch (x)
				{
				case 7:
					if(chess.k.lu()){
						somethingWrong=1;
					}
					break;
				case 8:
					if(chess.k.u()){
						somethingWrong=1;
					}
					break;
				case 9:
					if(chess.k.ru()){
						somethingWrong=1;
					}
					break;

				case 4:
					if(chess.k.l()){
						somethingWrong=1;
					}
					break;
				case 6:
					if(chess.k.r()){
						somethingWrong=1;
					}
					break;
				
				case 1:
					if(chess.k.ld()){
						somethingWrong=1;
					}
					break;
				case 2:
					if(chess.k.d()){
						somethingWrong=1;
					}
					break;
				case 3:
					if(chess.k.rd()){
						somethingWrong=1;
					}
					break;
				
				default:
					somethingWrong=1;
					break;
				}
			}
			else somethingWrong=1;
			if(isHacked(chess.k,chess.q)){
				chess.k.setLocation(_now);
				somethingWrong=1;
			}
			if(somethingWrong){
				cls();
				printf("Something wrong...\nPlease input again.\n");
			}
			else{
				kingsMove.push_back(x);
				break;
			}
		}
		cls();
		printf("Queen's turn.\nPress `Enter' to continue...");
		getline(cin,line);
		cls();
		while(1){
			chess.printState(0);
			printf("Please input the next step(direction&step).\nDirections:\n7\\ 8^ 9/\n4<    6>\n1/ 2v 3\\\n");
			printf("King's Last Move: %d\n",kingsMove.back());
			getline(cin,line);
			input.clear();
			input<<line;
			int x,s;
			bool somethingWrong=0;
			if(input>>x>>s){
				switch (x)
				{
				case 7:
					if(chess.q.lu(s)){
						somethingWrong=1;
					}
					break;
				case 8:
					if(chess.q.u(s)){
						somethingWrong=1;
					}
					break;
				case 9:
					if(chess.q.ru(s)){
						somethingWrong=1;
					}
					break;

				case 4:
					if(chess.q.l(s)){
						somethingWrong=1;
					}
					break;
				case 6:
					if(chess.q.r(s)){
						somethingWrong=1;
					}
					break;
				
				case 1:
					if(chess.q.ld(s)){
						somethingWrong=1;
					}
					break;
				case 2:
					if(chess.q.d(s)){
						somethingWrong=1;
					}
					break;
				case 3:
					if(chess.q.rd(s)){
						somethingWrong=1;
					}
					break;
				
				default:
					somethingWrong=1;
					break;
				}
			}
			else somethingWrong=1;
			if(somethingWrong){
				cls();
				printf("Something wrong...\nPlease input again.\n");
			}
			else break;
		}
		cls();
	}
	cls();
	chess.printState();
	printf("Game Over.\nKing's Last Location: (%d,%d)\nQueen's Last Location: (%d,%d)\n",
		chess.k.getLocation().x,chess.k.getLocation().y,chess.q.getLocation().x,chess.q.getLocation().y);
	return 0;
}
