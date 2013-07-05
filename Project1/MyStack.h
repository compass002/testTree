#ifndef _MY_STACK_H_
#define _MY_STACK_H_
// ===================================================================
#include<cstdlib>
/*
STACK IMPLEMENTATION FROM 
<<CRACKING THE CODE INTERVIEW>>
A VERY SIMPLE VERSION

1  class Stack {
2    Node top;
3    Node pop() {
4    if (top != null) {
5     Object item = top.data;
6     top = top.next;
7     return item;
8    }
9     return null;
10   }
11   void push(Object item) { 
12   Node t = new Node(item);
13   t.next = top;
14   top = t;
15   } 
16 }
*/
// My Implementation

//struct Data{
//      int num;
//      Data():num(0){}
//      Data(const Data &e){
//              num = e.num;
//      }
//};
template<class Data> struct Node{
        Data mData;
        struct Node *prev;
        struct Node *next;
        Node():prev(nullptr),next(nullptr){}
        Node(const Node &e){
                prev = e.prev;
                next = e.next;
                mData = e.mData;
        }
};

// link list version
template<class Data> class Stack_LL{
        Node<Data> *top;
        int size;
public:
        Stack_LL():size(0){
                top = new Node<Data>;
        }
        Stack_LL(const Stack_LL &e):size(e.size){
                Node<Data> *p = e.top;
                Node<Data> *q = new Node<Data>;
                while(top->prev){
                        top = top->prev;
                        delete top->next;
                }delete top;
                top = q;
                while(p->prev){
                        q->prev = new Node<Data>;
                        q->prev->next = q;
                        q->prev->mData = p->prev->mData;
                        
                        q = q->prev;
                        p = p->prev;
                }
        }
        ~Stack_LL(){
        }
        void operator = (const Stack_LL &e){
                size = e.size;
                Node<Data> *p = e.top;
                Node<Data> *q = new Node;
                while(top->prev){
                        top = top->prev;
                        delete top->next;
                }delete top;
                top = q;
                while(p->prev){
                        q->prev = new Node<Data>;
                        q->prev->next = q;
                        q->prev->mData = p->prev->mData;
                        
                        q = q->prev;
                        p = p->prev;
                }
        }
        bool Push(Data &e){
                top->mData = e;
                top->next = new Node<Data>;
                if(top->next){
                        top->next->prev = top;
                        top = top->next;
                        size++;
                        return true;
                }else
                        return false;
        }

        bool Pop(Data &e){
                if(top->prev){
                        e = top->prev->mData;
                        top = top->prev;
                        delete top->next;
                        top->next = nullptr;
                        size--;
                        return true;
                }else{
                        return false;
                }
        }

        bool GetTop(Data &e){
                if(top->prev){
                        e = top->prev->mData;
                        return true;
                }else
                        return false;
        }
        int GetSize(){
                return size;
        }
        bool IsEmpty(){
                if(size == 0)
                        return true;
                else
                        return false;
        }
        bool Clear(){
                while(top->prev){
                        top = top->prev;
                        delete top->next;
                }
                size = 0;
        }
        bool Traverse(bool (*Visit)(Data &)){
                while(top->prev){
                        top = top->prev;
                        if(!Visit(top->mData))
                                return false;
                }
                return true;
        }
};
// Sequence storage version
// C ver
template<class Data> struct Stack_C{
        Data *top;
        Data *base;
        const int INIT_SIZE;
        const int EXPAND_SIZE;
        int capacity;
        Stack_C():INIT_SIZE(4),EXPAND_SIZE(1),capacity(INIT_SIZE){
                base = (Data*)malloc(INIT_SIZE*sizeof(Data));
                if(!base)
                        throw("malloc failed");
                top = base;
        }
        Stack_C(const Stack_C &e):INIT_SIZE(100),EXPAND_SIZE(10){
                capacity = e.capacity;
                base = (Data*)malloc(capacity*sizeof(Data));
                for(int i = 0; i<capacity; i++)
                        *(base+i) = *(e.base+i);
                int size = e.top - e.base;
                top = base+size;
        }
        ~Stack_C(){
                if(top){
                        top = nullptr;
                }
                if(base){
                        free(base);
                        base = nullptr;
                }
        }

        //top is like end in std::vector, point to the next of the last element

        void operator = (const Stack_C &e){
                capacity = e.capacity;
                base = (Data*)malloc(capacity*sizeof(Data));
                for(int i = 0; i<capacity; i++)
                        *(base+i) = *(e.base+i);
                int size = e.top - e.base;
                top = base+size;
        }

        bool Pop(Data &e){
                if(top == base)
                        return false;
                else{
                        e = *(top-1);
                        top--;
                        return true;
                }
        }
        bool Push(Data &e){
                if((top - base) >= capacity ){
                        base = (Data *)realloc(base,(capacity+EXPAND_SIZE)*sizeof(Data));
                        if(!base)
                                return false;
                        top = base+capacity;
                        top++;
                        *(top-1) = e;
                        capacity += EXPAND_SIZE;
                        return true;
                }else{
                        top++;
                        *(top-1) = e;
                        return true;
                }       
        }
        bool GetTop(Data &e){
                if(top == base)
                        return false;
                e = *(top-1);
                return true;
        }
        int GetSize(){
                return top - base;
        }
        bool IsEmpty(){
                if(top == base)
                        return true;
                else
                        return false;

        }
        bool Clear(){
                top = base;
                return true;
        }
        bool Traverse(bool (*Visit)(Data &)){
                for(int i =0; i< top - base; i++){
                        if(!(*Visit)(*(base+i)))
                                return false;
                }
                return true;
        }
};
// C++ ver
template<class Data> class Stack{
        Data *top;
        Data *base;
        const int INIT_SIZE;
        const int EXPAND_SIZE;
        int capacity;
public:
        Stack():INIT_SIZE(4),EXPAND_SIZE(1),capacity(INIT_SIZE){
                base = new Data[INIT_SIZE];
                top = base;
        }
        Stack(const Stack &e):INIT_SIZE(e.INIT_SIZE),EXPAND_SIZE(e.EXPAND_SIZE){
                capacity = e.capacity;
                base = new Data[capacity];
                for(int i = 0; i<capacity; i++)
                        base[i] = e.base[i];
                int size = e.top - e.base;
                top = &base[size];
        }
        ~Stack(){
                if(top){
                        top = nullptr;
                }
                if(base){
                        delete []base;
                        base = nullptr;
                }
        }
        // =============

        //top is like end in std::vector, point to the next of the last element
        void operator = (const Stack &e){
                delete [] base;
                capacity = e.capacity;
                base = new Data[capacity];
                for(int i = 0; i<capacity; i++)
                        base[i] = e.base[i];
                int size = e.top - e.base;
                top = &base[size];
        }
        bool Pop(Data &e){
                if(top == base)
                        return false;
                else{
                        e = *(top-1);
                        top--;
                        return true;
                }
        }
        bool Push(Data &e){
                if((top - base) >= capacity ){
                        Data *temp = new Data[capacity+EXPAND_SIZE];
                        if(!temp)
                                return false;
                        for(int i = 0; i<capacity; i++){
                                temp[i] = base[i];
                        }
                        delete [] base;
                        base = temp;
                        top = base+capacity;
                        top++;
                        *(top-1) = e;
                        capacity += EXPAND_SIZE;
                        return true;
                }else{
                        top++;
                        *(top-1) = e;
                        return true;
                }
        }
        bool GetTop(Data &e){
                if(top == base)
                        return false;
                e = *(top-1);
                return true;
        }
        int GetSize(){
                return top - base;
        }
        bool IsEmpty(){
                if(top == base)
                        return true;
                else
                        return false;

        }
        bool Clear(){
                top = base;
                return true;
        }
        bool Traverse(bool (*Visit)(Data &)){
                for(int i =0; i< top - base; i++){
                        if(!(*Visit)(base[i]))
                                return false;
                }
                return true;
        }
};

// ===================================================================
#endif//_MY_STACK_H_