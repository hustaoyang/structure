#include<iostream>
#include<deque>
#include<assert.h>

using namespace std;

template <typename T> class CStackWithMin
{
public:
    CStackWithMin(void) {}
    virtual ~CStackWithMin(void) {}

    T& top(void);
    const T& top(void) const;

    void push(const T& value);
    void pop(void);

    const T& min(void) const;

private:
    deque<T> m_data;
    deque<size_t> m_minIndex;
};

template <typename T> T& CStackWithMin<T>::top()
{
    return m_data.back();
}

template <typename T> const T& CStackWithMin<T>::top() const
{
    return m_data.back();
}

template <typename T> void CStackWithMin<T>::push(const T& value)
{
    m_data.push_back(value);

    if(m_minIndex.size() == 0)
	m_minIndex.push_back(0);
    else
    {
	if(value < m_data[m_minIndex.back()])
	   m_minIndex.push_back(m_data.size() - 1);
	else
 	   m_minIndex.push_back(m_minIndex.back());
    }
}

template <typename T> void CStackWithMin<T>::pop()
{
    m_data.pop_back();

    m_minIndex.pop_back();
}

template <typename T> const T& CStackWithMin<T>::min() const
{
    assert(m_data.size() > 0);
    assert(m_minIndex.size() > 0);

    return m_data[m_minIndex.back()];
}
int main(void)
{
    CStackWithMin<int> mystack;
    mystack.push(3);
    cout<<mystack.min()<<endl;
    mystack.push(4);
    cout<<mystack.min()<<endl;
    mystack.push(2);
    cout<<mystack.min()<<endl;
    mystack.push(1);
    cout<<mystack.min()<<endl;
    mystack.pop();
    cout<<mystack.min()<<endl;
    mystack.pop();
    cout<<mystack.min()<<endl;
    mystack.push(0);
    cout<<mystack.min()<<endl;

    

    return 0;
}
