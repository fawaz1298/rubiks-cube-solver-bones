#include<iostream>
#include<string.h>
#include<vector>
#include<unordered_map>
#include<queue>
#include<set>

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
    set<int> movn;
    long long count=0;
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
            count++;
            que.push(cube);
            key[cube]=moves;
        }
    }
    string left(string cube , string moves){
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
    string right(string cube , string moves){
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
    void lefti(string cube , string moves){
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

        checker(cube,moves+'L');

    }   
    void righti(string cube , string moves){
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

        checker(cube,moves+'R');

    }   
    void upi(string cube , string moves){
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

        checker(cube,moves+'U');

    }   
    void downi(string cube , string moves){
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

        checker(cube,moves+'D');

    }   
    void fronti(string cube , string moves){
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

        checker(cube,moves+'F');

    }   
    void backi(string cube , string moves){
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

        checker(cube,moves+'B');

    }
    void bfs1(){
        string temp="wwwwggxgoooxbbxxrrxxyxxx";   //wwwwggxgoooxbbxxrrxxyxxx        wwwwggggoooobbbbrrrryyyy
        key[temp]="";
        que.push(temp);
        int i=1;
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
            lefti(cube,tmoves);
            righti(cube,tmoves);
            upi(cube,tmoves);
            downi(cube,tmoves);
            fronti(cube,tmoves);
            backi(cube,tmoves);     //1632959
        }
        cout<<"bfs 1 complete "<<count<<"\n";
    }

    void bfs2(){
        string temp="xwxxxxggxxoobxbbxrrryyyy";   //wwwwggxgoooxbbxxrrxxyxxx        wwwwggggoooobbbbrrrryyyy
        key[temp]="";
        que.push(temp);
        int i=1;
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
            lefti(cube,tmoves);
            righti(cube,tmoves);
            upi(cube,tmoves);
            downi(cube,tmoves);
            fronti(cube,tmoves);
            backi(cube,tmoves);     //1632959
        }
        cout<<"bfs 2 complete "<<count;
    }
};

int main(){
    rubiks_cube cube;
    cube.bfs1();
    cube.bfs2();
    return 0;
}
