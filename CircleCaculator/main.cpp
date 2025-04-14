#include <iostream>
#include <iomanip>
#include <cmath>

#define MinimumConversionValueOfLength 10
#define MinimumConversionValueOfArea 100

int main()
{
	
	unsigned short InputType;
	unsigned short UnitInitialEncoding = 0; std::string LengthUnit;

	const double pi = 3.14159265358979;
	double Radius, Diameter;
	double Square, Circumference;

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
		

		InputType = 1;
		std::cout << "知一得全部，半径请输入1，直径请输入2，周长请输入3，面积请输入4" << std::endl;
		std::cin >> InputType;
		if (InputType == 1) {
			std::cout << "请输入圆的半径" << std::endl;
			std::cin >> Radius;
			Diameter = Radius * 2;
			Circumference = 2 * pi * Radius;
			Square = pi * Radius * Radius;
			break;
		}
		if (InputType == 2) {
			std::cout << "请输入圆的直径" << std::endl;
			std::cin >> Diameter;
			Radius = Diameter / 2;
			Circumference = 2 * pi * Radius;
			Square = pi * Radius * Radius;
			break;
		}
		if (InputType == 3)
		{
			std::cout << "请输入圆的周长" << std::endl;
			std::cin >> Circumference;
			Diameter = Circumference / pi;
			Radius = Diameter / 2;
			Square = Radius * Radius * pi;
			break;
		}
		if (InputType == 4) 
		{
			std::cout << "请输入圆的面积" << std::endl;
			std::cin >> Square;
			Radius = sqrt(Square / pi);
			Diameter = Radius * 2;
			Circumference = 2 * pi * Radius;
			break;
		}
		else {
			std::cout << "输入非法" << std::endl;OutlierDetection = true;
		}
	} while (OutlierDetection);

	
	std::cout << "圆的半径是：" << std::setprecision(9) << Radius << LengthUnit << std::endl;
	std::cout << "圆的直径是：" << std::setprecision(9) << Diameter << LengthUnit << std::endl;
	std::cout << "圆的周长是：" << std::setprecision(9) << Circumference << LengthUnit << std::endl;
	std::cout << "圆的面积是：" << std::setprecision(9) << Square << LengthUnit << "²" << std::endl;

	std::string conversion = "no";
	std::cout << "\n" << "是否要换算单位（yes or no）" << std::endl;
	std::cin >> conversion;

	if (conversion == "yes")
	{
		double ConvertedRadius, ConvertedDiameter;
		double ConvertedSquare, ConvertedCircumference;
		unsigned short UnitTargetEncoding = 0; std::string ConvertLengthUnit;

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
			ConvertedRadius = Radius;
			ConvertedDiameter = Diameter;
			ConvertedCircumference = Circumference;
			ConvertedSquare = Square;
		}

		if (ConvertUnitDistance > 0) {
			ConvertedRadius = Radius * pow(MinimumConversionValueOfLength, ConvertUnitDistance);
			ConvertedDiameter = Diameter * pow(MinimumConversionValueOfLength, ConvertUnitDistance);
			ConvertedCircumference = Circumference * pow(MinimumConversionValueOfLength, ConvertUnitDistance);
			ConvertedSquare = Square * pow(MinimumConversionValueOfArea, ConvertUnitDistance);
		}

		if (ConvertUnitDistance < 0) {
			ConvertUnitDistance = abs(ConvertUnitDistance);

			ConvertedRadius = Radius / pow(MinimumConversionValueOfLength, ConvertUnitDistance);
			ConvertedDiameter = Diameter / pow(MinimumConversionValueOfLength, ConvertUnitDistance);
			ConvertedCircumference = Circumference / pow(MinimumConversionValueOfLength, ConvertUnitDistance);
			ConvertedSquare = Square / pow(MinimumConversionValueOfArea, ConvertUnitDistance);
		}

		std::cout << "换算后圆的半径是：" << std::setprecision(9) << ConvertedRadius << ConvertLengthUnit << std::endl;
		std::cout << "换算后圆的直径是：" << std::setprecision(9) << ConvertedDiameter << ConvertLengthUnit << std::endl;
		std::cout << "换算后圆的周长是：" << std::setprecision(9) << ConvertedCircumference << ConvertLengthUnit << std::endl;
		std::cout << "换算后圆的面积是：" << std::setprecision(9) << ConvertedSquare << ConvertLengthUnit << "²" << std::endl;

		std::cout << "程序运行结束" << std::endl;

		return 0;
	}
}
