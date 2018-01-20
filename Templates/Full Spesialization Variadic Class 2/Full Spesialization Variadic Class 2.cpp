// Full Spesialization Variadic Class 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>  


// Variadic Template Unpacking parameter pack of arg.cpp: ���������� ����� ����� ��� ����������� ����������.
//

template <int...> struct A;


template<typename... Types> void mark(Types...) {}

template <class T> T Out(T a) { std::cout << a << " "; return a; }

template <int first, int second, int... arg> //1
struct A<first, second, arg...> {
	A() {

		std::cout << "ctor <first, second, arg...>" << first << "*" << second << "*";
		// ������� ������������� ���� ���� �����
		mark(Out(arg)...);
		std::cout << "\n";
	}
	static const int value = A< first * second, arg...>::value;
};

template <int first>//2
struct A<first> {
	A() {
		std::cout << "ctor <first>" << first << "\n";
	}
	static const int value = first;

};

/*// - ��������� 1
template <int first, int... arg>//3
struct A<first,arg...> {
A() {
std::cout << "ctor <first,arg...>" << first << "*";
mark(Out(arg)...);
std::cout << "\n";
}

};*/




int main() {
	A<0> a1;

	A<3, 4, 5, 6, 7> a2;
	A<10, 40> a3;

	system("pause");
	return 0;
}
