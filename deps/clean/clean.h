#ifndef H95E613B3_B293_451C_8DA4_EE2CFFD3CC1B
#define H95E613B3_B293_451C_8DA4_EE2CFFD3CC1B

#include <iostream>

void clean(int x, int y)
{
	// 这里cout只是为了看看程序是否调用了这个接口
    std::cout << "Cleaned position: (" << x << ", " << y << ")." << std::endl;
    return;
}

#endif
