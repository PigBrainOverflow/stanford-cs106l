/* 
Assignment 2: Marriage Pact

This assignment asks you to discover your one true love using containers and pointers.
There are two parts: implement get_applicants and find_matches.

Submit to Paperless by 11:59pm on 2/1/2024.
*/

#include <iostream>
#include <string>
#include <queue>
#include <set>
// STUDENT
#include <fstream>
#include <sstream>

std::set<std::string> get_applicants(std::string filename) {
    // TODO: Implement this function. Feel free to change std::set to std::unordered_set if you wish!
    std::ifstream txtin(filename);
    if (!txtin) {
        throw std::runtime_error("cannot open file");
    }
    std::set<std::string> applicants;
    std::string line;
    // getline() consumes '\n'
    // >> does not consume white characters and skips leading white characters
    while (std::getline(txtin, line)) {
        std::cout << line << std::endl;
        applicants.insert(line);
    }
    return applicants;
}

// STUDENT
std::pair<char, char> get_initials(const std::string& s) {
    std::stringstream ss(s);
    std::string first, last;
    ss >> first >> last;
    return {first[0], last[0]};
}

std::queue<const std::string*> find_matches(std::set<std::string> &students, const std::string& target) {
    // TODO: Implement this function.
    std::queue<const std::string*> matches;
    auto [targetf, targetl] = get_initials(target);
    for (const auto& student : students) {
        auto [f, l] = get_initials(student);
        if (f == targetf && l == targetl) {
            matches.push(&student);
        }
    }
    return matches;
}

int main() {
    // Your code goes here. Don't forget to print your true love!
    std::string name{"MacArthur Kong"};
    auto applicants = get_applicants("students.txt");
    auto matches = find_matches(applicants, name);
    if (matches.empty()) {
        std::cout << "NO STUDENT FOUND." << std::endl;
    }
    else {
        auto match = matches.front();
        std::cout << match << std::endl;
    }
    return 0;
}
