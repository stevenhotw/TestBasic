#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>

class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(int value MEMBER m_value)

public:
    MyClass(QObject *parent = 0) : QObject(parent){}

    MyClass(const MyClass &other)
    {
        this->m_text = other.m_text;
        this->m_value = other.m_value;
    }

    MyClass &operator=(const MyClass &other)
    {
        this->m_text = other.m_text;
        this->m_value = other.m_value;
    }

    QString text() {return m_text;}
    void setText(QString t) {m_text = t;}

    bool operator<(const MyClass& other) const
    {
        return this->m_text < other.m_text;
    }

//    bool operator()( const MyClass& lhs, const MyClass& rhs ) const
//    {
//        return lhs.m_text < rhs.m_text;
//    }

    bool lessValue(MyClass* obj1, MyClass* obj2)
    {
        return obj1->m_value < obj2->m_value;
    }

    bool greaterValue(const MyClass& obj1, const MyClass& obj2) const
    {
        return obj1.m_text > obj2.m_text;
    }

private:
    QString m_text;
    int m_value;
};

#endif // MYCLASS_H
