//
//  Bisection.cpp
//  Bisection
//
//  Created by Stefan Janecek on 17.03.13.
//  Copyright (c) 2013 Stefan Janecek. All rights reserved.
//

#include "Bisection.hpp"
#include <cmath>
using namespace std;


///@@ Implement your bisection method here
///@@
///@@ Call the function 'double f(double x) (declared in Bisection.hpp, 
///@@ implemented in main.cpp) to calculate the value of the function f at 
///@@ position x)
void bisection(std::vector<double>& interval, double eps) {
	if ((interval.size() != 2) || (interval[1] - interval[0] < eps)) {
		std::cout << "Bitte sinnvolles Intervall einggeben, danke! \n";			//Länge des Vektors und sinnhaftigkeit des Intervalls wird überprüft
		end;
	}

	double l = interval[0];			//l ist jetzt untere Intervallgrenze und r ist obere Intervallgrene, dient zur Abkürzung im Folgenden
	double r = interval[1];			//es wird angenommen, dass dieses Intervall größer als epsilon ist und eine Nullstelle enthält

	while (r - l < eps) {
		if (f(l) == 0) {
			std::cout << "Das gesuchte Intervall ist [" << l << " ; " << l + eps << "] \n"
		}
		else if (f(r) == 0) {
			std::cout << "Das gesuchte Intervall ist [" << r-eps << " ; " << r << "] \n"		// es wird überprüft, ob f schon an den Intervallgrenzen eine Nullstelle hat.
		}
		else {
			double c = (r - l) / 2;			//Bisektion, halbiere das Intervall

			if ((f(l) < 0 && f(c) > 0) || (f(l) > 0 && f(c) < 0)) {				//Überprüfe, ob die Nullstelle in der ersten Intervallhälfte liegt
				r = c;		//Die obere Intervallgrenze wird überschrieben, die untere bleibt konstant
			}
			else if ((f(c) < 0 && f(r) > 0) || (f(c) > 0 && f(r) < 0)) {		//Überprüfe, ob die Nullstelle in der zweiten Intervallhälfte liegt
				l = c;		//Die untere Intervallgrenze wird überschrieben, die obere bleibt konstant
			}
			else { l = c }			//In diesem Fall muss c die gesuchte Nullstelle sein, da es dann egal ist, wird z.B. die untere Intervallgrenze überschrieben
		}
	}
	
	std::cout << "Die Nullstelle befindet sich im Intervall [" << l << " ; " << r << " ] \n"
}
