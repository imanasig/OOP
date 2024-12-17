/*Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file..*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    ofstream ofile;
    ofile.open("Example.txt");

    if(!ofile){
        cout<<"Error:cannot create outfile....."<<endl;
    }

    string s;
    cout<<"Enter some text : "<<endl;
    getline(cin,s);
    ofile<<s;

    cout<<"Data sucessfully written in output file......."<<endl;
    ofile.close();

    ifstream ifile;
    ifile.open("Example.txt",ios::in);

    if(!ifile){
        cout<<"Error:file cannot open in read mode...."<<endl;
    }

    string content;
    cout<<"reading content in file...."<<endl;

    while(getline(ifile,content)){
        cout<<content;
    }
    cout<<endl;
    
    ifile.close();
    return 0;
}
