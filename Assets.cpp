//
// Created by Jayden on 5/15/2024.
//

#include "Assets.h"
#include <iostream>
#include <sstream>


Assets::Assets() {
    _numberOfTags = 0;
    _tags = nullptr;
}
Assets::Assets(const string& name) {
    _name = name;
    _numberOfTags = 0;
    _tags = nullptr;
}

Assets::~Assets() {
    delete[] _tags;
}
Assets::Assets(const Assets& other) {
    _name = other._name;
    _numberOfTags = other._numberOfTags;
    if (_numberOfTags > 0) {
        _tags = new string[_numberOfTags];
        for (size_t i = 0; i < _numberOfTags; i ++) {
            _tags[i] = other._tags[i];
        }
    }
    else {
        _tags = nullptr;
    }
}
const Assets& Assets::operator=(const Assets& rhs) {
    if (this != &rhs) {
// Destruction
        delete[] _tags;
// Construction
        _name = rhs._name;
        _numberOfTags = rhs._numberOfTags;
        if (_numberOfTags > 0) {
            _tags = new string[_numberOfTags];
            for (size_t i = 0; i < _numberOfTags; i ++) {
                _tags[i] = rhs._tags[i];
            }
        }
        else {
            _tags = nullptr;
        }
    }
    return *this;
}
void Assets::AddTag(const string& tag) {
string* TempTags= _tags;//save all original tags to a temp string pointer
    _tags = new string[_numberOfTags+1];//set _tags equal to a string array with the size of the array being 1 more than the original amount of tags
    for (size_t i = 0; i < _numberOfTags; i ++) {
        _tags[i] = TempTags[i];//save all original tags
    }
// Add the new tag and increment count
    _tags[_numberOfTags++] = tag;
// Deallocate the old block
    delete[] TempTags;
}

string Assets::ToString() const {
stringstream ss;
ss << "{\"name\":\"" << _name << "\", \"numberofTags\":\"" << _numberOfTags << "\",\"Tags\":";
for(int i=0; i<_numberOfTags;i++)
ss<< _tags[i]<< ";";
ss<<"}";
return ss.str();
}