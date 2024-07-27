#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <Eigen>

int main() {
    // ����һ��3x3��Eigen����
    Eigen::Matrix3d A;
    A << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    // ������������ʽ
    double det_A = A.determinant();
    std::cout << "����A������ʽ: " << det_A << std::endl;

    // �������������������ڣ�
    if (A.determinant() != 0.0) 
    {
        Eigen::Matrix3d inv_A = A.inverse();
        std::cout << "����A�������:\n" << inv_A << std::endl;
    }
    else
    {
        std::cout << "����A�ǲ�����ģ�û�������" << std::endl;
    }

    // ��������������
    double cond_A = A.inverse().norm() * A.norm();
    std::cout << "����A��������: " << cond_A << std::endl;

    // �������ķ���
    double norm_A = A.norm();
    std::cout << "����A��Frobenius����: " << norm_A << std::endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

// ����е�ֵ
const double PI = std::acos(-1);
#include "matplotlibcpp.h"
#include <cmath>

namespace plt = matplotlibcpp;

int main() {
    // ����x����
    std::vector<double> x(10);
    for (int i = 0; i < 10; ++i) {
        x[i] = i * M_PI / 10;
    }

    // ����y1���ݣ�y1 = x
    std::vector<double> y1(x);

    // ����y2���ݣ�y2 = sin(x)
    std::vector<double> y2(x);
    for (int i = 0; i < 10; ++i) {
        y2[i] = std::sin(x[i]);
    }

    // ����y1ͼ
    plt::plot(x, y1, "b-");
    plt::title("y=x");
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();

    // ����y2ͼ
    plt::subplot(2, 1, 2);
    plt::plot(x, y2, "r--");
    plt::title("y=sinx");
    plt::xlabel("x");
    plt::ylabel("y");
    plt::legend();

    // ��ʾͼ��
    plt::show();

    return 0;
}

int main() {
    // ����xֵ�ķ�Χ�Ͳ���
    const int num_points = 10;
    const double step = PI / (num_points - 1);

    std::vector<double> x, y1, y2;

    // ����x�Ͷ�Ӧ��yֵ
    for (int i = 0; i < num_points; ++i) {
        double x_val = i * step;
        x.push_back(x_val);
        y1.push_back(x_val);  // y1��x�ĸ���
        y2.push_back(std::sin(x_val));  // y2��x������ֵ
    }

    // ������д���ļ����Ա�gnuplot��ȡ
    std::ofstream data_file("data.dat");
    for (int i = 0; i < num_points; ++i) {
        data_file << x[i] << " " << y1[i] << " " << y2[i] << std::endl;
    }
    data_file.close();

    // ����gnuplot������ͼ��
    system("gnuplot -p -e \"plot 'data.dat' using 1:2 with linespoints title 'x', '' using 1:3 with linespoints title 'sin(x)'\"");

    return 0;
}


#include "matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

int main() {
    // ������������
    std::vector<double> t = { 10, 20, 30, 40, 50 };
    std::vector<double> x = { 31, 40, 45, 50, 70 };
    std::vector<double> s = { 2, 1.4, 1.5, 1.3, 1.6 };

    // ��������vector���洢����Y�������
    std::vector<double> x_axis, y_axis1, y_axis2;

    // ���x��͵�һ��Y�������
    for (int i = 0; i < t.size(); ++i) {
        x_axis.push_back(t[i]);
        y_axis1.push_back(x[i]);
    }

    // ���ڶ���Y�������
    y_axis2 = s;

    // ���û�ͼ����
    plt::figure_size(1200, 780);
    plt::xlabel("t/min");
    plt::ylabel("conversion rate");
    plt::title("experiment data");

    // ���Ƶ�һ��Y�������
    plt::plot(x_axis, y_axis1, "r");

    // ���Ƶڶ���Y�������
    plt::twinx();
    plt::ylabel("selectivy");
    plt::plot(x_axis, y_axis2, "b");

    // ��ʾͼ��
    plt::show();

    return 0;
}



