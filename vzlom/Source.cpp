#include <iostream>
using namespace std;
struct sList
{
	int count; //Ввод индекса
	int mainInfo; //Данныеiterator
	sList * nextElem; //След. элемент
};
class cList
{
public:
	cList()
	{
		head = nullptr;
	}
	void p_back(int inx)
	{
		sList * inxA = new sList;
		if (head == nullptr)
		{
			head = inxA;
			head->mainInfo = inx;
			head->count = 1;
			head->nextElem = nullptr;
		}
		else if (head != nullptr)
		{
			inxA->mainInfo = inx;
			sList * inxB = head;
			while (inxB->nextElem != nullptr)
			{
				inxB = inxB->nextElem;
			}
			inxB->nextElem = inxA;
			inxA->nextElem = nullptr;
			addCount();
		}
	}
	void p_front(int iny)
	{
		sList * inyA = new sList;
		inyA->mainInfo = iny;
		inyA->nextElem = head;
		head = inyA;
		addCount();
	}
	void l_print()
	{
		sList * inxA = head;
		while (inxA != nullptr)
		{
			cout << inxA->count << "\t--\t" << inxA->mainInfo << endl;
			inxA = inxA->nextElem;
		}
	}
	void l_printCount(int indxCntr)
	{
		sList * del = head;
		int cntr = 1;
		while (del != nullptr)
		{
			if (cntr == indxCntr)
			{
				cout << del->count << "\t--\t" << del->mainInfo << endl;
				break;
			}
			del = del->nextElem;
			cntr++;
		}
	}
	void DeleteAll()
	{
		sList * del = head;
		while (head != nullptr)
		{
			head = head->nextElem; //nullptr
			delete del; //
			del = head; //nullptr
		}
	}
	void DeleteCount(int delUser) // удаление элемента по индексу
	{
		sList * del = head;
		if (delUser == 1)
		{
			head = head->nextElem;
			delete del;
		}
		else
		{
			int cntr = 1;
			while (del != nullptr)
			{
				if (cntr == delUser - 1)
				{
					sList * remElem = del->nextElem;
					del->nextElem = del->nextElem->nextElem;
					delete remElem;
					break;
				}
				cntr++;
				del = del->nextElem;
			}
		}
	}
	void changeCount(int cnhgCon, int indx) // изменение элемента по индексу
	{
		sList * cnhgr = head;
		int cntr = 1;
		while (cnhgr != nullptr)
		{
			if (cntr == cnhgCon)
			{
				cnhgr->count = cnhgCon;
				cnhgr->mainInfo = indx;
				break;
			}
			cntr++;
			cnhgr = cnhgr->nextElem;
		}
	}
	~cList()
	{

	}
private:
	sList * head;
	void addCount()
	{
		sList * inxA = head;
		int a = 1;
		while (inxA != nullptr)
		{
			inxA->count = a;
			++a;
			inxA = inxA->nextElem;
		}
	}
};

int main()
{
	cList fun;
	fun.p_back(10);
	fun.p_back(20);
	fun.p_back(30);
	fun.p_back(40);
	fun.p_back(50);
	fun.l_print();
	cout << "---" << endl;
	fun.changeCount(5, 405);
	fun.l_print();
	system("pause");
	return 0;
}