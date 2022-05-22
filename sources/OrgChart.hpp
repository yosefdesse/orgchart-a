
#include <vector>
#include <string>
using namespace std;

namespace ariel
{
    class OrgChart
    {
        private:
            

            class Node
            {
                public:
                string emp_name;
                int employee_rank;
                vector<Node *> children;
                Node *parent;
                Node(const string &name , int rank)
                {
                    this->emp_name=name;
                    this->employee_rank=rank;
                    this->parent=nullptr;
                }
                ~Node();
            };
            class Iterator
            {
                private:
                    Node *curr;

                public:
                Iterator(Node *ptr = nullptr)
                {
                    this->curr=ptr;
                }
                string &operator*() const
                {
                    return curr->emp_name;
                }
                string* operator->() const
                {
                    return &(curr->emp_name);
                }
                Iterator &operator++()
                {
                    return *this;

                }
                Iterator &operator++(int)
                {
                    return *this;

                }
                bool operator==(const Iterator &emp) const
                {
                    if(this->curr==emp.curr)
                    {
                        return true;
                    }
                    return false;
                }
                bool operator!=(const Iterator &emp) const
                {
                    if(this->curr==emp.curr)
                    {
                        return false;
                    }
                    return true;
                }

                
            };
            Node *root;
            int num_of_employees;

        
        public: 
            OrgChart();
            OrgChart add_root(const string &new_root);
            OrgChart add_sub(const string &emp1 , const string &emp2);
            Iterator begin_level_order();
            Iterator end_level_order();

            Iterator begin_reverse_order();
            Iterator reverse_order();

            Iterator begin_preorder();
            Iterator end_preorder();

            Iterator begin();
            Iterator end();
            Node &get_root();
            Node *if_employee_exist(Node *employee ,const string &emp) ;
            int get_num_of_employees();
            friend ostream &operator << ( ostream &output, const OrgChart &oc);            
        
         
            
                             
    };
}