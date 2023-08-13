#include<iostream>
#include<windows.h>

using namespace std;





void title(){
	cout<<"\n\n\t\t--- --- --- --- --- --- --- --- --- --- ---\n";
	cout<<"\t\t--- --- ---EMPLOYEE MANAGER MENU--- --- ---\n";
	cout<<"\t\t--- --- --- --- --- --- --- --- --- --- ---\n\n\n";
}

void clrScr(){
	system("cls");
}


void progressIndicator(int num = 5){
	for(int i = 0;i<num;i++){
		if(i==0){
			cout<<"\t\t.";		
		}else{
			cout<<".";
		}
		Sleep(400);
	}
}


void pricingUI(){
    
    cout<<endl<<endl<<" --- PRICING --- "<<endl;

    cout<<"\n\n";
    cout<<"\t\t - - - - - - - - - - - - - - - - - - - - "<<endl;
	cout<<"\t\t - BASIC PACK ~ For income under 10K   - "<<endl;
    cout<<"\t\t -                                     - "<<endl;
	cout<<"\t\t - $ Save Auth Info                    - "<<endl;
	cout<<"\t\t - $ Basic CRUD operations             - "<<endl;
	cout<<"\t\t - $ Store upto 100 employees          - "<<endl;
    cout<<"\t\t - $ Price FREE                        - "<<endl;
    cout<<"\t\t - - - - - - - - - - - - - - - - - - - - "<<endl;

    cout<<"\n\n";
    cout<<"\t\t - - - - - - - - - - - - - - - - - - - - "<<endl;
	cout<<"\t\t - PRO PACK ~ Recommended              - "<<endl;
    cout<<"\t\t -                                     - "<<endl;
	cout<<"\t\t - $ Save Auth Info                    - "<<endl;
	cout<<"\t\t - $ Basic CRUD operations             - "<<endl;
    cout<<"\t\t - $ Save all employee data            - "<<endl;
	cout<<"\t\t - $ Store upto 500 employees          - "<<endl;
    cout<<"\t\t - $ Price Rs. 5,999                   - "<<endl;
    cout<<"\t\t - - - - - - - - - - - - - - - - - - - - "<<endl;

    cout<<"\n\n";
    cout<<"\t\t - - - - - - - - - - - - - - - - - - - - "<<endl;
	cout<<"\t\t - ENTERPRISE PACK ~ For Genius like U - "<<endl;
    cout<<"\t\t -                                     - "<<endl;
	cout<<"\t\t - $ Save Auth Info                    - "<<endl;
	cout<<"\t\t - $ Basic CRUD operations             - "<<endl;
    cout<<"\t\t - $ Save all employee data            - "<<endl;
	cout<<"\t\t - $ Store upto 1000 employees         - "<<endl;
    cout<<"\t\t - $ Price Rs. 9,999                   - "<<endl;
    cout<<"\t\t - - - - - - - - - - - - - - - - - - - - "<<endl;

    cout<<"\n\t\t * Enter 1 for BASIC, 2 for PRO, 3 for ENTERPRISE ";
}


void menuUI(){
    cout<<"\n\n";
        cout<<"\t\t - - - - - - - - - - - - - - - - - - - - - - - - "<<endl;
		cout<<"\t\t - Enter 1 :: Create entries                   - "<<endl;
		cout<<"\t\t - Enter 2 :: Read records                     - "<<endl;
		cout<<"\t\t - Enter 3 :: Search in records                - "<<endl;
		cout<<"\t\t - Enter 4 :: Update details                   - "<<endl;
		cout<<"\t\t - Enter 5 :: Delete records                   - "<<endl;
		cout<<"\t\t - Enter 6 :: Log Out                          - "<<endl;
		cout<<"\t\t - Enter 7 :: Exit                             - "<<endl;
        cout<<"\t\t - Enter 8 :: Backup records to local storage  - "<<endl;
        cout<<"\t\t - - - - - - - - - - - - - - - - - - - - - - - - "<<endl;
}


string pricingScreen(){
    title();
	pricingUI();
    int val;
    cin>>val;
    string packType = "basic";
    val==1?packType="basic":val==2?packType="pro":packType="enterprise";
    cout<<"\n\n\t\t CONGRATULATIONS FOR SELECTING OUR SERVICE. YOU HAVE BEEN REDIRECTED";
    progressIndicator();
    clrScr();
    return packType;
}
