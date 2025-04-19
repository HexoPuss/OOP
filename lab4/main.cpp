#include "heads/hexagon.hpp"
#include "heads/pentagon.hpp"
#include "heads/octagon.hpp"

#include <array.hpp>
#include <string>



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
    Array<std::unique_ptr<Figure<double>>> figures;
    char command;
    std::unique_ptr<Figure<double>> newFigure;
    std::unique_ptr<Point<double>> center;
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
            std::cout << "1 - пятиугольник" << std::endl;
            std::cout << "2 - шестиугольник" << std::endl;
            std::cout << "3 - восьмиугольник" << std::endl;
            std::cin >> command;
            switch (command)
            {
            case '1':
                newFigure = std::make_unique<Pentagon<double>>();
                std::cout << "Введите верхнюю вершину, и сторону." << std::endl;
                std::cout << "Формат: X Y SIDE" << std::endl;
                try
                {
                    std::cin >> *newFigure;
                    if (!std::cin.fail())
                    {
                        figures.pushBack(std::move(newFigure));
                        std::cout << "Успешно добавлен пятиугольник." << std::endl;
                    }
                }
                catch (std::invalid_argument &e)
                {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case '2':
                newFigure = std::make_unique<Hexagon<double>>();
                std::cout << "Введите левую вершину и сторону." << std::endl;
                std::cout << "Формат: X Y SIDE" << std::endl;
                try
                {
                    std::cin >> *newFigure;
                    if (!std::cin.fail())
                    {
                        figures.pushBack(std::move(newFigure));
                        std::cout << "Успешно добавлен шестиугольник." << std::endl;
                    }
                }
                catch (std::invalid_argument &e)
                {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case '3':
                newFigure = std::make_unique<Octagon<double>>();
                std::cout << "Введите центр фигуры и сторону." << std::endl;
                std::cout << "Формат: X Y SIDE" << std::endl;
                try
                {
                    std::cin >> *newFigure;
                    if (!std::cin.fail())
                    {
                        figures.pushBack(std::move(newFigure));
                        std::cout << "Успешно добавлена трапеция." << std::endl;
                    }
                }
                catch (std::invalid_argument &e)
                {
                    std::cerr << e.what() << std::endl;
                }
                break;

            default:
                std::cerr << "Ошибка: команда не найдена" << std::endl;
                break;
            }
            break;

        case 'L':
            for (size_t i{}; i < figures.getSize(); ++i)
            {
                center = figures[i]->findCenter();
                std::cout << "Фигура \"" << *figures[i] << "\" с id=" << i << std::endl;
                std::cout << "    - Площадь: " << static_cast<double>(*figures[i]) << std::endl;
                std::cout << "    - Центр: (" << center->X() << ", " << center->Y() << ")" << std::endl;
            }
            break;

        case 'S':
            area = 0;
            for (size_t i{}; i < figures.getSize(); ++i)
                area += static_cast<double>(*figures[i]);
            std::cout << "Общая площадь: " << area << std::endl;
            break;

        case 'R':
            std::cout << "Введите id фигуры для удаления:" << std::endl;
            std::cin >> id;
            try
            {
                figures.remove(id);
                std::cout << "Фигура удалена" << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cerr << "Ошибка: фигура не найдена" << std::endl;
            }
            break;

        case 'H':
        case 'h':
        case '?':
            printHelp();
            break;

        case 'Q':
        case 'q':
        case 'E':
        case 'e':
            std::cout << "Выход..." << std::endl;
            isRunning = false;
            break;

        default:
            std::cin.clear();
            std::cerr << "Ошибка: команда не найдена" << std::endl;
            break;
        }
    }

    return 0;
}