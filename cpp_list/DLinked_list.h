#ifndef DLINKED_LIST_H
#define DLINKED_LIST_H

#include "iostream"

template<typename T> struct NodeDLinkedList {
	T data;
	NodeDLinkedList<T>* previous;
	NodeDLinkedList<T>* next;

	NodeDLinkedList(): previous(NULL),next(NULL), data(0){ }
	NodeDLinkedList(T element): previous(NULL), next(NULL), data(element){ }
};

template<typename T> class DLinkedList {
private:
	NodeDLinkedList<T>* head;
	NodeDLinkedList<T>* tail;

public:
	DLinkedList() : head(NULL), tail(NULL) { }
	DLinkedList<T>& insertHead(T element);
	DLinkedList<T>& insertTail(T element);
	bool erase(T element);
	NodeDLinkedList<T>* locate(T element);
	T retrieve(NodeDLinkedList<T>* p);
	void toList();
	
};

template<typename T> DLinkedList<T>& DLinkedList<T>::insertHead(T element) {
	NodeDLinkedList<T>* pNode = new NodeDLinkedList<T>(element);
	pNode->next = head;
	/* 
	  ���head�ǿգ���ά��head->previoud,
	  ���headΪ�գ���pNode�ǵ�һ���ڵ㣬tailҲӦ��ָ��pNode;
	  ��һ��дDLinkedListʱ��insertHead��insertTail����δ��������������Ҫע������!head���֡�
	*/
	if (!head) {
		tail = pNode;
	}
	else {
		head->previous = pNode;
	}
	head = pNode;
	cout << "DLinkedList insertHead element: " << element << endl;
	return *this;
}

template<typename T> DLinkedList<T>& DLinkedList<T>::insertTail(T element) {
	NodeDLinkedList<T>* pNode = new NodeDLinkedList<T>(element);
	/* ���淽���д��Ľ� * 
	if (tail == NULL) {
		pNode->previous = tail;
		tail = pNode;
	}
	pNode->previous = tail;
	tail->next = pNode;
	tail = pNode;
	/* ���ַ������ */
	pNode->previous = tail;
	if (!tail) {
		head = pNode;
	}
	else {
		tail->next = pNode;
	}
	tail = pNode;
	cout << "DLinkedList insertTail element: " << element << endl;
	return *this;
}

template<typename T> bool DLinkedList<T>::erase(T element) {
	NodeDLinkedList<T>* pNode = new NodeDLinkedList<T>();
	NodeDLinkedList<T>* pDeleted = NULL;
	bool bDeleted = false;
	for (pNode = head; pNode != NULL; ) {
		if (pNode->data == element) {
			/*	���pNodeָ���ͷ��㣬��ά��pNode->previous->next,���ָ��ͷ��㣬��ά��ͷ��㣬!!! ��ά��tail�ڵ㣻
				���pNodeָ���tail�ڵ㣬��ά��pNode->next->previous�����ָ��tail����ά��tail��!!! ��ά��head�ڵ㡣
			*/
			if (pNode == head) {
				head = head->next;
				if (!head) {
					tail = head;
				}
			}
			else {
				pNode->previous->next = pNode->next;
			}
			if (pNode == tail) {
				tail = tail->previous;
				if (!tail) {
					head = tail;
				}
			}
			else {
				pNode->next->previous = pNode->previous;
			}
			pDeleted = pNode;			
		}
		/*	��pNode�ĸ���Ҫ����if���� */
		pNode = pNode->next;
		if (pDeleted) {
			delete pDeleted;
			pDeleted = NULL;
			bDeleted = true;
			cout << "DLinkedList erase element: " << element << endl;
		}
	}
	if (!bDeleted) {
		cout << "DLinkedList erase " << element << " failed" << endl;
	}
	return bDeleted;
}

template<typename T> NodeDLinkedList<T>* DLinkedList<T>::locate(T element) {
	NodeDLinkedList<T>* pNode;
	for (pNode = head; pNode != NULL; pNode = pNode->next) {
		if (pNode->data == element) {
			cout << "DLinkedList locate: " << element << endl;
			return pNode;
		}
	}
	cout << "DlinkedList locate: failed" << endl;
	return NULL;
}

template<typename T> T DLinkedList<T>::retrieve(NodeDLinkedList<T>* p) {
	NodeDLinkedList<T>* pNode;
	for (pNode = head; pNode != NULL; pNode = pNode->next) {
		if (pNode == P) {
			cout << "DLinkedList retrieve: " << pNode->data << endl;
			return pNode->data;
		}
	}
	cout << "DLinkedList retrieve: failed" << endl;
	return 0;
}

template<typename T> void DLinkedList<T>::toList() {
	NodeDLinkedList<T>* pNode;
	cout << "\nDLinkedList head->";
	for (pNode = head; pNode!= NULL; pNode = pNode->next) {
		cout << pNode->data << "<-->";
	}
	cout << "NULL\n\nDLinkedList tail->";
	for (pNode = tail; pNode != NULL; pNode = pNode->previous) {
		cout << pNode->data << "<--->";
	}
	cout << "NULL\n" << endl;
}

#endif