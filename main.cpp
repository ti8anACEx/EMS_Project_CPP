#include<iostream>
#include<fstream>
// #include "models.cpp"
#include "views.cpp"
#include "controllers.cpp"

using namespace std;

string username="",password="",packType="basic";

// total and namespace should be under models.cpp file

int total = 0;


namespace basic{
    struct EMPLOYEE {
		string name,id,address;
		int contact,salary;
	}emp[100];

void insertData(){
	progressIndicator(3);
	int ch;
	cout<<"\n\nHow many employees\' data do you want to insert? (Can store details of "<<100-total<<" more employees)\n";
	cin>>ch;
	for(int i = total;i<total+ch;i++){
		cout<<"\n\nEnter data of Employee "<<i+1<<endl;
		cout<<"----- ----- ----- -----\n";
		cout<<"Employee Name : ";
		cin>>emp[i].name;
		cout<<"Employee ID : ";
		cin>>emp[i].id;
		cout<<"Employee Address : ";
		cin>>emp[i].address;
		cout<<"Employee Contact : ";
		cin>>emp[i].contact;
		cout<<"Employee Salary : ";
		cin>>emp[i].salary;
		progressIndicator(3);
	}
	total = total + ch;
}


void readData(){
	progressIndicator(3);
	cout<<"\n\n--- --- ALL RECORDS --- ---\n";
	if(total!=0){
		for(int i=0;i<total;i++){
			cout<<"\nData of Employee "<<i+1<<endl<<endl;
			cout<<"Employee Name : "<<emp[i].name<<endl;
			cout<<"Employee ID : "<<emp[i].id<<endl;
			cout<<"Employee Address : "<<emp[i].address<<endl;
			cout<<"Employee Contact : "<<emp[i].contact<<endl;
			cout<<"Employee Salary : "<<emp[i].salary<<endl;
		}
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

void searchData(){
	progressIndicator(3);
	if(total!=0){
		cout<<"\n\nEnter the ID/Name of the employee to search :"<<endl;
		string id;
		cin>>id;
		progressIndicator(3);
		bool isPresent = false;
		for(int i = 0; i< total;i++){
			if(id==emp[i].id || id == emp[i].name){
				isPresent = true;
				cout<<"\nEmployee serial no. "<<i+1<<endl<<endl;
				cout<<"Employee Name : "<<emp[i].name<<endl;
				cout<<"Employee ID : "<<emp[i].id<<endl;
				cout<<"Employee Address : "<<emp[i].address<<endl;
				cout<<"Employee Contact : "<<emp[i].contact<<endl;
				cout<<"Employee Salary : "<<emp[i].salary<<endl;
			}
			if(i==total-1 && isPresent == false){
				cout<<"\nNo record found corresponding to the search terms\n";
			}
		}
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

void updateData(){
	progressIndicator(3);
	if(total!=0){
		cout<<"\n\nEnter the ID of the employee to search :"<<endl;
		string id;
		cin>>id;
		progressIndicator(3);
		for(int i = 0; i< total;i++){
			if(id==emp[i].id){
				cout<<"\n--- PREVIOUS DATA ---"<<endl;
				
				cout<<"Employee serial no. "<<i+1<<endl<<endl;
				cout<<"Employee Name : "<<emp[i].name<<endl;
				cout<<"Employee ID : "<<emp[i].id<<endl;
				cout<<"Employee Address : "<<emp[i].address<<endl;
				cout<<"Employee Contact : "<<emp[i].contact<<endl;
				cout<<"Employee Salary : "<<emp[i].salary<<endl;
				
				string oldID = emp[i].id;
				cout<<"\n--- ENTER NEW DATA ---\n";
				
				cout<<"Employee Name : ";
				cin>>emp[i].name;
				cout<<"Employee ID : ";
				cin>>emp[i].id;
				cout<<"Employee Address : ";
				cin>>emp[i].address;
				cout<<"Employee Contact : ";
				cin>>emp[i].contact;
				cout<<"Employee Salary : ";
				cin>>emp[i].salary;
				
				progressIndicator(3);
				cout<<"\nDATA UPDATED! Employee Serial no. "<<i+1<<"\'s New ID : "<<emp[i].id<<" (Old ID: "<<oldID<<") \n";
				break;
			}
			if(i==total-1){
				cout<<"\nNo record found corresponding to the search terms\n";
			}
		}
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

void deleteData(){
	if(total!=0){
		DEL:
		cout<<"\nPress 1 to delete the record of a specific employee by ID\n";
		cout<<"Press 2 to delete all the current records\n";
		int ch;
		if(ch==1){
			cout<<"\nEnter the ID of the employee to search and delete :"<<endl;
			string id;
			cin>>id;
			progressIndicator(3);
			for(int i = 0; i< total;i++){
				
				if(id==emp[i].id){
				cout<<"\nEmployee serial no. "<<i+1<<endl<<endl;
				cout<<"Employee Name : "<<emp[i].name<<endl;
				cout<<"Employee ID : "<<emp[i].id<<endl;
				cout<<"Employee Address : "<<emp[i].address<<endl;
				cout<<"Employee Contact : "<<emp[i].contact<<endl;
				cout<<"Employee Salary : "<<emp[i].salary<<endl;
				break;
				if(i==total-1){
					cout<<"\nNo record found corresponding to the search terms\n";
				}
				}
			}
		
			cout<<"Deleting Data";
			progressIndicator(3);
			
			for(int i = 0;i<total;i++){
				if(id == emp[i].id){
					for(int j = i; j<total; j++){
						emp[j].name = emp[j+1].name;
						emp[j].id = emp[j+1].id;
						emp[j].address = emp[j+1].address;
						emp[j].contact = emp[j+1].contact;
						emp[j].salary = emp[j+1].salary;
						total--;
						break;
					}
				}
			}
			char key;
			cout<<"\nPress any key to continue...\n";
			cin>>key;
			
			
		}else if(ch == 2){
			total = 0;
		}else{
			cout<<"\nInvalid Input.\n";
			goto DEL;
		}
	}else{
		cout<<"Your record is empty!\n";
	}
}

void saveEmpData(){
    progressIndicator(3);
	if(total!=0){
        
        ofstream outFile("employee_records_basic.txt");
        if (outFile.is_open()){
            for(int i=0;i<total;i++){
			    outFile<<"\nEmployee Serial No. "<<i+1<<endl<<endl;
			    outFile<<"Employee Name : "<<emp[i].name<<endl;
			    outFile<<"Employee ID : "<<emp[i].id<<endl;
			    outFile<<"Employee Address : "<<emp[i].address<<endl;
			    outFile<<"Employee Contact : "<<emp[i].contact<<endl;
			    outFile<<"Employee Salary : "<<emp[i].salary<<endl;
                outFile<<endl<<"----------------------------------------------------------------"<<endl;
		    }
            outFile.close();
        }
        cout<< " Employee Data saved to Local Database/Directory "<<endl;
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

}

namespace pro{
    struct EMPLOYEE {
		string name,id,address;
		int contact,salary;
	}emp[500];

void insertData(){
	progressIndicator(3);
	int ch;
	cout<<"\n\nHow many employees\' data do you want to insert? (Can store details of "<<500-total<<" more employees)\n";
	cin>>ch;
	for(int i = total;i<total+ch;i++){
		cout<<"\n\nEnter data of Employee "<<i+1<<endl;
		cout<<"----- ----- ----- -----\n";
		cout<<"Employee Name : ";
		cin>>emp[i].name;
		cout<<"Employee ID : ";
		cin>>emp[i].id;
		cout<<"Employee Address : ";
		cin>>emp[i].address;
		cout<<"Employee Contact : ";
		cin>>emp[i].contact;
		cout<<"Employee Salary : ";
		cin>>emp[i].salary;
		progressIndicator(3);
	}
	total = total + ch;
}


void readData(){
	progressIndicator(3);
	cout<<"\n\n--- --- ALL RECORDS --- ---\n";
	if(total!=0){
		for(int i=0;i<total;i++){
			cout<<"\nData of Employee "<<i+1<<endl<<endl;
			cout<<"Employee Name : "<<emp[i].name<<endl;
			cout<<"Employee ID : "<<emp[i].id<<endl;
			cout<<"Employee Address : "<<emp[i].address<<endl;
			cout<<"Employee Contact : "<<emp[i].contact<<endl;
			cout<<"Employee Salary : "<<emp[i].salary<<endl;
		}
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

void searchData(){
	progressIndicator(3);
	if(total!=0){
		cout<<"\n\nEnter the ID/Name of the employee to search :"<<endl;
		string id;
		cin>>id;
		progressIndicator(3);
		bool isPresent = false;
		for(int i = 0; i< total;i++){
			if(id==emp[i].id || id == emp[i].name){
				isPresent = true;
				cout<<"\nEmployee serial no. "<<i+1<<endl<<endl;
				cout<<"Employee Name : "<<emp[i].name<<endl;
				cout<<"Employee ID : "<<emp[i].id<<endl;
				cout<<"Employee Address : "<<emp[i].address<<endl;
				cout<<"Employee Contact : "<<emp[i].contact<<endl;
				cout<<"Employee Salary : "<<emp[i].salary<<endl;
			}
			if(i==total-1 && isPresent == false){
				cout<<"\nNo record found corresponding to the search terms\n";
			}
		}
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

void updateData(){
	progressIndicator(3);
	if(total!=0){
		cout<<"\n\nEnter the ID of the employee to search :"<<endl;
		string id;
		cin>>id;
		progressIndicator(3);
		for(int i = 0; i< total;i++){
			if(id==emp[i].id){
				cout<<"\n--- PREVIOUS DATA ---"<<endl;
				
				cout<<"Employee serial no. "<<i+1<<endl<<endl;
				cout<<"Employee Name : "<<emp[i].name<<endl;
				cout<<"Employee ID : "<<emp[i].id<<endl;
				cout<<"Employee Address : "<<emp[i].address<<endl;
				cout<<"Employee Contact : "<<emp[i].contact<<endl;
				cout<<"Employee Salary : "<<emp[i].salary<<endl;
				
				string oldID = emp[i].id;
				cout<<"\n--- ENTER NEW DATA ---\n";
				
				cout<<"Employee Name : ";
				cin>>emp[i].name;
				cout<<"Employee ID : ";
				cin>>emp[i].id;
				cout<<"Employee Address : ";
				cin>>emp[i].address;
				cout<<"Employee Contact : ";
				cin>>emp[i].contact;
				cout<<"Employee Salary : ";
				cin>>emp[i].salary;
				
				progressIndicator(3);
				cout<<"\nDATA UPDATED! Employee Serial no. "<<i+1<<"\'s New ID : "<<emp[i].id<<" (Old ID: "<<oldID<<") \n";
				break;
			}
			if(i==total-1){
				cout<<"\nNo record found corresponding to the search terms\n";
			}
		}
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

void deleteData(){
	if(total!=0){
		DEL:
		cout<<"\nPress 1 to delete the record of a specific employee by ID\n";
		cout<<"Press 2 to delete all the current records\n";
		int ch;
		if(ch==1){
			cout<<"\nEnter the ID of the employee to search and delete :"<<endl;
			string id;
			cin>>id;
			progressIndicator(3);
			for(int i = 0; i< total;i++){
				
				if(id==emp[i].id){
				cout<<"\nEmployee serial no. "<<i+1<<endl<<endl;
				cout<<"Employee Name : "<<emp[i].name<<endl;
				cout<<"Employee ID : "<<emp[i].id<<endl;
				cout<<"Employee Address : "<<emp[i].address<<endl;
				cout<<"Employee Contact : "<<emp[i].contact<<endl;
				cout<<"Employee Salary : "<<emp[i].salary<<endl;
				break;
				if(i==total-1){
					cout<<"\nNo record found corresponding to the search terms\n";
				}
				}
			}
		
			cout<<"Deleting Data";
			progressIndicator(3);
			
			for(int i = 0;i<total;i++){
				if(id == emp[i].id){
					for(int j = i; j<total; j++){
						emp[j].name = emp[j+1].name;
						emp[j].id = emp[j+1].id;
						emp[j].address = emp[j+1].address;
						emp[j].contact = emp[j+1].contact;
						emp[j].salary = emp[j+1].salary;
						total--;
						break;
					}
				}
			}
			char key;
			cout<<"\nPress any key to continue...\n";
			cin>>key;
			
			
		}else if(ch == 2){
			total = 0;
		}else{
			cout<<"\nInvalid Input.\n";
			goto DEL;
		}
	}else{
		cout<<"Your record is empty!\n";
	}
}

void saveEmpData(){
    progressIndicator(3);
	if(total!=0){
        
        ofstream outFile("employee_records_pro.txt");
        if (outFile.is_open()){
            for(int i=0;i<total;i++){
			    outFile<<"\nEmployee Serial No. "<<i+1<<endl<<endl;
			    outFile<<"Employee Name : "<<emp[i].name<<endl;
			    outFile<<"Employee ID : "<<emp[i].id<<endl;
			    outFile<<"Employee Address : "<<emp[i].address<<endl;
			    outFile<<"Employee Contact : "<<emp[i].contact<<endl;
			    outFile<<"Employee Salary : "<<emp[i].salary<<endl;
                outFile<<endl<<"----------------------------------------------------------------"<<endl;
		    }
            outFile.close();
        }
        cout<< " Employee Data saved to Local Database/Directory "<<endl;
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

}

namespace enterprise{
    struct EMPLOYEE {
		string name,id,address;
		int contact,salary;
	}emp[1000];

void insertData(){
	progressIndicator(3);
	int ch;
	cout<<"\n\nHow many employees\' data do you want to insert? (Can store details of "<<1000-total<<" more employees)\n";
	cin>>ch;
	for(int i = total;i<total+ch;i++){
		cout<<"\n\nEnter data of Employee "<<i+1<<endl;
		cout<<"----- ----- ----- -----\n";
		cout<<"Employee Name : ";
		cin>>emp[i].name;
		cout<<"Employee ID : ";
		cin>>emp[i].id;
		cout<<"Employee Address : ";
		cin>>emp[i].address;
		cout<<"Employee Contact : ";
		cin>>emp[i].contact;
		cout<<"Employee Salary : ";
		cin>>emp[i].salary;
		progressIndicator(3);
	}
	total = total + ch;
}


void readData(){
	progressIndicator(3);
	cout<<"\n\n--- --- ALL RECORDS --- ---\n";
	if(total!=0){
		for(int i=0;i<total;i++){
			cout<<"\nData of Employee "<<i+1<<endl<<endl;
			cout<<"Employee Name : "<<emp[i].name<<endl;
			cout<<"Employee ID : "<<emp[i].id<<endl;
			cout<<"Employee Address : "<<emp[i].address<<endl;
			cout<<"Employee Contact : "<<emp[i].contact<<endl;
			cout<<"Employee Salary : "<<emp[i].salary<<endl;
		}
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

void searchData(){
	progressIndicator(3);
	if(total!=0){
		cout<<"\n\nEnter the ID/Name of the employee to search :"<<endl;
		string id;
		cin>>id;
		progressIndicator(3);
		bool isPresent = false;
		for(int i = 0; i< total;i++){
			if(id==emp[i].id || id == emp[i].name){
				isPresent = true;
				cout<<"\nEmployee serial no. "<<i+1<<endl<<endl;
				cout<<"Employee Name : "<<emp[i].name<<endl;
				cout<<"Employee ID : "<<emp[i].id<<endl;
				cout<<"Employee Address : "<<emp[i].address<<endl;
				cout<<"Employee Contact : "<<emp[i].contact<<endl;
				cout<<"Employee Salary : "<<emp[i].salary<<endl;
			}
			if(i==total-1 && isPresent == false){
				cout<<"\nNo record found corresponding to the search terms\n";
			}
		}
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

void updateData(){
	progressIndicator(3);
	if(total!=0){
		cout<<"\n\nEnter the ID of the employee to search :"<<endl;
		string id;
		cin>>id;
		progressIndicator(3);
		for(int i = 0; i< total;i++){
			if(id==emp[i].id){
				cout<<"\n--- PREVIOUS DATA ---"<<endl;
				
				cout<<"Employee serial no. "<<i+1<<endl<<endl;
				cout<<"Employee Name : "<<emp[i].name<<endl;
				cout<<"Employee ID : "<<emp[i].id<<endl;
				cout<<"Employee Address : "<<emp[i].address<<endl;
				cout<<"Employee Contact : "<<emp[i].contact<<endl;
				cout<<"Employee Salary : "<<emp[i].salary<<endl;
				
				string oldID = emp[i].id;
				cout<<"\n--- ENTER NEW DATA ---\n";
				
				cout<<"Employee Name : ";
				cin>>emp[i].name;
				cout<<"Employee ID : ";
				cin>>emp[i].id;
				cout<<"Employee Address : ";
				cin>>emp[i].address;
				cout<<"Employee Contact : ";
				cin>>emp[i].contact;
				cout<<"Employee Salary : ";
				cin>>emp[i].salary;
				
				progressIndicator(3);
				cout<<"\nDATA UPDATED! Employee Serial no. "<<i+1<<"\'s New ID : "<<emp[i].id<<" (Old ID: "<<oldID<<") \n";
				break;
			}
			if(i==total-1){
				cout<<"\nNo record found corresponding to the search terms\n";
			}
		}
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

void deleteData(){
	if(total!=0){
		DEL:
		cout<<"\nPress 1 to delete the record of a specific employee by ID\n";
		cout<<"Press 2 to delete all the current records\n";
		int ch;
		if(ch==1){
			cout<<"\nEnter the ID of the employee to search and delete :"<<endl;
			string id;
			cin>>id;
			progressIndicator(3);
			for(int i = 0; i< total;i++){
				
				if(id==emp[i].id){
				cout<<"\nEmployee serial no. "<<i+1<<endl<<endl;
				cout<<"Employee Name : "<<emp[i].name<<endl;
				cout<<"Employee ID : "<<emp[i].id<<endl;
				cout<<"Employee Address : "<<emp[i].address<<endl;
				cout<<"Employee Contact : "<<emp[i].contact<<endl;
				cout<<"Employee Salary : "<<emp[i].salary<<endl;
				break;
				if(i==total-1){
					cout<<"\nNo record found corresponding to the search terms\n";
				}
				}
			}
		
			cout<<"Deleting Data";
			progressIndicator(3);
			
			for(int i = 0;i<total;i++){
				if(id == emp[i].id){
					for(int j = i; j<total; j++){
						emp[j].name = emp[j+1].name;
						emp[j].id = emp[j+1].id;
						emp[j].address = emp[j+1].address;
						emp[j].contact = emp[j+1].contact;
						emp[j].salary = emp[j+1].salary;
						total--;
						break;
					}
				}
			}
			char key;
			cout<<"\nPress any key to continue...\n";
			cin>>key;
			
			
		}else if(ch == 2){
			total = 0;
		}else{
			cout<<"\nInvalid Input.\n";
			goto DEL;
		}
	}else{
		cout<<"Your record is empty!\n";
	}
}

void saveEmpData(){
    progressIndicator(3);
	if(total!=0){
        
        ofstream outFile("employee_records_enterprise.txt");
        if (outFile.is_open()){
            for(int i=0;i<total;i++){
			    outFile<<"\nEmployee Serial No. "<<i+1<<endl<<endl;
			    outFile<<"Employee Name : "<<emp[i].name<<endl;
			    outFile<<"Employee ID : "<<emp[i].id<<endl;
			    outFile<<"Employee Address : "<<emp[i].address<<endl;
			    outFile<<"Employee Contact : "<<emp[i].contact<<endl;
			    outFile<<"Employee Salary : "<<emp[i].salary<<endl;
                outFile<<endl<<"----------------------------------------------------------------"<<endl;
		    }
            outFile.close();
        }
        cout<< " Employee Data saved to Local Database/Directory "<<endl;
		char key;
		cout<<"\nPress any key to continue...\n";
		cin>>key;
	}else{
		cout<<"Your record is empty!\n";
	}
}

}






int showMenu(){
	while(true){
		progressIndicator(3);
		clrScr();
		int ch;
		title();
		menuUI();
		cin>>ch;
		switch(ch){
			case 1:
                packType=="basic"?
				basic::insertData():
                packType=="pro"?
                pro::insertData():
                enterprise::insertData();
				break;
			case 2:
                packType=="basic"?
				basic::readData():
                packType=="pro"?
                pro::readData():
                enterprise::readData();
				break;
			case 3:
                packType=="basic"?
				basic::searchData():
                packType=="pro"?
                pro::searchData():
                enterprise::searchData();
				break;
			case 4:
                packType=="basic"?
				basic::updateData():
                packType=="pro"?
                pro::updateData():
                enterprise::updateData();
				break;
			case 5:
                packType=="basic"?
				basic::deleteData():
                packType=="pro"?
                pro::deleteData():
                enterprise::deleteData();
				break;
			case 6:
				return 6;
				break;
			case 7:
				return 7;
				break;
            case 8:
                packType=="basic"?
				basic::saveEmpData():
                packType=="pro"?
                pro::saveEmpData():
                enterprise::saveEmpData();
			default:
				cout<<"\aInvalid Input. Please try again.\n";
				break;
		}
	
	}
	return 0;
}

int logORsign(string type){
	if(type=="Sign Up"){
		cout<<"\t\t----- Sign Up -----"<<endl;
		cout<<"\t\tUsername : ";
		cin>>username;
		cout<<"\t\tPassword : ";
		cin>>password;
		Controller controller(username,password,packType);
       	controller.saveAuthData();
		progressIndicator();
		cout<<"\n\t\tData saved to Local Database/Directory ! Redirecting...\n";
		Sleep(1000);
		return 0;
	}else{
		login:
			cout<<"\t\t----- Login -----"<<endl;
			string uname, pass;
			cout<<"\t\tUsername : ";
			cin>>uname;
			cout<<"\t\tPassword : ";
			cin>>pass;
			if(username == uname && password == pass){
				cout<<"\t\tSuccess\n";
				Sleep(1000);
				clrScr();
				int val = showMenu();
				return val;
			}else if(username!=uname || password!=pass){
				cout<<"\t\tIncorrect details\n";
				Sleep(1000);
				goto login;
			}
			return 0;
	}
}



int main(){
  	packType = pricingScreen();
	title();
	AUTH:
	logORsign("Sign Up");
	clrScr();
	title();
	MENU:
	int val = logORsign("Log In");
	if(val==6) {
		cout<<"\t\tAre you sure to log out? (y/n)"<<endl;
		char ch;
		cin>>ch;
		if	(ch=='y'){
			goto AUTH;
		}else{
			goto MENU;
		}
	}else if(val == 7){
		exit(0);
	}
	return 0;
}
