//
// Created by Jayden on 5/15/2024.
//

#ifndef ASSETCLASS_ASSETS_H
#define ASSETCLASS_ASSETS_H

#include "string"
using namespace std;
class Assets {
    public:
        Assets();
        Assets(const string& name);
        Assets(const Assets& other);
        ~Assets();
        const Assets& operator=(const Assets& rhs);
        void AddTag(const string& tag);
        string ToString() const;
    private:
        string _name;
        size_t _numberOfTags;
        string* _tags;

};


#endif //ASSETCLASS_ASSETS_H
