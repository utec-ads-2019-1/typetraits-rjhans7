#ifndef LIST_H
#define LIST_H

#include "node.h"

template <typename Tr>
class List {     
    public:
        typedef typename Tr::T T; //Esta parte igual!
        typedef typename Tr::Operation Operation;
      
    private:
        Node<T>* head;
        Operation cmp; //Qué hace operation?
        int nodes;
              
    public:
        List() : head(nullptr), nodes(0) {};

        bool find(T search, Node<T> **&pointer) {//Pointer pasado por referencias
            pointer = &head;
            while(*pointer)
            {
                if(cmp(search,(*pointer)->data))
                    return (*pointer)->data == search; //Corregir
                pointer = &((*pointer)->next);
            }
            return false;
        }


        bool insert(T data) {
            auto newNode = new Node <T> (data);
            Node <T> **ptr = nullptr;
            if (find(data, ptr))
                return false;
            else{
                newNode->next = *ptr; //*ptr ya está apuntando al siguiente
                *ptr = newNode;
                nodes++;
                return true;
            }

        }
             
        bool remove(T data) {
            Node <T> **ptr = nullptr;
            if (find(data, ptr)){
                Node<T> *temp = *ptr;
                *ptr = (*ptr)->next;
                delete temp;
                nodes--;
                return true;
            }else
                return false;
        }  
             
        int size() {
            return nodes;
        }

        T operator[](int index) {
            if ((index < 0) | (index >= nodes))
                throw out_of_range("Out of range!");
            else{
                Node <T>** ptr = &head;
                for (int i = 0; i < index; i++)
                    ptr = &((*ptr)->next);
                return (*ptr)->data;
            }
        }
        void print(){
            Node <T>** ptr = &head;
            for (int i= 0; i < nodes; i++){
                if ( i%6==0)
                    cout << endl;
                cout << (*ptr)->data << " - ";
                ptr = &((*ptr)->next);
            }

        };

        ~List() {
            head->killSelf();
        }         
};

#endif