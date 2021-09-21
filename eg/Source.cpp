#include "Header.h"

Node* createNode(Student s)
{
	Node* p = new Node;
	if (p == NULL)
	{
		cout << "\nNot enough memory to allocate!" << endl;
		return NULL;
	}
	p->data = s;
	p->next = NULL;
	return p;
}

void createList(List& l)
{
	l.head = NULL;
	l.tail = NULL;
}

void input(Student& s)
{
	cout << "\nINPUT:" << endl;

	cin.ignore();
	cout << "\nName : ";
	cin.getline(s.name, 51);

	do
	{
		cout << "ID   : ";
		cin >> s.ID;
		if (s.ID < 1000000 || s.ID > 9999999)
			cout << "\nIllegal! ID must has 7 digits." << endl;
	} while (s.ID < 1000000 || s.ID > 9999999);

	do
	{
		cout << "Marks: ";
		cin >> s.mark;
		if (s.mark < 0 || s.mark > 10)
			cout << "\nIllegal!" << endl;
	} while (s.mark < 0 || s.mark > 10);
}

void addHead(List& l, Student s)
{
	Node* p = createNode(s);
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		p->next = l.head;
		l.head = p;
	}
}

void addTail(List& l, Student s)
{
	Node* p = createNode(s);
	if (l.head == NULL)
		l.head = l.tail = p;
	else
	{
		l.tail->next = p;
		l.tail = p;
	}
}

void addNodeAfterHead(List& l, Student s)
{
	Node* p = createNode(s);
	if (l.head->next == NULL)
		addTail(l, s);
	else
	{
		p->next = l.head->next;
		l.head->next = p;
	}
}

void addNodeBeforeTail(List& l, Student s)
{
	Node* p = createNode(s);
	if (l.head->next == NULL)
		addHead(l, s);
	else
	{
		for (Node* curr = l.head; curr != NULL; curr = curr->next)
		{
			if (curr->next == l.tail)
			{
				p->next = l.tail;
				curr->next = p;
				return;
			}
		}
	}
}

void randomString(char* code, int codeLength)
{
	const char* box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz";
	int boxLength = strlen(box);
	for (int i = 0; i < codeLength; ++i)
		code[i] = box[rand() % boxLength];
	code[codeLength] = '\0';
}

int randomInt(int min, int max)
{
	return min + rand() % (max + 1 - min);
}

float randomFloat(float min, float max)
{
	float scale = rand() / (float)RAND_MAX; /* [0, 1.0] */
	return min + scale * (max - min);       /* [min, max] */
}

void add5NodesWithRandomInformation(List& l, Student& s)
{
	srand(time(0));
	for (int i = 0; i < 5; ++i)
	{
		randomString(&s.name[0], randomInt(1, 50));
		s.ID = randomInt(1000000, 9999999);
		s.mark = randomFloat(0, 10);
		addTail(l, s);
	}
}

void deleteHead(List& l)
{
	if (l.head == NULL)
	{
		cout << "\nEmpty list!" << endl;
		return;
	}
	Node* temp = l.head;
	l.head = l.head->next;
	delete temp;
}

void deleteTail(List& l)
{
	if (l.head == NULL)
	{
		cout << "\nEmpty list!" << endl;
		return;
	}

	else if (l.head == l.tail)
		deleteHead(l);
	else 
	{
		for (Node* curr = l.head; curr != NULL; curr = curr->next)
		{
			if (curr->next == l.tail)
			{
				delete l.tail;
				l.tail = curr;
				curr->next = NULL;
			}
		}
	}
}

bool checkTargetMarks(List l, float target_marks)
{
	if (0 < target_marks && target_marks < 10)
	{
		for (Node* curr = l.head; curr != NULL; curr = curr->next)
			if (curr->data.mark == target_marks)
				return true;
	}
	return false;
}

void deleteAllStudentsWhoseMarksJustEntered(List& l, float &target_marks)
{
	if (l.head == NULL)
	{
		cout << "\nEmpty list!" << endl;
		return;
	}

	do
	{
		cout << "\nInput target marks: ";
		cin >> target_marks;
		if (!checkTargetMarks(l,target_marks))
			cout << "\nIllegal!" << endl;
	} while (!checkTargetMarks(l, target_marks));

	// Xoa nhung diem so co vi tri o dau
	while (l.head->data.mark == target_marks)
	{
		deleteHead(l);
		if (l.head == NULL)
			return;
	}
	// Xoa nhung diem so o vi tri khac vi tro o dau
	Node* curr = l.head;
	while (curr->next != NULL)
	{
		if (curr->next->data.mark == target_marks)
		{
			Node* temp = curr->next;
			curr->next = temp->next;
			delete temp;
		}
		else
			curr = curr->next;
	}

	// hoi bi can o cho neu so khoi tao la random vi so random khong duoc lam tron nen khi nhap vao se khong tim ra so do
}

void add10NodesWithRandomInformation(List& l, Student& s)
{
	srand(time(0));
	for (int i = 0; i < 10; ++i)
	{
		randomString(&s.name[0], randomInt(1, 50));
		s.ID = randomInt(1000000, 9999999);
		s.mark = randomFloat(0, 10);
		addTail(l, s);
	}
}

// coi lai cau nay luon
Node* removeDuplicates(List &l)
{
	if (l.head == NULL) 
		return NULL;

	Node* curr = l.head;
	while (curr->next != nullptr) 
	{
		if (curr->data.ID == curr->next->data.ID) 
		{
			Node* aux = curr->next->next;
			delete curr->next;
			curr->next = aux;
		}
		else 
			curr = curr->next;
	}
	return l.head;
}

void reverse(List& l)
{
	Node* prev = NULL;
	Node* next = NULL;
	Node* curr = l.head;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	l.head = prev;
}

// Nghien cuu lai
//Node* sorted;

//void insertAsc(Node* temp)
//{
//	if (sorted == NULL || sorted->data.mark >= temp->data.mark)
//	{
//		temp->next = sorted;
//		sorted = temp;
//	}
//	else
//	{
//		Node* curr = sorted;
//
//		while (curr->next != NULL && curr->next->data.mark < temp->data.mark)
//			curr = curr->next;
//
//		temp->next = curr->next;
//		curr->next = temp;
//	}
//}

//void insertionSort(List &l)
//{
//	sorted = NULL;
//	Node* curr = l.head;
//	while (curr != NULL) 
//	{
//		Node* next = curr->next;
//		insertAsc(curr);
//		curr = next;
//	}
//	l.head = sorted;
//}

void insertionSort(List& l)
{
	for (Node* curr = l.head; curr != NULL; curr = curr->next)
	{
		insertAsc(curr);
	}
}

// Xu ly voi danh sach lien ket don vong

bool checkCircle(List l)
{
	if (l.head == NULL || l.head->next == NULL)
		return false;

	Node* slow = l.head;
	Node* fast = l.head;

	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}

void printStudent(Node* temp);
void printH(List l)
{
	int count = 0;

	for (Node* curr = l.head; curr != NULL; curr = curr->next)
	{
		if (curr->data.name[0] == 'H' || curr->data.name[0] == 'h')
		{
			++count;
			cout << "\nSTUDENT " << count << ":" << endl;
			printStudent(curr);
		}
	}

	if (count == 0)
		cout << "\nNothing to print!" << endl;
}

// Them thong tin sinh vien neu ID da ton tai thi cap nhat thong tin
void addOrUpdate(List& l)
{
	Student s;
	input(s);

	for (Node* curr = l.head; curr != NULL; curr = curr->next)
	{
		if (curr->data.ID == s.ID)
		{
			curr->data = s;
			return;
		}
	}
	addTail(l, s);
}

void printStudent(Node* temp)
{
	cout << "\tName : " << temp->data.name;
	cout << "\tID   : " << temp->data.ID;
	cout << "\tMarks: " << temp->data.mark << endl;
}

void output(List l)
{
	cout << "\nOUTPUT:" << endl;

	if (l.head == NULL)
	{
		cout << "\nEmpty list!" << endl;
		return;
	}

	int count = 1;
	for (Node* curr = l.head; curr != NULL; curr = curr->next)
	{
		cout << "\nSTUDENT " << count << ":" << endl;
		printStudent(curr);
		++count;
	}
}

void clear(List& l)
{
	while (l.head != NULL)
		deleteHead(l);
}

void menu()
{
	int choice;
	List l;
	Student s;

	do
	{
		cout << "\n\t\t===== MENU =====" << endl;
		cout << "\t\t01. Create empty list." << endl;
		cout << "\t\t02. Add head." << endl;
		cout << "\t\t03. Add tail." << endl;
		cout << "\t\t04. Add after node head." << endl;
		cout << "\t\t05. Add before node tail." << endl;
		cout << "\t\t06. Add head 5 nodes with random information." << endl;
		cout << "\t\t07. Delete head." << endl;
		cout << "\t\t08. Delete tail." << endl;
		cout << "\t\t09. Input marks, delete all students whose marks just entered." << endl;
		cout << "\t\t10. Add head 10 nodes with random information." << endl;
		cout << "\t\t11. Delete duplicate nodes, keep only 1 node." << endl;
		cout << "\t\t12. Reserve list." << endl;
		cout << "\t\t13. Sort the list of student nodes in ascending order of scores from the top of the list." << endl;
		cout << "\t\t14. Add a node to the list so that the list still keeps increasing with the score." << endl;
		cout << "\t\t15. Check if the above linked list contains a circle or not?" << endl;
		cout << "\t\t16. Find students whose last name begins with the letter H." << endl;
		cout << "\t\t17. Input 1 student information and add to the list. If ID already exists, update information." << endl;
		cout << "\t\t18. Output list." << endl;
		cout << "\t\t19. Clear." << endl;
		cout << "\t\t00. Exit" << endl;
		cout << "\t\t===== END =====" << endl;

		cout << "Choice >> ";
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			createList(l);
			break;
		}
		case 2:
		{
			input(s);
			addHead(l, s);
			break;
		}
		case 3:
		{
			input(s);
			addTail(l, s);
			break;
		}
		case 4:
		{
			if (l.head == NULL)
			{
				cout << "\nEmpty list!" << endl;
				break;
			}
			input(s);
			addNodeAfterHead(l, s);
			break;
		}
		case 5:
		{
			if (l.head == NULL)
			{
				cout << "\nEmpty list!" << endl;
				break;
			}
			input(s);
			addNodeBeforeTail(l, s);
			break;
		}
		case 6:
		{
			add5NodesWithRandomInformation(l, s);
			break;
		}
		case 7:
		{
			deleteHead(l);
			break;
		}
		case 8:
		{
			deleteTail(l);
			break;
		}
		case 9:
		{
			float target_marks;
			deleteAllStudentsWhoseMarksJustEntered(l, target_marks);
			break;
		}
		case 10:
		{
			add10NodesWithRandomInformation(l, s);
			break;
		}
		case 11:
		{
			removeDuplicates(l); // van chua xong
			break;
		}
		case 12:
		{
			reverse(l);
			break;
		}
		case 13:
		{
			insertionSort(l);
			break;
		}
		case 14:
		{
			input(s);
			Node* p = createNode(s);
			insertAsc(p);
			break;
		}
		case 15:
		{
			bool check = checkCircle(l);

			if (check == true)
				cout << "\nWith circle" << endl;
			else
				cout << "\nNo circle" << endl;

			break;
		}
		case 16:
		{
			printH(l);
			break;
		}
		case 17:
		{
			addOrUpdate(l);
			break;
		}
		case 18:
		{	
			output(l);
			break;
		}
		case 19:
		{
			clear(l);
			break;
		}
		case 0: break;

		default: 
		{
			cout << "\nIllegal!";
			break;
		}
		}
	} while (choice);
}