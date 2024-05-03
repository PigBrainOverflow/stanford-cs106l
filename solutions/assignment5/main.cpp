#include <iostream>
#include "user.h"

// TODO: Implement the non-member function + operator overload here!
User operator+(const User& u, User& v) {
    // we create a new user from u
    User res(u.name);
    for (auto f : u.friends) {
        res.friends.insert(f);
    }
    res.friends.insert(&v);
    v.friends.insert(const_cast<User*>(&u));
    return res; // NRVO or move constructor is called
}

void printFriends(const User& user) {
    std::cout << user.getName() << " is friends with: " << std::endl;
    for(auto& user : user.getFriends()) {
        std::cout << "  " << user->getName() << std::endl;
    }
}

int main() {
    // create a bunch of users
    User alice("Alice");
    User bob("Bob");
    User charlie("Charlie");
    User dave("Dave");

    // make them friends
    alice = alice + bob;
    alice = alice + charlie;

    dave = dave + bob;
    charlie = charlie + dave;


    // print out their friends
    printFriends(alice);
    printFriends(bob);
    printFriends(charlie);
    printFriends(dave);



    return 0;

}