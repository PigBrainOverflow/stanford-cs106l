#include <set>
#include <string>

class User {
public:
    // TODO: write special member functions, including default constructor!
    User() =default;
    User(std::string name);

    // no copy functions
    User(const User& other) =delete;
    User& operator=(const User& other) =delete;

    // move functions
    User(User&& other) =default;    // name and friends have move functions, using default
    User& operator=(User&& other) =default;

    // getter functions
    std::string getName() const;
    std::set<User*> getFriends() const;

    // setter functions
    void setName(std::string name);

    // TODO: add the < operator overload here!
    bool operator<(const User& other) const {
        return name < other.name;
    }
    friend User operator+(const User& u, User& v);

private:
    std::string name;
    std::set<User*> friends;    // should be pointers

};
