#include <iostream>
using std::cout;
using std::string;

// Payload class definition (as provided)
struct Payload {
    static int counter;
    int id;
    string name;

    Payload(string n = "") : id(++counter), name(n) { say_born(); }
    ~Payload() { say_die(); }
    Payload(const char *n) : Payload(string(n)) {}
    Payload(const Payload &x) : id(++counter), name(x.name) { say_born(); }
    Payload(Payload &&x) : id(++counter), name(std::move(x.name)) { say_born(); }
    void operator=(const Payload &x) { name = x.name; }

    void say_born() const;
    void say_die() const;
    void print() const;
};

int Payload::counter = 0;
void Payload::say_born() const { /* Implementation hidden for brevity */ }
void Payload::say_die() const { /* Implementation hidden for brevity */ }
void Payload::print() const {
    cout << '(' << id << ':' << name << ')';
}

// Node structure for the List
struct Node {
    Payload data;
    Node* next;

    Node(const Payload& payload) : data(payload), next(nullptr) {}
};

// List class definition
class List {
    Node* head;

public:
    List() : head(nullptr) {}
    ~List();

    void push_front(const Payload& payload);
    bool pop_front();
    size_t size() const;
    void print() const;
};

List::~List() {
    while (pop_front()) {}
}

void List::push_front(const Payload& payload) {
    Node* newNode = new Node(payload);
    newNode->next = head;
    head = newNode;
}

bool List::pop_front() {
    if (!head) return false;
    Node* temp = head;
    head = head->next;
    delete temp;
    return true;
}

size_t List::size() const {
    size_t count = 0;
    Node* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void List::print() const {
    Node* current = head;
    while (current) {
        current->data.print();
        current = current->next;
    }
}

int main() {
    auto showList = [](const List & s)
        {
            cout << "List size: " << s.size() << '\n';
            s.print(); cout << '\n';
        };
        {
            List s;
            s.push_front("apple");
            s.push_front("pear");
            s.push_front("banana");
            showList(s);
            s.pop_front();
            showList(s);
        }
}
