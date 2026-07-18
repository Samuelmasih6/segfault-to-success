#include <iostream>
using namespace std;

class stack{
    int top,arr[5];
    public:
    stack(){
        top=-1;
        for(int i=0;i<5;i++){
            arr[i]=0;
        }
    }
    bool isempty(){
        if(top==-1)
        return true;
        else
        return false;
    }
    bool isfull(){
        if(top==4)
        return true;
        else
        return false;
    }
    void push(int value){
        if(isfull()){
            cout<<"stack overflow"<<endl;
        }
        else
        {
            top++;
            arr[top]=value;
        }
    }
    int pop(){
        if(isempty()){
            cout<<"stack underflow"<<endl;
            return 0;
        }
        else
        {
            int popvalue=arr[top];
            arr[top]=0;
            top--;
            return popvalue;
        }
    }
    int count(){
        return top+1;
    }
    int peek(int pos){
        if(isempty()){
            cout<<"stack underflow"<<endl;
            return 0;
        }
        else
        return arr[pos];
    }
    void change(int pos, int value){
        arr[pos]=value;
        cout<<"value changed at location "<<pos<<endl;
    }

    void display(){
        cout<<"All values in the stack are "<<endl;
        for(int i = 4; i>=0;i--){
            cout<<arr[i]<<" "<<endl;
        }
    }
};


int main(){
    stack s1;
    int position,option,value;

    do{
        cout<<"What operation do you want to perform? Select Option number. Enter 0 to exit."<<endl;
        cout<<"1. Push()"<<endl;
        cout<<"2. Pop()"<<endl;
        cout<<"3. Peek()"<<endl;
        cout<<"4. isempty()"<<endl;
        cout<<"5. isfull()"<<endl;
        cout<<"6. change()"<<endl;
        cout<<"7. display()"<<endl;
        cout<<"8. count()"<<endl;
        cout<<"9. Clear screen"<<endl;

        cin>>option;
        switch(option){
            case 1:
            cout<<"Enter an item to push in the stack"<<endl;
            cin>>value;
            s1.push(value);
            break;
            case 2:
            cout<<"Pop function called, pop value is "<<s1.pop()<<endl;
            break;
            case 3:
            cout<<"Enter the position on which you want to know the value"<<endl;
            cin>>position;
            break;
            cout<<"The value at position "<<position<<" is "<<s1.peek(position)<<endl;
            case 4:
            if(s1.isempty()) cout<<"The stack is empty."<<endl;
            else cout<<"The stack has elements"<<endl;
            break;
            case 5:
            if(s1.isfull()) cout<<"The stack is full."<<endl;
            else cout<<"The stack is empty."<<endl;
            break;
            case 6:
            cout<<"Enter the position: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>value;
            s1.change(position,value);
            break;
            case 7:
            s1.display();
            break;
            case 8:
            cout<<"The number of elements in the stack are "<<s1.count()<<endl;
            break;
            case 9:
            system("cls");
            break;
        }
    }while(option!=0);
    
    return 0;
}
