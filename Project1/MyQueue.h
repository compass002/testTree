#ifndef __MY_QUEUE__
#define	__MY_QUEUE__

//struct Data{
//	int num;
//	Data():num(0){}
//	Data(int x):num(x){}
//};
template<class Data>class Queue{
	Data *base;
	int front;
	int rear;
	int size;
	int capacity;
	const int INIT_SIZE;
	const int EXPAND;

public:
	Queue():INIT_SIZE(8),EXPAND(4),size(0){
		capacity = INIT_SIZE;
		base = new Data[INIT_SIZE];
		front = 0;
		rear = 0;
	}
	~Queue(){
		delete [] base;
		base = nullptr;
	}

	// =============

	bool EnQueue(Data &e){
		if(rear >= capacity){
			Data *temp = new Data[capacity+EXPAND];
			if(!temp)
				return false;
			for(int i = 0; i<capacity; i++){
				temp[i] = base[i];
			}
			delete [] base;
			base = temp;
			base[rear] = e;
			rear++;
			size++;
			capacity += EXPAND;
			return true;
		}else{
			base[rear] = e;
			rear ++;
			size++;
			return true;
		}
	}

	bool DeQueue(Data &e){
		if(front == capacity )
			return false;
		else{
			if(size == 0)
				return false;
			e = base[front];
			front++;
			size--;
			return true;
		}
	}
	
	bool IsEmpty(){
		if(size == 0)
			return true;
		else
			return false;
	}
};
// ===================
template <class Data>class Queue_Cir{
	Data *base;
	int front;
	int rear;
	int size;
	int capacity;
	const int INIT_SIZE;
	const int EXPAND;
public:
	Queue_Cir():INIT_SIZE(8),EXPAND(4),size(0){
		capacity = INIT_SIZE;
		base = new Data[INIT_SIZE];
		front = 0;
		rear = 0;
	}
	~Queue_Cir(){
		delete [] base;
		base = nullptr;
	}

	// =============

	bool EnQueue(Data &e){
		if(front == rear){
			if(size == capacity){// full
				Data *temp = new Data[capacity+EXPAND];
				if(!temp)
					return false;
				int j = 0;
				for(int i = front; i < capacity; i++){
					temp[j] = base[i];
					j++;
				}
				for(int i = 0; i < front; i++){
					temp[j] = base[i];
					j++;
				}
				delete [] base;
				base = temp;
				front = 0;
				rear = j;
				base[rear] = e;
				rear++;
				capacity += EXPAND;
				size++;
			}else if(size == 0){// empty
				base[rear] = e;
				rear++;
				size++;
				if(rear == capacity)
					rear = 0;
			}else{
				throw("error: either full or empty.");
			}
		}else{
			base[rear] = e;
			rear++;
			size++;
			if(rear == capacity)
				rear = 0;
		}
		return true;
	}

	bool DeQueue(Data &e){
		if(front == rear ){
			if(size == 0)
				return false;
			else if(size == capacity){
				e = base[front];
				front++;
				if(front == capacity)
					front = 0;
			}else{
				throw("error : either full or empty.");
			}
		}else{
			e = base[front];
			front++;
			if(front == capacity)
					front = 0;
		}
		size--;
		return true;
	}

	bool IsEmpty(){
		if(size == 0)
			return true;
		else
			return false;
	}
};
// ===================
template <class Data>struct Node{
	Data mData;
	struct Node *prev;
	struct Node *next;

	Node():prev(nullptr),next(nullptr){}
};
template <class Data>class Queue_LL{
	Node<Data> *front;
	Node<Data> *rear;
	int size;
public:
	Queue_LL(){
		rear = new Node<Data>;
		front = rear;
		size = 0;
	}
	~Queue_LL(){
		while(front != rear){
			Node<Data> *temp = front->next;
			delete front;
			front = temp;
		}
		if(front)
			delete front;
		front = nullptr;
		rear = nullptr;
	}

	// ============

	bool EnQueue(Data &e){
		rear->mData = e;
		if(!(rear->next = new Node<Data>))
			return false;
		rear->next->prev = rear;
		rear = rear->next;
		size++;
		return true;
	}

	bool DeQueue(Data &e){
		if(!front)
			return false;
		e = front->mData;
		front = front->next;
		delete front->prev;
		front->prev = nullptr;
		size--;
		return true;
	}

	bool IsEmpty(){
		if(size == 0)
			return true;
		else
			return false;
	}
};
#endif // !__MY_QUEUE__
