//
// Created by Олег on 16.12.2019.
//



#include <iostream>

#include <vector>
#include <iterator>
#include "bankint.h"

OwnIterator OwnContainer::begin() {return OwnIterator(data.begin());}
OwnIterator OwnContainer::end()  {return OwnIterator(data.end());}

void OwnContainer::insert(std::pair<int,UsualDep*> fi) {
    OwnIterator ix=begin();
    if (data.empty()) data.push_back(fi);
    else {
    cout<<"2";
    for(; ix!=end()&&ix.ii->first!=fi.first;++ix);
    if(ix!=end()|| (ix==end()&&ix.ii->first==fi.first))
    {ix.ii->second=fi.second;        cout<<"1";
        return;}
    else {
        data.push_back(fi);
        cout<<"0";
    }}
}
void OwnContainer::erase(int k) {
    if (data.empty()) return;
    OwnIterator ix=begin();
    for(; ix!=end()&&ix.ii->first!=k;++ix);
    data.erase(ix.ii);
}

OwnIterator OwnContainer::find(int k) {
    if (data.empty()) return begin();
    OwnIterator ix=begin();
    for(; ix!=end()&&ix.ii->first!=k;++ix);
    return ix;
}

void OwnContainer::print() {
    if (data.empty()) return;
    for(auto i=begin(); i!=end();++i)
        std::cout<<i<<std::endl;
    std::cout<<"--------"<<std::endl;
}

OwnIterator &OwnIterator::operator++(){ii++;return *this;}
bool OwnIterator::operator!=(OwnIterator const& other) const{return ii != other.ii;}
bool OwnIterator::operator==(OwnIterator const& other) const{return ii == other.ii;}
std::ostream &operator<<(std::ostream &os, const OwnIterator &iterator) {return os << "i: "<<iterator.ii->first<<"   " <<*iterator.ii->second;}

