#include <stdio.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <stdexcept>

namespace WidgetStuff {

template<typename T>
class Widget {
public:
    Widget(T t);
    ~Widget();
    void swap(Widget& other);
    T getObj();
private:
    T* obj;
};

template<typename T>
Widget<T>::Widget(T t)
{
    obj = new T(t);
}

template<typename T>
Widget<T>::~Widget()
{
    if (obj != NULL) {
        delete obj;
    }
}

template<typename T>
void Widget<T>::swap(Widget<T>& other)
{
    using std::swap;
    swap(obj, other.obj);
}

template<typename T>
T Widget<T>::getObj()
{
    return *obj;
}

template<typename T>
void swap(Widget<T>& a, Widget<T>& b)
{
    printf("this swap has been called\n");
    a.swap(b);
}

template<typename T>
void doSomething(T& obj1, T& obj2)
{
    using std::swap;
    swap(obj1, obj2);
}

}

int main()
{
    using WidgetStuff::doSomething;
    using WidgetStuff::Widget;
    int a1 = 5;
    int a2 = 10;
    doSomething(a1, a2);
    printf("a1 = %d, a2 = %d\n", a1, a2);
    Widget<int> w1(5);
    Widget<int> w2(10);
    doSomething(w1, w2);
    printf("w1 = %d, w2 = %d\n", w1.getObj(), w2.getObj());
}
