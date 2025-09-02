#include<iostream>
#include<string>

class Publication {
protected:
    std::string title;
public:
    Publication(std::string t) : title(t) {}
    void print() {
        std::cout << "Title: " << title << std::endl;
    }
};

class Book : virtual public Publication 
{
protected:
    float accessionNo;
public:
    Book(std::string t, float a) : Publication(t), accessionNo(a) {}
    void print() {
        Publication::print();
        std::cout << "Accession Number: " << accessionNo << std::endl;
    }
};

class Magazine : virtual public Publication {
protected:
    int volumeNo;
public:
    Magazine(std::string t, int v) : Publication(t), volumeNo(v) {}
    void print()  {
        Publication::print();
        std::cout << "Volume Number: " << volumeNo << std::endl;
    }
};

class Journal : public Book, public Magazine 
{
public:
    Journal(std::string t, float a, int v) : Publication(t), Book(t, a), Magazine(t, v) {}
    void print() {
        Book::print();
        Magazine::print();
    }
};

int main() {
    Journal IEEEOOP("IEEEOOP", 681.3, 1);
    IEEEOOP.print();
    return 0;
}