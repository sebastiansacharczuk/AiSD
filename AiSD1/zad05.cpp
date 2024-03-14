#include <iostream>
#include <string>

struct Node{
    std::string name;
    int fans;
    bool role;
    Node* next;

    Node(std::string ipt_name, int ipt_fans){
        name = ipt_name;
        fans = ipt_fans;
        next = nullptr;
        role = false;
    }
};
void push_top_unique(Node **head, std::string ipt_name, int ipt_fans){
    if(*head == nullptr){
        *head = new Node(ipt_name, ipt_fans);
        std::cout << "TAK\n";
        return;
    }
    else{
        Node *current = *head;

        while(current != nullptr){
            if(current->name == ipt_name && current->fans == ipt_fans){
                std::cout << "NIE\n";
                return;
            }
            current = current->next;
        }

        Node* new_head = new Node(ipt_name, ipt_fans);
        new_head->next = *head;
        *head = new_head;
        std::cout << "TAK\n";
    }
}

bool compare(Node a, Node b){
    if(a.role && !b.role)
        return true;
    else if(a.fans < b.fans)
        return true;
    else if(a.fans == b.fans && a.name > b.name)
        return true;
    else
    return false;
}

void enroll(Node **head, int limit){
    if(*head == nullptr){
        std::cout << "NIE\n";
        return;
    }
    // bubblesort
    Node *current = *head, *done = nullptr;
    bool swapped = true;

    std::string tmp_name;
    int tmp_fans;
    bool tmp_role;
    while(swapped){
        swapped = false;
        current = *head;
        while(current->next != done){
            if(compare(*current, *current->next)){

                tmp_name = current->name;
                tmp_fans = current->fans;
                tmp_role = current->role;

                current->name = current->next->name;
                current->fans = current->next->fans;
                current->role = current->next->role;

                current->next->name = tmp_name;
                current->next->fans = tmp_fans;
                current->next->role = tmp_role;

                swapped = true;
            }
            current = current->next;
        }
        done = current;
    }

    current = *head;
    Node *prev_node = nullptr;
    while(current != nullptr){
        if(current->fans <= limit){
            std::cout << current->name << '\n';
            Node* next_node = current->next;
            if(prev_node == nullptr){
                *head = next_node;
            }
            else{
                prev_node->next = next_node;
            }
            delete current;
            return;
        }
        prev_node = current;
        current = current->next;
    }
    std::cout << "NIE\n";
}

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::cin.ignore();
    Node* head = nullptr;
    std::string ipt_name;
    int op;
    int inputFans;

    for(int i = 0; i < n; i++){
        std::cin >> op >> std::ws;
        if(op == 1){
            std::getline(std::cin, ipt_name);
            std::cin >> inputFans;
            push_top_unique(&head, ipt_name, inputFans);
        }
        else if (op == 2){
            std::cin >> inputFans;
            enroll(&head, inputFans);
        }
    }

    return 0;
}
