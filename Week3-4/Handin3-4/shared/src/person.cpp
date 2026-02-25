// person.cpp - Implementation fil (definitioner)
#include "person.h"

Person::Person(const std::string& name, int age)
    : name_{name}, age_{age} {
}

std::string Person::get_name() const {
    return name_;
}

int Person::get_age() const {
    return age_;
}

std::string Person::to_string() const {
    return "Person: " + name_ + ", Age: " + std::to_string(age_);
}
