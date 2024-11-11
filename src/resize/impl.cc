#include "impls.h"


cv::Mat my_resize(const cv::Mat& input, float scale) {
    /**
     * 要求：
     *      实现resize算法，只能使用基础的语法，比如说for循环，Mat的基本操作。不能
     * 用cv::resize。resize算法的内容自行查找学习，不是很难。
     * 
     * 提示：
     * 无。
     * 
     * 通过条件：
     * 运行测试点，你的结果跟答案长的差不多就行。
     */
    int new_rows = input.rows * scale, new_cols = input.cols * scale;
    // IMPLEMENT YOUR CODE HERE
   
    cv::Mat output(new_rows, new_cols, input.type());

   
    for (int i = 0; i < new_rows; i++) {
        for (int j = 0; j < new_cols; j++) {
            
            float x = j / scale;
            float y = i / scale; 

            int x1 = static_cast<int>(x);
            int y1 = static_cast<int>(y);
            int x2 = std::min(x1 + 1, input.cols - 1);
            int y2 = std::min(y1 + 1, input.rows - 1);

            cv::Vec3f p11 = input.at<cv::Vec3f>(y1, x1);
            cv::Vec3f p12 = input.at<cv::Vec3f>(y1, x2);
            cv::Vec3f p21 = input.at<cv::Vec3f>(y2, x1);
            cv::Vec3f p22 = input.at<cv::Vec3f>(y2, x2);

           
            float a = x - x1;
            float b = y - y1;

            cv::Vec3f pixelValue = (1 - a) * (1 - b) * p11 +
                                   (a) * (1 - b) * p12 +
                                   (1 - a) * (b) * p21 +
                                   (a) * (b) * p22;

           
            output.at<cv::Vec3f>(i, j) = pixelValue;
        }
    }


    return cv::Mat::zeros(new_rows, new_cols, input.type());
}