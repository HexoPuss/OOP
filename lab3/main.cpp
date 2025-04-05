#include "heads/hexagon.hpp"
#include "heads/pentagon.hpp"
#include "heads/octagon.hpp"


#define MAXIMUM_FIGURES_COUNT 64

void printHelp()
{
    std::cout << "<<< СПРАВКА >>>" << std::endl;
    std::cout << "A - добавить фигуру" << std::endl;
    std::cout << "L - список всех фигур" << std::endl;
    std::cout << "S - общая площадь фигур" << std::endl;
    std::cout << "R - удалить фигуру" << std::endl;
    std::cout << "H - справка" << std::endl;
    std::cout << "Q - выход" << std::endl;
    std::cout << std::endl;
}

int main()
{
    Figure *figures[MAXIMUM_FIGURES_COUNT];
    size_t figuresCount{};
    char command;
    Figure *newFigure;
    Point center;
    double area;
    size_t id;
    printHelp();
    bool isRunning{true};
    while (isRunning)
    {
        std::cin >> command;
        switch (command)
        {
        case 'A':
            std::cout << "Выберите тип фигуры:" << std::endl;
            std::cout << "1 - 5-угольник" << std::endl;
            std::cout << "2 - 6-угольник" << std::endl;
            std::cout << "3 - 8-угольник" << std::endl;
            std::cin >> command;
            switch (command)
            {
            case '1':
                newFigure = new Pentagon;
                std::cout << "Введите верхнюю ввершину 5-угольника и его сторону." << std::endl;
                std::cout << "Формат: X Y SIDE" << std::endl;
                try
                {
                    std::cin >> *newFigure;
                }
                catch (std::invalid_argument &e)
                {
                    std::cerr << e.what() << std::endl;
                    break;
                }
                if (!std::cin.fail())
                {
                    figures[figuresCount] = newFigure;
                    ++figuresCount;
                    std::cout << "Добавлен 5-угольник." << std::endl;
                }
                break;

            case '2':
                newFigure = new Hexagon;
                std::cout << "Введите левую ввершину 6-угольника и его сторону." << std::endl;
                std::cout << "Формат: X Y SIDE" << std::endl;
                try
                {
                    std::cin >> *newFigure;
                }
                catch (std::invalid_argument &e)
                {
                    std::cerr << e.what() << std::endl;
                    break;
                }
                if (!std::cin.fail())
                {
                    figures[figuresCount] = newFigure;
                    ++figuresCount;
                    std::cout << "Добавлен 6-угольник." << std::endl;
                }
                break;

            case '3':
                newFigure = new Octagon;
                std::cout << "Введите координаты центра и сторону." << std::endl;
                std::cout << "Формат: X Y SIDE" << std::endl;
                try
                {
                    std::cin >> *newFigure;
                }
                catch (std::invalid_argument &e)
                {
                    std::cerr << e.what() << std::endl;
                    break;
                }
                if (!std::cin.fail())
                {
                    figures[figuresCount] = newFigure;
                    ++figuresCount;
                    std::cout << "Добавлен 8-угольник." << std::endl;
                }
                break;

            default:
                std::cerr << "Ошибка: команда не найдена" << std::endl;
                break;
            }
            break;

        case 'L':
            for (size_t i{}; i < figuresCount; ++i)
            {
                center = figures[i]->findCenter();
                std::cout << "Фигура \"" << *figures[i] << "\" с id=" << i << std::endl;
                std::cout << "    - Площадь: " << static_cast<double>(*figures[i]) << std::endl;
                std::cout << "    - Центр: " << center << std::endl;
            }
            break;

        case 'S':
            area = 0;
            for (size_t i{}; i < figuresCount; ++i)
                area += static_cast<double>(*figures[i]);
            std::cout << "Общая площадь: " << area << std::endl;
            break;

        case 'R':
            std::cout << "Введите id фигуры для удаления:" << std::endl;
            std::cin >> id;
            if (id < figuresCount)
            {
                delete figures[id];
                for (size_t i{id + 1}; i < figuresCount; ++i)
                    figures[i - 1] = figures[i];
                --figuresCount;
                std::cout << "Фигура удалена" << std::endl;
            }
            else
            {
                std::cerr << "Ошибка: фигура не найдена" << std::endl;
            }
            break;

        case 'H':
            printHelp();
            break;

        case 'Q':
            std::cout << "Выход..." << std::endl;
            isRunning = false;
            break;

        default:
            std::cin.clear();
            std::cerr << "Ошибка: команда не найдена" << std::endl;
            break;
        }
    }
    for (size_t i{}; i < figuresCount; ++i)
        delete figures[i];
    return 0;
}
