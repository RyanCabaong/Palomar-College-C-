#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class ComboLock{
public:
	ComboLock(int secret1, int secret2, int secret3);
	void reset();
	void turn_left(int ticks);
	void turn_right(int ticks);
	bool open() const;
	int getdial();
private:
	int dial;
	int s1,s2,s3;
	bool check1,check2;
};
ComboLock::ComboLock(int secret1, int secret2, int secret3){
	dial = 0;
	s1 = secret1;
	s2 = secret2;
	s3 = secret3;
	//when tick has turned on secret then true on check
	check1 = false;
	check2 = false;
}
int ComboLock::getdial(){
	return dial;
}
void ComboLock::reset(){
	dial=0;
}
void ComboLock::turn_left(int ticks){
	for(int i = 0; i < ticks;i++){
		//check if dial was leaving secret 1
		if(dial==s1){
			check1 = true;
		}
		//if dial continued past secret 2 then fail
		if(dial==s2){
			check1=false;
			check2=false;
		}
		//if dial turned left after s1 and s2 for a reason then fail
		if(check1&&check2){
			check1=false;
			check2=false;
		}
		//if the turn left clicked to secret 2 then flip true on check2
		//full circle dia
		if(dial==0){
			dial=39;
		}
		else{
			dial--;
		}
	}


}
void ComboLock::turn_right(int ticks){
	for(int i = 0; i < ticks;i++){
		//if the turn right initiated on secret 2 then flip true on check2
		//check if dial was leaving secret 2
		if(dial==s2&&check1){
			check2 = true;
		}
		//if journey from s1 to s2 is interrupted with right turn then fail
		if(check1&&check2==false){
			check1=false;
			check2 = false;
		}
		//if dial continued past secret 1 then fail

	//	if(dial==s1&&check1&&check2){
	//		//do nothing
	//	}
	//	//if didnt previously hit s2 then fail
	//	else if(dial==s1&&check1==false&&check2==false){
	//		check1==false;
	//	}

		//full circle dial
		if(dial==39){
			dial=0;
		}
		else{
			dial++;
		}
	}


}
bool ComboLock::open()const{
	//if current dial is equal to secret 3 and check1 and check 2 true and failright and failleft is false
	if((dial==s3)&&check1&&check2){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	ComboLock c = ComboLock(4,2,5);//keys hardcoded as [4] , [2] , [5]
	int ticks = 0;
	char a;
	cout<<"-ComboLock-"<<endl;
	cout<<"There are 39 ticks and three keys from [right to left to right]. Type (r) or (l) to turn right or left, type (o) to open!"<<endl;
	while(true){
		cout<<"current tick: ["<<c.getdial()<<"]"<<endl;
		cout<<"Enter action: ";
		cin>>a;
		if(a=='r'){
			cout<<"How many ticks?: ";
			cin>>ticks;
			c.turn_right(ticks);
		}
		else if(a=='l'){
			cout<<"How many ticks?: ";
			cin>>ticks;
			c.turn_left(ticks);
		}
		else if(a=='o'){
			if(c.open()){
				cout<<"You have successfully opened the combo-lock!"<<endl;
				break;
			}
			else{
				cout<<"Still locked"<<endl;
			}
		}
		else{
			cout<<"error"<<endl;
			break;
		}
	}
	cout<<"Goodbye!";
}
