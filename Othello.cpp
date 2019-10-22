#include <iostream>
#include "TreeNode.h"
int main() {
	TreeNode x;
	std::cout << x.getBoard()[0].size() << std::endl;
	auto a(x);
	std::cout << a.getBoard()[0].size() << std::endl;
	
	std::cout << int(COLOR ::White) << std::endl;
    return 0;
}