#include <bits/stdc++.h>
using namespace std;

// implement on a linked list
class Node {
public:
    int key;
    int val;
    int use_counter = 1;
    Node* next = nullptr;
    Node* prev = nullptr;

    Node(int key, int data = 0) : key(key), val(data) {};
};

class LL{
// private:
public:
    Node* Head = nullptr; // most recently used node
    Node* Tail = nullptr; // least recently used node
    LL() {}
    
    Node* add_at_head(int key, int data)
    {
        Node* node = new Node(key, data);
        add_at_head(node);
        return node;
    }

    void add_at_head(Node* node)
    {
        if(Head == nullptr)
        {
            Head = node;
            Tail = node;
            return;
        }
        node->next = Head;
        Head->prev = node;
        Head = node;
    }

};

class LL_Op_Handler
{
public:
    void move_node_to_target_LL(Node* curr, LL* curr_LL, LL* target_LL)
    {
        if (!curr || !curr_LL || !target_LL) return;

        // remove curr from curr_LL
        if(curr == curr_LL->Head) curr_LL->Head = curr->next;
        if(curr == curr_LL->Tail) curr_LL->Tail = curr->prev;

        if(curr->next) curr->next->prev = curr->prev;
        if(curr->prev) curr->prev->next = curr->next;
        
        curr->next = nullptr;
        curr->prev = nullptr;
    
        // add curr to target_LL
        target_LL->add_at_head(curr);
    
        //update the use_counter
        curr->use_counter++;
    }
    
    int delete_LFU_Node(LL* LL_of_node)
    {
        if (!LL_of_node || LL_of_node->Tail == nullptr)
            return -1; // nothing to delete
        
        // LFU node is tail node
        int deleted_node_key = LL_of_node->Tail->key;
        if(LL_of_node->Tail->prev == nullptr)
        {
            delete LL_of_node->Tail;
            LL_of_node->Tail = nullptr;
            LL_of_node->Head = nullptr;
        }
        else
        {
            Node* tail_node_to_delete = LL_of_node->Tail;
            // cout << tail_node_to_delete->prev << endl;
            tail_node_to_delete->prev->next = nullptr;
            LL_of_node->Tail = LL_of_node->Tail->prev; 
            delete tail_node_to_delete;
        }
        return deleted_node_key;
    }
};

class LFUCache {
private:
    int capacity = 0;
    int least_used_nodes = 1;
    unordered_map<int, Node*> address_book; // key : address of that LL
    unordered_map<int, LL*> use_counter_book; // use_count : LL which maintaines the LRU Data{key:value}
    LL_Op_Handler* LFU_LL_Handler;

    void update_use_counter_book(int key)
    {
        Node* target = address_book[key];
        int curr_use_cnt = target->use_counter;

        if(use_counter_book.find(curr_use_cnt+1) == use_counter_book.end())
        {
            use_counter_book[curr_use_cnt+1] = new LL();
        }

        LFU_LL_Handler->move_node_to_target_LL(target, use_counter_book[curr_use_cnt], use_counter_book[curr_use_cnt+1]); // move tar from it's LL, to LL 2

        if(least_used_nodes == curr_use_cnt && use_counter_book[least_used_nodes]->Head == nullptr)
        {
            use_counter_book.erase(least_used_nodes);
            least_used_nodes++;
        }
    }

public:
    LFUCache(int capacity)
    {
        this->LFU_LL_Handler = new LL_Op_Handler();
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(address_book.find(key) != address_book.end())
        {
            // logic to update the use counter
            update_use_counter_book(key);
            return address_book[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        //if key already exists, update the counter and value
        if(address_book.find(key) != address_book.end())
        {
            address_book[key]->val = value;
            update_use_counter_book(key);            
            return;
        }
        
        // capacity full, we have to delete the LFU
        if(address_book.size() == capacity)
        {
            // remove LFU
            int deleted_node_key = LFU_LL_Handler->delete_LFU_Node(use_counter_book[least_used_nodes]);
            if(use_counter_book[least_used_nodes]->Head == nullptr) use_counter_book.erase(least_used_nodes);
            address_book.erase(deleted_node_key);
        }

        // created and added the node into both entries;
        if(use_counter_book.find(1) == use_counter_book.end())
        {
            use_counter_book[1] = new LL();
        }

        Node* curr = use_counter_book[1]->add_at_head(key, value);
        address_book[key] = curr;
        least_used_nodes = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
