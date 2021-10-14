#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_, const std::wstring& title_) :
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

void SharedPtrMain()
{
    // Use make_shared function when possible.
    auto sp1 = make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");

    // Ok, but slightly less efficient. 
    // Note: Using new expression as constructor argument
    // creates no named variable for other code to access.
    shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

    // When initialization must be separate from declaration, e.g. class members, 
    // initialize with nullptr to make your programming intent explicit.
    shared_ptr<Song> sp5(nullptr);
    //Equivalent to: shared_ptr<Song> sp5;
    //...
    sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing");
}