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

Node<int>* insert_at_head(Node<int>* head, int value) {
    Node<int>* insert_at_head(Node<int>*head, int value); {
        Node<int>* newNode = new Node<int>(value, head);
        return newNode; // Цей вузол стає новою головою
    }
    return nullptr;
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

template<typename T, typename F>
void format_list(Node<T>* node, F f, std::vector<std::string>& out) {
    if (node == nullptr) return;
    out.emplace_back(f(node->val));
    format_list(node->next, f, out);
}

template<typename T>
void put_words(const std::vector<T>& v) {
    if (!v.empty()) {
        std::copy(v.begin(), std::prev(v.end()), std::ostream_iterator<T>{std::cout, " "});
        std::cout << v.back();
    }
    std::cout << '\n';
}

int main() {
    std::vector<std::string> head_vec = get_words<std::string>();
    auto head_it = head_vec.begin();
    auto head_end = head_vec.end();
    Node<int>* head = build_list<int>(head_it, head_end, [](auto s) { return std::stoi(s); });
    int value;
    std::cin >> value;
    ignore_line();
    Node<int>* res = insert_at_head(head, value);
    std::vector<std::string> res_vec;
    format_list(res, [](auto v) { return std::to_string(v); }, res_vec);
    put_words(res_vec);
}
