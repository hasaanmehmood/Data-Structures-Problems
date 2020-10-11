#include<iostream>
using namespace std;
class node
{
public:
	int data;
	node* next;
	node(int d = 0)
	{
		data = d;
		next = NULL;
	}
};
class queue
{
	node* front, * rare;

public:
	int length = 0;
	queue()
	{
		front = rare = NULL;
	}
	node* makeNode(int x)
	{
		node* n = new node(x);
		return n;
	}
	
	void Enqueue(int x)
	{
		node* n = makeNode(x);
		if (isEmpty())
		{
			front = rare = n;
			length++;
			cout << "\nenqueued\n";
		}
		else
		{
			rare->next = n;
			rare = n;
			length++;
			cout << "\nenqueued\n";
		}
		
	}
	
	node* Dequeue()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			node* temp = front;
			front = front->next;
			length--;
			return temp;
		}
		
	}
	
	bool isEmpty()
	{
		if (front == NULL && rare == NULL)
		{
			return true;
		}
		return false;
	}

	void Display()
	{
		node* temp = front;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	node* Return_Middle()
	{
		node* temp = front;
		if (length % 2 == 0)
		{

			return NULL;
		}
		else
		{
			for (int i = 0; i < length / 2; i++)
			{
				temp = temp->next;
			}
		}
		return temp;
	}
};
int main()
{
	queue s;
	node* n;
	int option, x;
	do {
		cout << "\n";
		cout <<"Press 1 to Enqueue\n";
		cout <<"Press 2 to Dequeue \n";
		cout <<"Press 3 to Count Elements\n";
		cout <<"Press 4 to Display all Elements\n";
		cout <<"Press 5 to Check isEmpty\n";
		cout <<"Press 6 to Check Middle Element\n";
		cout <<"Press 7 to Exit\n";
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			cout << "\nEnter Number to Enqueue: ";
			cin >> x;
			s.Enqueue(x);
			cout << endl << endl;
			break;
		case 2:
			system("cls");
			n = s.Dequeue();

			if (n == NULL)
			{
				cout << "\nQueue is empty";
			}
			else
				cout << endl << n->data << " is Dequeued\n";

			break;
		case 3:
			system("cls");
			cout << "Number of Elements in Queue = " << s.length;
			break;
		case 4:
			system("cls");
			cout << "Queue: ";
			s.Display();
			break;
		case 5:
			system("cls");
			if (s.isEmpty())
			{
				cout << "\nQueue is Empty\n";
			}
			else
				cout << "\nQueue is not Empty\n";
			
			break;
		case 6:
			system("cls");
			n = s.Return_Middle();

			if (n == NULL)
			{
				cout << "\nQueue is Even, No Middle Value\n";
			}
			else
			{
				cout << "\n Middle Element = " << n->data;
			}
			break;
		case 7:
			break;
		default:
			cout << "\nInvalid Choice!\n";
		}

	} while (option != 7);
	system("pause>0");
}