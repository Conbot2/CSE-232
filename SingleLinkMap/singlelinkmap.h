#ifndef SINGLELINKMAP_H
#define SINGLELINKMAP_H

#include <iostream>
using std::cin; using std::cout; using std::endl; using std::ostream;
#include <algorithm>
using std::swap;

template <typename Key_Type, typename Value_Type>
struct Node {
    public:
        Node *next_;
        Key_Type key_;
        Value_Type value_;
        
        Node() : key_( Key_Type() ), value_( Value_Type() ), next_(nullptr) {};
        Node(Key_Type k, Value_Type d) : key_(k), value_(d), next_(nullptr) {};
        ostream& print_node(ostream&);
};

template<typename Key_Type, typename Value_Type>
ostream& Node<Key_Type,Value_Type>::print_node(ostream& out){
    out << key_ << ":" << value_;
    return out;
}

template <typename Key_Type, typename Value_Type>
class SingleLinkMap {
    private:
        Node<Key_Type,Value_Type> *begin_;
        Node<Key_Type,Value_Type> *last_;
    
    public:
        SingleLinkMap() : begin_(nullptr), last_(nullptr) {};
        SingleLinkMap(SingleLinkMap &l);
        ~SingleLinkMap();
        SingleLinkMap& operator=(SingleLinkMap l);
        void append_back(const Key_Type &key, const Value_Type &val);
        ostream& print_list(ostream&);
        Value_Type find_then_front(Key_Type);  
        Value_Type find_then_swap(Key_Type);
};

// copy constructor
template<typename Key_Type, typename Value_Type>
SingleLinkMap<Key_Type,Value_Type>::SingleLinkMap(SingleLinkMap<Key_Type,Value_Type> &l){
    SingleLinkMap<Key_Type,Value_Type> *n = new SingleLinkMap<Key_Type,Value_Type>();
    for (Node<Key_Type,Value_Type>* it = l.begin_; it != nullptr; it = it->next_)
        n->append_back(it->key_,it->value_);
    this->begin_ = n->begin_;
    this->last_ = n->last_;
}

template<typename Key_Type, typename Value_Type>
SingleLinkMap<Key_Type,Value_Type>::~SingleLinkMap(){
    Node<Key_Type,Value_Type> *lead = this->begin_->next_;
    Node<Key_Type,Value_Type> *trail = this->begin_;
    while (trail != nullptr) {
        trail->next_ = nullptr;
        trail = lead;
        if (lead != nullptr)
            lead = lead->next_;
    }
    this->begin_ = nullptr;
}

template<typename Key_Type, typename Value_Type>
SingleLinkMap<Key_Type,Value_Type>& SingleLinkMap<Key_Type,Value_Type>::operator=(SingleLinkMap<Key_Type,Value_Type> l){
    swap(this->begin_,l.begin_);
    swap(this->last_,l.last_);
    return *this;
}
  
template<typename Key_Type, typename Value_Type>
void SingleLinkMap<Key_Type,Value_Type>::append_back(const Key_Type &key, const Value_Type &val){
    Node<Key_Type,Value_Type> *n = new Node<Key_Type,Value_Type>(key,val);
    if (last_ != nullptr) {
        last_->next_ = n;
        last_ = n;
    }
    else {   // no items in list
        begin_ = n;
        last_ = n;
    }
}

template<typename Key_Type, typename Value_Type>
ostream& SingleLinkMap<Key_Type,Value_Type>::print_list(ostream &out){
    out << "List: ";
    for (auto iter = this->begin_; iter != nullptr; iter = iter->next_) {
        iter -> print_node(cout);
        if (iter->next_ == nullptr)
            out << "";
        else
            out << ", ";
    }
    return out;
}

template<typename Key_Type, typename Value_Type>
Value_Type SingleLinkMap<Key_Type,Value_Type>::find_then_front(Key_Type key){
    if (this->begin_ != nullptr) {    // find node
        Node<Key_Type,Value_Type>* prev = this->begin_;
        Node<Key_Type,Value_Type>* target = this->begin_;
        while (target != nullptr) {
            if (target->key_ == key)
                break;
            else {
                if (target == this->begin_)  // first iteration
                    target = target ->next_;
                else {
                    prev = prev->next_;
                    target = target->next_;
                }
            }
        }
        // move node
        if (target == this->begin_)
            return target->value_;
        else if (target != nullptr && target != this->begin_) {  // target in middle/at end
            prev->next_ = target->next_;
            target->next_ = this->begin_;
            this->begin_ = target;
            return target->value_;
        }
        else if (target == nullptr)  // target not found
            return Value_Type();
    }
    else  // list is empty
        return Value_Type();
}

template<typename Key_Type, typename Value_Type>
Value_Type SingleLinkMap<Key_Type,Value_Type>::find_then_swap(Key_Type key){
    if (this->begin_ != nullptr) {
        Node<Key_Type,Value_Type>* fixer = this->begin_;
        Node<Key_Type,Value_Type>* prev = this->begin_;
        Node<Key_Type,Value_Type>* target = this->begin_;
        size_t iter = 0;
        // find node
        while (target != nullptr) {
            if (target->key_ == key)
                break;
            else {
                if (iter == 0) {
                    target = target ->next_;
                    ++iter;
                }
                else if (iter == 1) {
                    prev = prev->next_;
                    target = target->next_;
                    ++iter;
                }
                else if (iter >= 2) {
                    prev = prev->next_;
                    target = target->next_;
                    fixer = fixer->next_;
                    ++iter;
                }
            }
        }
        // swap nodes
        if (iter == 0)
            return target->value_;
        else if (iter == 1) {
            prev->next_ = target->next_;
            target->next_ = prev;
        }
        else if (iter >=2 && target != nullptr) {
            prev->next_ = target->next_;
            target->next_ = prev;
            fixer->next_ = target;
            return target->value_;
        }
        else if (target == nullptr)  // target not found
            return Value_Type();
    }
    else  // list is empty
        return Value_Type();
}
#endif
  
