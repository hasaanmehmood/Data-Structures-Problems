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
class stack
{

	node* head;
public:
	int length = 0;
	stack()
	{
		head = NULL;
	}
	node* makeNode(int x)
	{
		node* n = new node(x);
		return n;
	}
	
	void Push(int x)
	{

		node* n = makeNode(x);
		if (isEmpty())
		{
			head = n;
			length++;
			cout << "\npushed\n";
		}
		else
		{
			node* temp = head;
			head = n;
			head->next = temp;
			length++;
			cout << "\npushed\n";
		}
	}

	
	node* Pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			node* temp = head;
			head = head->next;
			length--;
			return temp;
		}
	}

	
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}
	void Display()
	{
		node* temp = head;
		while (temp != NULL)
		{
			cout <<"\n"<< temp->data << "\n";
			temp = temp->next;
		}
	}
	
	node* Return_Middle()
	{
		node* temp = head;
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
	stack s;
	node* n;
	int opt, x;
	do {
		cout<<"Press 1 to Push\n";
		cout<<"Press 2 to Pop \n";
		cout<<"Press 3 to Count Elements\n";
		cout<<"Press 4 to Display all Elements\n";
		cout<<"Press 5 to Check isEmpty\n";	
		cout<<"Press 6 to Find Middle Element\n";
		cout<<"Press 7 to Exit\n";
		cin >> opt;
		switch (opt)
		{
		case 1:
			system("cls");
			cout << "\nEnter Number to Push: ";
			cin >> x;
			s.Push(x);
			cout << endl << endl;
			break;
			
		case 2:
			system("cls");
			n = s.Pop();

			if (n == NULL)
			{
				cout << "\nStack is Empty";

			}
			else
				cout << endl << n->data << " is Popped\n";


			
			break;
		case 3:
			system("cls");
			cout << "Number of elements in stack: " << s.length;
			break;
		case 4:
			system("cls");
			cout << "Stack: ";
			s.Display();
			break;
		case 5:
			system("cls");
			if (s.isEmpty())
			{
				cout << "\nStack is Empty\n";
			}
			else
				cout << "\nStack is not Empty\n";
			break;
		case 6:
			system("cls");
			n = s.Return_Middle();
			
				if (n == NULL)
				{
					cout << "\nSize of stack is even,No Middle value\n";
					
				}
				else
				{
					cout << "\n Middle Element = " << n->data;
				}
		
			break;
		case 7:
			break;
		default:
			cout << "\nInvalid choice\n";
		}

	} while (opt != 7);

}