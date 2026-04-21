#include <algorithm>
#include <iostream>
#include <iterator>
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

Node<int>* create_linked_list(std::vector<int>& values) {
    Node<int>* create_linked_list(std::vector<int>&values); {
        if (values.empty()) return nullptr; // Якщо масив порожній, повертаємо null

        Node<int>* head = new Node<int>(values[0]); // Створюємо перший вузол
        Node<int>* current = head;

        for (size_t i = 1; i < values.size(); ++i) {
            current->next = new Node<int>(values[i]); // Створюємо наступний вузол
            current = current->next; // Переміщуємо вказівник
        }

        return head; // Повертаємо голову нового списку
    }
    return nullptr;
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
    std::vector<int> values = get_words<int>();
    Node<int>* res = create_linked_list(values);
    std::vector<std::string> res_vec;
    format_list(res, [](auto v) { return std::to_string(v); }, res_vec);
    put_words(res_vec);
}

