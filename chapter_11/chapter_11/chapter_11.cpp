// chapter_11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "mytime0.h"
#include "stonewt.h"

int main()
{
    std::cout << "Hello World!\n";
    /*
    Time t1 = Time(1, 1);
    Time t2 = Time(2, 2);
    Time t3 = Time(3, 3);
    
    // Time sum = t1 + t2 + t3;
    //Time sum = t2 - t1;
    Time sum = 2 * t2;
    //sum.Show();
    std::cout << sum;
    */
    Stonewt poppins(9, 2.8);
    double p_wt = poppins;

    std::cout << "Convert to double =>";
    std::cout << "Poppins: " << p_wt << " pounds.\n";
    std::cout << "Convert to int =>";
    std::cout << "Poppins: " << int(poppins) << " pounds.\n";

    // long gone = poppins;  // 转换存在二义性
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
