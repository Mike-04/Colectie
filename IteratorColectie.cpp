#include "IteratorColectie.h"
#include "Colectie.h"

IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	this->current = col.head;
    this->current_freq = 1;
}

TElem IteratorColectie::element() const{
	    if (this->current == nullptr) {
        throw std::exception();
    }
    return this->current->element().first;
}

bool IteratorColectie::valid() const {
	    if (this->current != nullptr) {
        return true;
    }
	return false;
}

void IteratorColectie::urmator() {

    if (this->current == nullptr) {
        throw std::exception();
    }

    if (this->current_freq < this->current->element().second) {
        this->current_freq++;
        return;
    }
    this->current = this->current->getNext();
    this->current_freq = 1;
}

void IteratorColectie::prim() {
    this->current = col.head;
    this->current_freq = 1;
}
