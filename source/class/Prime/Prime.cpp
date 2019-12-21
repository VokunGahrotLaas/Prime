#include "Prime.hpp"

//public:

//constructor
Prime::Prime(const std::string& filePath){
    m_file.open(filePath, std::ios_base::out | std::ios_base::trunc);
    if(m_file.is_open()){
        std::cout << std::endl;
        std::cout << "|------------------------|" << std::endl;
        std::cout << "|File opened successfully|" << std::endl;
        std::cout << "|------------------------|" << std::endl;
    }else{
        std::cout << std::endl;
        std::cout << "|-------------------|" << std::endl;
        std::cout << "|File failed to open|" << std::endl;
        std::cout << "|-------------------|" << std::endl;
    }
}

//destructor
Prime::~Prime(){
    m_file.close();
}

//static attribute

//static member

//member
void Prime::calc(){
    uint32_t number;
    std::cout << "How many primes :";
    std::cin >> number;
    //
    std::time_t start = std::time(nullptr);
    std::cout << std::endl;
    std::cout << "Computing " << number << " primes :" << std::endl;
    std::cout << "|----------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|";
    int ratio = 0;
    int printedRatio = 0;
    const int RATIO_PER_LINE = 100;
    const double RATIO_TOTAL = 1000.0;
    m_dm.push_back(2);
    uint64_t inTest = 3;
    unsigned long i = 0;
    while(m_dm.size() < number){
        m_dm.cursorDefault();
        for(i = 0; inTest % m_dm.cursorData() != 0 && i < m_dm.size() && m_dm.cursorData() * m_dm.cursorData() <= inTest; i++){
            m_dm.cursorFront();
        }
        if(inTest % m_dm.cursorData() != 0){
            m_dm.push_back(inTest);
            ratio = int((double(m_dm.size()) / double(number)) * RATIO_TOTAL);
            while(ratio >= printedRatio + 1){
                std::cout << "=";
                printedRatio++;
                if(printedRatio % RATIO_PER_LINE == 0){
                    std::cout << "|" << printedRatio / RATIO_PER_LINE << std::endl << "|";
                }
            }
            inTest += 2;
        }else{
            inTest += 2;
        }
    }
    std::cout << "----------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "Time since start: " << std::time(nullptr) - start << "s" << std::endl;
    start = std::time(nullptr);
    //
    std::cout << std::endl;
    std::cout << "Writing " << number << " primes :" << std::endl;
    std::cout << "|----------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|";
    ratio = 0;
    printedRatio = 0;
    i = 0;
    double originalSize = double(m_dm.size());
    while(m_dm.size() > 0){
        ratio = int((double(i + 1) / originalSize) * RATIO_TOTAL);
        while(ratio >= printedRatio + 1){
            std::cout << "=";
            printedRatio++;
            if(printedRatio % RATIO_PER_LINE == 0){
                std::cout << "|" << printedRatio / RATIO_PER_LINE << std::endl << "|";
            }
        }
        m_file << m_dm.pop_front() << std::endl;
        i++;
    }
    std::cout << "----------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "Time since start: " << std::time(nullptr) - start << "s" << std::endl;
}

//friendly operator

//operator

//protected:

//attribute

//member