#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

Node::Node(pair<TElem, int> data, Node* next) {
    this->data = data;
    this->next = next;
}

pair<TElem, int> Node::element() {
    return this->data;
}

Node* Node::getNext() {
    return this->next;
}

void Node::update_freq(int freq) {
    this->data.second=freq;
}


bool rel(TElem e1, TElem e2) {
    if (e1 <= e2) {
        return true;
    }
	return false;
}

Colectie::Colectie() {
    this->head = nullptr;
    this->size = 0;
}

void Colectie::adauga(TElem e) {
	//check if there are elements in the list
    if (this->head == nullptr) {
        this->head = new Node(make_pair(e, 1), nullptr);
        this->size++;
        return;
    }
    //check if the element is already in the list
    Node* current = this->head;
    while (current != nullptr) {
        if (current->element().first == e) {
            current->update_freq(current->element().second + 1);
            this->size++;
            return;
        }
        current = current->getNext();
    }
    //add the element to the list so all nodes are in relation
    current = this->head;
    Node* prev = nullptr;
    while (current != nullptr && rel(current->element().first, e)) {
        prev = current;
        current = current->getNext();
    }
    if (prev == nullptr) {
        this->head = new Node(make_pair(e, 1), current);
    } else {
        prev->next = new Node(make_pair(e, 1), current);
    }
    this->size++;
}


bool Colectie::sterge(TElem e) {
	//check if the list is empty
    if (this->head == nullptr) {
        return false;
    }
    //check if the element is in the list
    Node* current = this->head;
    Node* prev = nullptr;
    while (current != nullptr) {
        if (current->element().first == e) {
            if (current->element().second > 1) {
                current->update_freq(current->element().second - 1);
                this->size--;
                return true;
            }
            if (prev == nullptr) {
                this->head = current->getNext();
            } else {
                prev->next = current->getNext();
            }
            delete current;
            this->size--;
            return true;
        }
        prev = current;
        current = current->getNext();
    }
	return false;
}


bool Colectie::cauta(TElem elem) const {
	//check if the element is in the list
    Node* current = this->head;
    while (current != nullptr) {
        if (current->element().first == elem) {
            return true;
        }
        current = current->getNext();
    }
	return false;
}


int Colectie::nrAparitii(TElem elem) const {
	//return the number of appearances of the element in the list
    Node* current = this->head;
    while (current != nullptr) {
        if (current->element().first == elem) {
            return current->element().second;
        }
        current = current->getNext();
    }
	return 0;
}



int Colectie::dim() const {
	//return the number of elements in the list
    return this->size;
}


bool Colectie::vida() const {
	//check if the list is empty
    if (this->size == 0) {
        return true;
    }
	return false;
}


IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
	/* de adaugat */
}
