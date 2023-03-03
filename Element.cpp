#include "Element.h"

Element::Element() {
	previous_element = nullptr;
	value_ = 0;
}

Element::~Element() {
	previous_element = nullptr;
	value_ = 0;
}

void Element::SetValue(int value) {
	value_ = value;
}

void Element::Set_Previous(Element* prev) {
	previous_element = prev;
}

int Element::GetValue() {
	return value_;
}

Element* Element::GetPrevious() {
	return previous_element;
}
