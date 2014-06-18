#include <iostream>
#include <stack>
using namespace std;

template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);
	
	void appendTail(const T& node);
	T deleteHead();
	
private:
	stack<T> stack1;
	stack<T> stack2;
};


template<typename T> CQueue<T>::CQueue(void){
	
}

template<typename T> CQueue<T>::~CQueue(void){
	
}

template<typename T> void CQueue<T>::appendTail(const T& element){
	stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead(){
	if(stack2.size() <= 0){
		while(stack1.size() > 0){
			T data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}
	
	if(stack2.size() == 0){
		throw new exception("queue is  empty");
	}
	
	T head = stack2.top();
	stack2.pop();
	
	return head;
}


void Test1(){
	CQueue<int> queue;
	cout <<"Test1:"<<endl;
	cout << "expected: 32 2 21 5"<<endl;
	queue.appendTail(32);
	queue.appendTail(2);
	queue.appendTail(21);
	cout << "actual: ";
	cout << queue.deleteHead() <<" ";
	cout << queue.deleteHead() <<" ";
	queue.appendTail(5);
	cout << queue.deleteHead() <<" ";
	cout << queue.deleteHead() <<" ";
	cout << endl;
}

void Test2(){
	CQueue<char> queue;
	cout <<"Test2: "<<endl;
	cout << "expected: l o v e"<<endl;
	queue.appendTail('l');
	queue.appendTail('o');
	queue.appendTail('v');
	queue.appendTail('e');
	cout << "actual: ";
	cout << queue.deleteHead() <<" ";
	cout << queue.deleteHead() <<" ";
	cout << queue.deleteHead() <<" ";
	cout << queue.deleteHead() <<" ";
	cout << endl;
}

// 抛出异常
void Test3(){
	CQueue<int> queue;
	queue.appendTail(2);
	queue.deleteHead();
	queue.deleteHead();
}

int main()
{
	Test1();
	Test2();
	try
	{
		Test3();
	}
	catch (exception* e)
	{
		cout << e->what() <<endl;
	}
	
	return 0;
}