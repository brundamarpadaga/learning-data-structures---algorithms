#include<iostream>


class baseObject{
    public:
    baseObject(){
        std::cout << "baseObject constructor called" << std::endl;
    }
    baseObject(std::string name): m_name(name){
        std::cout << "baseObject constructor called with name: " << name << std::endl;
    }
    ~baseObject(){
        std::cout << "baseObject destructor called" << std::endl;
    }
    public:
    std::string m_name;
};

class animal : public baseObject{
    public: 
    animal(){
        std::cout << "animal constructor called" << std::endl;

    }
    animal(std::string name, std::string sound): m_name(name), m_sound(sound){
        std::cout << "animal constructor called with name: " << name << " and it makes sound: " << sound <<std::endl;
    }
    ~animal(){
        std::cout << "animal destructor called" << std::endl;
    }
    public:
    int m_publicMember;
    protected:
    int m_protectedMember;
    private:
    int m_privateMember;
    std::string m_name;
    std::string m_sound = "generic animal sound";
};

class dog : public animal{
    public:
    dog(): animal("dog", "bow bow"){
        std::cout << "dog constructor called" << std::endl;
        m_publicMember = 10;
        m_protectedMember = 20;
        // m_privateMember = 30; cannot access private member from outside the class
    }
    dog(std::string name): animal(name, "bow bow"){
        std::cout << "dog constructor called with name: " << name << std::endl;
    }
    ~dog(){
        std::cout << "dog destructor called" << std::endl;
    }
    private:
    std::string dogName;
    
};

int main(){
    dog d;
    d.m_publicMember = 10; //using protected on animal extension would make it accessible
    // d.m_protectedMember = 20; cannot access protected member from outside the class, can be accessed from derived class
    // d.m_privateMember = 30; cannot access private member from outside the class
    return 0;
}