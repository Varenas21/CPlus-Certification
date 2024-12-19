#include <iostream>

struct Library
{
    const std::string sTitle{};
    const std::string sAuthor{};
    const std::string sPublisher{};
    const std::string sSubject{};
    const std::string sOCLC{};

    const long lISBN{};
    const double  dDecimal{};
    const int iPublished{};
    const int iAcquired{};
    const int iStock{};
};


unsigned long NonRecursiveFactorial(unsigned long n)
{
    unsigned long i{n};
    while (i > n)
    {
        i *= --n;
    }
    return i;

}

int main()
{
    std::cout << "Non Recursive Factorial" << NonRecursiveFactorial(5);

    Library firstBook { "Name", "Author", "Publisher", "Subject", "OCLC", 1243, 24.5f, 23,22,1 };
    std::cout << "Name: " << firstBook.sTitle << std::endl;
    std::cout << "Author: " << firstBook.sAuthor << std::endl;
    std::cout << "Publisher: " << firstBook.sPublisher << std::endl;
    std::cout << "Subject: " << firstBook.sSubject << std::endl;
    std::cout << "OCLC: " << firstBook.sOCLC << std::endl;
    std::cout << "ISBN: " << firstBook.lISBN << std::endl;
    std::cout << "Published: " << firstBook.iPublished << std::endl;
    std::cout << "Acquired: " << firstBook.iAcquired << std::endl;
    std::cout << "Stock: " << firstBook.iStock << std::endl;

    // CHALLENGE TWO PRIME NUMBERS
    int array[] { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89, 97 };
    int i{};
    while (i < 100)
    {
        i++;
        auto y = i % 2;

        if (y == 1 || i ==2  ) std::cout << "Prime number: " << i << std::endl;
        else std::cout << "NOT Prime number: " << i << std::endl;
    }

    
}

