#include <opencv2/core/core.hpp>
#include "../sand.cpp"
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <thread>
#include <chrono>


int main() {

  int factor = 5;
  SandpileModel model(1080/factor,1920/factor);
  model.iterate(1);
  while (true){
    // Sample 2D vector
    std::vector<std::vector<int>> data = model.getGrid();
  
    int rows = data.size();
    int cols = data[0].size();

    cv::Mat image(rows, cols, CV_8SC1);  // 8-bit signed single channel matrix

    for (int i = 0; i < rows; i += 1) {
      for (int j = 0; j < cols; j += 1) {
	image.at<int8_t>(i, j) = data[i][j];
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
		  cv::NORM_MINMAX, CV_8UC1);
    cv::imshow("Grayscale Image", scaled_grid);
    cv::waitKey(1);
    
    model.iterate(1);
  }
  return 0;
}
