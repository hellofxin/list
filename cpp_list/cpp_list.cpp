
#include "stdafx.h"
#include "iostream"
#include "linked_list.h"
#include "DLinked_list.h"
#include "stack_array.h"
#include "stackLinkedList.h"
#include "queueLinkedList.h"

using namespace std;

int main(){
	LinkedListInt<int> linkedListInt;
	linkedListInt.insert(1).insert(2).insert(3).insert(4).insert(5).insert(6);
	linkedListInt.erase(4);
	Node<int>* p = linkedListInt.first();
	cout << "first->data = " << p->data << "\n\n"<<endl;
	p = linkedListInt.end();
	cout << "end->data = " << p->data << "\n\n" << endl;
	p = linkedListInt.locate(3);
	cout << "retrieve(p) = " << linkedListInt.retrieve(p) << endl;
	linkedListInt.toString();
	linkedListInt.toList();

	/* DLinkedList */
	DLinkedList<int> dLinkedList;
	dLinkedList.insertHead(11).insertHead(22).insertHead(33).insertHead(4).insertHead(5).insertHead(6).insertTail(77).insertTail(88).insertTail(99);
	/**/
	dLinkedList.erase(11);
	dLinkedList.erase(11);
	/**/
	dLinkedList.erase(5);
	dLinkedList.erase(66);
	/**/
	dLinkedList.toList();


	/* stackArray */
	StackArray<int> stackArray;
	stackArray.pop();
	stackArray.isEmpty();
	stackArray.getTop();
	stackArray.push(11);
	stackArray.push(22);
	stackArray.push(33);
	stackArray.push(33);
	stackArray.showtime();
	stackArray.getTop();
	stackArray.pop();
	stackArray.isEmpty();
	stackArray.showtime();


	/* StackLinkedList */
	StackLinkedList<int>* stackLinkedList = new StackLinkedList<int>();
	stackLinkedList->isEmpty();
	stackLinkedList->getTop();
	stackLinkedList->pop();
	stackLinkedList->push(11);
	stackLinkedList->push(22);
	stackLinkedList->push(33);
	stackLinkedList->push(44);
	stackLinkedList->showtime();
	stackLinkedList->isEmpty();
	stackLinkedList->pop();
	stackLinkedList->getTop();
	stackLinkedList->showtime();


	/* queueLinkedList */
	QueueLinkedList<int> queueLinkedList;
	queueLinkedList.isEmpty();
	queueLinkedList.deQueue();
	queueLinkedList.showtime();
	queueLinkedList.enQueue(11).enQueue(22).enQueue(33).enQueue(44).enQueue(55);
	queueLinkedList.isEmpty();
	queueLinkedList.showtime();
	queueLinkedList.deQueue();
	queueLinkedList.showtime();

	system("pause");
    return 0;
}

