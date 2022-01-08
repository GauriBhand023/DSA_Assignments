#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
struct student{
    int roll_no;
    char name[15];
    float mark;
}s;
void create_database(student s[],int n);
void reply(student s[],int n);
void display_data(student s[],int n);
void bubble_sort(student s[],int n);
void insertion_sort(student s[],int n);
void quick_Sort(student s[],int low,int high);
void linearSearch(student s[],int n,int key);
void binarySearch(student s[],int n);

int main(){
    struct student s[20];  
    cout<<"\t\t\tWELCOME"<<endl;
    int response,n;
    while(true){
        cout<<"\n1]Create a student database"<<endl;
        cout<<"2]Display the student database"<<endl;
        cout<<"3]Bubble sort the data by roll no"<<endl;
        cout<<"4]Sort names by insertion sort"<<endl;
		cout<<"5]Quick sort the marks"<<endl;
        cout<<"6]Linear search on marks"<<endl;
        cout<<"7]Binary search on names"<<endl;
        cout<<"8]Exit"<<endl;
        cout<<"\nEnter the task = ";
        cin>>response;
        

        switch(response){
            
            case 1:
            cout<<endl;
            cout<<"Enter the number of students = ";
            cin>>n;
            create_database(s,n);
            break;

            case 2:
            cout<<endl;
            display_data(s,n);
            break;

            case 3:
            cout<<endl;
            bubble_sort(s,n);
            break;

        
            case 4:
            cout<<endl;
            insertion_sort(s,n);
            break;

			case 5:
			quick_Sort(s,0,n-1);
			cout<<"\n**** Information sorted succesfully  !! ****"<<endl;
			reply(s,n);
            break;

            case 6:
            int key;
            cout<<"Enter the marks to be found = ";
            cin>>key;
            linearSearch(s,n,key);
            break;

            case 7:
            binarySearch(s,n);			
            break;

            case 8:
            return 0;

            default:
            cout<<"Enter the correct choice"<<endl;

        }
    }
    return 0;
}
void create_database(student s[],int n){
        cout<<endl;

        for(int i=0;i<n;i++){     
            cout<<"Student "<<i+1<<" :"<<endl;
			cout<<"Enter the name    = ";
            cin>>s[i].name;

            cout<<"Enter the roll no = ";
            cin>>s[i].roll_no;
            
            cout<<"Enter the marks   = ";
            cin>>s[i].mark;
            cout<<endl;
            for(int j=i-1;j>=0;j--){
                if(s[i].roll_no==s[j].roll_no){
                i--;
                cout<<"enter the unique roll no."<<endl;
                break;
                }
            }    
        }       
}                                                          
void reply( student s[],int n){
	char re;
	cout<<"Want to display sorted data y or n = ";
	cin>>re;
	cout<<endl;
	if(re=='y'){
	   	display_data(s,n);
		cout<<endl;    
	}
    else{
        return;
    }
}
void display_data(student s[],int n){
         cout<<"Roll no: "<<"\t\tName: "<<"\t\t\tMarks: "<<endl;
         for(int i=0;i<n;i++){
             cout<<s[i].roll_no<<"\t\t\t"<<s[i].name<<"\t\t\t"<<s[i].mark<<endl;
         }
         cout<<endl;
         cout<<"*** Information displayed succesfully  !! ***"<<endl;
         cout<<"\nPress any key to move further";
        getch();
        cout<<endl;
}
void bubble_sort(student s[],int n){

        student temp;
        int counter = 1;
        while (counter <n){
            for(int i=0;i<n-counter;i++){
            if(s[i].roll_no>s[i+1].roll_no){
                temp = s[i];
                s[i] = s[i+1];
                s[i+1] = temp;
            }
        }
        counter ++;
        }
        cout<<endl;
        cout<<"*** Information sorted succesfully  !! ***"<<endl;
		reply(s,n);
}
void insertion_sort(student s[],int n){
    student key;
    for(int i =1;i<n;i++){
        key=s[i];
        int j=i-1;

        while(j>=0 && strcmp(s[j].name,key.name)>0){
            s[j+1]=s[j];
            j=j-1;
        }
        s[j+1]=key;
    }
    cout<<"*** Information sorted succesfully  !! ***"<<endl;
	reply(s,n);
}
int partition (student s[], int low, int high) {
    int pivot = s[high].mark; 
    int i = (low - 1); 
    for (int j = low; j <= high - 1; j++) 
    { 
        if (s[j].mark < pivot) 
        { 
            i++; 
            ;
			student temp;
			temp = s[i];
			s[i]=s[j];
			s[j]=temp; 
        } 
    } 
	student temp1;
	temp1=s[i+1];
	s[i+1]=s[high];
	s[high]=temp1;
    return (i + 1); 
} 
void quick_Sort(student s[], int low, int high) {

    if (low < high) 
    { 
        int pi = partition(s, low, high); 
        quick_Sort(s, low, pi - 1); 
        quick_Sort(s, pi + 1, high); 
	    } 	
} 
void linearSearch(student s[],int n, int key){
    bool flag=true;
    cout<<"Roll no: "<<"\t\tName: "<<"\t\t\tMarks:"<<endl;
    for(int i =0;i<n;i++){    
     if(s[i].mark==key){
        cout<<s[i].roll_no<<"\t\t\t"<<s[i].name<<"\t\t\t"<<s[i].mark<<endl;
         flag=false;
     }                
    }
    if(flag){
         cout<<"NA"<<"\t\t\t"<<"NA"<<"\t\t\t"<<"NA"<<endl;
         cout<<"No data  found of entered marks"<<endl;
    }
    cout<<"/nPress any key to continue ";
    getch();
}
void binarySearch(student s[],int n){
    insertion_sort(s, n);
    cout<<endl;
    string key;
    cout<<"Enter the name to be found = ";
    cin>>key;
    cout<<endl;
    int start = 0;
    int end = n ;
    bool flag=true;
    cout<<"Roll no: "<<"\t\tName: "<<"\t\t\tMarks: "<<endl;
    while( start <= end){
       int mid = (start + end)/2;
       if(s[mid].name==key){
           
           flag=false;
           while(s[mid].name==key){
               cout<<s[mid].roll_no<<"\t\t\t"<<s[mid].name<<"\t\t\t"<<s[mid].mark<<endl;
               mid--;
           }
           while(s[mid].name==key){
               cout<<s[mid].roll_no<<"\t\t\t"<<s[mid].name<<"\t\t\t"<<s[mid].mark<<endl;
               mid++;
           }
           return;         
       } 
       else if(s[mid].name<key){
           start=mid+1;
       }       
       else{
           end=mid-1;
       }
       cout<<"\nPress any key to continue "<<endl;
       getch();
    }
    if(flag){
        cout<<"NA"<<"\t\t\t"<<"NA"<<"\t\t\t"<<"NA"<<endl;
         cout<<"No data  found of entered marks"<<endl;
    }
    cout<<endl;
}