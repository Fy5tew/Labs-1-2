#pragma once
struct Element                  
{
	Element* Prev;                
	Element* Next;             
	void* Data;

	Element(Element* prev, void* data, Element* next);

	Element* GetNext();

	Element* GetPrev();
};


struct Object                     
{
	Element* Head;  

	Object();

	Element* GetFirst();     

	Element* GetLast();         

	Element* Search(void* data);   

	bool Insert(void* data);       

	bool InsertEnd(void* data);    

	bool Delete(Element* e);     

	bool Delete(void* data);    

	bool DeleteList();

	void PrintList(void(*f)(void*));

	void PrintList(void(*f)(void*), Element*);

	int CountList();

	bool DeleteDouble();
};


Object Create();                   
