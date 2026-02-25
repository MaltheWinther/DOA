// person.h - Header fil (deklarationer)
// ═══════════════════════════════════════════════════════════════════════════
// DELT KODE - Denne klasse kan bruges af alle projekter (week1, week2, etc.)
// ═══════════════════════════════════════════════════════════════════════════
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
    // Constructor
    Person(const std::string& name, int age);

    // Getters
    std::string get_name() const;
    int get_age() const;

    // Methods
    std::string to_string() const;

private:
    std::string name_;
    int age_;
};

#endif // PERSON_H
