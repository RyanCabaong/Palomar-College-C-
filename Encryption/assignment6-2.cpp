#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
    int i,j,k,n;
    //encryption
    //test example
    //message: help
    //key: take
    //expected encryption: gbiq
    cout<<"Enter the message"<<endl;
    string s,origin;
    getline(cin,origin);
    cout<<"Enter the key"<<endl;
    string key;
    cin>>key;
    //retrieve message
    for(i=0;i<origin.size();i++){
        if(origin[i]!=' ')
            s+= origin[i];
        //cout<<s;
        //help
    }
    //create double vector R2 space of chars called a
    vector<vector<char> > a(5,vector<char>(5,' '));
    n=5;

    map<char,int> mp;
    k=0;
    //looping through each letter in key and placing it in (a) and saving letter location in map (mp)
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        	//while.. letter is saved (1) in map and k is less than number of letters in key
            while(mp[key[k]]>0&&k<key.size()){
                k++;
            }
            //put key in char vector (a) and save in map (mp)
            if(k<key.size()){
                a[i][j]=key[k];//insert key "----abcdef..."
                //cout<<key[k];
                mp[key[k]]++;

            }
            //cout<<mp[key[k]]; 11110 for take key
            if(k==key.size())
            break;
        }
        //cout<<endl;
        if(k==key.size())
            break;
    }
    //create insert alphabetical letters into 5x5 double array ignoring j
    k=0;
    for(;i<n;i++){
        for(;j<n;j++){
        	//inc map 1 to each character as iterating alphebet and checks if k is lowercase letter
            while(mp[char(k+'a')]>0&&k<26){
                k++;
            }
            //since j will be discounted j-- to redo loop and k++ to next letter
            if(char(k+'a')=='j'){
                j--;
                k++;
                continue;
            }
            //insert alphebet after key "----abcd..."
            if(k<26){
                a[i][j]=char(k+'a');
                //cout<<a[i][j];
                mp[char(k+'a')]++;
            }
        }
        j=0;
        //cout<<endl;
    }
    string ans;
    //in this case the message is EVEN for group of two [help] 4 letters
    if(s.size()%2==1)
        s+="x";//if message not EVEN insert dummy letter "x"
    for(i=0;i<s.size()-1;i++){//reiterate message, if same letter appears in message
        if(s[i]==s[i+1])
            s[i+1]='x';//[help] has no repeating letters
    }
    //map location: char , value: pair<int,int>
    //need to record
    map<char,pair<int,int> > mp2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mp2[a[i][j]] = make_pair(i,j);
            //designate each character to value in 2d pair i,j 5x5
            /*location, first(y) second(x)
             *  takeb, 0 01234
             *  cdfgh, 1 01234
             *  ilmno, 2 01234
             *  pqrsu, 3 01234
             *  vwxyz, 4 01234
             */
            cout<<a[i][j];//comment out later
        }
        cout<<endl;
    }
    cout<<endl;
    //iterate through help a[][] (y,x) positions
    for(i=0;i<s.size()-1;i+=2){//iterate by TWO
        int y1 = mp2[s[i]].first;
        int x1 = mp2[s[i]].second;
        int y2 = mp2[s[i+1]].first;
        int x2 = mp2[s[i+1]].second;
        //if both letters are in same row return rightmost values
        if(y1==y2){
            ans+=a[y1][(x1+1)%5];
            ans+=a[y1][(x2+1)%5];
        }//if both letters are in same column return uppermost values
        else if(x1==x2){
            ans+=a[(y1+1)%5][x1];
            ans+=a[(y2+1)%5][x2];
        }//otherwise (most of the time) return a[row1][column2] and a[row2][column1]
        else {
            ans+=a[y1][x2];
            ans+=a[y2][x1];
        }
    }
    cout<<"encrypted message: "<<ans<<'\n';
    return 0;
}
