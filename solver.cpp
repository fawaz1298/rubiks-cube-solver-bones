#include<iostream>
#include<string.h>
#include<vector>
#include<unordered_map>

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

    vector<vector<char>> white;       //up
    vector<vector<char>> yellow;      //down
    vector<vector<char>> green;        //front
    vector<vector<char>> blue;       //back
    vector<vector<char>> red;         //right
    vector<vector<char>> orange;   //left

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
    public:
    int read_cube(){
        cout<<"READING CUBE:\n";
        white = face_maker(w,b);
        yellow = face_maker(y,g);
        green = face_maker(g,w);
        blue = face_maker(b,w);
        red = face_maker(r,w);
        orange = face_maker(o,w);
    }
    void left(){
        white[0][0]=blue[0][0];
        white[1][0]=blue[1][0];
    }
};
void main(){

}
