#ifndef ELEMENT_H
#define ELEMENT_H

class Element {
public:
	Element();
	~Element();
	void Set_Previous(Element* prev);
	void SetValue(int value);
	int GetValue();
	Element* GetPrevious();

private:
	Element* previous_element;
	int value_;
};

#endif // !ELEMENT_H