#include <opencv2/core/core.hpp>
#include "sandpile/sand.cpp"
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <thread>
#include <chrono>


int main() {

  SandpileModel model(720,1280);
  model.iterate(10000);
  while (true){
    // Sample 2D vector
    std::vector<std::vector<int>> data = model.getGrid();
  
    int rows = data.size();
    int cols = data[0].size();

    cv::Mat image(rows, cols, CV_8SC1);  // 8-bit signed single channel matrix

    for (int i = 0; i < rows; i += 2) {
      for (int j = 0; j < cols; j += 2) {
	image.at<int8_t>(i, j) = data[i][j];
	image.at<int8_t>(i, j+1) = data[i][j];
	image.at<int8_t>(i+1, j) = data[i][j];
	image.at<int8_t>(i+1, j+1) = data[i][j];
      }
    }

    cv::normalize(image, image, 0, 255, cv::NORM_MINMAX, CV_8UC1);  // Normalize for visualization

    cv::imshow("Grayscale Image", image);
    cv::waitKey(1);
    
    model.iterate(10);
  }
  return 0;
}
