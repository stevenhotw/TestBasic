#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include <QPoint>
#include <QtMath>
#include <QSet>
#include <QStringList>
#include <algorithm>
#include <functional>
#include "myclass.h"

std::vector<MyClass> createVec()
{
    std::vector<MyClass> vec;
    MyClass obj;
    obj.setText("Hello Steven");
    vec.push_back(obj);
    return vec;
}

template<typename T>
void f(T& param)
{
    //param += 1;
}

template<typename T>
void f(T&& param)
{
    param += 1;
}

template<typename T>
void f1(T param)
{
    param += 1;
}

template<typename T>
void f2(T* param)
{
    //*param += 1;
    qDebug() << *param;
}

void f3(int param[])
{
    param[0] = 99;
}

void f4(int* param)
{
    param[0] = 999;
}

int& f5()
{
    int x = 100;
    x++;
    return x; // runtime error
}
//class MyPoint : public QPoint
//{
//public:
//    MyPoint() : QPoint() {}
//    MyPoint(int x, int y) : QPoint(x, y) {}

//    MyPoint& operator=(const MyPoint &rhs)
//    {
//        QPoint::operator=(rhs);
//        z = 9999;
//    }

//    int z = -1;
//    QPoint parent;
//};

//inline uint qHash (const MyPoint & key)
//{
//    return qHash (static_cast <qint64> (key.x () ) << 32 | key.y () );
//}

class A
{
public:
    A() {qDebug() << "A() constructor.";}
         A(int a) : A() {qDebug() << "A(int a) constructor.";}
    ~A() {qDebug() << "A destructor called.";}
};

class B : public A
{
public:
    ~B() {qDebug() << "B destructor called.";}
};

bool isEqual(double value1, double value2, quint8 precision)
{
    qreal difference = qFabs(value1 - value2);
    qreal epsilon = qPow(10, -precision);

    if(QString::number(difference,'f',precision) == QString::number(epsilon,'f',precision))
    {
        return false;
    }
    else
    {
        return difference < epsilon;
    }
}

double ConvertToSlope(double angle)
{
    if ((int)angle % 180 == 0)
        return 0.0;
    else if ((int)angle % 90 == 0)
        return std::numeric_limits<double>::max();
    else
        return qTan((M_PI / 180.0) * angle);
}

bool IsInfinity(double value)
{
    if (value > std::numeric_limits<double>::max()){
        return true;
    }
    else if (value < -std::numeric_limits<double>::max()){
        return true;
    }
    else
        return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    A* a = new A(1);

    double slope = ConvertToSlope(90);
    qDebug() << "slope ? " << slope;
    qDebug() << "IsInfinity(slope) ? " << IsInfinity(slope);

    double dd = NAN;
    double d1 = 0.0;
    double d11 = INFINITY;
    double d12 = std::numeric_limits<double>::max();
    double d13 = INFINITY;
    qDebug() << "dd is NAN ?" << qIsNaN(dd);
    qDebug() << "d1 is NAN ?" << qIsNaN(d1);
    qDebug() << "0.0 / 0.0 is NAN ?" << qIsNaN(d1/d1);
    qDebug() << "1.0 / 0.0 is NAN?" << qIsNaN(1.0 / d1);
    qDebug() << "1.0 / 0.0 is Infinity?" << qIsInf(1.0 / d1);
    qDebug() << "d11 is Infinity?" << qIsInf(d11);
    qDebug() << "d11 = " << d11;
    qDebug() << "d12 is Infinity?" << qIsInf(d12);
    qDebug() << "d12 = " << d12;
    qDebug() << "d11 > d12 ?" << (d11 > d12);
    qDebug() << "d13 is Infinity?" << qIsInf(d12);
    qDebug() << "d11 == d13 ?" << (d11 == d13);

    double d2 = 999999.12345678901;
    double d3 = 999999.12345678801;
    qDebug() << QString("d2(%1) == d3(%2))) ?").arg(QString::number(d2,'f',4)).arg(QString::number(d3,'f',4)) << (d2 == d3);
    qDebug() << "isEqual(d2, d3, 12) ?" << isEqual(d2, d3, 12);
    qDebug() << "isEqual(d2, d3, 11) ?" << isEqual(d2, d3, 11);
    qDebug() << "isEqual(d2, d3, 10) ?" << isEqual(d2, d3, 10);
    qDebug() << "isEqual(d2, d3, 9) ?" << isEqual(d2, d3, 9);
    qDebug() << "isEqual(d2, d3, 8) ?" << isEqual(d2, d3, 8);
    qDebug() << "isEqual(d2, d3, 7) ?" << isEqual(d2, d3, 7);
    qDebug() << "isEqual(d2, d3, 6) ?" << isEqual(d2, d3, 6);
    qDebug() << "isEqual(d2, d3, 5) ?" << isEqual(d2, d3, 5);
    qDebug() << "isEqual(d2, d3, 4) ?" << isEqual(d2, d3, 4);
    qDebug() << "isEqual(d2, d3, 3) ?" << isEqual(d2, d3, 3);
    qDebug() << "isEqual(d2, d3, 2) ?" << isEqual(d2, d3, 2);
    qDebug() << "isEqual(d2, d3, 1) ?" << isEqual(d2, d3, 1);
    qDebug() << "isEqual(d2, d3, 0) ?" << isEqual(d2, d3, 0);

    qDebug() << "d11 > d2 ?" << (d11 > d2);

//    QStringList aList;
//    aList = QStringList() << "ab\\]";//<< "\\\\[" << "\\\\" << "\\\\]";
//    QString c = aList.join("");
//    c = QRegExp::escape(c);
//    QRegExp rxp = QRegExp(QString("[%1]*").arg(c));//QRegExp("[\\\\]*");
//    QString any = "\\";
//    bool b = rxp.exactMatch(any);


//    int intAry[] = {0, 1, 2};
//    int& intRef = intAry[1];
//    intRef = 999;
//    qDebug() << "intAry[1]: " << intAry[1];

//    int aNum = 66;
//    qDebug() << "aNum: " << aNum;
//    int* const aNum_ptr = &aNum;
//    *aNum_ptr = 77;
//    qDebug() << "aNum: " << aNum;

//    int otherNum = 666;
//    qDebug() << "otherNum: " << otherNum;
//    //aNum_ptr = &otherNum; //error: assignment of read-only variable 'aNum_ptr'
//    int const* otherNum_ptr = &otherNum;
//    //*otherNum_ptr = 777; //error: assignment of read-only location '*otherNum_ptr'
//    qDebug() << "otherNum: " << otherNum;



//    auto vw = createVec();
//    MyClass& obj1 = vw[0];

//    qDebug() << "original text: " << vw[0].text();
//    obj1.setText("Aaron");
//    qDebug() << "changed1 text: " << vw[0].text();
//    vw[0].setText("David");
//    qDebug() << "changed2 text: " << vw[0].text();

//    MyClass* ptr = &obj1;
//    ptr->setText("John"); //


//    qDebug() << "changed3 text: " << vw[0].text();
//    //MyClass*& pRef = &vw[0]; cannot reference a r value
//    MyClass* const & pRef = &vw[0];
//    qDebug() << pRef->text();
//    // pRef = &vw[1]; // compile error

//    if(!vw.empty())
//    {
//        f(&vw[0]);
//    }

//    const auto c_vw = createVec();
//    const MyClass& w_ref = c_vw[0];
//    MyClass obj;
//    obj.setText("Hello Aaron");
//    //c_vw.push_back(obj);


//    int anotherNum = 1999;
//    int anotherNum1= 2999;
//    const int* ptr_anotherNum = &anotherNum;
//    ptr_anotherNum = &anotherNum1;
//    //*ptr_anotherNum = 3999; error: assignment of read-only location
//    int const* ptr1_anotherNum = &anotherNum;
//    ptr1_anotherNum = &anotherNum1;
    //*ptr1_anotherNum = 3999; error: assignment of read-only location
//    int x = 99;

//    const int* px = &x;
    //int*& rpx = px;
//    const int*& crpx = px;
//    *rpx = 999;
//    qDebug() << x;

//    f2(px);
//    qDebug() << x;

//    f2(rpx);
//    qDebug() << x;

//    f2(crpx);
//    qDebug() << x;
//    int x = 99;
//    const int& rx = x;
//    f(rx);
//    qDebug() << rx;
//    QByteArray bAry(256, '\0');
//    uchar c = 0;
//    for(int i=0; i<256; i++)
//    {
//        c = ((uchar)i);
//        bAry[i] = c;
//    }

//    char* uc = ((char*)bAry.data());
//    for(int i=0; i<bAry.count(); i++)
//    {
//       qDebug() << (int)(uc[i]);
//    }

//    qreal a = NAN;
//    qreal b = 100;
//    qreal c = -100;
//    qDebug()  << "a: " << a << " b: " << b << " qMax(a, b): " << qMax(a, b);
//    qDebug()  << "a: " << a << " b: " << b << " qMin(a, b): " << qMin(a, b);
//    qDebug()  << "a: " << a << " c: " << c << " qMax(a, c): " << qMax(a, c);
//    qDebug()  << "a: " << a << " c: " << c << " qMin(a, c): " << qMin(a, c);

//    B* aB = new B();
//    delete aB;

//    MyPoint p1(33, 44);
//    p1.z = 99;
//    p1.parent = QPoint(11, 22);

//    MyPoint p2;
//    p2 = p1;
//qDebug() << "p2: " << p2;
//qDebug() << "p2.parent: " << p2.parent;
//qDebug() << "p2.z: " << p2.z;

//    QSet< MyPoint > pointSet;
//    MyPoint p1(5, 5);
//    p1.parent = QPoint(4, 4);
//    pointSet.insert(p1);

//    MyPoint p2(4, 4);
//    p2.parent = QPoint(3, 3);
//    pointSet.insert(p2);

//    MyPoint p3(3, 3);
//    p3.parent = QPoint(2, 2);
//    pointSet.insert(p3);

//    MyPoint p = *pointSet.find(MyPoint(3,3));
//    qDebug() << p;
//    qDebug() << p.parent;

//    char c1 = 128;
//    int i1 = c1;

//    qDebug() << "i1: " << i1;

//    unsigned char c2 = 128;
//    int i2 = c2;
//    qDebug() << "i2: " << i2;

//    MyClass m;
//    m.setProperty("value", 10);
//    bool ok;
//    qDebug() << m.property("value").toInt(&ok);
//    MyClass m1;
//    m1.setProperty("text", "aaa");
//    if(m1.setProperty("value", QVariant(100)) == false)
//    {
//        qDebug() << "no value property in m1";
//    }
//    qDebug() << m1.property("value").toInt();


//    MyClass m2;
//    m2.setProperty("text", "bbb");
//    m2.setProperty("value", QVariant(200));
//    qDebug() << m2.property("value").toInt();

//    MyClass m3;
//    m3.setProperty("text", "ccc");
//    m3.setProperty("value", QVariant(300));
//    qDebug() << m3.property("value").toInt();

//    MyClass m4;
//    m4.setProperty("text", "ddd");
//    m4.setProperty("value", QVariant(400));
//    qDebug() << m4.property("value").toInt();

//    MyClass m5;
//    m5.setProperty("text", "eee");
//    m5.setProperty("value", QVariant(99));
//    qDebug() << m5.property("value").toInt();

//    QList<MyClass> list1;
//    list1 << m5 << m4 << m1 << m3 << m2;
//    list1[0].setProperty("value", 99);
//    list1[1].setProperty("value", 400);
//    list1[2].setProperty("value", 300);
//    list1[3].setProperty("value", 200);
//    list1[4].setProperty("value", 100);

//    foreach(const MyClass& c, list1)
//    {
//        qDebug() << c.property("text");

//    }

//    qDebug() << "=================";
//    std::sort(list1.begin(), list1.end(), std::less<MyClass>());
//    foreach(const MyClass& c, list1)
//    {
//        qDebug() << c.property("text");
//    }

//    qDebug() << "=================";

//    std::sort(list1.begin(), list1.end(), std::bind(&MyClass::greaterValue, &m1, std::placeholders::_1, std::placeholders::_2));
//    foreach(const MyClass& c, list1)
//    {
//        qDebug() << c.property("text");
//        qDebug() << c.property("value").toInt();
//    }

//    qDebug() << "=================";

//    qSort(list1);
//    foreach(const MyClass& c, list1)
//    {
//        qDebug() << c.property("text");
//    }
//    int ary[] = {1,2,3,4,5};
//    for(int i=0; i<5; i++)
//    {
//        qDebug() << ary[i];
//    }

//    f3(ary);
//    for(int i=0; i<5; i++)
//    {
//        qDebug() << ary[i];
//    }

//    f4(ary);
//    for(int i=0; i<5; i++)
//    {
//        qDebug() << ary[i];
//    }

//    int x = f5();
//    x++;
//    qDebug() << "x:" << x;
//    qDebug() << "f5() x:" << f5();

    return app.exec();
}
