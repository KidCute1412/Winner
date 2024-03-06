#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>


struct Node {
	int data;
	Node* next;
};
struct DNode {
	int data;
	DNode *next, * prev;
};

// INPUT Node until 0
void inputNode(Node*& arr)
{
	int x;
	Node* cur = arr;
	Node* pre = arr;
	std::cin >> x;
	if (!x)
	{
		arr = NULL;
		return;
	}
	while (x)
	{
		cur->data = x;
		pre = cur;
		cur->next = new Node;
		cur = cur->next;
		std::cin >> x;
	}
	pre->next = NULL;


}
// OUTPUT Node formally

void outputNode(Node* arr)
{
	while (arr)
	{
		std::cout << arr->data << " ";
		arr = arr->next;
	}
}


// INPUT DNode until 0

void inputDNode(DNode*& arr)
{
	int x;
	DNode* tmp = arr;
	arr->prev = NULL;
	do {
		std::cin >> x;
		if (x == 0)
		{
			tmp->prev->next = NULL;
		}
		tmp->data = x;
		tmp->next = new DNode;
		tmp->next->prev = tmp;
		tmp = tmp->next;
	} while (x != 0);

}

// OUTPUT DNode formally

void outputDNode(DNode* arr)
{
	DNode* tmp = arr;
	while (tmp->next)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
	std::cout << tmp->data << std::endl;
	while (tmp)
	{
		std::cout << tmp->data << " ";
		tmp = tmp->prev;
	}
	delete tmp;
}


// Deallocate

void deallocateNodeList(Node* &arr)
{
	while (arr)
	{
		Node* tmp = arr;
		arr = arr->next;
		delete tmp;
	}
}
// Need to be fixed
void deleteAllXNode(Node*& arr, int& x)
{
	std::cout << "Input x:";
	std::cin >> x;
	if (!arr)
	{
		return;
	}
	Node* cur = arr;
	Node* prev = arr;
	while (cur->data == x)
	{
		prev = cur;
		cur = cur->next;
		arr = cur;
		

	}
	while (cur)
	{
		if (cur->data == x)
		{
			prev->next = cur->next;
			Node* tmp = cur;
			cur = cur->next;
			delete tmp;
		}
		else {
			prev = cur;
			cur = cur->next;
		}
	}
}

void deleteAllXDNode(DNode*& arr, int& x)
{
	std::cout << "Input x: ";
	std::cin >> x;
	DNode* cur = arr;
	DNode* prev = arr;
	while (cur->data == x)
	{
		DNode* tmp = cur;
		cur = cur->next;
		delete tmp;
		arr = cur;
		prev = cur;
		cur->prev = NULL;
	}
	while (cur)
	{
		if (cur->data == x)
		{
			prev->next = cur->next;
			DNode* tmp = cur;
			cur = cur->next;
			delete tmp;
			if (cur->next)
				cur->next->prev = prev;

		}
		else {
			prev = cur;
			cur = cur->next;
		}
	
	}
}




// DELETE modern way
void deleteAllXNodeUp(Node*& arr, int& x)
{
	std::cout << "Input x:";
	std::cin >> x;
	Node* cur = arr;
	Node* pre = arr;
	while (cur->next)
	{
		if (cur->data == x)
		{
			Node* tmp = cur->next;
			*cur = *tmp;
			delete tmp;

		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	if (cur->next == NULL && cur->data == x)
	{
		pre->next = NULL;
		delete cur;
	}
}

void deleteAllXDNodeUp(DNode*& arr, int& x)
{
	std::cout << "Input x: ";
	std::cin >> x;
	DNode* cur = arr;
	DNode* pre = NULL;
	while (cur->next)
	{
		if (cur->data == x)
		{
			DNode* tmp = cur->next;
			*cur = *tmp;
			cur->prev = pre;
			delete tmp;
			if (cur->next)
				cur->next->prev = cur;
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	if (cur->next == NULL && cur->data == x)
	{
		pre->next = NULL;
		delete cur;
	}
}






//Stadiumname, Status, Capacity, Country, City, Clubs, Renovations, Record attendance, Address
struct stadium {
	std::string Stadiumname;
	std::string Status;
	std::string Capacity;
	std::string Country;
	std::string City;
	std::string Clubs;
	std::string Renovations;
	std::string Record;
	std::string Address;
};
void readFile(stadium G[], int& n)
{
	n = 0;
	std::ifstream fin;
	fin.open("stadium.txt");
	if (!fin.is_open())
	{
		std::cout << "Fail?";
		return;
	}
	std::string ignore_line;
	std::getline(fin, ignore_line);
	while (std::getline(fin, G[n].Stadiumname, ',')) {
		std::getline(fin, G[n].Status, ',');
		std::getline(fin, G[n].Capacity, ',');
		std::getline(fin, G[n].Country, ',');
		std::getline(fin, G[n].City, ',');
		std::getline(fin, G[n].Clubs, ',');
		char ignore_one;

		fin >> ignore_one;

		char ignore_two;
		if (ignore_one == '"')
		{
			fin.ignore();
			std::getline(fin, G[n].Renovations, '"');
			
			fin >> ignore_two;
			fin.ignore();
		}
		else if (ignore_one != '"' && ignore_one != ',')
		{
			fin.ignore();
			std::getline(fin, G[n].Renovations, ',');
			G[n].Renovations = ignore_one + G[n].Renovations;
			
		}
		fin >> ignore_one;
		if (ignore_one == '"')
		{
			fin.ignore();
			std::getline(fin, G[n].Record, '"');
			fin >> ignore_two;
			fin.ignore();
		}
		else if (ignore_one != '"' && ignore_one != ',')
		{
			fin.ignore();
			std::getline(fin, G[n].Record, ',');
			G[n].Record = ignore_one + G[n].Record;
		}
		fin >> ignore_one;
		if (ignore_one == '"')
		{
			fin.ignore();
			std::getline(fin, G[n].Address, '"');
		}
		else if (ignore_one != '"' && ignore_one != ',')
		{
			fin.ignore();
			std::getline(fin, G[n].Address, ',');
			G[n].Address = ignore_one + G[n].Address;
		}
		n++;
	
	}
	fin.close();

}
void printFile(stadium G[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << "1." << G[i].Stadiumname << " 2." << G[i].Status << " 3." << G[i].Capacity << " 4." << G[i].Country << " 5." << G[i].City << " 6." << G[i].Clubs << " 7." << G[i].Renovations << " 8." << G[i].Record << " 9." << G[i].Address << std::endl;
	}
}

// Remove Duplicate (unfinished)

int countNumbersNode(Node* arr)
{
	int n = 0;
	while (arr)
	{
		n++;
		arr = arr->next;
	}
	return n;
}
void RemoveDuplicate(Node*& arr)
{
	int n = countNumbersNode(arr);
	int* members = new int[n];
	Node* pmembers = arr;

}



// Reverse list
void reverseNodeList(Node*& arr)
{
	Node* cur = arr;
	Node* pre = NULL;
	while (cur)
	{
		Node* tmp = cur;
		cur = cur->next;
		tmp->next = pre;
		pre = tmp;
	}
	arr = pre;
}





// Insert Even Number

void insertEvenNumber(Node*& arr)
{
	if (!arr)
		return;
	Node* cur = arr;
	Node* pre = NULL;
	int data = 2;
	while (cur)
	{
		Node* newOne = new Node;
		newOne->data = data;
		newOne->next = cur;
		if(pre != NULL)
			pre->next = newOne;
		if (cur == arr)
			arr = newOne;
		data += 2;
		pre = cur;
		cur = cur->next;


	}
}


// Sorted List


void insertInSortedList(Node*& arr)
{
	int n;
	std::cout << "Input n: ";
	std::cin >> n;
	Node* cur = arr;
	Node* NodeX = new Node;
	NodeX->data = n;
	Node* pre = NULL;
	while (cur)
	{
		if (n <= cur->data && !pre)
		{
			NodeX->next = arr;
			arr = NodeX;
			return;
		}
		else if (pre && pre->data < n && cur->data >= n)
		{
			NodeX->next = cur;
			pre->next = NodeX;
			return;
		}
		else if (cur->next == NULL && cur->data <= n)
		{
			NodeX->next = cur->next;
			cur->next = NodeX;
			return;
		}
		pre = cur;
		cur = cur->next;
	}

}



// List Of Sum

void listofSum(Node*& arr)
{
	Node* cur = arr;
	if (!arr)
		return;
	int sum = 0;
	while (cur)
	{
		sum += cur->data;
		cur->data = sum;
		cur = cur->next;
		
	}
}


// Seperate ODD list and EVEN list

void seperateList(Node*& arr, Node*& arrODD, Node*& arrEVEN)
{
	Node* cur = arr;
	arrODD = NULL;
	arrEVEN = NULL;
	if (cur) {
		arrODD = cur;
		cur = cur->next;
	}

	if (cur) {
		arrEVEN = cur;
		cur = cur->next;
	}
	Node* cur1 = arrODD;
	Node* cur2 = arrEVEN;
	int i = 3;
	while (cur)
	{
		if (i % 2 != 0)
		{
			cur1->next = cur;
			cur1 = cur1->next;
		}
		else {
			cur2->next = cur;
			cur2 = cur2->next;
		}
		i++;
		cur = cur->next;
		
	}
	if (cur1)
		cur1->next = NULL;
	if (cur2)
		cur2->next = NULL;
	
	

}

// Merge 2 List In Order

void merge2NodeList(Node*& arr1, Node* arr2)
{
	Node* cur1 = arr1;
	Node* cur2 = arr2;
	if (!cur1)
	{
		cur1 = cur2;
		return;
	}
	if (cur1 && cur2 && cur1->data > cur2->data)
	{
		Node* tmp = cur1;
		cur1 = cur2;
		cur2 = tmp;
	}
	while (cur1->next && cur2)
	{
		if (cur1->next->data <= cur2->data)
		{
			cur1 = cur1->next;
		}
		else {
			Node* tmp = cur1->next;
			cur1->next = cur2;
			cur2 = tmp;
			cur1 = cur1->next;
			
		}
	}
	if (cur1->next == NULL && cur2)
	{
		cur1->next = cur2;
	}
}

void merge2NodeListV2(Node*& arr1, Node* arr2)
{

}


// List to Number
void newinputListToNumber(Node*& arr)
{
	Node* cur = arr;
	int x;
	std::cin >> x;
	if (x < 0)
		cur = NULL;
	do {
		cur->data = x;
		cur->next = new Node;
		std::cin >> x;
		if (x < 0) {
			cur->next = NULL;
			return;
		}
		cur = cur->next;

	} while (x >= 0);
}

int numberFromNodeList(Node*& arr)
{
	int res = 0;
	Node* cur = arr;
	while (cur)
	{
		res = res * 10 + cur->data;
		cur = cur->next;
	}
	return res;
}


// Number to List

void numberToNodeList(Node*& arr, int& n)
{
	std::cout << "Input n: ";
	std::cin >> n;
	Node* cur = arr;
	do {
		int x = n % 10;
		n = n / 10;
		cur->data = x;
		if (n != 0)
		{
			cur->next = new Node;
			cur = cur->next;
		}
	} while (n != 0);
	cur->next = NULL;
	reverseNodeList(arr);
	
}




int main()
{
	Node* arr = new Node;
	int n;
	numberToNodeList(arr, n);
	outputNode(arr);
;

	
	
}