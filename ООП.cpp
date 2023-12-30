#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
int j = 1;


class Animal
{
protected:
	string Name;
	string Type;
public:
	virtual void display() const
	{
		cout << "Имя " << j << ": " << this->Name << '\n';
		cout << "Вид " << j << ": " << this->Type << '\n';
	}
};


class Bird : public Animal
{
protected:
	double Size_Wings;
public:
	void SetName(string a)
	{
		Name = a;
	}
	void SetType(string a)
	{
		Type = a;
	}
	void SetSize_Wings(double a)
	{
		Size_Wings = a;
	}
	void GetName()
	{
		cout << "Имя " << j << ": " << this->Name << '\n';
	}
	void GetType()
	{
		cout << "Вид " << j << ": " << this->Type << '\n';
	}
	void display() const override
	{
		cout << "Имя " << j << ": " << this->Name << '\n';
		cout << "Вид " << j << ": " << this->Type << '\n';
		cout << "Размах крыльев " << j << ": " << this->Size_Wings << " см" << '\n';
	}
};


class Mammal : public Animal
{
protected:
	string Type_Wool;
public:
	void SetName(string a)
	{
		Name = a;
	}
	void SetType(string a)
	{
		Type = a;
	}
	void SetType_Wool(string a)
	{
		Type_Wool = a;
	}
	void display() const override
	{
		cout << "Имя " << j << ": " << this->Name << '\n';
		cout << "Вид " << j << ": " << this->Type << '\n';
		cout << "Тип шерсти " << j << ": " << this->Type_Wool << '\n';
	}
};



int main()
{
	system("chcp 1251 > nul");
	Bird B1, B2, B3;
	Mammal M1, M2, M3;
	vector <Animal> Animals;
	vector <Bird> Birds = { B1,B2,B3 };
	vector <Mammal> Mammals = { M1,M2,M3 };
	vector <string> Name = { "сапсан", "трясогузка", "филин" };
	vector <string> Type = { "соколообразный", "воробьинообразная", "совообразный" };
	vector <double> Size_Wings = { 120, 25, 175 };

	vector <string> Name1 = { "хорёк", "гепард", "овцебык" };
	vector <string> Type1 = { "куньи", "кошачьи", "паррнокопный" };
	vector <string> Type_Wool = { "короткая", "короткая", "длинная" };
	for (int i = 0; i < 3; i++)
	{
		Birds[i].SetName(Name[i]);
		Birds[i].SetType(Type[i]);
		Birds[i].SetSize_Wings(Size_Wings[i]);
		Birds[i].display();
		j++;
		cout << '\n';
		Animals.push_back(Birds[i]);
	}
	for (int i = 0; i < 3; i++)
	{
		Mammals[i].SetName(Name1[i]);
		Mammals[i].SetType(Type1[i]);
		Mammals[i].SetType_Wool(Type_Wool[i]);
		Mammals[i].display();
		j++;
		cout << '\n';
		Animals.push_back(Mammals[i]);
	}
	j = 0;
	for_each (Animals.begin(), Animals.end(), [](Animal i)
	{
			j++;
			i.display();
			cout << '\n';
	});
}