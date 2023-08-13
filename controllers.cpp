#include<iostream>
#include<fstream>
using namespace std;


class Controller {
    private:
        string username,password, packType;
    public:
        Controller(string username,string password,string packType){
            this->username = username;
            this->password = password;
            this->packType = packType;
        }
        void saveAuthData(){
            ofstream outFile("auth_details.txt");
            if (outFile.is_open()) {
                outFile << "username : " << username << endl;
                outFile << "password : " << password << endl;
                outFile << "packType : " << packType << endl;
                outFile.close();
            }
        }
};