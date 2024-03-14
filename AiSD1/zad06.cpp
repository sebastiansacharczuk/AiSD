#include <iostream>
#include <queue>
#include <list>

struct TreeNode{
    char letter;
    int amount, counter;
    std::list<TreeNode*> childrens;

    TreeNode(char letter, int amount){
        this->letter = letter;
        this->amount = amount;
        this->counter = 0;
    }
};

std::queue<TreeNode*> g_q;

void addTreeNode(TreeNode** root, char letter, int amount){
    if(*root == nullptr){
        *root = new TreeNode(letter, amount);
        g_q.push(*root);
        return;
    }

    TreeNode* currNode = g_q.front(), *newNode = new TreeNode(letter, amount);
    if (currNode->counter == currNode->amount){
        
        g_q.pop();
        currNode = g_q.front();
    }
    if(currNode->counter < currNode->amount){

        currNode->childrens.push_back(newNode);
        currNode->counter++;

        g_q.push(newNode);
    }
    

    
}

void printPreorder(TreeNode* current){
    if(current == nullptr)
        return;

    std::cout << current->letter;

    for(auto child : current->childrens){
                printPreorder(child);
    }
}


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int sets;
    std::cin >> sets;
    for(int i = 0; i < sets; i++){
        while(!g_q.empty())
            g_q.pop();
        int vertices, amount;
        char letter;
        std::cin >> vertices;
        TreeNode *root = nullptr;
        for(int j = 0; j < vertices; j++){
            std::cin >> letter >> amount;
            addTreeNode(&root, letter, amount);
        }
        printPreorder(root);
        std::cout << '\n';
    }
    return 0;
}