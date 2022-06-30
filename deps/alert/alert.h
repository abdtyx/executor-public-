#ifndef H49FFDC31_A2D2_4FC7_B589_D4A628090088
#define H49FFDC31_A2D2_4FC7_B589_D4A628090088

#include <iostream>

typedef enum
{
	IN_DANGEROUS = 3,
} AlertType;

void alert(AlertType type, int x, int y)
{
	// 这里cout只是为了看看程序是否调用了这个接口
	std::cout << "At dangerous position: (" << x << ", " << y << "). System alert!" << std::endl;
	return;
}

#endif
