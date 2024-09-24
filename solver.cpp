#include<iostream>
#include<string.h>
#include<vector>
#include<unordered_map>
#include<queue>

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
    vector<vector<char>> face_maker(string face1,string face2){
        cout<< face1 <<"Facing top and "<< face2 <<"facing front\n";
        vector<vector<char>> temp(2,vector<char> (2));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cin>>temp[i][j];
                temp[i][j]=tolower(temp[i][j]);
                if(!(temp[i][j]!='w'&&temp[i][j]!='b'&&temp[i][j]!='r'&&temp[i][j]!='g'&&temp[i][j]!='o'&&temp[i][j]!='y')){
                    return {{'x','x'},{'x','x'}};
                }
            }
        }
        return temp;
    }
    unordered_map<string,string> key;
    queue<string> que;
    public:
    /*int read_cube(){
        cout<<"READING CUBE:\n";
        white = face_maker(w,b);
        yellow = face_maker(y,g);
        green = face_maker(g,w);
        blue = face_maker(b,w);
        red = face_maker(r,w);
        orange = face_maker(o,w);
        return 1;
    }*/
    void checker(string cube,string moves){
        if(!(key.find(cube)!=key.end())){
            que.push(cube);
            key[cube]=moves;
            cout<<cube<<":"<<moves.length()<<"\n";
        }
    }
    void left(string cube , string moves){
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

        checker(cube,moves+'l');

    }   
    void right(string cube , string moves){
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

        checker(cube,moves+'r');

    }   
    void up(string cube , string moves){
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

        checker(cube,moves+'u');

    }   
    void down(string cube , string moves){
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

        checker(cube,moves+'d');

    }   
    void front(string cube , string moves){
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

        checker(cube,moves+'f');

    }   
    void back(string cube , string moves){
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

        checker(cube,moves+'b');

    }
    void bfs(){
        string temp="wwwwggggoooobbbbrrrryyyy";
        key[temp]="";
        que.push(temp);
        while (!que.empty()){
            string cube=que.front();
            que.pop();
            string tmoves=key[cube];
            left(cube,tmoves);
            right(cube,tmoves);
            up(cube,tmoves);
            down(cube,tmoves);
            front(cube,tmoves);
            back(cube,tmoves);
        }
        cout<<"bfs complete";
    }
};

int main(){
    rubiks_cube cube;
    cube.bfs();
    cout<<"jam";
    return 0;
}
