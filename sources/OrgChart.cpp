
#include "OrgChart.hpp"
using namespace ariel;


namespace ariel
{
    OrgChart::OrgChart() : root(nullptr) , num_of_employees(0)
    {
        this->root=nullptr;
        this->num_of_employees=0;
    }
    OrgChart OrgChart::add_root(const string &new_root)
    {
        if(this->root==nullptr)
        {
            this->root=new Node(new_root , 0);
            this->num_of_employees++;
        }
        this->root->emp_name=new_root;

        return *this;

    }
    OrgChart::Node* OrgChart::if_employee_exist(Node *employee ,const string &emp)
    {
        int size=employee->children.size();
        for (unsigned int i = 0; i <size; i++)
        {
            if(employee->children[i]->emp_name==emp)
            {
                Node *employee=employee->children[i];
                return employee;
            }
            else{
                Node *employee=if_employee_exist(employee->children[i] ,emp);


            }
        }
        return nullptr;
    }

    OrgChart OrgChart::add_sub(const string &emp1 ,const string &emp2)
    {
        if(this->root==nullptr)
        {
            throw("root doesn't exist");
        }
        if(this->get_root().emp_name==emp1)
        {
            Node *new_employee = new Node(emp2 , this->get_root().employee_rank+1);
            this->get_root().children.push_back(new_employee);
            this->num_of_employees++;

        }
        // else{
        //     int size=this->num_of_employees;
        //     Node *employee=if_employee_exist(&this->get_root(),emp1);
        //     if(employee==nullptr)
        //     {
        //         throw("the employee doesn't exist");
        //     }
        //     Node *new_employee = new Node(emp2 , employee->employee_rank+1);
        //     employee->children.push_back(new_employee);
        //     new_employee->parent=employee;
        //     this->num_of_employees++;
        // }
        return *this;
    }
    OrgChart::Iterator OrgChart::begin_level_order()
    {
        return Iterator(root);
    }
    OrgChart::Iterator OrgChart::end_level_order()
    {
        return Iterator(root);
    }

    OrgChart::Iterator OrgChart::begin_reverse_order()
    {
        return Iterator(root);
    }
    OrgChart::Iterator OrgChart::reverse_order()
    {
        return Iterator(root);
    }

    OrgChart::Iterator OrgChart::begin_preorder()
    {
        return Iterator(root);
    }
    OrgChart::Iterator OrgChart::end_preorder()
    {
        return Iterator(root);
    }

    OrgChart::Iterator OrgChart::begin()
    {
        return Iterator(root);
    }
    OrgChart::Iterator OrgChart::end()
    {
        return Iterator(root);
    }

    OrgChart::Node &OrgChart::get_root()
    {
        return *root;
    }

    int OrgChart::get_num_of_employees()
    {
        return num_of_employees;
    }

    ostream &operator << ( ostream &os, const OrgChart &orgC)
    {
        return os;
    }      
        
         
}