#include <iostream>
#include <algorithm>


int rectangleIntersectionArea(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    int left = std::max(x1, x3); 
    int right = std::min(x2, x4); 
    int top = std::min(y2, y4); 
    int bottom = std::max(y1, y3); 
    
    if (left < right && bottom < top) {
        return (right - left) * (top - bottom);
    }
    return 0;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int x1, y1, x2 , y2, x3, y3, x4, y4;
    std::cout << "Введите нижнюю левую точку 1 прямоугольника\n";
    std::cin >> x1 >> y1;
    std::cout << "Введите верхнюю правую точку 1 прямоугольника\n";
    std::cin >> x2 >> y2;
    std::cout << "Введите нижнюю левую точку 2 прямоугольника\n";
    std::cin >> x3 >> y3;
    std::cout << "Введите верхнюю правую точку 2 прямоугольника\n";
    std::cin >> x4 >> y4;
    int area = rectangleIntersectionArea(x1, y1, x2, y2, x3, y3, x4, y4);
    std::cout << "Площадь пересечения: " << area << std::endl;
  
}
