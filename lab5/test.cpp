#include <iostream>
#include <string>
#include "src/array.hpp"
#include "src/custom_memory_resourse.hpp"

struct Person {
    std::string name;
    int         age;
    double      height;
};

int main() {
    // Создаём собственный пул памяти и передаём его контейнерам
    CustomMemoryResource pool;

    {
        // --- Работа с простыми типами ---
        DynamicArray<int> numbers(&pool);
        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);

        std::cout << "Numbers: ";
        for (int n : numbers) std::cout << n << ' ';
        std::cout << "\n\n";

        // --- Работа со сложным типом (структурой) ---
        DynamicArray<Person> people(&pool);
        people.push_back({"Alice",   30, 1.70});
        people.push_back({"Bob",     25, 1.82});
        people.push_back({"Charlie", 28, 1.75});

        std::cout << "People in array:\n";
        for (const auto& p : people) {
            std::cout << "  " << p.name << ", age " << p.age
                      << ", height " << p.height << " m\n";
        }

        std::cout << "\nLeaving inner scope...\n";
    }
    // Здесь массивы уже разрушены, CustomMemoryResource сообщит, если протечки
    std::cout << "Back in main, pool will be destroyed now.\n";
    return 0;
}
