#include <iostream>
template<typename... Types>
 inline void marker(Types&&...) {}

template <class T> T&& f1(T&& a)
{ std::cout << a << " "; return a; }

template <class T> T&& f2(T&& a)
{  std::cout << 2*a << " "; return a; }

 template<class ... Types> int F(Types ... arg) {
 // у тілі лямбди через список захоплення
  auto L1 = [=]() { marker(f1(arg)...);  };
  L1();
 // у списку захоплення лямбди
  auto L2 = [&, arg...]{return marker(f2(arg)...);};
  L2();
  return 0;
 }
 int main() {  int g = F(1, 2, 3); }
