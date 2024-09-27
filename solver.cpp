#include<iostream>
#include<string.h>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>

using namespace std;


class rubiks_cube{
    private:
    string w="white"; 
    string y="yellow"; 
    string g="green"; 
    string b="blue"; 
    string r="red"; 
    string o="orange"; 

    //faces

    const string scan_order = "wygobr";
    string face_maker(){
        cout<<"Enter states:\n";
       string temp = "";
       char t;
        for(int i=0;i<4;i++){
            cin>>t;
            t=tolower(t);
            temp+=t;
            if(!(t!='w'||t!='b'||t!='r'||t!='g'||t!='o'||t!='y')){
                return "xxxx";
            }
        }
        return temp;
    }

    unordered_map<string,int> key;
    queue<string> que;
    unordered_set<string> type1={"ygr","gry","ryg","yrb","rby","byr","ybo","boy","oyb"};
    unordered_set<string> type2={"ygr","gry","ryg","yrb","rby","byr","ybo","boy","oyb"};
    long long count=0;
    public:
    string read_cube(){
        cout<<"READING CUBE:\n";
        string test;
        cout<<"front face:\n";
        test += face_maker();
        cout<<"do full cube right move face:\n";
        test += face_maker();
        cout<<"do full cube up inverse move face:\n";
        test += face_maker();
        cout<<"do full cube up inverse move face:\n";
        test += face_maker();
        cout<<"do full cube up inverse move face:\n";
        test += face_maker();
        cout<<"do full cube right move face:\n";
        test += face_maker();
        return test;
    }
    string masker1(string test){
        if(type1.find({test[0],test[8],test[13]})!=type1.end()){
            test[0]='x';
            test[8]='x';
            test[13]='x';
        }
        if(type1.find(string({test[1],test[12],test[17]}))!=type1.end()){
            test[1]='x';
            test[12]='x';
            test[17]='x';
        }
        if(type1.find(string({test[2],test[16],test[15]}))!=type1.end()){
            test[2]='x';
            test[16]='x';
            test[15]='x';
        }
        if(type1.find(string({test[3],test[4],test[9]}))!=type1.end()){
            test[3]='x';
            test[4]='x';
            test[9]='x';
        }
        if(type1.find(string({test[20],test[10],test[7]}))!=type1.end()){
            test[20]='x';
            test[10]='x';
            test[7]='x';
        }
        if(type1.find(string({test[21],test[6],test[19]}))!=type1.end()){
            test[21]='x';
            test[6]='x';
            test[19]='x';
        }
        if(type1.find(string({test[22],test[18],test[15]}))!=type1.end()){
            test[22]='x';
            test[18]='x';
            test[15]='x';
        }
        if(type1.find(string({test[23],test[14],test[11]}))!=type1.end()){
            test[23]='x';
            test[14]='x';
            test[11]='x';
        }
        return test;
    }
    string masker2(string test){
        if(type2.find({test[0],test[8],test[13]})!=type2.end()){
            test[0]='x';
            test[8]='x';
            test[13]='x';
        }
        if(type2.find(string({test[1],test[12],test[17]}))!=type2.end()){
            test[1]='x';
            test[12]='x';
            test[17]='x';
        }
        if(type2.find(string({test[2],test[16],test[15]}))!=type2.end()){
            test[2]='x';
            test[16]='x';
            test[15]='x';
        }
        if(type2.find(string({test[3],test[4],test[9]}))!=type2.end()){
            test[3]='x';
            test[4]='x';
            test[9]='x';
        }
        if(type2.find(string({test[20],test[10],test[7]}))!=type2.end()){
            test[20]='x';
            test[10]='x';
            test[7]='x';
        }
        if(type2.find(string({test[21],test[6],test[19]}))!=type2.end()){
            test[21]='x';
            test[6]='x';
            test[19]='x';
        }
        if(type2.find(string({test[22],test[18],test[15]}))!=type2.end()){
            test[22]='x';
            test[18]='x';
            test[15]='x';
        }
        if(type2.find(string({test[23],test[14],test[11]}))!=type2.end()){
            test[23]='x';
            test[14]='x';
            test[11]='x';
        }
        return test;
    }
    void checker(vector<string> states,int moves){
        for(auto cube:states){
            if(!(key.find(cube)!=key.end())){
            count++;
            que.push(cube);
            key[cube]=moves;
            }
        }
    }
    string left(string cube ){
        char temp1=cube[0],temp2=cube[3];
        cube[0]=cube[14];
        cube[3]=cube[13];
        cube[14]=cube[20];
        cube[13]=cube[23]; //edges
        cube[20]=cube[4];
        cube[23]=cube[7];
        cube[4]=temp1;
        cube[7]=temp2;

        char temp=cube[9];
        cube[9]=cube[8];
        cube[8]=cube[11]; //face
        cube[11]=cube[10];
        cube[10]=temp;

        return cube;

    }   
    string right(string cube ){
        char temp1=cube[1],temp2=cube[2];
        cube[1]=cube[5];
        cube[2]=cube[6];
        cube[5]=cube[21];
        cube[6]=cube[22]; //edges
        cube[21]=cube[15];
        cube[22]=cube[12];
        cube[15]=temp1;
        cube[12]=temp2;

        char temp=cube[16];
        cube[16]=cube[19];
        cube[19]=cube[18]; //face
        cube[18]=cube[17];
        cube[17]=temp;

        return cube;

    }   
    string up(string cube ){
        char temp1=cube[4],temp2=cube[5];
        cube[4]=cube[16];
        cube[5]=cube[17];
        cube[16]=cube[12];
        cube[17]=cube[13]; //edges
        cube[12]=cube[8];
        cube[13]=cube[9];
        cube[8]=temp1;
        cube[9]=temp2;

        char temp=cube[0];
        cube[0]=cube[3];
        cube[3]=cube[2]; //face
        cube[2]=cube[1];
        cube[1]=temp;
        
        return cube;

    }   
    string down(string cube ){
        char temp1=cube[7],temp2=cube[6];
        cube[7]=cube[11];
        cube[6]=cube[10];
        cube[11]=cube[15];
        cube[10]=cube[14]; //edges
        cube[15]=cube[19];
        cube[14]=cube[18];
        cube[19]=temp1;
        cube[18]=temp2;

        char temp=cube[20];
        cube[20]=cube[23];
        cube[23]=cube[22]; //face
        cube[22]=cube[21];
        cube[21]=temp;
        
        return cube;

    }   
    string front(string cube ){
        char temp1=cube[3],temp2=cube[2];
        cube[3]=cube[10];
        cube[2]=cube[9];
        cube[10]=cube[21];
        cube[9]=cube[20]; //edges
        cube[21]=cube[16];
        cube[20]=cube[19];
        cube[16]=temp1;
        cube[19]=temp2;

        char temp=cube[4];
        cube[4]=cube[7];
        cube[7]=cube[6]; //face
        cube[6]=cube[5];
        cube[5]=temp;
        
        return cube;

    }   
    string back(string cube ){
        char temp1=cube[0],temp2=cube[1];
        cube[0]=cube[17];
        cube[1]=cube[18];
        cube[17]=cube[22];
        cube[18]=cube[23]; //edges
        cube[22]=cube[11];
        cube[23]=cube[8];
        cube[11]=temp1;
        cube[8]=temp2;

        char temp=cube[12];
        cube[12]=cube[15];
        cube[15]=cube[14]; //face
        cube[14]=cube[13];
        cube[13]=temp;
        
        return cube;

    }
    string lefti(string cube ){
        char temp1=cube[0],temp2=cube[3];
        cube[0]=cube[4];
        cube[3]=cube[7];
        cube[4]=cube[20];
        cube[7]=cube[23]; //edges
        cube[20]=cube[14];
        cube[23]=cube[13];
        cube[14]=temp1;
        cube[13]=temp2;

        char temp=cube[9];
        cube[9]=cube[10];
        cube[10]=cube[11]; //face
        cube[11]=cube[8];
        cube[8]=temp;
        
        return cube;

    }   
    string righti(string cube ){
        char temp1=cube[1],temp2=cube[2];
        cube[1]=cube[15];
        cube[2]=cube[12];
        cube[15]=cube[21];
        cube[12]=cube[22]; //edges
        cube[21]=cube[5];
        cube[22]=cube[6];
        cube[5]=temp1;
        cube[6]=temp2;

        char temp=cube[16];
        cube[16]=cube[17];
        cube[17]=cube[18]; //face
        cube[18]=cube[19];
        cube[19]=temp;
        
        return cube;

    }   
    string upi(string cube ){
        char temp1=cube[4],temp2=cube[5];
        cube[4]=cube[8];
        cube[5]=cube[9];
        cube[8]=cube[12];
        cube[9]=cube[13]; //edges
        cube[12]=cube[16];
        cube[13]=cube[17];
        cube[16]=temp1;
        cube[17]=temp2;

        char temp=cube[0];
        cube[0]=cube[1];
        cube[1]=cube[2]; //face
        cube[2]=cube[3];
        cube[3]=temp;
        
        return cube;

    }   
    string downi(string cube ){
        char temp1=cube[7],temp2=cube[6];
        cube[7]=cube[19];
        cube[6]=cube[18];
        cube[19]=cube[15];
        cube[18]=cube[14]; //edges
        cube[15]=cube[11];
        cube[14]=cube[10];
        cube[11]=temp1;
        cube[10]=temp2;

        char temp=cube[20];
        cube[20]=cube[21];
        cube[21]=cube[22]; //face
        cube[22]=cube[23];
        cube[23]=temp;
        
        return cube;

    }   
    string fronti(string cube ){
        char temp1=cube[3],temp2=cube[2];
        cube[3]=cube[16];
        cube[2]=cube[19];
        cube[16]=cube[21];
        cube[19]=cube[20]; //edges
        cube[21]=cube[10];
        cube[20]=cube[9];
        cube[10]=temp1;
        cube[9]=temp2;

        char temp=cube[4];
        cube[4]=cube[5];
        cube[5]=cube[6]; //face
        cube[6]=cube[7];
        cube[7]=temp;
        
        return cube;

    }   
    string backi(string cube){
        char temp1=cube[0],temp2=cube[1];
        cube[0]=cube[11];
        cube[1]=cube[8];
        cube[11]=cube[22];
        cube[8]=cube[23]; //edges
        cube[22]=cube[17];
        cube[23]=cube[18];
        cube[17]=temp1;
        cube[18]=temp2;

        char temp=cube[12];
        cube[12]=cube[13];
        cube[13]=cube[14]; //face
        cube[14]=cube[15];
        cube[15]=temp;
        
        return cube;

    }
    void bfs1(){
        string temp = "wwwwggxgoooxbbxxrrxxyxxx";   //wwwwggxgoooxbbxxrrxxyxxx        xwxxxxggxxoobxbbxrrryyyy
        key[temp] = 0;
        string temp2 = "xwxxxxggxxoobxbbxrrryyyy";
        key[temp2] = 0;
        que.push(temp);
        que.push(temp2);
        while (!que.empty()){
            string cube=que.front();
            que.pop();
            vector<string> tempstates(12,"");
            tempstates[0] = left(cube);
            tempstates[1] = right(cube);
            tempstates[2] = up(cube);
            tempstates[3] = down(cube);
            tempstates[4] = front(cube);
            tempstates[5] = back(cube);
            tempstates[6] = lefti(cube);
            tempstates[7] = righti(cube);
            tempstates[8] = upi(cube);
            tempstates[9] = downi(cube);
            tempstates[10] = fronti(cube);
            tempstates[11] = backi(cube);
            checker(tempstates,key[cube]+1);//1632959     3265918
        }
        cout<<"bfs complete "<<count<<"\n";
    }
    int show(string c){
        return key[c];
    }
};

int main(){
    rubiks_cube cube;
    cube.bfs1();
    string sub = cube.masker1("wyorwggbrbrrbggwwobyyooy");  //wyorwggbrbrrbggwwobyyooy   wwwwggggoooobbbbrrrryyyy
    cout<<sub<<"\n";
    cout<<cube.show(sub)<<"\n";
    return 0;
}
