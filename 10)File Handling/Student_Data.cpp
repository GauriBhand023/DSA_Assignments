#include<iostream> 
#include<fstream> 
using namespace std; 
 
void create(); 
void display(); 
int search(int roll); 
void add(); 
void del(); 
void modify(); 
 
int rollno;  	
char name[10];  	
char dept[10]; 
 
fstream f,r,temp; 
 
int main() 
{ 
    int x=1,ch; 
 
    while(x) 
        { 
            cout<<"\nEnter your choice what you want to perform:-\n1. Create\n2. Display\n3. Add\n4. Modify\n5. Delete\n6. Exit\n";
            cout<<"Enter the choice: ";
            cin>>ch; 
 
        switch(ch) 
        {case 1: 
            create(); 
 	 	    break; 
        case 2:
            display(); 
 	 	    break; 
        case 3: 
            add(); 
 	 	    break; 
        case 4: 
            modify(); 
 	 	    break; 
        case 5: 
            del(); 
 	 	    break; 
        case 6:
        x=0; 
 	 	break; 
        default:
            cout<<"\nPLease enter correct choice!\n"; 
 	 	    break; 
        } 
 
    } 
 
}
void create() 
{
 	int n,i; 
 	f.open("data.txt",ios::out);  
 	cout<<"How many records you want to enter:-"; 
 	cin>>n; 
 	for(i=0;i<n;i++) { 
 	    cout<<"\nEnter roll no: ";  	 	
        cin>>rollno;
        cout<<"Enter the name: ";
        cin>>name;
        cout<<"Enter the department: ";
        cin>>dept;  	 	
        f<<rollno<<"\t"<<name<<"\t"<<dept<<"\n"; 
 	} 
 	f.close(); 
}
void add() 
{ 
 	int x,i,roll;  
 	cout<<"Enter roll no: ";  	
    cin>>roll;  	
    x = search(roll); 
 	if(x==1) { 	 
 	 	cout<<"\nRecord already exist!\n"; 
 	} 
 	else { 
 	f.open("data.txt",ios::app);  	
    cout<<"Enter name: "; 	
    cin>>name;
    cout<<"and department: "; 
    cin>>dept;  	
    rollno = roll;  	
    f<<rollno<<"\t"<<name<<"\t"<<dept<<"\n"; 
	f.close(); 
    } 
}
void display() 
{ 
 	f.open("data.txt",ios::in); 
 	cout<<"Roll No"<<"\t"<<"Name"<<"\t"<<"Department"<<"\n"; 
 	f>>rollno>>name>>dept; 
    while(!f.eof()) { 
 	 	cout<<rollno<<"\t"<<name<<"\t"<<dept<<"\n";  	 	
        f>>rollno>>name>>dept; 
 	} 
 	f.close(); 
}
int search(int roll) {  
 	r.open("data.txt",ios::in);  
 	while(!r.eof()) { 
 	 	r>>rollno>>name>>dept;  	 	
        if(roll == rollno) { 
 	 	 	r.close(); 
 	 	 	return 1; 
 	 	} 
 	}  
 	r.close();  
 	return 0; 
}   
void modify() {
     int x,roll; 
    cout<<"Enter roll no: ";
    cin>>roll; 
    x = search(roll); 
    if(x==1) { 
 	    f.open("data.txt",ios::in);  	
        temp.open("temp.txt",ios::out); 
 	    f>>rollno>>name>>dept; 
 	    while(!f.eof()) { 
 	 	    if(roll == rollno) { 
 	 	 	    cout<<"Enter name : "; 
 	 	 	    cin>>name;
                cout<<"Enter the department: ";
                cin>>dept; 
 	 	 	    temp<<rollno<<"\t"<<name<<"\t"<<dept<<"\n";  	 	 	
                f>>rollno>>name>>dept; 
 	 	 	    continue; 
 	 	} 
 	 	temp<<rollno<<"\t"<<name<<"\t"<<dept<<"\n";  	 	
        f>>rollno>>name>>dept; 
 	} 
    f.close(); temp.close(); 
    f.open("data.txt",ios::out);
    temp.open("temp.txt",ios::in); 
    temp>>rollno>>name>>dept; 
    while(!temp.eof()) { 
	 	f<<rollno<<"\t"<<name<<"\t"<<dept<<"\n"; 
 	 	temp>>rollno>>name>>dept; 
 	} 
 	f.close();  	
    temp.close(); 
 	} 
 	else{
 	 	cout<<"\nRecord not exist!\n"; 
 	} 
} 
 
void del() 
{ 
 	int x,roll; 
 	cout<<"Enter roll no to delete: ";  	
    cin>>roll; 
    x = search(roll); 
    if(x==1) { 
        f.open("data.txt",ios::in); 
        temp.open("temp.txt",ios::out); 
        f>>rollno>>name>>dept; 
        while(!f.eof()){ 
 	 	    if(roll != rollno) { 
 	 	 	    temp<<rollno<<"\t"<<name<<"\t"<<dept<<"\n"; 
 	 	} 
 	 	f>>rollno>>name>>dept; 
 	} 
 	f.close();  	
    temp.close(); 
 	f.open("data.txt",ios::out);  
	temp.open("temp.txt",ios::in);  
 	temp>>rollno>>name>>dept;  	
     while(!temp.eof()) { 
 	 	f<<rollno<<"\t"<<name<<"\t"<<dept<<"\n";  	
        temp>>rollno>>name>>dept; 
          } 
 
f.close(); 
temp.close(); 
} 
 
else { 
	 	cout<<"\nRecord not exist!\n"; 
 	} 
}  
 