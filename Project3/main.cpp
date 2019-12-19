
//#define NDEBUG

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <limits>
#include <stdexcept>

#include "bankint.h"

#include "acutest.h"

int debug = 0;
bool testingSuccess = false;

using namespace std;

void Test(void)
{
	/* Deposits */

	UsualDep* udep = new UsualDep(1, 2, 3, 4, 5);
	termDep* tdep = new termDep(11, 12, 13, 14, 15, 16);
	currencyDep* cdep = new currencyDep(21, 22, 23, 24, 25, 26);

	// udep, udep2

	TEST_CHECK(udep->getAmount() == 1);
	TEST_CHECK(udep->getPercent() == 2);
	TEST_CHECK(udep->getDate() == 3);
	TEST_CHECK(udep->getYear() == 4);
	TEST_CHECK(udep->getNumber() == 5);

	// tdep

	TEST_CHECK(tdep->getAmount() == 11);
	TEST_CHECK(tdep->getPercent() == 12);
	TEST_CHECK(tdep->getDate() == 13);
	TEST_CHECK(tdep->getYear() == 14);
	TEST_CHECK(tdep->getNumber() == 15);
	TEST_CHECK(tdep->getSafeDate() == 16);

	// cdep

	TEST_CHECK(cdep->getAmount() == 21);
	TEST_CHECK(cdep->getPercent() == 22);
	TEST_CHECK(cdep->getDate() == 23);
	TEST_CHECK(cdep->getYear() == 24);
	TEST_CHECK(cdep->getNumber() == 25);
	TEST_CHECK(cdep->getExchangeRate() == 26);

	cout << *udep << "\n";
	cout << *tdep << "\n";
	cout << *cdep << "\n";

	/* Assoc */

	Assoc* a = new Assoc();

	/*
	public:
		Assoc();
		int getCurYear() const;
		void setCurYear(int curYear);
		int getCurDate() const;
		void setCurDate(int curCate);
		friend std::ostream& operator <<(std::ostream&, const Assoc&);
		void insert(int, UsualDep*);
		void erase(int n);
	*/
	a->setCurDate(3);
	a->setCurYear(4);

	TEST_CHECK(a->getCurDate() == 3);
	TEST_CHECK(a->getCurYear() == 4);

	cout << "curDate: " << a->getCurDate() << "\n";
	cout << "curYear: " << a->getCurYear() << "\n";

	a->insert(1, tdep);

	cout << *a << "\n";

	a->erase(1);

	cout << "After erasure:\n" << *a << "\n";

	/* Memory Work */

	delete a;
	delete cdep;
	delete tdep;
	delete udep;

	testingSuccess = true;
}

void EntryPoint(void)
{
	int option = 0;
	while (true) {
		cout << "\n1. Testing\n2. Dialog\n\nChoose an option: ";
		if ((cin >> option) && option >= 1 && option <= 2)
			break;
		cin.clear();
		cin.ignore(256, '\n');
	}

	if (option == 1) {
		Test();
		TEST_CHECK(testingSuccess);
	}
	else {
		std::cout << "Hello, World!" << std::endl;
		Application* app = new Application;
		app->start();
	}
}

TEST_LIST = {
	{ "EntryPoint", EntryPoint },
	{ nullptr, nullptr }
};

/*
 std::ostream& operator <<(std::ostream &os, const std::map<int, UsualDep*>::iterator &el){
	return os<< el->first <<": "<<el->second<<endl;
}
std::ostream& operator <<(std::ostream &os, const std::map<int, UsualDep*>::const_iterator &el){
	return os<< el->first <<": "<<el->second<<endl;
}
 */