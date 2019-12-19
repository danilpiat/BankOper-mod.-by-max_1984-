//
// Created by Олег on 26.11.2019.
//

#include "bankint.h"

Assoc::Assoc(const Assoc &a) {
    for (auto p = arr.begin(); p != arr.end(); ++p)
        arr.insert(make_pair(p.ii->first, p.ii->second));
}


std::ostream &operator<<(std::ostream &s, const Assoc &a) {
    s << "===== Assoc =====" << std::endl;
    a.getOwn().print();
    return s;
}


void Assoc::insert(int s,UsualDep* u) {
    arr.insert(make_pair(s, u));
}
void Assoc::erase(int s)  {
    arr.erase(s);
}
OwnIterator Assoc::get(int x) {
    auto p = arr.find(x);
    if (p == arr.end())
        throw MyException("illegal index");
    return p;
    //cout <<"number = "<<p->first <<"\nDeposit = "<< p->second << endl;
}

bool Assoc::check(int s)
{
    auto  p = arr.find(s);
    if (p == arr.end()) return true;
    return false;
}

int Assoc::getCurDate() const {
    return cur_date;
}

void Assoc::setCurDate(int curCate) {
    cur_date = curCate;
}

int Assoc::getCurYear() const {
    return cur_year;
}

void Assoc::setCurYear(int curYear) {
    cur_year = curYear;
}
