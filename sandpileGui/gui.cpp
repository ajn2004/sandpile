#include <opencv2/core/core.hpp>
#include "../sand.cpp"
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <chrono>


int main() {

  int factor = 4;
  int width = 680;
  int height = 240;
  // import 3 models for RGB generation
  SandpileModel model0(height/factor,width/factor);
  SandpileModel model1(height/factor,width/factor);
  SandpileModel model2(height/factor,width/factor);
  model0.iterate(1);
  model1.iterate(1);
  model2.iterate(1);
  while (true){
    // Sample 2D vector
    std::vector<std::vector<int>> data0 = model0.getGrid();
    std::vector<std::vector<int>> data1 = model1.getGrid();
    std::vector<std::vector<int>> data2 = model2.getGrid();
  
    int rows = data0.size();
    int cols = data0[0].size();

    cv::Mat image(rows, cols, CV_8UC3);  // 8-bit signed single channel matrix

    for (int i = 0; i < rows; i += 1) {
      for (int j = 0; j < cols; j += 1) {
	cv::Vec3b &pixel = image.at<cv::Vec3b>(i,j);
	// fix the pixel value
        pixel[0] = data0[i][j];
	pixel[1] = data1[i][j];
        pixel[2] = data2[i][j];
      }
    }
    // resize the image
    cv::Mat scaled_grid;
    
    cv::resize(image,
	       scaled_grid,
	       cv::Size(), factor, factor,
	       cv::INTER_NEAREST);

    cv::normalize(scaled_grid,
		  scaled_grid,
		  0, 255,
		  cv::NORM_MINMAX, CV_8UC3);
    // cv::Mat colored_image;
    // cv::applyColorMap(scaled_grid,
    //     		      colored_image,
    // 		      cv::COLORMAP_JET);
    cv::imshow("// ", scaled_grid);
    cv::waitKey(1);
    
    model0.iterate(1);
    model1.iterate(1);
    model2.iterate(2);
  }
  return 0;
}
