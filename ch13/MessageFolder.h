//
//  ex13_34_36_37.h
//  Exercise 13.34 13.36 13.37
//
//  Created by pezy on 1/26/15.
//  Copyright (c) 2015 pezy. All rights reserved.
//
//   34: Write the Message class as described in this section.
//
//   36: Design and implement the corresponding Folder class. That class should
//   hold a set that points to the Messages in that Folder.
//
//   37:  Add members to the Message class to insert or remove a given Folder*
//   into folders.
//        These members are analogous to Folder’s addMsg and remMsg operations.

#ifndef MESSAGEFOLDER_H
#define MESSAGEFOLDER_H

#include <set>
#include <string>

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Folder;

public:
    explicit Message(const std::string& str = "") : contents(str) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);

    void print_debug();

private:
    std::string contents;
    std::set<Folder*> folders;

    void add_to_Folders(const Message&);
    void remove_from_Folders();

    void addFldr(Folder* f) { folders.insert(f); }
    void remFldr(Folder* f) { folders.erase(f); }
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Message;

public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void print_debug();

private:
    std::set<Message*> msgs;

    void add_to_Messages(const Folder&);
    void remove_from_Messages();

    void addMsg(Message* m) { msgs.insert(m); }
    void remMsg(Message* m) { msgs.erase(m); }
};

void swap(Folder&, Folder&);

#endif // MESSAGE