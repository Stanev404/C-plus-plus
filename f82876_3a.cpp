#include "Queue.h"

template<typename TElement>
class AQueue : public CQueue {
	AQueue();
	AQueue(int cap, int max_cap);
	~AQueue();

	//sloji enqueue i dequeue
private:
	int m_nCap;
	int m_nMaxCap;

	TElement ** m_pElements;

	int m_nHead;
	int m_nTail;

	void resize_queue();
};


template<typename TElement>
AQueue<TElement>::AQueue(){
	m_nCap = 0;
	m_nMaxCap = m_nCap * 4;

	m_pElements = new TElement*[m_nCap];
	m_nHead = -1;
	m_nTail = -1;
}


template<typename TElement>
AQueue<TElement>::AQueue(int cap, int max_cap){
	m_nCap = cap;
	m_nMaxCap = max_cap;

	m_pElements = new TElement*[m_nCap];
	m_nHead = -1;
	m_nTail = -1;
}

template<typename TElement>
AQueue<TElement>::~AQueue(){
	if (m_nHead != -1){

		for (int i = m_nHead; i <= m_nTail){
			delete m_pElements[i];
		}

	}
	delete[] m_pElements;
}

template<typename TElement>
void AQueue<TElement>::enqueue(TElement* pInE1) throw (QueueOverflowException){
	if (m_nTail - m_nHead + 1 < m_nCap){
		m_nTail++;
		m_pElements[m_nTail % m_nCap] = pInE1;
	}
	else {
		throw QueueOverflowException();
	}
}
template<typename TElement>
TElement * AQueue<TElement>::dequeue() throw (QueueEmptyException){
	if (m_nTail < m_nHead)){
		throw QueueEmptyException();
	}
	TElement* pE1 = NULL;
	pE1 = m_pElements[m_nHead % m_nCap];
	m_nHead++;

	return pE1;
}