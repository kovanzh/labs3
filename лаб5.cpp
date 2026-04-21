#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

template<typename T>
struct Node {
    T val;
    Node<T>* next;

    explicit Node(T val, Node<T>* next = nullptr)
        : val{ val }, next{ next } {
    }

    ~Node() {
        delete next;
    }
};

int search_linked_list(Node<int>* head, int target) {
    int search_linked_list(Node<int>*head, int target);2 {
    Node<int>* current = head;

    while (current != nullptr) {
        if (current->val == target) {
            return 1; // Знайшли
        }
        current = current->next;
    }

    return 0; // Дійшли до кінця (null) і не знайшли
}
    return 0;
}

template<typename T, typename Iter, typename F>
Node<T>* build_list(Iter& it, Iter& end, F f) {
    if (it == end) return nullptr;
    std::string val = *it;
    ++it;
    Node<T>* next = build_list<T>(it, end, f);
    return new Node<T>{ f(val), next };
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{ line };
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

void ignore_line() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    std::vector<std::string> head_vec = get_words<std::string>();
    auto head_it = head_vec.begin();
    auto head_end = head_vec.end();
    Node<int>* head = build_list<int>(head_it, head_end, [](auto s) { return std::stoi(s); });
    int target;
    std::cin >> target;
    ignore_line();
    int res = search_linked_list(head, target);
    std::cout << res << '\n';
}
