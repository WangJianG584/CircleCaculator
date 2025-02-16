#include <iostream>
#include <iomanip>
#include <cmath>


#define MinimumConversionValueOfLength 10
#define MinimumConversionValueOfArea 100


int main()
{
    
    unsigned int inputtype;
    unsigned int UnitInitialEncoding = 0; std::string LengthUnit;

    const double pi = 3.14159265358979;
    double radius, diameter;

    bool OutlierDetection;
    do {
        OutlierDetection = false;
        LengthUnit = "km";

        std::cout << "你现在输入的长度单位是多少" << "(请输入英文缩写)" << std::endl;
        std::cin >> LengthUnit;
        if (LengthUnit == "mm" || LengthUnit == "MM") {
            UnitInitialEncoding = 1;
            break;
        }
        if (LengthUnit == "cm" || LengthUnit == "CM") {
            UnitInitialEncoding = 2;
            break;
        }
        if (LengthUnit == "dm" || LengthUnit == "DM") {
            UnitInitialEncoding = 3;
            break;
        }
        if (LengthUnit == "m" || LengthUnit == "M") {
            UnitInitialEncoding = 4;
            break;
        }
        if (LengthUnit == "km" || LengthUnit == "KM") {
            UnitInitialEncoding = 7;
            break;
        }
        else {
            std::cout << "输入非法" << std::endl;OutlierDetection = true;

        }
    } while (OutlierDetection);

    do {
        OutlierDetection = false;

        inputtype = 1;
        std::cout << "你现在输入的是直径还是半径，半径请输入1，直径请输入2" << std::endl;
        std::cin >> inputtype;
        if (inputtype == 1) {
            std::cout << "请输入圆的半径" << std::endl;
            std::cin >> radius;
            diameter = radius * 2;
            std::cout << "圆的直径是：" << std::setprecision(9) << diameter << LengthUnit << std::endl;
            break;
        }
        if (inputtype == 2) {
            std::cout << "请输入圆的直径" << std::endl;
            std::cin >> diameter;
            radius = diameter / 2;
            std::cout << "圆的半径是：" << std::setprecision(9) << radius << LengthUnit << std::endl;
            break;
        }
        else {
            std::cout << "输入非法" << std::endl;OutlierDetection = true;
        }

    } while (OutlierDetection);

    double area, perimeter;
    perimeter = 2 * pi * radius;
    area = pi * radius * radius;
    std::cout << "圆的周长是：" << std::setprecision(9) << perimeter << LengthUnit << std::endl;
    std::cout << "圆的面积是：" << std::setprecision(9) << area << LengthUnit << "²" << std::endl;

    std::string conversion = "no";
    std::cout << "\n" << "是否要换算单位（yes or no）" << std::endl;
    std::cin >> conversion;

    if (conversion == "yes")
    {
        double ConvertedRadius, ConvertedDiameter;
        double ConvertedArea, ConvertedPerimeter;
        unsigned int UnitTargetEncoding = 0; std::string ConvertLengthUnit;

        do {
            OutlierDetection = false;

            ConvertLengthUnit = "km";
            std::cout << "请输入要换算的单位缩写" << std::endl;
            std::cin >> ConvertLengthUnit;
            if (ConvertLengthUnit == "mm" || ConvertLengthUnit == "MM") {
                UnitTargetEncoding = 1;
                break;
            }
            if (ConvertLengthUnit == "cm" || ConvertLengthUnit == "CM") {
                UnitTargetEncoding = 2;
                break;
            }
            if (ConvertLengthUnit == "dm" || ConvertLengthUnit == "DM") {
                UnitTargetEncoding = 3;
                break;
            }
            if (ConvertLengthUnit == "m" || ConvertLengthUnit == "M") {
                UnitTargetEncoding = 4;
                break;
            }
            if (ConvertLengthUnit == "km" || ConvertLengthUnit == "KM") {
                UnitTargetEncoding = 7;
                break;
            }
            else {
                std::cout << "输入非法" << std::endl;OutlierDetection = true;
            }
        } while (OutlierDetection);

        int ConvertUnitDistance = UnitInitialEncoding - UnitTargetEncoding;
        if (ConvertUnitDistance == 0) {

            ConvertedRadius = radius;
            ConvertedDiameter = diameter;
            ConvertedPerimeter = perimeter;
            ConvertedArea = area;
        }

        if (ConvertUnitDistance > 0) {

            ConvertedRadius = radius * pow(MinimumConversionValueOfLength, ConvertUnitDistance);
            ConvertedDiameter = diameter * pow(MinimumConversionValueOfLength, ConvertUnitDistance);
            ConvertedPerimeter = perimeter * pow(MinimumConversionValueOfLength, ConvertUnitDistance);
            ConvertedArea = area * pow(MinimumConversionValueOfArea, ConvertUnitDistance);

        }

        if (ConvertUnitDistance < 0) {
            ConvertUnitDistance = abs(ConvertUnitDistance);

            ConvertedRadius = radius / pow(MinimumConversionValueOfLength, ConvertUnitDistance);
            ConvertedDiameter = diameter / pow(MinimumConversionValueOfLength, ConvertUnitDistance);
            ConvertedPerimeter = perimeter / pow(MinimumConversionValueOfLength, ConvertUnitDistance);
            ConvertedArea = area / pow(MinimumConversionValueOfArea, ConvertUnitDistance);

        }

        std::cout << "换算后圆的半径是：" << std::setprecision(9) << ConvertedRadius << ConvertLengthUnit << std::endl;
        std::cout << "换算后圆的直径是：" << std::setprecision(9) << ConvertedDiameter << ConvertLengthUnit << std::endl;
        std::cout << "换算后圆的周长是：" << std::setprecision(9) << ConvertedPerimeter << ConvertLengthUnit << std::endl;
        std::cout << "换算后圆的面积是：" << std::setprecision(9) << ConvertedArea << ConvertLengthUnit << "²" << std::endl;

        std::cout << "程序运行结束" << std::endl; 
        
        return 0;

    }

}