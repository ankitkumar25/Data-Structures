// Queue implementation using array

#include<iostream>
using namespace std;

class CircularQueue{
	private:
		 int front;
		 int rear;
		 int arr[5];
		 int itemCount;
	public:
		CircularQueue()
		{
			itemCount = 0;
			front = -1;
			rear =-1;
			for(int i=0; i<5; i++)
			{
				arr[i]=0;
			}
		}
		bool isEmpty()
		{
			if(front==-1 && rear ==-1)
				return true;
			else
				return false;
					
		}
		bool isFull()
		{
			if((rear+1)%5==front)   // 5 is size of array here or the max capacity of queue
				return true;
			else
			 return false;
		}
		void enqueue(int value)
		{
			if(isFull())
			{
				cout<<"Queue Overflow"<<endl;
				return;
			}
			else if(isEmpty())
			{
				front=0;
				rear=0;
			}
			else
			{
				rear = (rear+1)%5;
			}
			arr[rear]=value;
			itemCount++;
		}
		int dequeue()
		{
			int x=0;
			if(isEmpty())
			{
				cout<<"Queue Underflow";
				return 0;
			}
			else if(front==rear)
			{
				x = arr[front];
				arr[front]=0;
				front=-1;
				rear=-1;
			}
			else
			{
				x= arr[front];
				arr[front]=0;
				front = (front+1)%5;
				itemCount--;
			}
			return x;
		}
		int count()
		{
			return itemCount;
		}
		void display()
		{
			cout<<"All values in the Queue are : "<<endl;
			for(int i=0; i<5; ++i)
			{
				cout<<arr[i]<<" ";
			}
		}
	
};

int main()
{
	CircularQueue q1;
	int value;
	int option;
	do
	{
		cout<<"\n Enter your choice (Press 0 to exit): "<<endl;
		cout<<"1.enqueue"<<endl;
		cout<<"2.dequeue"<<endl;
		cout<<"3.isEmpty"<<endl;
		cout<<"4.isFull"<<endl;
		cout<<"5.count"<<endl;
		cout<<"6.display"<<endl;
		cout<<"7.Clear Screen"<<endl;	
		
		cin>>option;
		switch(option)
		{
			case 0:
				 break;
			case 1:
				cout<<"Enqueue funtion is called "<<endl;
				cout<<"Enter value : "<<endl;
				cin>>value;
				q1.enqueue(value);
				break;
			case 2:
				cout<<"Dequeue funtion is called- \n Dequeued value:  "<<q1.dequeue()<<endl;
				 break;
			case 3:
				if(q1.isEmpty())
				 cout<<"Queue is empty"<<endl;
				else
					cout<<"Queue is not empty"<<endl;
					
				break;
			case 4:
				if(q1.isFull())
					cout<<"Queue is Full"<<endl;
				else
					cout<<"Queue is not full"<<endl;
					
				 break;
			case 5:
				cout<<"Count Operation -\n Count of items in the queue are : "<<q1.count()<<endl;
				break;
			case 6:
				cout<<"Display Function called : "<<endl;
				q1.display();
				 break;
			case 7:
				system("cls");
				break;
				
			default:
				cout<<"Invalid input."<<endl;
				
				
			
			}	
	}while(option!=0);
	
	return 0;
}

// By- Ankit Kumar Tiwari
// Github Link: https://github.com/ankitkumar25/Data-Structures 
