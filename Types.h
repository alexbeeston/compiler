#ifndef  TYPES_H
#define  TYPES_H


#include <iostream>
#include <vector>

struct Type
{
    virtual void print() {std::cout << "Type toString() function" << std::endl;}
};


struct SimpleType : Type
{
    char* ident;
    SimpleType(char* p_indent) { ident = p_indent; };
    void print() {std::cout << ident << std::endl;};
};

struct IdentList
{
    char* firstIdent;
    std::vector<char*> idents;
    IdentList (char* p_firstIdent, std::vector<char*> p_extraIdents)
    {
        idents.push_back(p_firstIdent);
        // check for a null list here, in which case there is only one identifier, the first one
        for (char* extraIdent : p_extraIdents)
        {
            idents.push_back(extraIdent);
        }
    }
};

struct TypedList
{
    std::vector<char*> idents;
    char* type;

    TypedList (std::vector<char*> p_idents, char* p_type)
    {
        idents = p_idents;
        type = p_type;
    }
};

struct RecordType : Type
{
    std::vector<TypedList*> typedLists;
    RecordType (std::vector<TypedList*> p_typedLists) { typedLists = p_typedLists; } ;
};


//RecordType : RECORD TypedLists END;
//TypedLists : TypedLists TypedList | ;
//TypedList: IdentList COLON Type DONE;
//IdentList : IDENT IdentListExtraSet { $$ = new IdentList($1, $2); };
//IdentListExtraSet : IdentListExtraSet IdentExtra { $1.push_back($2); }
//      | { $$ = new std::vector<char*>; };
//IdentExtra : COMMA IDENT { $$ = $2; ;

#endif