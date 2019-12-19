//
// Created by РћР»РµРі on 25.11.2019.
//

#ifndef DAN2_BANKINT_H
#define DAN2_BANKINT_H
#include <iostream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;
struct MyException : public std::exception
{
    std::string s;
    MyException(std::string ss) : s(ss) {}
    ~MyException() throw () {} // Updated
    const char* what() const throw() { return s.c_str(); }
};

class UsualDep
{
public:
    UsualDep()= default;
    UsualDep(double amount, double percent, int date, int year, int number);
    [[nodiscard]] int getNumber() const;
    void setNumber(int _number);
    [[nodiscard]] double getAmount() const;
    void setAmount(double _amount);
    [[nodiscard]] int getDate() const;
    void setDate(int _date);
    [[nodiscard]] int getDateLast() const;
    void setDateLast(int _dateLast);
    [[nodiscard]] double getPercent() const;
    void setPercent(double _percent);
    [[nodiscard]] double getYear() const ;
    void setYear(int _year);
    virtual std::ostream& show(ostream &os)const;
    virtual double the_amount_of_accrued_interest(int datex, int yearx);
    virtual void print_interests(int datex, int yearx);
    void recalculate (int datex, int yearx);

    friend ostream &operator<<(ostream &os, const UsualDep &dep);
    virtual void getMoney(double a, int date , int year);
protected:
    double amount;
    double percent;
    int date;
    int year;
    int dateLast;
    int number;
};
class termDep : public UsualDep
{
public:
    termDep(){};
    virtual std::ostream& show(ostream &os)const;
    termDep(double amount, double percent, int date, int year, int number, int safeDate);
    [[nodiscard]] int getSafeDate() const;
    void setSafeDate(int _safeDate);
    virtual double the_amount_of_accrued_interest(int datex, int yearx);
    virtual void print_interests(int datex, int yearx);

    friend ostream &operator<<(ostream &os, const termDep &dep);
    virtual void getMoney(double a, int date , int year);
private:
    int safeDate;
};
class currencyDep : public UsualDep
{

public:
    virtual std::ostream& show(ostream &os)const;
    friend ostream &operator<<(ostream &os, const currencyDep &dep);
    currencyDep(){};
    currencyDep(double amount, double percent, int date, int year, int number, double exchange_rate);
    [[nodiscard]] double getExchangeRate() const;
    void setExchangeRate(double _exchangeRate);
    virtual double the_amount_of_accrued_interest(int datex, int yearx);
    virtual void print_interests(int datex, int yearx);
    virtual double the_amount_of_accrued_interest_incurr(int datex, int yearx);
    virtual void getMoney(double a, int date , int year);
private:
    double exchange_rate;
};






class OwnIterator: public std::iterator<std::input_iterator_tag, std::pair<int,UsualDep*>> {
public:
    friend class OwnContainer;
    OwnIterator(std::vector <std::pair<int,UsualDep*>>::iterator ii) : ii(ii) {}
    OwnIterator &operator++();
    bool operator!=(OwnIterator const &other) const;
    bool operator==(OwnIterator const &other) const;
    friend std::ostream &operator<<(std::ostream &os, const OwnIterator &iterator);

    std::vector <std::pair<int,UsualDep*>>::iterator ii;
};
class OwnContainer
{
public:
    OwnContainer()= default;
    OwnContainer(std::initializer_list<std::pair<int,UsualDep*>> l):data(l){};
    [[nodiscard]] OwnIterator begin();
    [[nodiscard]] OwnIterator end();
    void insert(std::pair<int,UsualDep*>);
    void erase(int k);
    OwnIterator find(int k);
    void print();
private:
    std::vector <std::pair<int,UsualDep*>> data;

};


class Assoc
{
private:
    int cur_date=0;
    int cur_year=0;
    OwnContainer getOwn() const {return arr;}
public:
    int getCurYear() const;
    void setCurYear(int curYear);
    int getCurDate() const;
    void setCurDate(int curCate);

public:
    OwnContainer arr;
    Assoc() {}
    Assoc(const Assoc&);
    ~Assoc() {};
    friend std::ostream& operator <<(std::ostream&, const Assoc&);
    void insert(int,UsualDep*);
    void erase(int n);
    OwnIterator get(int x);
    bool check(int num);
};


class Application
{
private:
    Assoc* a;
public:
    Application()
    { a = new Assoc();}
    void start();
    void printAll();

    void recalculate();
    void addDeposit(int num);
    void closeDeposit(int num);
    void find(int num);
    void modify(int num);

};




#endif //DAN2_BANKINT_H