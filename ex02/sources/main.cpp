#include "../includes/PmergeMe.hpp"

static void    print_time(std::string msg, clock_t start, clock_t end, PmergeMe* db)
{
    if (start && end)
        std::cout << msg << double(end - start) * 1000.0 / CLOCKS_PER_SEC  << " ms"<< std::endl;
    else
        std::cout << msg;
    if (db)
        db->print();
}

static void    print_process(size_t elem, clock_t start, clock_t end, int v)
{
    std::cout << "Time to process a range of " << elem << " elements with std::";
    if (v)
       std::cout << "vector: ";
    else
       std::cout << "deque:  ";
    std::cout << double(end - start) * 1000.0 / CLOCKS_PER_SEC  << " ms"<< std::endl;
}

int main(int argc, char** argv)
{
    clock_t     global_start = clock();
    PmergeMe    db(argc, argv);
    if (db.isSorted())
        return 0;

    print_time("Before : ", 0, 0, &db);
    clock_t     start_v = clock();
    fordJohnson(db.getVector());
    clock_t     end_v = clock();

    clock_t     start_d = clock();
    fordJohnson(db.getDeque());
    clock_t     end_d = clock();

    print_time("After  : ", 0, 0, &db);
    print_process(db.getVectorSize(), start_v, end_v, 1);
    print_process(db.getDequeSize(), start_d, end_d, 0);

    clock_t     global_end = clock();
    print_time("Duration : ", global_start, global_end, NULL);

    return 0;
}
