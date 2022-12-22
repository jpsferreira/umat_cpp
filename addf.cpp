#include <iostream>

extern "C" {
  void addf(float a, float b);
//function definition
float addf(float a,float b)
{
	return (a+b);
}

}

