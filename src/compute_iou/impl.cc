#include "impls.h"
#include <algorithm>

float compute_iou(const cv::Rect& a, const cv::Rect& b) {
    /**
     * 要求：
     *      有一个重要的指标叫做“交并比”，简称“IOU”，可以用于衡量
     * 两个矩形的重合程度，本练习要求自行学习交并比的计算方式，计算输入
     * 的两个矩形的交并比。
     * 
     * 提示：
     * (1) 注意OpenCV中规定的xy坐标系方向跟平常的xy坐标系不一样。
     * (2) 注意矩形的x, y, width, height四个属性在坐标系内的含义。
     * (3) 注意分母不要除以0（不过我们不会测试这一点）
     * 
     * 通过条件：
     * 运行测试点，显示通过就行，不通过会告诉你哪一组矩形错了。
    */
    // IMPLEMENT YOUR CODE HERE
    int x_intersection = std::max(a.x, b.x);
    int y_intersection = std::max(a.y, b.y);
    int x_union = std::min(a.x + a.width, b.x + b.width);
    int y_union = std::min(a.y + a.height, b.y + b.height);
    int intersection_width = std::max(0, x_union - x_intersection);
    int intersection_height = std::max(0, y_union - y_intersection);
    int intersection_area = intersection_width * intersection_height;
    int union_area = a.area() + b.area() - intersection_area;
    if (union_area == 0)
     {
        return 0.f; // 避免除以零的情况
    }


    return 0.f;
}