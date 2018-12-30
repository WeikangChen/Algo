#include <future>
#include <iostream>
#include <thread>
#include <mutex>

std::once_flag flag;

void print()
{    
    std::cout << "Hi, my name is " << std::this_thread::get_id() 
              << ", what?" << std::endl;
}

void do_once(std::string str)
{
    std::cout << "sleeping for a while..." << str << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << "Done" << std::endl;
}

void work()
{
    std::call_once(flag, do_once,  "abcd");
    print();
}


int main()
{
    auto handle1 = std::async(std::launch::async, work);
    auto handle2 = std::async(std::launch::async, work);
    auto handle3 = std::async(std::launch::async, work);
    auto handle4 = std::async(std::launch::async, work);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
