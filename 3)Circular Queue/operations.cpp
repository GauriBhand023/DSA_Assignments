#include <iostream>
using namespace std;
int cqueue[5];
int front = -1 ,rear=-1,n=5;
void insert(int val){
    if((front == 0 && rear ==n-1) || (front == rear+1)){
        cout<<"\nQueue is full you can't insert the element "<<endl;
        return;
    }
    if(front== -1){
        front = 0;
        rear = 0;
    }
    else{
        if(rear==n-1){
            rear=0;
        }
        else{
            rear = rear+1;
        }
    }
    cqueue[rear] = val;
}
void deletion(){
    if(front == -1){
        cout<<"\nQueue is already empty "<<endl;
        return;
    }
    cout<<"Element deleted from queue is --> "<<cqueue[front]<<endl;

    if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        if(front == n-1){
            front = 0;
        }
        else{
            front = front +1;
        }
    }
}
void display_front(){
    int f= front ,r = rear;
    if(front == -1){
        cout<<"\nQueue is already empty "<<endl;
        return ;
    }
    cout<<"Queue elements in forward order -->"<<endl;

    if(f<=r){
        while(f<=r){
            cout<<cqueue[f]<<" ";
            f++;
        }
    }
    else{
        while(f<=n-1){
            cout<<cqueue[f]<<" ";
            f++;
        }
        f=0;
        while(f<=r){
            cout<<cqueue[f]<<" ";
            f++;
        }
    }
    cout<<endl;   
}
void display_reverse(){
    int f= front ,r = rear;

    if(front == -1){
        cout<<"\nQueue is already empty "<<endl;
        return ;
    }
    cout<<"Queue elements in reverse order -->"<<endl;
    if(f<=r){
        while(f<=r){
            cout<<cqueue[r]<<" ";
            r--;
        }
    }
    else{
        while(r>=0){
            cout<<cqueue[r]<<" ";
            r--;
        }
        r=n-1;
        while(r>=f){
            cout<<cqueue[r]<<" ";
            r--;
        }
    }
    cout<<endl;   
}
int main()
{
     int ch,val;
     cout<<"1]Insert"<<endl;
     cout<<"2)Delete"<<endl;
     cout<<"3)Display Forward"<<endl;
     cout<<"4)Display Reverse"<<endl;
     cout<<"5)Exit"<<endl;
   do {
      cout<<"Enter choice --> ";
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Input for insertion--> ";
         cin>>val;
         cout<<endl;
         insert(val);
         break;

         case 2:
         deletion();
         cout<<endl;
         break;

         case 3:
         display_front();
         cout<<endl;
         break;

         case 4:
         display_reverse();
         cout<<endl;
         break;

         case 5:
         cout<<"Exit\n";
         break;

         default: cout<<"\nEnter correct choice !"<<endl;
      }
   } while(ch != 5);
   return 0;
}