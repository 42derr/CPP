#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setField(Field field, const std::string& value) {
    _fields[field] = value;
}

std::string Contact::getField(Field field) const {
    return _fields[field];
}