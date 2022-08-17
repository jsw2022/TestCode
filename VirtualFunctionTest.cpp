#include <iostream>

using namespace std;

class super_c
{
    public:
        /** pure vitrual function **/
        virtual void nothing(void){}
        
        void show_s(void)
        {
            cout<<"Supper Class\n";
        }
};

class sb_c : public super_c
{
    public:
        void nothing(void)
        {
            cout<<"Call Sub Class\n";
        }
        
        void show_s(void)
        {
            cout<<"Show sub class\n";
        }
};

int main()
{
    super_c ss, *s_ptr;
    sb_c sb, *sb_ptr;
    
    s_ptr = &sb;      
    s_ptr->nothing();
    s_ptr->show_s();
    
    //sb_ptr = &ss;  //note: can't do it
    
    
    //sb_ptr = &sb;
    //sb_ptr->nothing();
    //sb_ptr->show_s();
    
    //ss.nothing(); /** do nothing when call super class pure vitural function **/
    //sb.nothing();
}