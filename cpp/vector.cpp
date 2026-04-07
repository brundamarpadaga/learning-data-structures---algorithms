#include<iostream>
#include<vector>


int main(){
    std::vector<int> v;

    // You must add elements to a vector before accessing them.
    // front() and back() only access existing elements.
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(5);
    v.push_back(6);
    v.push_back(5);
    v.push_back(6);

    std::cout << v[0] << std::endl;


    std::cout << "Front : " << v.front() << std::endl;
    std::cout << "Back : " << v.back() << std::endl;
    std::cout << "Size : " << v.size() << std::endl;
    std::cout << "Max Size : " << v.max_size() << std::endl;
    std::cout << "Capacity : " << v.capacity() << std::endl;
    std::cout << "Empty : " << v.empty() << std::endl;  



    return 0;
}
