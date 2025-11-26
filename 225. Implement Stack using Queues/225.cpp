#include <iostream>
class StackNode
{
private:
    int val;
    StackNode *next;

public:
    StackNode() : val(0), next(nullptr) {}
    StackNode(int x) : val(x), next(nullptr) {}
    StackNode(int x, StackNode *next) : val(x), next(next) {}

    int getValue() const { return val; }
    StackNode *getNext() const
    {
        return next;
    }

    void setValue(int newVal) { val = newVal; }
    void setNext(int newVal, StackNode *toNext)
    {
        val = newVal;
        next = toNext;
    }
    void setNext(StackNode *toNext)
    {
        next = toNext;
    }
};

class MyStack
{
private:
    StackNode *topNode;

public:
    MyStack() : topNode(nullptr) {};

    void push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->setNext(topNode);
        topNode = newNode;
    }

    int pop()
    {
        if (empty())
        {
            throw std::runtime_error("Cannot pop from empty stack");
        }
        StackNode *temp = topNode;
        int value = topNode->getValue();
        topNode = topNode->getNext();
        delete temp;
        std::cout << "value is:" << value << std::endl;
        return value;
    }

    int top()
    {
        if (empty())
        {
            throw std::runtime_error("Cannot top from empty stack");
        }
        return topNode->getValue();
    }

    bool empty()
    {
        return topNode == nullptr;
    }
    ~MyStack()
    {
        while (!empty())
        {
            pop();
        }
    }
};
int main()
{
    MyStack *obj = new MyStack();
    int x = 2;
    obj->push(x);
    int param_2 = obj->pop();
    int param_3 = obj->top();
    bool param_4 = obj->empty();
    return 0;
}