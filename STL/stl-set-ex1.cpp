// https://modoocode.com/224
#include <iostream>
#include <set>
#include <string>

template <typename T>
void printSet(std::set<T>& s){
    for(const auto& elem : s){
        std::cout << elem << " " << std::endl;
    }
}

class Todo{
private:
    int priority; // high value high priority
    std::string job_desc;
public:
    Todo(int priority, std::string job_desc) : priority(priority), job_desc(job_desc) {}
    bool operator<(const Todo& t) const {
        if(priority == t.priority){
            return job_desc < t.job_desc;
        }
        return priority > t.priority;
    }
    friend std::ostream& operator<<(std::ostream& o, const Todo& td);
};

std::ostream& operator<<(std::ostream& o, const Todo& td){
    o << "[ priority : " << td.priority << "] " << td.job_desc;
    return o;
}

int main(void){
    std::set<Todo> todos;

    todos.insert(Todo(1, "Running"));
    todos.insert(Todo(2, "Study algorithm"));
    todos.insert(Todo(1, "Vision project"));
    todos.insert(Todo(3, "Meet friend"));
    todos.insert(Todo(2, "Reading book"));

    printSet(todos);

    std::cout << "------------------" << std::endl;
    std::cout << "If have done study algorithm" << std::endl;
    todos.erase(todos.find(Todo(2, "Study algorithm")));

    printSet(todos);
}