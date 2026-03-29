#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <iostream>
#include <map>
#include <string>

using std::map;


template<typename ID, typename Value>
class Map
{
public:

    //constructor & deconstructor
    Map(){}; // no implementation required
    ~Map(){}; // no implementation required

    //CRUD operation
    void Create(const ID& id, const Value& value);
    const Value& operator[](const ID& id) const;
    void Update(const ID& id, const Value& value);
    void Delete(const ID& id);

private:
    map<ID, Value> data;
};


//Create
template<typename ID, typename Value>
void Map<ID, Value>::Create(const ID& id, const Value& value)
{
    data.insert({id, value});
}

//Read
template<typename ID, typename Value>
const Value& Map<ID, Value>::operator[](const ID& id) const {
    if (data.find(id) == data.end()) {
        throw std::out_of_range("Key not found");
    }
    return data.find(id)->second;
}

//Update
template<typename ID, typename Value>
void Map<ID, Value>::Update(const ID& id, const Value& value)
{
    if (data.find(id) != data.end()) {
        data.find(id)->second = value;
    }
}

//Delete
template<typename ID, typename Value>
void Map<ID, Value>::Delete(const ID& id)
{
    data.erase(id);
}

#endif // MAP_H_INCLUDED
