//
// Created by abeeston on 3/28/20.
//

#ifndef COMPILERS_TYPEINDICATOR_H
#define COMPILERS_TYPEINDICATOR_H

enum TypeIndicator {INTEGER, CHAR, STRING, BOOLEAN, ALIAS}; // maybe replace with the name style to avoid ambiguity?
enum LValueType {PRIMITIVE_TYPE, ALIAS_TYPE, SIMPLE_TYPE, ARRAY_TYPE, RECORD_TYPE};
enum Label { CONSTANT, VARIABLE};

#endif //COMPILERS_TYPEINDICATOR_H
