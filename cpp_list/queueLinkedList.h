#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

/*	��β���룬��ͷɾ����˳�����Ӽ�ͷ�ķ��򣬶�ͷΪ��һ��Ԫ�أ���βΪ���һ��Ԫ�ء�
	��ͷ���룺pNode->next=head; head=pNode;
	��β���룺rear->next=pNode; rear=pNode;
*/


template<typename T> struct NodeQueue {
	T data;
	NodeQueue<T>* next;

	NodeQueue(T element = 0) :data(element), next(NULL) { }
};

template<typename T> class QueueLinkedList {
private:
	NodeQueue<T>* front;
	NodeQueue<T>* rear;

public:
	QueueLinkedList():front(NULL), rear(NULL){ }
	bool isEmpty();
	QueueLinkedList<T>& enQueue(T element);
	T deQueue();
	void showtime();
};

template<typename T> bool QueueLinkedList<T>::isEmpty() {
	if (front == NULL) {
		cout << "QueueLinkedList isEmpty: true" << endl;
		return true;
	}
	cout << "QueueLinkedList isEmpty: false" << endl;
	return false;
}

template<typename T> QueueLinkedList<T>& QueueLinkedList<T>::enQueue(T element) {
	NodeQueue<T>* pNode = new NodeQueue<T>(element);
	/**	������β�壬������ͷ�塣
	/**/
	if (rear == NULL) {
		rear = pNode;
		front = pNode;
	}
	else {
		rear->next = pNode;
		rear = pNode;
	}
	cout << "QueueLinkedList enQueue: " <<element<< endl;
	return *this;
}

template<typename T> T QueueLinkedList<T>::deQueue() {
	NodeQueue<T>* pNode = NULL;
	T dataTemp = (T)0;
	if (front == NULL) {
		cout << "QueueLinkedList deQueue: failed" << endl;
		return (T)0;
	}
	pNode = front;
	front = front->next;
	/*	!!! ע�⣬deQueue������Ϊ��ʱ������rear��
	*/
	if (!front) {
		rear = NULL;
	}
	dataTemp = pNode->data;
	delete pNode;
	pNode = NULL;
	cout << "QueueLinkedList deQueue: " << dataTemp << endl;
	return dataTemp;
}

template<typename T> void QueueLinkedList<T>::showtime() {
	NodeQueue<T>* pNode = front;
	cout << "\nQueueLinkedList showtime front->";
	while (pNode) {
		cout << pNode->data << "->";
		pNode = pNode->next;
	}
	cout << "NULL\n" << endl;
}

#endif