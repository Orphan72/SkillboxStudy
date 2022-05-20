#include <iostream>

struct vctr
{
    float abs = 0.0;
    float ord = 0.0;
};


vctr add (vctr frst, vctr scnd)
{
    vctr thrd;
    thrd.abs = frst.abs + scnd.abs;
    thrd.ord = frst.ord + scnd.ord;
    return thrd;
}

//a + b =  {ax + bx; ay + by}


int main()
{
    std::string command = " ";

    vctr first;
    vctr second;
    vctr result;

    std::cout << "For adding two vectors enter \'add\'\n";
    std::cout << "For subtracting two vectors enter \'subtract\'\n";
    std::cout << "For multiplying a vector by a scalar enter \'scale\'\n";
    std::cout << "For finding the length of a vector enter \'length\'\n";
    std::cout << "For vector normalization enter \'normalize\'\n";

    first.abs = 1;
    first.ord = 2;

    second.abs = 4;
    second.ord = 8;

    result = add (first, second);

    std::cout << "Result's coordinate are: \n X = " << result.abs << "\n Y = " << result.ord << std::endl;


    //
    // a - b = {ax - bx; ay - by}



    return 0;
}
