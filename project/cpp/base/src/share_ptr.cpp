#include<iostream>
#include<memory>
#include"A.hpp"
#include"B.hpp"
using namespace std;
void shareptrfuncpara(shared_ptr<A> ptr) {
	ptr->print();
	ptr->SetA1(300);
	return;
}
void shareptr()
{
	{
		int *p;
		int a;
		p = (int*)a;
	}
	{
		shared_ptr<A> ptra = make_shared<A>();
		ptra->SetA1(100);
		{
			//A* a = (A*)&ptra;
			//A* a = reinterpret_cast<A*>(reinterpret_cast<int*>(ptra));
			//cout << " a->GetA1() :" << a->GetA1() << endl;
		}
		cout << " ptra->GetA1() :" << ptra->GetA1() << endl;
		cout << "shared_ptr<A> ptra = make_shared<A>();" << endl;
		ptra->print();
		{
			shared_ptr<A> ptra1 = ptra;
			ptra->SetA1(200);
			ptra1->print();
			cout << " ptra->GetA1() :" << ptra->GetA1() << endl;
			cout <<" ptra1->GetA1() :" <<  ptra1->GetA1() << endl;
		}
		cout << "shared_ptr<A> ptra1 = ptra;" << endl;
		{
			weak_ptr<A> ptra2 = ptra;
		}
		cout << "shareptrfuncpara start" << endl;
		shareptrfuncpara(ptra);
		cout << "shareptrfuncpara end" << endl;

		cout << " ptra->GetA1() :" << ptra->GetA1() << endl;

		ptra = NULL;
		cout << " ptra = NULL;"<< endl;
	}

}
//int main() {
//	shareptr();
//	system("pause");
//	return 0;
//}