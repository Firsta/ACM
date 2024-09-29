#include <string>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <iostream>

using namespace std;

struct Node
{
    Node *pre_;
    Node *next_;
    int cnt_;
    unordered_set<string> s_;

    Node() : pre_(nullptr), next_(nullptr), cnt_(0)
    {
    }

    Node(int cnt, string s) : pre_(nullptr), next_(nullptr), cnt_(cnt)
    {
        s_.insert(s);
    }
};

class List
{
    Node *head_;
    Node *end_;

public:
    List()
    {
        head_ = new Node();
        end_ = new Node();
        head_->next_ = end_;
        end_->pre_ = head_;
    }

    bool is_empty()
    {
        return head_->next_ == end_;
    }

    string getMaxKey()
    {
        if (this->is_empty())
        {
            return string();
        }
        else
        {
            return *end_->pre_->s_.begin();
        }
    }

    string getMinKey()
    {
        if (this->is_empty())
        {
            return string();
        }
        else
        {
            return *head_->next_->s_.begin();
        }
    }

    Node *insert(string s)
    {
        if (is_empty() || head_->next_->cnt_ != 1)
        {
            // cout << "insert not 1 " << s << endl;
            Node *nn = new Node(1, s);
            Node *next = head_->next_;
            nn->next_ = next;
            nn->pre_ = head_;
            head_->next_ = nn;
            next->pre_ = nn;

            return nn;
        }
        else
        {
            // cout << "insert has 1" << s << endl;

            head_->next_->s_.insert(s);
            return head_->next_;
        }
    }

    Node *dec(Node *cur, string s)
    {
        int cnt = cur->cnt_ - 1;

        cur->s_.erase(s);
        if (cur->s_.empty())
        {
            cur->pre_->next_ = cur->next_;
            cur->next_->pre_ = cur->pre_;

            Node *t = cur->next_;
            delete cur;
            cur = t;
        }

        if (cnt == 0)
        {
            return nullptr;
        }

        if (cur->pre_ == head_ || cur->pre_->cnt_ != cnt)
        {
            Node *nn = new Node(cnt, s);

            Node *pre = cur->pre_;

            nn->pre_ = pre;
            nn->next_ = cur;
            pre->next_ = nn;
            cur->pre_ = nn;

            return nn;
        }
        else
        {
            cur->pre_->s_.insert(s);
            return cur->pre_;
        }
    }

    Node *inc(Node *cur, string s)
    {
        int cnt = cur->cnt_ + 1;

        cur->s_.erase(s);
        if (cur->s_.empty())
        {
            cur->pre_->next_ = cur->next_;
            cur->next_->pre_ = cur->pre_;

            Node *t = cur->pre_;
            delete cur;
            cur = t;
        }

        if (cur->next_ == end_ || cur->next_->cnt_ != cnt)
        {
            Node *nn = new Node(cnt, s);

            Node *next = cur->next_;

            nn->pre_ = cur;
            nn->next_ = next;
            next->pre_ = nn;
            cur->next_ = nn;

            return nn;
        }
        else
        {
            cur->next_->s_.insert(s);
            return cur->next_;
        }
    }

    void print()
    {
        Node *p = head_->next_;
        cout << "list: ";
        while (p != end_)
        {
            cout << p->cnt_;
            cout << "(";
            for (auto i : p->s_)
            {
                cout << i << ",";
            }
            cout << ")";

            p = p->next_;
        }
        cout << endl;
    }
};

class AllOne
{
    unordered_map<string, Node *> m_;
    List l_;

public:
    AllOne()
    {
    }

    void inc(string key)
    {
        if (m_.find(key) != m_.end())
        {
            m_[key] = l_.inc(m_[key], key);
        }
        else
        {
            m_[key] = l_.insert(key);
        }

        // print();
    }

    void dec(string key)
    {
        Node *t = l_.dec(m_[key], key);
        if (t == nullptr)
        {
            m_.erase(key);
        }
        else
        {
            m_[key] = t;
        }
        // print();
    }

    string getMaxKey()
    {
        return l_.getMaxKey();
    }

    string getMinKey()
    {
        return l_.getMinKey();
    }

    void print()
    {
        l_.print();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

int main()
{
    AllOne *obj = new AllOne();
    obj->inc("hello");
    obj->print();
    obj->inc("goodbye");
    obj->print();

    obj->inc("hello");
    obj->print();
    obj->inc("hello");

    assert(obj->getMaxKey() == "hello");
    obj->inc("leet");
    obj->print();

    obj->inc("code");
    obj->print();

    obj->inc("leet");
    obj->print();

    obj->dec("hello");
    obj->print();

    obj->inc("leet");
    obj->print();

    obj->inc("code");
    obj->print();

    obj->inc("code");
    obj->print();

    cout << obj->getMaxKey() << endl;
    assert(obj->getMaxKey() == "code");

    return 0;
}