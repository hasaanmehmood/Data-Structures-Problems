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
		}
		else
		{
			node* temp = head;
			head = n;
			head->next = temp;
		}
	}

	int Pop()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{
			node* temp = head;
			head = head->next;
			return temp->data;
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
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};
void DisplayPoles(stack p, stack p1, stack p2)
{
	cout << "1st Pole:- ";
	p.Display();
	cout << "\n2nd Pole:- ";
	p1.Display();
	cout << "\n3rd Pole:- ";
	p2.Display();
	cout << endl;
}
bool CheckValid(stack pop, stack push)
{
	int p1, p2;
	p1 = pop.Pop();
	p2 = push.Pop();
	if ((p1 == NULL && p2 == NULL) || p1 == NULL)
	{
		return false;
	}
	else if (p2 == NULL)
	{
		return true;
	}
	else if (p1 > p2)
	{
		return false;
	}
	else
		return true;
}
int main()
{
	stack pole[3];
	int Pop, Push, Moves = 0, disk;
	cout << "Enter Number of Disks = ";
	cin >> disk;
	for (int i = disk; i > 0; i--)
	{
		pole[0].Push(i);
	}
	while (true)
	{
		if (pole[0].isEmpty() && pole[1].isEmpty())
		{
			break;
		}
		DisplayPoles(pole[0], pole[1], pole[2]);
		cout << "\nEnter Pole Number to Pop Value = ";
		do {
			cin >> Pop;
			if (Pop > 3 || Pop <= 0)
				cout << "Invalid input!\n";
		} while (Pop > 3 || Pop <= 0);
		cout << "Enter Pole Number to Push Value = ";
		do {
			cin >> Push;
			if (Push > 3 || Push <= 0)
				cout << "invalid Input!\n";
		} while (Push > 3 || Push <= 0);
		if (CheckValid(pole[Pop - 1], pole[Push - 1]))
		{
			pole[Push - 1].Push(pole[Pop - 1].Pop());
			Moves++;
		}
		else
			cout << "Invalid Move\n\n";

	}
	DisplayPoles(pole[0], pole[1], pole[2]);
	cout << "Number of Moves = " << Moves;
}