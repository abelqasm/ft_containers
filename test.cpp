#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class A{
    private:
        char *str;
    public:
        A(){str = (char*)malloc(100);std::cout<<"A()"<<std::endl;};
        ~A(){free(str);std::cout<<"~A()"<<std::endl;};
};

void test()
{
    A *b = new A;
    A *a = new (b) A;
    delete a;
}

int main()
{
    test();
    system("leaks   a.out");
    return 0;
}