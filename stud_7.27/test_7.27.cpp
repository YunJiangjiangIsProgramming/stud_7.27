#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Eigen>

int main() {
    // 创建一个3x3的Eigen矩阵
    Eigen::Matrix3d A;
    A << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    // 计算矩阵的行列式
    double det_A = A.determinant();
    std::cout << "矩阵A的行列式: " << det_A << std::endl;

    // 计算矩阵的逆矩阵（如果存在）
    if (A.determinant() != 0.0) 
    {
        Eigen::Matrix3d inv_A = A.inverse();
        std::cout << "矩阵A的逆矩阵:\n" << inv_A << std::endl;
    }
    else
    {
        std::cout << "矩阵A是不可逆的，没有逆矩阵。" << std::endl;
    }

    // 计算矩阵的条件数
    double cond_A = A.inverse().norm() * A.norm();
    std::cout << "矩阵A的条件数: " << cond_A << std::endl;

    // 计算矩阵的范数
    double norm_A = A.norm();
    std::cout << "矩阵A的Frobenius范数: " << norm_A << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

// 定义π的值
const double PI = std::acos(-1);
#include "matplotlibcpp.h"
#include <cmath>

namespace plt = matplotlibcpp;

int main() {
    // 创建x数据
    std::vector<double> x(10);
    for (int i = 0; i < 10; ++i) {
        x[i] = i * M_PI / 10;
    }

    // 创建y1数据，y1 = x
    std::vector<double> y1(x);

    // 创建y2数据，y2 = sin(x)
    std::vector<double> y2(x);
    for (int i = 0; i < 10; ++i) {
        y2[i] = std::sin(x[i]);
    }

    // 绘制y1图
    plt::plot(x, y1, "b-");
    plt::title("y=x");
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();

    // 绘制y2图
    plt::subplot(2, 1, 2);
    plt::plot(x, y2, "r--");
    plt::title("y=sinx");
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();

    // 显示图形
    plt::show();

    return 0;
}

int main() {
    // 设置x值的范围和步长
    const int num_points = 10;
    const double step = PI / (num_points - 1);

    std::vector<double> x, y1, y2;

    // 计算x和对应的y值
    for (int i = 0; i < num_points; ++i) {
        double x_val = i * step;
        x.push_back(x_val);
        y1.push_back(x_val);  // y1是x的复制
        y2.push_back(std::sin(x_val));  // y2是x的正弦值
    }

    // 将数据写入文件，以便gnuplot读取
    std::ofstream data_file("data.dat");
    for (int i = 0; i < num_points; ++i) {
        data_file << x[i] << " " << y1[i] << " " << y2[i] << std::endl;
    }
    data_file.close();

    // 调用gnuplot来绘制图形
    system("gnuplot -p -e \"plot 'data.dat' using 1:2 with linespoints title 'x', '' using 1:3 with linespoints title 'sin(x)'\"");

    return 0;
}


#include "matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

int main() {
    // 给定您的数据
    std::vector<double> t = { 10, 20, 30, 40, 50 };
    std::vector<double> x = { 31, 40, 45, 50, 70 };
    std::vector<double> s = { 2, 1.4, 1.5, 1.3, 1.6 };

    // 创建两个vector来存储两个Y轴的数据
    std::vector<double> x_axis, y_axis1, y_axis2;

    // 填充x轴和第一个Y轴的数据
    for (int i = 0; i < t.size(); ++i) {
        x_axis.push_back(t[i]);
        y_axis1.push_back(x[i]);
    }

    // 填充第二个Y轴的数据
    y_axis2 = s;

    // 设置绘图参数
    plt::figure_size(1200, 780);
    plt::xlabel("t/min");
    plt::ylabel("conversion rate");
    plt::title("experiment data");

    // 绘制第一个Y轴的数据
    plt::plot(x_axis, y_axis1, "r");

    // 绘制第二个Y轴的数据
    plt::twinx();
    plt::ylabel("selectivy");
    plt::plot(x_axis, y_axis2, "b");

    // 显示图形
    plt::show();

    return 0;
}



