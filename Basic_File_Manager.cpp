#include<bits\stdc++.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
vector<string>paths;
void copy_text(string pathfrom,string p){
ifstream file;
file.open(pathfrom);
    if(!file.is_open()){
        cout<<"(path from) not find\n";
    return;
    }
vector<string>outfile;
string lines;
    while(getline(file,lines)){
    outfile.push_back(lines);
    }
ofstream file_to;
file_to.open(p);
    if(!file_to.is_open()){
        cout<<"(path to) not find\n";
    return;
    }
    for(auto i:outfile){
    file_to<<i;
    }
        paths.push_back(p);
}
void creat_direction(vector<string>text,string path){
    ofstream file;
    file.open(path);
        for(auto i:text)file<<i;
    file.close();
}
void view_file(string file_path)
{
ifstream file;
file.open(file_path);
    if(!file.is_open()){
        cout<<"path not find\n";
    return;
    }
vector<string>outfile;
string lines;
    while(getline(file,lines)){
    outfile.push_back(lines);
    }
    for(auto i:outfile){
        cout<<i<<'\n';
    }
}
void printallpath(){
    for(int i=0;i<paths.size();i++)
    {
        cout<<i+1<<"->"<<paths[i]<<'\n';
    }
}
int main(){
    paths.clear();
while(true)
{
        cout<<"1.creat\n2.view\n3.copy\n";
int option;cin>>option;

    if(option==0){
    cout<<"Good by\n";
    return 0;
    }
if(option==1){
string path;
vector<string>t;
    cout<<"your path is and type like(.txt)\n";cin>>path;
    cout<<"your text\n";
    while(true){
    string str;
        getline(cin,str);
        t.push_back(str);
        if(str=="done")break;
    }
    creat_direction(t,path);
    paths.push_back(path);
}
if(option==2){
int ind=0;
    cout<<"what number file you want see it\n";
        printallpath();
    cin>>ind;
    if(ind<0 || ind>paths.size()){
        cout<<"your path unvalid\n pleas try again\n";
}
else
{view_file(paths[ind-1]);}
}
if(option==3){
        cout<<"path from -> ";string path_form;cin>>path_form;
            cout<<'\n';
        cout<<"path to -> ";string p;cin>>p;
    copy_text(path_form,p);
}
}
}

