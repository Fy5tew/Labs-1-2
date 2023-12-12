#include "List.h"


Element::Element(Element* prev, void* data, Element* next) {
	Prev = prev;
	Data = data;
	Next = next;
}

Element* Element::GetNext() {
	return Next;
};

Element* Element::GetPrev() {
	return Prev;
};


Object::Object() {
	Head = nullptr;
}

Element* Object::GetFirst() {
	return Head;
}

Element* Object::GetLast()
{
	Element* e = Head, * rc = e;
	while (e != nullptr)
	{
		rc = e;
		e = e->GetNext();
	}
	return rc;
}

bool Object::Insert(void* data) {
	bool rc = 0;
	if (Head == nullptr)
	{
		Head = new Element(nullptr, data, Head);
		rc = true;
	}
	else
	{
		Head = (Head->Prev = new Element(nullptr, data, Head));
		rc = true;
	}
	return rc;
}

bool Object::InsertEnd(void* data) {
	Element* last = GetLast();
	last->Next = new Element(last, data, nullptr);
	return true;
}

Element* Object::Search(void* data) {
	Element* rc = Head;
	while ((rc != nullptr) && (rc->Data != data))
		rc = rc->Next;
	return rc;
}

void Object::PrintList(void(*f)(void*)) {
	Element* e = Head;
	while (e != nullptr)
	{
		f(e->Data);
		e = e->GetNext();
	};
}

void Object::PrintList(void(*f)(void*), Element* e) {
	f(e->Data);
}

bool  Object::Delete(Element* e) {
	bool rc = 0;
	if (rc = (e != nullptr))
	{
		if (e->Next != nullptr)
			e->Next->Prev = e->Prev;
		if (e->Prev != nullptr)
			e->Prev->Next = e->Next;
		else
			Head = e->Next;
		delete e;
	}
	return rc;
}

bool Object::Delete(void* data) {
	return Delete(Search(data));
};

bool Object::DeleteList() {
	Element* current = GetLast();
	Element* prev = current->GetPrev();
	while (prev != nullptr) {
		if (!Delete(current)) {
			return false;
		}
		current = prev;
		prev = current->GetPrev();
		if (prev == nullptr) {
			return Delete(current);
		}
	}
	return true;
}

int Object::CountList() {
	int count = 0;
	Element* rc = Head;
	while (rc != nullptr) {
		rc = rc->Next;
		count++;
	}
	return count;
}

Object Create() {
	return *(new Object());
}
